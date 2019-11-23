import * as SerialPort  from 'serialport';
const { Readline } = SerialPort.parsers;

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

setInterval(() => {
  arduino.write(Buffer.from('o'), (err) => {
    if (err != null) throw err;
  });
}, 1000);

// arduino.emit('o');

