import * as SerialPort  from 'serialport';
// $ ls /dev/ | grep cu.usb | pbcopy
const portName = '/dev/cu.usbmodem143401'; // Mac環境

const arduino = new SerialPort(portName, {
  baudRate: 9600 / 2,
}, (error) => {
  if (error == null) return;
  console.error('通信できませんでした');
  console.error(error);
  throw error;
});

arduino.write('o');
// arduino.emit('o');

