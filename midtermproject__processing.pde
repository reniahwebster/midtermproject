import processing.serial.*;

Serial myPort;
//int potState;
int motionState;
//int[] inputVars = {0, 0}; //make array to be populated from serial (note number of variables)

import processing.video.*;

Capture cam;

void setup () {
  size(640, 480);

  String[] cameras = Capture.list();
 
  if (cameras.length == 0) {
    println("There are no cameras available for capture.");
    exit();
  } else {
    println("Available cameras:");
    for (int i = 0; i < cameras.length; i++) {
      println(cameras[i]);
    }
   
    // The camera can be initialized directly using an
    // element from the array returned by list():
    cam = new Capture(this, cameras[0]);
    cam.start();    
  }      
  rectMode(CENTER);
  println(Serial.list()); //print serial devices (remember to count from 0)
  myPort = new Serial(this, Serial.list()[0], 9600); //make sure the baudrate matches arduino
  myPort.bufferUntil('\n'); // don't generate a serialEvent() unless you get a newline character
}
void draw () {
    if (cam.available() == true) {
    cam.read();
  }
  //background(0);
  if (motionState == 1){
    //fill(color(int(random(255)),int(random(255)),int(random(255))));
    image(cam, 0, 0, width, height);
  }
  else{
    background(0);
    //fill(255);
  }
  //rect(width/2, height/2, width, height);
   //rect(width/2, height/2, map(inputVars[0], 0, 1023, 0, width), map(inputVars[0], 0, 1023, 0, width));

}

void serialEvent (Serial myPort) {
  String inString = myPort.readStringUntil('\n'); //read until new line (Serial.println on Arduino)
  if (inString != null) {
    motionState = int(trim(inString)); // trim off whitespace
    //inputVars = int(split(inString, '&')); // break string into an array and change strings to ints
}
}
