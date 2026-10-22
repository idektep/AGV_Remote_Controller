#include <WiFi.h>
#include <WebServer.h>

// ----------------------
// Access Point Settings
// ----------------------
const char* ssid = "______________";
const char* password = "______________";

// Create Web Server
WebServer server(80);

// HTML Page
String webpage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>AGV Online</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body{
      font-family: Arial;
      text-align:center;
      margin-top:50px;
    }
    h1{
      color:#333;
    }
  </style>
</head>
<body>
  <h1>AGV Online</h1>
  <p>ESP32 Web Server Connected Successfully</p>

  <button onclick="sendCmd('forward')">
  Forward
  </button>
  //backward
  //left
  //right
  //stop


 
<script>



</script>

</body>
</html>
)rawliteral";

// Home Page
void handleRoot() {
  server.send(200, "text/html", webpage);
}

// Start WiFi AP + WebServer
void initWebServer() {

  Serial.println();
  Serial.println("Starting Access Point...");

  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();

  Serial.print("AP IP Address: ");
  Serial.println(IP);

  server.on("/", handleRoot);
  server.on("/forward", handleForward);



  

  
  server.begin();

  Serial.println("Web Server Started");
}

void handleForward() {
  
}

void handleBackward() {

}

void handleLeft() {

}

void handleRight() {

}

void handleStop() {

}

// Handle Client
void updateWebServer() {
  server.handleClient();
}
