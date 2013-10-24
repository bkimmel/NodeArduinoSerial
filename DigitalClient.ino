// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;
int checkState;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(13, OUTPUT);
}



// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  
  if(buttonState == HIGH)
  {
    digitalWrite(13, HIGH);
    delay(50); //crude de-bounce
    if (checkState != buttonState)
    {
      delay(50); //crude de-bounce
      
      // print out the state of the button:
      Serial.println("ON");
      
    }
    checkState = buttonState;
    
  }
  else
  {
    digitalWrite(13, LOW);
    delay(50); //crude de-bounce
    if (checkState != buttonState)
    {
      delay(50); //crude de-bounce
      
      // print out the state of the button:
      Serial.println("OFF");
    }
    checkState = buttonState;
  }
  
  delay(100);        // delay in between reads for stability
}




