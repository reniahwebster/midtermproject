int led = 13;                // the pin that the LED is atteched to
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)
void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  Serial.println(val);
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    delay(100);                // delay 100 milliseconds
   
    if (state == LOW) {
//      Serial.println("Motion detected!");
      state = HIGH;       // update variable state to HIGH
    }
  }
  else {
      digitalWrite(led, LOW); // turn LED OFF
      delay(200);             // delay 200 milliseconds
     
      if (state == HIGH){
//        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}


//
//void loop() {                   //different functions for different data needs
//  if (Serial.available() > 0) {
//    receiveOneByte();
//    //receiveString();
//    //receiveInt();
//    //receiveMultipleBytes();
//  }
//}





//void receiveOneByte(){ //0-255
//  inByte = Serial.read();
//  if (inByte == 255){         //whatever conditional / logic / mapping
//    digitalWrite(13, HIGH);
//  }
//  else{
//    digitalWrite(13, LOW);
//  }
//}
//
//
//
//void receiveString(){ //needs teriminal new line to end packet (or a character of your choosing in processing)
//  inString = Serial.readStringUntil('\n');
//  inString.trim();
//  if (inString == "ON"){         //whatever conditional / logic / mapping
//    digitalWrite(13, HIGH);
//  }
//  else{
//    digitalWrite(13, LOW);
//  }
//}
//
//
//
//void receiveInt(){ //needs teriminal new line to end packet (or a character of your choosing in processing)
//  inString = Serial.readStringUntil('\n');
//  inString.trim();
//  inInt = inString.toInt();
//  if (inInt > 512){               //whatever conditional / logic / mapping
//    digitalWrite(13, HIGH);
//  }
//  else{
//    digitalWrite(13, LOW);
//  }
////  analogWrite(8, inInt);
//}
//
//
//
//void receiveMultipleBytes(){ //needs teriminal new line to end packet (or a character of your choosing in processing)
//  inString = Serial.readStringUntil('\n');
//  for (int i = 0; i < numVars; i++){ //converting from hex string to int
//    int converterA;
//    int converterB;
//    if (int((inString.substring(2*i, 2*i+2)).charAt(0)) < 58){
//      converterA = 48;
//    }
//    else{
//      converterA = 55;
//    }
//    if (int((inString.substring(2*i, 2*i+2)).charAt(1)) < 58){
//      converterB = 48;
//    }
//    else{
//      converterB = 55;
//    }
//    hexArray[i] = (int((inString.substring(2*i, 2*i+2)).charAt(0))-converterA)*16 + (int((inString.substring(2*i, 2*i+2)).charAt(1))-converterB);
//  }
//  if (hexArray[0] == 238){           //whatever conditional / logic / mapping
//    digitalWrite(13, HIGH);
//  }
//  else{
//    digitalWrite(13, LOW);
//  }
//}
//
//







































//HEAD
//byte tempByte;
//byte terminationByte = 255; // multiple bytes
//boolean multiBytesStarted = 0; // multiple bytes
//byte inBytes[numVars]; // multiple bytes
//int byteCounter = 0; // multiple bytes



//void receiveMultipleBytes(){
//  tempByte = Serial.read();
//  if (tempByte = terminationByte && !multiBytesStarted){
//    multiBytesStarted = 1;
//  }
//  if (multiBytesStarted){
//    inBytes[byteCounter] = tempByte;
//    byteCounter++;
//  }
//  if (byteCounter >= numVars && multiBytesStarted){
//    !multiBytesStarted;
//    byteCounter = 0;
//  }
//  if (inBytes[0] == 125){
//    digitalWrite(13, HIGH);
//  }
//  else{
//    digitalWrite(13, LOW);
//  }
//  if (tempByte != terminationByte){
//    inBytes[byteCounter] = tempByte;
//    byteCounter++;
//    if (byteCounter >= numVars){
//      byteCounter = numVars - 1;
//    }
//  }
//  else{
//    inBytes[byteCounter] = '\0';
//    byteCounter = 0;
//  }
//}
