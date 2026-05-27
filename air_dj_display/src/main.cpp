#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <WebServer.h>

#define LCD_ADDR 0x3E
#define RGB_ADDR 0x2D

const char* ssid = "AirDJHotspot";
const char* password = "airdj12345";

WebServer server(80);

void lcdCommand(uint8_t cmd) {
  Wire.beginTransmission(LCD_ADDR);
  Wire.write(0x80);
  Wire.write(cmd);
  Wire.endTransmission();
  delay(2);
}

void lcdData(uint8_t data) {
  Wire.beginTransmission(LCD_ADDR);
  Wire.write(0x40);
  Wire.write(data);
  Wire.endTransmission();
}

void lcdPrint(String text) {
  for (int i = 0; i < text.length(); i++) lcdData(text[i]);
}

void lcdSetCursor(uint8_t col, uint8_t row) {
  uint8_t row_offsets[] = {0x00, 0x40};
  lcdCommand(0x80 | (col + row_offsets[row]));
}

void lcdClear() {
  lcdCommand(0x01);
  delay(2);
}

void rgbWrite(uint8_t reg, uint8_t data) {
  Wire.beginTransmission(RGB_ADDR);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission();
}

void setRGB(uint8_t r, uint8_t g, uint8_t b) {
  rgbWrite(0x00, 0x00);
  rgbWrite(0x01, 0x00);
  rgbWrite(0x08, 0xAA);

  rgbWrite(0x02, b);  // green
  rgbWrite(0x01, r);  // red
  rgbWrite(0x03, g);  // blue
}

void lcdInit() {
  delay(50);
  lcdCommand(0x38);
  delay(5);
  lcdCommand(0x39);
  delay(5);
  lcdCommand(0x14);
  lcdCommand(0x70);
  lcdCommand(0x56);
  lcdCommand(0x6C);
  delay(200);
  lcdCommand(0x38);
  lcdCommand(0x0C);
  lcdClear();
  lcdCommand(0x06);
}

void showTwoLines(String line1, String line2) {
  lcdClear();
  lcdSetCursor(0, 0);
  lcdPrint(line1.substring(0, 16));
  lcdSetCursor(0, 1);
  lcdPrint(line2.substring(0, 16));
}

void handleUpdate() {
  String line1 = server.hasArg("line1") ? server.arg("line1") : "";
  String line2 = server.hasArg("line2") ? server.arg("line2") : "";

  int r = server.hasArg("r") ? server.arg("r").toInt() : 255;
  int g = server.hasArg("g") ? server.arg("g").toInt() : 255;
  int b = server.hasArg("b") ? server.arg("b").toInt() : 255;

  showTwoLines(line1, line2);
  setRGB(r, g, b);

  server.send(200, "text/plain", "OK");
}

void setup() {
  Wire.begin(8, 10);

  lcdInit();
  setRGB(255, 255, 255);
  showTwoLines("WiFi", "Connecting...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  String ip = WiFi.localIP().toString();

  setRGB(0, 255, 0);
  showTwoLines("ESP32 IP:", ip);

  server.on("/update", handleUpdate);
  server.begin();
}

void loop() {
  server.handleClient();
}