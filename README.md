# Etch-a-sketch P5.js

This P5.js application is designed to consume values being sent continously over the serial port from an Arduino running this [Gist by @unknowndomain](https://gist.github.com/unknowndomain/598d71fe88f169d44c36). The expectation is that the Arduino is wired with two potentiometers and a button. Every newline value being sent is a string in the following format:

`123, 345, 0`

The 3 values delimited by commas are expected to be two `analogRead()` values (between 0 & 1023) and one boolean (0 or 1).

In the sketch these values are being used to draw on x & y axis and clear the screen:

`x-axis, y-axis, clear`

----

### p5.serialport 

So that our P5.js application can access the serial port from the browser we need to install and run the [p5.serialport](https://github.com/vanevery/p5.serialport) node server. To do this make sure [NodeJS is installed](https://nodejs.org/en/download/). Once NodeJS is installed you can use Node Package Manager (`npm`) to install the the P5.SerialPort server by running the following command in the terminal:

`sudo npm install -g p5.serialserver`

> Note: You will be asked for your password   
> Note: using the `-g` flag will make the command available globally 

Once this has finished installing you will be able to run node server by entering the following command:

`p5serial`

You are all done. Running the P5 application provided in this repo should now connect to a serial port with the prefix of `cu.usb`. The p5.serialport.js client script is already [included the the HTML file](https://github.com/lcc-prototyping-lab/etch-a-sketch-p5js/blob/master/index.html#L4).
