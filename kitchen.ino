void kitchen_hood_fn(int kitchen_hood_speed) //Kitchen Hoods fun
{
    analogWrite(kitchen_hood_pin,kitchen_hood_speed); 
}
void kitchen_lamp_on()
  {
    digitalWrite(kitchen_lamp_pin,HIGH);
  }
void kitchen_lamp_off()
  {
    digitalWrite(kitchen_lamp_pin,LOW);
  }
void kitchen_setup(){
  pinMode(kitchen_hood_pin,OUTPUT);
  pinMode(kitchen_lamp_pin,OUTPUT);
  }

  /** for test **/
//void loop() {
//  // put your main code here, to run repeatedly:
//  kitchen_hood_fn(500);
//  kitchen_lamp_on();
//  delay(10000);
//  kitchen_lamp_off();
//  delay(1000);
//
//}
