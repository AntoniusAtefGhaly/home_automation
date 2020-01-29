#include <ESP8266WiFi.h> // Include the Wi-Fi library
#include <ESP8266WiFiMulti.h> // Include the Wi-Fi-Multi library
ESP8266WiFiMulti wifiMulti; // Create an instance of the ESP8266WiFiMulti class, called 'wifiMulti'
char * wifi_ssid1=" ";
char * wifi_ssid2=" ";
char * wifi_ssid3=" ";
char * wifi_password1=" ";
char * wifi_password2=" ";
char * wifi_password3=" ";


void wifisetup() {
  IPAddress ip(192,168,137,150);
  IPAddress getway(192,168,137,254);
  IPAddress subnet(192,168,137,0);
  WiFi.config(ip,getway,subnet);
  wifiMulti.addAP(wifi_ssid1,wifi_password1); // add Wi-Fi networks you want to connect to
  wifiMulti.addAP(wifi_ssid2,wifi_password2);
  wifiMulti.addAP(wifi_ssid3,wifi_password3);
}

void wifi_check_connect() {
  while (wifiMulti.run() != WL_CONNECTED) { // Wait for the Wi-Fi to connect: scan for Wi-Fi networks,and connect to the strongest of the networks above
  delay(1000);
  Serial.print('.');
}
Serial.println('\n');
Serial.print("Connected to ");
Serial.println(WiFi.SSID()); // Tell us what network we're connected to
Serial.print("IP address:\t");
Serial.println(WiFi.localIP()); // Send the IP address of the ESP8266 to the computer
}
