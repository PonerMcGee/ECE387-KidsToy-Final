#include <IRremote.hpp>
#include <IRremote.h>
int RECV_PIN = 13;
IRrecv irrecv(RECV_PIN);
decode_results results;
int enB = 3;
int in3 = 5;
int in4 = 4;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(12, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);
}

void loop() {
  
  if (irrecv.decode(&results))// Returns 0 if no data ready, 1 if data ready.
  {
    int value = results.value;
    Serial.println(" ");
    Serial.print("Code: ");
    Serial.println(value); //prints the value a a button press
    Serial.println(" ");


    switch (value) {
      case 6375: //Keypad button UP
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
    }
    switch (value) {
      case 19125: //Keypad button STOP
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
      
    }
    switch (value) {
      case 14535: //Keypad button DOWN
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
      
    }
    irrecv.resume(); // Restart the ISR state machine and Receive the next value
  }
}

//https://lastminuteengineers.com/l293d-dc-motor-arduino-tutorial/
//https://www.arduino.cc/reference/en/libraries/irremote/
