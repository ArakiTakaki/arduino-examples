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

arduino.on('open', function () {
  console.log('serial poort open');
  setInterval(() => {
    const byte = 6;
    const buf = Buffer.alloc(byte);

    buf.fill(Buffer.from('r')[0], 0, 1);
    buf.fill(Math.floor(0xff * Math.random()),1, 2);

    buf.fill(Buffer.from('g')[0], 2, 3);
    buf.fill(Math.floor(0xff * Math.random()),3, 4);

    buf.fill(Buffer.from('b')[0], 4, 5);
    buf.fill(Math.floor(0xff * Math.random()),5, 6);

    arduino.write(buf, (err) => {
      if (err != null) throw err;
    });
  }, 1000);
});

// arduino.emit('o');

