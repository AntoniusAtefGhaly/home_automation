#include "pins_configuration.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h> // Include the WebServer library
#define speed1 500
#define speed2 800
#define speed3 1023

WiFiServer server(80); 
int brightness = 1000;
int value = 0;
int door_state=1;
int time_open=millis();;


void setup()
{
  wifisetup();
  bathroom_setup();  
  bedroom_setup();
  door_setup();
  kitchen_setup();
  livingroom_setup();
  outdoorlamp_setup();
    server.begin(); 
//    Serial.begin(115200); 
//    test();
}


void loop(){

//  Serial.print(analogRead(ooutdoor_sensor));
//  Serial.print("\n"); 
  outdoor_lamp();
  door_sensor();
  
//  wifi_check_connect();
 WiFiClient client = server.available();   // listen for incoming clients 
  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected  
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character
 
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
           // The HTTP response ends with another blank line:
        
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

/******************** BATHROOM ************************/ 
        if (currentLine.endsWith("GET /A")) {
           bathroom_lamp_on();                          //ON bathroom lamp
        }
        if (currentLine.endsWith("GET /a")) {
          bathroom_lamp_off();                         //OFF bathroom lamp
        }

/******************** BEDROOM ************************/               
        if (currentLine.endsWith("GET /B")) {
          brightness +=100;                           //increase bedroom lamp brightness
          bedroom_lamp_brightness();
        }
        if (currentLine.endsWith("GET /b")) {
          brightness -=100;                           //decrease bedroom lamp brightness
          bedroom_lamp_brightness();
        }
        
        if (currentLine.endsWith("GET /C")) {
           bedroom_AC_on();                          //ON bedroom AC
        }
        if (currentLine.endsWith("GET /c")) {
          bedroom_AC_off();                         //OFF bedroom AC
        }
        
/******************** DOOR ************************/ 
        if (currentLine.endsWith("GET /D")) {
           door_open();                          //open door
           door_state=0;
        }
        if (currentLine.endsWith("GET /d")) {
          door_close();                         //close door
          door_state=1;
        }


/******************** KITCHEN ************************/ 
        if (currentLine.endsWith("GET /E")) {
          kitchen_hood_fn(speed1);                   //hood speed 1
        }
        if (currentLine.endsWith("GET /F")) {
          kitchen_hood_fn(speed2);                   //hood speed 2
        }
        if (currentLine.endsWith("GET /G")) {
          kitchen_hood_fn(speed3);                   //hood speed 3
        }
        if (currentLine.endsWith("GET /g")) {
          kitchen_hood_fn(0);                   //hood speed 3
        }
        
        if (currentLine.endsWith("GET /H")) {
           kitchen_lamp_on();                          //ON kitchen lamp
        }
        if (currentLine.endsWith("GET /h")) {
          kitchen_lamp_off();                         //OFF kitchen lamp
        }
 
 /******************** LIVINGROOM ************************/ 
        if (currentLine.endsWith("GET /J")) {
           livingroom_lamps_on();                          //ON livingroom lamp
        }
        if (currentLine.endsWith("GET /j")) {
          livingroom_lamps_off();                         //OFF livingroom lamp
        }
        if (currentLine.endsWith("GET /I")) {
           livingroom_AC_on();                          //ON livingroom AC
        }
        if (currentLine.endsWith("GET /i")) {
         livingroom_AC_off();                         //OFF livingroom AC
        }

 /******************** OUTDOOR LAMP ************************/ 

    
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
