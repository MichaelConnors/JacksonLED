#include <IRremote.h>
#include <Servo.h>

#define VRY_PIN A1
int yValue = 0;


const int PIN_SEND = 2;

int potPin = A2; // Potentiometer output connected to analog pin 3
int potVal = 0; // Variable to store the input from the potentiometer
int percent = 0;
bool motorOn = false;
Servo myservo;
int rudderRot;
int lastPercent = -1;
int buttonTimer = 0;
int counter = 0;
bool sendSignal = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(4800);

  pinMode(12,OUTPUT);
  pinMode(10,INPUT);
  IrSender.begin(PIN_SEND); // Initializes IR sender
  digitalWrite(12,HIGH);
  buttonTimer = 2;
}

void loop() {
  // put your main code here, to run repeatedly:

  yValue = analogRead(VRY_PIN);

  rudderRot = map(yValue,0,1023,0,180);
  

  potVal = analogRead(potPin);
  percent = map(potVal,1,1023,0,100);
  Serial.println(motorOn);
  if(digitalRead(10) == HIGH && buttonTimer <= 0){
    if (counter > 10)
      sendSignal = true;
    counter++;
  }
  else{
    counter = 0;
    sendSignal = false;
  }
  if(sendSignal && buttonTimer < 1){
    motorOn = motorOn == false ? true : false;
    buttonTimer = 20;
  }
  if (motorOn == true && lastPercent != percent){
    Serial.println("WOrking");
    delay(100);
    IrSender.sendNEC(0x101, percent, 0); // the address 0x0102 with the command 0x34 is sent
    lastPercent = percent;

  }
  if(buttonTimer > 0)
    buttonTimer -= 1;
  delay(100);
  IrSender.sendNEC(0x102,rudderRot,0);
  
  
}
