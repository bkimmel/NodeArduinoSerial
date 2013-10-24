var serialport = require("serialport");
var SerialPort = serialport.SerialPort; // localize object constructor
var http = require('http');
var io = require('socket.io').listen(80); 


/*
{ 
    parser: serialport.parsers.readline("\n") 
  }
*/

var serialPort = new SerialPort("COM4", {
		baudrate: 9600,
		parser: serialport.parsers.readline("\n")
});
	

io.sockets.on('connection', function (socket) {
  
  serialPort.on('data', function(data) {
		console.log('sending to socketio: ' + data);
		socket.emit('news', { hello: data });
   });
  
});