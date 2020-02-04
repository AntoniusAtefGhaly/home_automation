
void outdoorlamp_setup() {
 pinMode(ooutdoor_sensor,INPUT);
 pinMode(ooutdoor_lamp,OUTPUT);

}

void outdoor_lamp() {
  int t=analogRead(ooutdoor_sensor);
  if(t<200){
    digitalWrite(ooutdoor_lamp,HIGH);   
  }
  else
  {
    digitalWrite(ooutdoor_lamp,LOW);
  }
}
