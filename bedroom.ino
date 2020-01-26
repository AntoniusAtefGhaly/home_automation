/*
 * Bed room contains:
- 1 lamp which I can control its brightness level through the mobile app only. (Led simulator)
- 1 AC only on/off control through the mobile app only. (Led simulator)
 */
 int bedroom_lamp_pin = D1;
 int bedroom_AC_pin = D2;

 //function to setup pins mode
void bedroom_setup() {
pinMode(bedroom_lamp_pin,OUTPUT);
pinMode(bedroom_AC_pin,OUTPUT);
}

//function to control lamp brightness
void bedroom_lamp_brightness(int brightness)
{
  analogWrite(bedroom_lamp_pin,brightness);
}

//function to on AC
void bedroom_AC_on()
{
  digitalWrite(bedroom_AC_pin,HIGH);
}

//function to off AC
void bedroom_AC_off()
{
  digitalWrite(bedroom_AC_pin,LOW);  
}

void loop() {
  //test code
//for example
bedroom_AC_on();
dealy(2000);
bedroom_AC_off();
dealy(2000);
for(int i=0;i<1023;i+=10){
 bedroom_lamp_brightness(i);
}
}
