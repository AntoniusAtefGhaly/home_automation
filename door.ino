#include<Servo.h>
Servo door;
int door_servo_int = D5;
int trig = D2; //sender>>
int echo = D3 ; //reciver
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
void setup() {
  // put your setup code here, to run once:
  //door.attach(door_servo_int);
}
void door_setup(){
  pinMode(trig ,OUTPUT);
  pinMode(echo,INPUT);
  door.attach(door_servo_int);
  door.write(0);
  }
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  dur = pulseIn(echo,HIGH);
  dis = (dur/2)*(0.034); //0.034 speed of audio in microsecound
  if (dis <= 30){
    open_door();
    delayMicroseconds(3000);
  }
  else{
    close_door();
  }
  
}
