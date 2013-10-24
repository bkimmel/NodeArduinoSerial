// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

int sensorTmp = 0;

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  if (abs(sensorTmp - sensorValue) >= 25)
  {
    sensorTmp = sensorValue;
    Serial.println(map(sensorValue, 0, 1023, 255, 1));
  }
  
  delay(20);        // delay in between reads for stability
}
