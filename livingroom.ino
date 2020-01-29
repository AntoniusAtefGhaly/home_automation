 /*
 *the living room contains:
- 2 lamps,  the two lamps one the same switch I can control it on/off through the mobile app only. (No brightness control). (Led simulator)
- 1 AC only on/off control throug the mobile app only. (Led simulator)
 */ 
 
//function to setup pins mode
void livingroom_setup() {
pinMode(livingroom_lamps_pin,OUTPUT);
pinMode(livingroom_AC_pin,OUTPUT);
}

//function to on lamp1 and lamp2
void livingroom_lamps_on()
{
  digitalWrite(livingroom_lamps_pin,HIGH);
}

//function to off lamp1 and lamp2
void livingroom_lamps_off()
{
  digitalWrite(livingroom_lamps_pin,LOW);
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

/*** test code **/
//void loop() {
//  // put your main code here, to run repeatedly:
//
//}
