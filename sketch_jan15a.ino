#define Water_Sensor A0 // Attach Water sensor to Arduino Digital Pin 8

#define merp 2
bool moter_on=false;
void setup() {
  pinMode(merp,"OUTPUT");
  Serial.begin(9600);
  digitalWrite(merp,"LOW");
}
void loop() {


   /* The water sensor will switch LOW when water is detected.
   Get the Arduino to illuminate the LED and activate the buzzer
   when water is detected, and switch both off when no water is present 
   Serial.println(analogRead(Water_Sensor));
   if(analogRead(Water_Sensor)>=270 && moter_on==false){
    moter_on=true;
     digitalWrite(merp,"HIGH");
   }else if(analogRead(Water_Sensor)<270 && moter_on==true){
     moter_on=false;
     digitalWrite(merp,"LOW");
     }
     */
     
   delay(10000);
}
