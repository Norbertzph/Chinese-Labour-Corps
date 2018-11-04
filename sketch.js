var serial;
var usbPort = "/dev/cu.usbmodem1411";

var x = 0;
var y = 0;
var prev_x = 0;
var prev_y = 0;

function setup() {
  // Instantiate our SerialPort object
  serial = new p5.SerialPort();

  // Add handlers
  serial.on('list', gotList);
  serial.on('data', gotData);
  serial.on('error', gotError);
  serial.on('open', gotOpen);

  createCanvas(800, 600);

  // Set background colour
  background( 204 );

  // Set line thickness
  strokeWeight( 2 );
}

function gotList(ports) {
  for (var i = 0; i < ports.length; i++) {
    if ( ports[i].indexOf( "cu.usb" ) != -1 ){
      usbPort = ports[i];
    }
  }

  serial.open(usbPort);
}

function gotOpen() {
  console.log("Serial Port is open!");
}

function gotError(error) {
  console.log(error);
}

function gotData() {
  var currentString = trim(serial.readStringUntil("\r\n"));
  if(!currentString){
    return;
  }
  // Trim white space and split data on commas
  var data = split( trim( currentString ), ',' );
  if(data.length < 3){
    return;
  }

  x = parseInt(map( data[0], 0, 1023, 0, width ));
  y = parseInt(map( data[1], 0, 1023, 0, height ));
}

function draw() {
  // Turn on stroke
  stroke( 0 );

  // Draw a line from current to previous X,Y
  line( x, y, prev_x, prev_y );

  // Store X,Y position for next frame
  prev_x = x;
  prev_y = y;

  // Set the fill colour to transparent white
  fill( 255, 255, 255, 2 );

  // Turn off stroke
  noStroke();

  // Fill screen with transparent white
  rect( 0, 0, width, height );
}
