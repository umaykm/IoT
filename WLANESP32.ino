#include <WiFi.h>
#include <WiFiClient.h> 
#include <WebServer.h> 
 
 const char* ssid = "Hahaha-1"; 
 const char* password = "12341234"; 
 /* Put IP Address details */ 
 IPAddress local_ip(192,168,1,1); 
 IPAddress gateway(192,168,1,1);
 IPAddress subnet(255,255,255,0); 
 WebServer server(80); 
 const int led1 = LED_BUILTIN; 
 bool led1Status = LOW; 
 void handle_OnConnect(){   server.send(200, "text/html", SendHTML(led1Status)); } 
 void handle_led1On(){   led1Status = HIGH;   server.send(200, "text/html", SendHTML(led1Status));   Serial.println("LED dinyalakan!!"); } 
 void handle_led1Off(){   led1Status = LOW;   server.send(200, "text/html", SendHTML(led1Status));   Serial.println("LED dimatikan!!"); } 
 void handleNotFound() {   String message = "File Not Found\n\n";   message += "URI: ";   message += server.uri();   message += "\nMethod: ";   message += (server.method() == HTTP_GET) ? "GET" : "POST";   message += "\nArguments: ";   message += server.args();   message += "\n";   for (uint8_t i = 0; i < server.args(); i++) {     message += " " + server.argName(i) + ": " + server.arg(i) + "\n";   }   server.send(404, "text/plain", message); } 
 
 void setup() {   
  pinMode(led1, OUTPUT);   
  Serial.begin(115200);   // wifi mode Soft AP   WiFi.softAP(ssid, password);   WiFi.softAPConfig(local_ip, gateway, subnet);   Serial.println(""); 
   delay(100); 
   server.on("/", handle_OnConnect); 
   server.on("/led1on", handle_led1On);  
   server.on("/led1off", handle_led1Off); 
   server.onNotFound(handleNotFound); 
   server.begin();  
   Serial.println("HTTP server started"); } 

void loop() {
  // put your main code here, to run repeatedly:

}

String SendHTML(uint8_t led1stat){ 
  String teks = "<!DOCTYPE html> <html>\n";
/*
  teks += "<h2> Suhu Sekarang : ";
  teks += suhu;
  teks += "</h2><br>";
  */
  if(led1Status) { 
    teks += "<h2>Status LED: MENYALA</h2><br>";} 
  else{ teks += "<h2>Status LED: MATI</h2><br>";}
  
  teks += "<a href=\"/led1on\"\"><button>Nyalakan LED </button></a>"; 
  teks += "<a href=\"/led1off\"\"><button>Matikan LED </button></a>";
  
  teks += "</html>";
  
  return teks;
}
