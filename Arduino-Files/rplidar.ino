    // defines pins numbers
    const int stepPin = 3; 
    const int dirPin = 4; 
    const int stall = 10; 

    int upPin = 9;
    int downPin = 8;
     
    void setup() {
  
      // initialize serial communication at 9600 bits per second:
      //Serial.begin(9600);
      // make the pushbuttons pins inputs:
      pinMode(upPin, INPUT);
      pinMode(downPin, INPUT);
      // Sets the two pins as Outputs
      pinMode(stepPin,OUTPUT); 
      pinMode(dirPin,OUTPUT);
      
    }
    void loop() {
      // read the state of the pushbutton value:
      int up = digitalRead(upPin);
      int down = digitalRead(downPin);

      
      if (up == 1)
      {
        digitalWrite(stall,LOW); //enable the controller
        digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
        // Makes 600 pulses
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(600); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(600); 
      }
      else if (down == 1)
      {
        digitalWrite(stall,LOW); //enable the controller
        digitalWrite(dirPin,LOW); //Changes the rotations direction
        // Makes 600 pulses
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(600);
        digitalWrite(stepPin,LOW);
        delayMicroseconds(600);
      }
      else{
        digitalWrite(stall,HIGH); //disable the controller
      }

// print out the state of the button:
//  Serial.print(up);
//  Serial.println(down);
    }

