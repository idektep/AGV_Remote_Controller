
#include <WiFi.h>
#include <WebServer.h>

// ----------------------
// Access Point Settings
// ----------------------

// กำหนดชื่อ WiFi และ Password
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

  <!-- ปุ่ม Forward (ตัวอย่าง) -->
  <button onclick="sendCmd('forward')">
    Forward
  </button>

  <!-- สร้างปุ่ม Backward -->


  <!-- สร้างปุ่ม Left -->


  <!-- สร้างปุ่ม Right -->


  <!-- สร้างปุ่ม Stop -->


  <script>

    // สร้างฟังก์ชัน JavaScript สำหรับส่งคำสั่ง

    

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

  // Web Server Routes
  server.on("/", handleRoot);
  server.on("/forward", handleForward);

  // เพิ่ม Route สำหรับ Backward


  // เพิ่ม Route สำหรับ Left


  // เพิ่ม Route สำหรับ Right


  // เพิ่ม Route สำหรับ Stop


  server.begin();

  Serial.println("Web Server Started");
}

// ฟังก์ชันควบคุม AGV เดินหน้า
void handleForward() {

  // คำสั่งเดินหน้า


  // HTTP Response


}

// ฟังก์ชันควบคุม AGV ถอยหลัง
void handleBackward() {

  // คำสั่งถอยหลัง


  // HTTP Response


}

// ฟังก์ชันควบคุม AGV เลี้ยวซ้าย
void handleLeft() {

  // คำสั่งเลี้ยวซ้าย


  // HTTP Response


}

// ฟังก์ชันควบคุม AGV เลี้ยวขวา
void handleRight() {

  // คำสั่งเลี้ยวขวา


  // HTTP Response


}

// ฟังก์ชันควบคุม AGV หยุด
void handleStop() {

  // คำสั่งหยุด


  // HTTP Response


}

// Handle Client
void updateWebServer() {
  server.handleClient();
}
