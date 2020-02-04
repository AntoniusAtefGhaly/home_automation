#include<Servo.h>
Servo door;
float dur;  //duration time
float dis; //distane 

void door_open()
{
    door.write(0);
}

void door_close()
{
    door.write(90);
}

void door_setup(){
  pinMode(door_trig_pin ,OUTPUT);
  pinMode(door_echo_pin,INPUT);
  pinMode(door_servo_pin,OUTPUT);
  
  door.attach(door_servo_pin);
  door.write(0);
  }


/*** for test ***/ 
void door_sensor() {
  // put your main code here, to run repeatedly:
  digitalWrite(door_trig_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(door_trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(door_trig_pin,LOW);
  dur = pulseIn(door_echo_pin,HIGH);
  dis = (dur/2)*(0.034); //0.034 speed of audio in microsecound
    
  if (dis <= 30){
    door_open();
    time_open=millis();
    
  }
  if ((millis()-time_open)>3000&&door_state==1){
    door_close();
    time_open=millis();
  }
    
}
