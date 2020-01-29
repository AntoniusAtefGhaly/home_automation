#include "pins_configuration.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h> // Include the WebServer library
WiFiServer server(80); 
int brightness = 50;
void setup()
{
  wifisetup();
  bathroom_setup();  
  bedroom_setup();
    Serial.begin(115200); 
    server.begin(); 
}

int value = 0;
 
void loop(){
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
        if (currentLine.endsWith("GET /P")) {
           bathroom_lamp_on();                          //ON bathroom lamp
        }
        if (currentLine.endsWith("GET /p")) {
          bathroom_lamp_off();                         //OFF bathroom lamp
        }

/******************** BEDROOM ************************/               
        if (currentLine.endsWith("GET /P")) {
          brightness +=100;                           //increase bedroom lamp brightness
          bedroom_lamp_brightness();
        }
        if (currentLine.endsWith("GET /p")) {
          brightness -=100;                           //decrease bedroom lamp brightness
          bedroom_lamp_brightness();
        }
        
        if (currentLine.endsWith("GET /P")) {
           bedroom_AC_on();                          //ON bedroom AC
        }
        if (currentLine.endsWith("GET /p")) {
          bedroom_AC_off();                         //OFF bedroom AC
        }
        
/******************** DOOR ************************/ 
        if (currentLine.endsWith("GET /P")) {
           door_open();                          //open door
        }
        if (currentLine.endsWith("GET /p")) {
          door_close();                         //close door
        }


/******************** KITCHEN ************************/ 
        if (currentLine.endsWith("GET /P")) {
          kitchen_hood_fn(300);                   //hood speed 1
        }
        if (currentLine.endsWith("GET /p")) {
          kitchen_hood_fn(700);                   //hood speed 2
        }
        if (currentLine.endsWith("GET /P")) {
          kitchen_hood_fn(1023);                   //hood speed 3
        }
        if (currentLine.endsWith("GET /P")) {
           kitchen_lamp_on();                          //ON kitchen lamp
        }
        if (currentLine.endsWith("GET /p")) {
          kitchen_lamp_off();                         //OFF kitchen lamp
        }
 
 /******************** LIVINGROOM ************************/ 
        if (currentLine.endsWith("GET /P")) {
           livingroom_lamp_on();                          //ON livingroom lamp
        }
        if (currentLine.endsWith("GET /p")) {
          livingroom_lamp_off();                         //OFF livingroom lamp
        }
        if (currentLine.endsWith("GET /P")) {
           livingroom_AC_on();                          //ON livingroom AC
        }
        if (currentLine.endsWith("GET /p")) {
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
