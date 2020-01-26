int kitchen_hood_pin = D2; //Kitchen Hoods Pin "PWM"
int dir_hood = D3; // direction motor
int kitchen_led = D4; //kitchen led
void kitchen_hood_fn(int spd) //Kitchen Hoods fun
{
    analogWrite(kitchen_hood_pin,spd);
    digitalWrite(dir_hood , 1); 
}
void kitchen_lamp_on()
  {
    digitalWrite(kitchen_led,HIGH);
  }
void kitchen_lamp_off()
  {
    digitalWrite(kitchen_led,LOW);
  }
void setup() {
  // put your setup code here, to run once:
 // pinMode(PKH,OUTPUT);
 // pinMode(dir,OUTPUT);
 // pinMode(Kled,OUTPUT);
}
void kitchen_setup(){
  pinMode(kitchen_hood_pin,OUTPUT);
  pinMode(dir_hood,OUTPUT);
  pinMode(kitchen_led,OUTPUT);
  }
void loop() {
  // put your main code here, to run repeatedly:
  kitchen_hood_fn(500);
  kitchen_lamp_on();
  delay(10000);
  kitchen_lamp_off();
  delay(1000);

}
