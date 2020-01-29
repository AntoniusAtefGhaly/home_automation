#include<Servo.h>
Servo door;
int dur;  //duration time
int dis; //distane 
void open_door()
{
    for (int i = 0 ; i <= 90; i+=2)
  {
    door.write(i);
    delay(10);
  }
}
void close_door()
{
    for (int i = 90 ; i >= 0; i-=2)
  {
    door.write(i);
    delay(10);
  }
}
void door_setup(){
  pinMode(door_trig_pin ,OUTPUT);
  pinMode(door_echo_pin,INPUT);
  door.attach(door_servo_pin);
  door.write(0);
  }

/*** for test ***/ 
//void loop() {
//  // put your main code here, to run repeatedly:
//  digitalWrite(door_door_trig,LOW);
//  delayMicroseconds(2);
//  digitalWrite(door_door_trig,HIGH);
//  delayMicroseconds(10);
//  digitalWrite(door_door_trig,LOW);
//  dur = pulseIn(door_echo_pin,HIGH);
//  dis = (dur/2)*(0.034); //0.034 speed of audio in microsecound
//  if (dis <= 30){
//    open_door();
//    delayMicroseconds(3000);
//  }
//  else{
//    close_door();
//  }
//  
//}
