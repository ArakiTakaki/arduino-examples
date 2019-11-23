import * as SerialPort  from 'serialport';
// $ ls /dev/ | grep cu.usb | pbcopy
const portName = '/dev/cu.usbmodem143401'; // Mac環境

const arduino = new SerialPort(portName, {
  baudRate: 9600,
}, (error) => {
  if (error == null) return;
  console.error('通信できませんでした');
  console.error(error);
  throw error;
});

// シリアル通信を受け取る
arduino.on('data', (data: Buffer) => {
  process.stdout.write(data.toString('ascii', 0, 32));
});

let rotate = 0;
let offset = 30;
arduino.on('open', function () {
  console.log('serial poort open');
  setInterval(() => {
    const byte = 1;
    const buf = Buffer.alloc(byte);
    buf.fill(rotate, 0, 1);
    rotate += offset;
    if (rotate <= 0 || rotate >= 180) offset *= -1;
    arduino.write(buf, (err) => {
      if (err != null) throw err;
    });
  }, 1000);
});

// arduino.emit('o');

