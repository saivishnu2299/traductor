// These constants won't change:
const int sensorPinTHUMB = A0;    // pin that the THUMB flex sensor is attached to
const int sensorPinINDEX = A1;    // pin that the INDEX flex sensor is attached to
const int sensorPinMIDDLE = A2;    // pin that the MIDDLE flex sensor is attached to
const int sensorPinRING = A3;    // pin that the RING flex sensor is attached to
const int sensorPinPINKEY = A4;    // pin that the PINKEY flex sensor is attached to


// variables:
int sensorValueTHUMB = 0;         // the sensor value
int sensorValueINDEX = 0;         // the sensor value
int sensorValueMIDDLE = 0;         // the sensor value
int sensorValueRING = 0;         // the sensor value
int sensorValuePINKEY = 0;         // the sensor value

int sensorMinTHUMB = 1023;          // minimum sensor value
int sensorMinINDEX = 1023;        // minimum senszor value
int sensorMinMIDDLE = 1023;        // minimum sensor value
int sensorMinRING = 1023;        // minimum sensor value
int sensorMinPINKEY = 1023;        // minimum sensor value

int sensorMaxTHUMB = 0;           // maximum sensor value
int sensorMaxINDEX = 0;           // maximum sensor value
int sensorMaxMIDDLE = 0;           // maximum sensor value
int sensorMaxRING = 0;           // maximum sensor value
int sensorMaxPINKEY = 0;           // maximum sensor value


void setup() {
  
/*
 // calibrate during the first five seconds 
  while (millis() < 5000) {
      sensorValueTHUMB = analogRead(sensorPinTHUMB);
      sensorValueINDEX = analogRead(sensorPinINDEX);
      sensorValueMIDDLE = analogRead(sensorPinMIDDLE);
      sensorValueRING = analogRead(sensorPinRING);
     sensorValuePINKEY = analogRead(sensorPinPINKEY); 
//--------------------------------------------------

    // record the maximum sensor value
    if (sensorValueTHUMB > sensorMaxTHUMB) {
      sensorMaxTHUMB = sensorValueTHUMB;
    }
       // record the maximum sensor value
    if (sensorValueINDEX > sensorMaxINDEX) {
      sensorMaxINDEX = sensorValueINDEX;
    }
   // record the maximum sensor value
    if (sensorValueMIDDLE > sensorMaxMIDDLE) {
      sensorMaxMIDDLE = sensorValueMIDDLE;
    }
    // record the maximum sensor value
    if (sensorValueRING > sensorMaxRING) {
      sensorMaxRING = sensorValueRING;
    }
    // record the minimum sensor value
    if (sensorValueRING < sensorMinRING) {
      sensorMinRING = sensorValueRING;
    }
     // record the maximum sensor value
    if (sensorValuePINKEY > sensorMaxPINKEY) {
      sensorMaxPINKEY = sensorValuePINKEY;
    }
    //--------------------------------------------------------

    // record the minimum sensor value
    if (sensorValueTHUMB < sensorMinTHUMB) {
      sensorMinTHUMB = sensorValueTHUMB;
    }
    
       // record the minimum sensor value
    if (sensorValueINDEX < sensorMinINDEX) {
      sensorMinINDEX = sensorValueINDEX;
    }
        // record the minimum sensor value
    if (sensorValueMIDDLE < sensorMinMIDDLE) {
      sensorMinMIDDLE = sensorValueMIDDLE;
    }
    // record the minimum sensor value
    if (sensorValueRING < sensorMinRING) {
      sensorMinRING = sensorValueRING;
    }
    // record the minimum sensor value
    if (sensorValuePINKEY < sensorMinPINKEY) {
      sensorMinPINKEY = sensorValuePINKEY;
    }
  
}
*/
  // signal the end of the calibration period
 // digitalWrite(ledPinBLUE, LOW);
 
  
  Serial.print ("LowTHUMB = ");
  Serial.println (sensorMinTHUMB);
  Serial.print ("HighTHUMB = ");
  Serial.println (sensorMaxTHUMB);
  
  Serial.println ("             ");
  
  Serial.print ("LowINDEX = ");
  Serial.println (sensorMinINDEX);
  Serial.print ("HighINDEX = ");
  Serial.println (sensorMaxINDEX);
  
  Serial.println ("             "); 
  
  Serial.print ("LowMIDDLE = ");
  Serial.println (sensorMinMIDDLE);
  Serial.print ("HighMIDDLE = ");
  Serial.println (sensorMaxMIDDLE);
  
  Serial.println ("             "); 
  
  Serial.print ("LowRING = ");
  Serial.println (sensorMinRING);
  Serial.print ("HighRING = ");
  Serial.println (sensorMaxRING);
  
  Serial.println ("             "); 
  
  Serial.print ("LowPINKEY = ");
  Serial.println (sensorMinPINKEY);
  Serial.print ("HighPINKEY = ");
  Serial.println (sensorMaxPINKEY);
  
  Serial.println ("             ");
  

}

void loop() {
 

  
  // read the sensor:
  sensorValueTHUMB = analogRead(sensorPinTHUMB);
  sensorValueINDEX = analogRead(sensorPinINDEX);
  sensorValueMIDDLE = analogRead(sensorPinMIDDLE);
  sensorValueRING = analogRead(sensorPinRING);
  sensorValuePINKEY = analogRead(sensorPinPINKEY);

  // apply the calibration to the sensor reading
  sensorValueTHUMB = map(sensorValueTHUMB, sensorMinTHUMB, sensorMaxTHUMB, 1, 255);
  sensorValueINDEX = map(sensorValueINDEX, sensorMinINDEX, sensorMaxINDEX, 1, 255);
  sensorValueMIDDLE = map(sensorValueMIDDLE, sensorMinMIDDLE, sensorMaxMIDDLE, 1, 255);
  sensorValueRING = map(sensorValueRING, sensorMinRING, sensorMaxRING, 1, 255);
  sensorValuePINKEY = map(sensorValuePINKEY, sensorMinPINKEY, sensorMaxPINKEY, 1, 255);

  // in case the sensor value is outside the range seen during calibration
  sensorValueTHUMB = constrain(sensorValueTHUMB, 1, 255);
  sensorValueINDEX = constrain(sensorValueINDEX, 1, 255);
  sensorValueMIDDLE = constrain(sensorValueMIDDLE, 1, 255);
  sensorValueRING = constrain(sensorValueRING, 1, 255);
  sensorValuePINKEY = constrain(sensorValuePINKEY, 1, 255);
  
  Serial.println ("-------------------");
  Serial.print ("sensorValue-THUMB = ");
  Serial.println (sensorValueTHUMB);
  
  Serial.print ("sensorValue-INDEX = ");
  Serial.println (sensorValueINDEX);
  
  Serial.print ("sensorValue-MIDDLE = ");
  Serial.println (sensorValueMIDDLE);
  
  Serial.print ("sensorValue-RING = ");
  Serial.println (sensorValueRING);
  
  Serial.print ("sensorValue-PINKEY = ");
  Serial.println (sensorValuePINKEY);
  
 
  
  //--------------------------------LetterA-----------------------------
  
  if (sensorValueTHUMB > 1 && sensorValueINDEX == 1 && sensorValueMIDDLE == 1 && sensorValueRING == 1 ) {
    
    Serial.println  ("\n");
    Serial.println ("A"); //Print letter A to serial
    Serial.println  ("        ");
    
  }
  
  else {
    
  }
  
  //--------------------------------LetterB-----------------------------
  
  if (sensorValueTHUMB > 200 && sensorValueINDEX > 200 && sensorValueMIDDLE > 200 && sensorValueRING > 200 /* && accelerationX > 650 */  ) {
    
    Serial.println ("B"); //Print letter B to serial
    Serial.println  ("        ");
    
  }
  
  else {
    
  }
  
  //--------------------------------LetterC-----------------------------
  
  
  if (sensorValueTHUMB < 200 && sensorValueTHUMB > 20 && sensorValueINDEX < 200 && sensorValueINDEX > 20 && sensorValueMIDDLE < 200 && sensorValueMIDDLE > 20 && sensorValueRING < 200 && sensorValueRING > 20) {
    
    Serial.println ("C"); //Print letter C to serial
    Serial.println  ("        ");
   
  }
  
  else {
   
  }
  
  //--------------------------------LetterD-----------------------------
  
  
  if (sensorValueTHUMB == 1 && sensorValueINDEX > 100 && sensorValueMIDDLE == 1 && sensorValueRING == 1 /* && accelerationX > 650 */) {
    
    Serial.println ("D"); //Print letter D to serial
    Serial.println  ("        ");
    
  }
  
  else {
   
  }
  
  //--------------------------------LetterE-----------------------------
  
  
  if (sensorValueTHUMB == 1 && sensorValueINDEX == 1 && sensorValueMIDDLE == 1 && sensorValueRING == 1 /* && accelerationX > 650 */) {
    
    Serial.println ("E"); //Print letter E to serial
    Serial.println  ("        ");
    
  }
  
  else {
   
  }
  
  //--------------------------------LetterF-----------------------------
  
  
  if (sensorValueTHUMB == 1 && sensorValueINDEX == 1 && sensorValueMIDDLE > 200 && sensorValueRING > 200 /* && accelerationX > 650 */) {
    
    Serial.println ("F"); //Print letter F to serial
    Serial.println  ("        ");
    
  }
  
  else {
   
  }
  
  delay (1000);
  
   

}
