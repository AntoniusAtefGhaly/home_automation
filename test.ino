void test()
{
           bathroom_lamp_on();                          //ON bathroom lamp

          bedroom_lamp_brightness();
           bedroom_AC_on();                          //ON bedroom AC
           door_open();                          //open door
          kitchen_hood_fn(1023);                   //hood speed 3
           kitchen_lamp_on();                          //ON kitchen lamp
           livingroom_lamps_on();                          //ON livingroom lamp
           livingroom_AC_on();                          //ON livingroom AC
           outdoor_lamp();
            door_open();
            delay(1000);
            door_close();
// kitchen_hood_fn(speed1); 
// delay(5000); 
// kitchen_hood_fn(speed2); 
// delay(5000); 
// kitchen_hood_fn(speed3); 
// delay(5000); 
//  kitchen_hood_fn(0); 
// delay(5000); 
//
}
