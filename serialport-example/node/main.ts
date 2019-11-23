import * as SerialPort  from 'serialport';
// $ ls /dev/ | grep cu.usb | pbcopy
const portName = '/dev/cu.usbmodem143401'; // Mac環境
const arduino = new SerialPort(portName, (error) => {
  console.error('通信できませんでした');
  console.error(error);
  throw error;
});

arduino.write('o');
// arduino.emit('o');
