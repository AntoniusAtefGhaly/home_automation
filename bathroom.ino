/*
 *The bathroom contains:
- 1 lamp control  through mobile app only. (Led simulator)
 */
 
//function to setup pins mode
void bathroom_setup() {
pinMode(bathroom_lamp_pin,OUTPUT);
}


//function to on bathroom lamp
void bathroom_lamp_on()
{
  digitalWrite(bathroom_lamp_pin,HIGH);
}


//function to off bathroom lamp
void bathroom_lamp_off()
{
  digitalWrite(bathroom_lamp_pin,LOW);
}


/*** test code **/
//void loop() {
//  // put your main code here, to run repeatedly:
//
//}
