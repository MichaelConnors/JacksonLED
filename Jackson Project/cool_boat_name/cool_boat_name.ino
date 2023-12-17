/*     Arduino Rotary Encoder Tutorial
*      
*  by Dejan Nedelkovski, www.HowToMechatronics.com
*  
*/
#include <IRremote.h>
#include <Servo.h>

#define VRY_PIN  A1

#define PIN_RECV 13
#define PWM 6                                       



const int MAX_SPEED = 0;
const int MIN_SPEED = -14;

Servo myservo;


void setup() {
  IrReceiver.begin(PIN_RECV); // Initializes the IR receiv
  pinMode(PWM,OUTPUT);
  analogWrite(PWM,135);
 Serial.begin (9600);
 myservo.attach(5);
} 

void loop() {
  
    
  if (IrReceiver.decode()) {
    if(IrReceiver.decodedIRData.address == 257){
    Serial.println(IrReceiver.decodedIRData.command);
    delay(50);
    }
    if(IrReceiver.decodedIRData.command  <  181  && IrReceiver.decodedIRData.address == 258){
    myservo.write(IrReceiver.decodedIRData.command);
    delay(50);
    }
    IrReceiver.resume(); // Important, enables to receive the next IR signal
    
    
  }
    
    delay(50);
}