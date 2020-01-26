 /*
 *the living room contains:
- 2 lamps,  the two lamps one the same switch I can control it on/off through the mobile app only. (No brightness control). (Led simulator)
- 1 AC only on/off control throug the mobile app only. (Led simulator)
 */
 
 int livingroom_lamp1_pin = D1;
 int livingroom_lamp2_pin = D2;
 int livingroom_AC_pin = D3;
 
//function to setup pins mode
void livingroom_setup() {
pinMode(livingroom_lamp1_pin,OUTPUT);
pinMode(livingroom_lamp2_pin,OUTPUT);
pinMode(livingroom_AC_pin,OUTPUT);
}

//function to on lamp1 and lamp2
void livingroom_lamps_on()
{
  digitalWrite(livingroom_lamp1_pin,HIGH);
  digitalWrite(livingroom_lamp2_pin,HIGH);
}

//function to off lamp1 and lamp2
void livingroom_lamps_off()
{
  digitalWrite(livingroom_lamp1_pin,LOW);
  digitalWrite(livingroom_lamp2_pin,LOW);
}

//function to on AC livingroom
void livingroom_AC_on()
{
  digitalWrite(livingroom_AC_pin,HIGH);
}

//function to off AC livingroom
void livingroom_AC_off()
{
  digitalWrite(livingroom_AC_pin,LOW);  
}

void loop() {
  // put your main code here, to run repeatedly:

}
