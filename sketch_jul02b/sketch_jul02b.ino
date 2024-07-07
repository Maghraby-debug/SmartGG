#include <Arduino.h>                               | 
#include <WiFi.h>                                  |                // esp32 library
#include <IOXhop_FirebaseESP32.h>                  |                                             // firebase library
#define FIREBASE_HOST "https://smart-garage-appliation-default-rtdb.firebaseio.com"                         // the project name address from firebase id
#define FIREBASE_AUTH "16AsZOC1XCyjVQftsa9mfX2C7NdddA8tGKAcMwbe"                    // the secret key generated from firebase
#define WIFI_SSID "Maghraby"                       | 
#define WIFI_PASSWORD "M12345678"                  | 
                                                   | 
///////////////////////////////////////////////////| [[[[[VERTICAL MOTOR]]]]]
                                                   | 
#define STEP_PIN1 18  // [[[[[VERTICAL MOTOR]]]]]  | 
#define DIR_PIN1 19   // [[[[[VERTICAL MOTOR]]]]]  | 
                                                   | 
///////////////////////////////////////////////////| [[[[[360 MOTOR]]]]]]]]]]
                                                   | 
#define STEP_PIN2 23  // [[[[[360 MOTOR]]]]]]]]]]  | 
#define DIR_PIN2 22   // [[[[[360 MOTOR]]]]]]]]]]  | 
                                                   | 
///////////////////////////////////////////////////| [[[[[HORIZONTAL MOTOR]]]
                                                   | 
#define STEP_PIN3 5555  // [[[[[HORIZONTAL MOTOR]  | 
#define DIR_PIN3 5555   // [[[[[HORIZONTAL MOTOR]  | 
///////////////////////////////////////////////////| 
                                                   | 
int sdata1 = 0;                                    | 
int sdata2 = 0;                                    | 
int sdata3 = 0;                                    | 
                                                   | 
int IR1 = 14;                                      | 
int IR2 = 15;                                      | 
int IR3 = 18;                                      | 
                                                   | 
///////////////////////////////////////////////////| 
String fireStatus = "";                            | 
String fireStatusCC = "";                          |                          // led status received from firebase
String fireStatusDD = "";                          | 
String fireStatusFF = "";                          | 
String fireStatusEE = "";                          | 
String fireStatusGG = "";                          | 
///////////////////////////////////////////////////| 
                                                   | 
void SENSORS() {                                   | 
sdata1 = digitalRead(IR1);                         | 
sdata2 = digitalRead(IR2);                         | 
sdata3 = digitalRead(IR3);                         | 
                                                   | 
///////////////////////////////////////////////////| 
                  //SENSOR 1                       | 
///////////////////////////////////////////////////| 
if(sdata1 == 1) {                                  | 
Firebase.setString("/Sensor1A","Available");       | 
  delay(10);                                       | 
                                                   | 
Firebase.setString("/Sensor1B","");                | 
  delay(10);                                       | 
}                                                  | 
                                                   | 
else if(sdata1 == 0){                              | 
Firebase.setString("/Sensor1B","Unavailable");     | 
  delay(10);                                       | 
                                                   | 
Firebase.setString("/Sensor1A","");                | 
  delay(10);                                       | 
}                                                  | 
///////////////////////////////////////////////////| 
                  //SENSOR 2                       | 
///////////////////////////////////////////////////| 
                                                   | 
if(sdata2 == 1) {                                  | 
Firebase.setString("/Sensor2A","Available");       | 
  delay(10);                                       | 
                                                   | 
Firebase.setString("/Sensor2B","");                | 
  delay(10);                                       | 
}                                                  | 
                                                   | 
else if(sdata2 == 0){                              | 
Firebase.setString("/Sensor2B","Unavailable");     | 
  delay(10);                                       | 
                                                   | 
Firebase.setString("/Sensor2A","");                | 
  delay(10);                                       |  
}                                                  | 
///////////////////////////////////////////////////| 
                  //SENSOR 3                       | 
///////////////////////////////////////////////////| 
                                                   | 
if(sdata3 == 1) {                                  | 
Firebase.setString("/Sensor3A","Available");       | 
  delay(10);                                       | 
                                                   | 
Firebase.setString("/Sensor3B","");                | 
  delay(10);                                       | 
}                                                  | 
                                                   | 
else if(sdata1 == 0){                              | 
Firebase.setString("/Sensor3B","Unavailable");     | 
  delay(10);                                       | 
                                                   | 
Firebase.setString("/Sensor3A","");                | 
  delay(10);                                       |  
}                                                  | 
///////////////////////////////////////////////////| 
}                                                  | 
                                                   | 
///////////////////////////////////////////////////| 
void setup() {                                     | 
                                                   | 
    pinMode(STEP_PIN1, OUTPUT);                    | 
    pinMode(DIR_PIN1, OUTPUT);                     | 
                                                   | 
    pinMode(STEP_PIN2, OUTPUT);                    | 
    pinMode(DIR_PIN2, OUTPUT);                     | 
                                                   | 
    pinMode(STEP_PIN3, OUTPUT);                    | 
    pinMode(DIR_PIN3, OUTPUT);                     | 
                                                   | 
  Serial.begin(115200);                            | 
                                                   | 
  delay(1000);                                     | 
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);              |                                       //try to connect with wifi
                                                   | 
  Serial.print("Connecting to ");                  | 
                                                   | 
  Serial.print(WIFI_SSID);                         | 
                                                   | 
  while (WiFi.status() != WL_CONNECTED) {          | 
                                                   | 
    Serial.print(".");                             | 
                                                   | 
    delay(500);                                    | 
                                                   | 
  }                                                | 
                                                   | 
  Serial.println();                                | 
                                                   | 
  Serial.print("Connected to ");                   | 
                                                   | 
  Serial.println(WIFI_SSID);                       | 
                                                   | 
  Serial.print("IP Address is : ");                | 
                                                   | 
  Serial.println(WiFi.localIP());                  |                                          //print local IP address
                                                   | 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);    |                                       // connect to firebase
                                                   | 
}                                                  | 
                                                   | 
///////////////////////////////////////////////////| 
                                                   | 
void loop() {                                      | 
                                                   | 
///////////////////////////////////////////////////| 
                  //SENSORS                        | 
///////////////////////////////////////////////////| 
SENSORS();                                         | 
///////////////////////////////////////////////////| 
                  //SLOT-1                         | 
///////////////////////////////////////////////////|
                                                   | 
  fireStatus = Firebase.getString("B1");           |   
                                                   | 
                                                   | 
                                                   | 
  if (fireStatus == "1") {                         | 
                                                   | 
     Serial.print("PROCESS WORKING");              | 
          delay(3000);                             | 
///////////////////////////////////////////////////| 
     digitalWrite(DIR_PIN3, HIGH);                 | 
  for(int i = 0; i < 240; i++) {                   | 
    digitalWrite(STEP_PIN3, HIGH);                 | 
    delayMicroseconds(16000);                      | 
    digitalWrite(STEP_PIN3, LOW);                  | 
    delayMicroseconds(16000);                      | 
}                                                  | 
          delay(6000);                             | 
///////////////////////////////////////////////////| 
     digitalWrite(DIR_PIN3, LOW);                  | 
  for(int i = 0; i < 300; i++) {                   | 
    digitalWrite(STEP_PIN3, HIGH);                 | 
    delayMicroseconds(16000);                      | 
    digitalWrite(STEP_PIN3, LOW);                  | 
    delayMicroseconds(16000);                      | 
}                                                  | 
          delay(6000);                             |           
///////////////////////////////////////////////////| 
     digitalWrite(DIR_PIN2, HIGH);                 | 
  for(int i = 0; i < 80; i++) {                    | 
    digitalWrite(STEP_PIN2, HIGH);                 | 
    delayMicroseconds(16000);                      | 
    digitalWrite(STEP_PIN2, LOW);                  | 
    delayMicroseconds(16000);                      |      
}                                                  | 
          delay(6000);                             | 
   digitalWrite(DIR_PIN1, LOW);                    | 
  for(int i = 0; i < 4000; i++) {                  | 
    digitalWrite(STEP_PIN1, HIGH);                 | 
    delayMicroseconds(1300);                       | 
    digitalWrite(STEP_PIN1, LOW);                  | 
    delayMicroseconds(1300);                       | 
}                                                  | 
          delay(6000);                             | 
///////////////////////////////////////////////////| 
     digitalWrite(DIR_PIN3, HIGH);                 | 
  for(int i = 0; i < 300; i++) {                   | 
    digitalWrite(STEP_PIN3, HIGH);                 | 
    delayMicroseconds(16000);                      | 
    digitalWrite(STEP_PIN3, LOW);                  | 
    delayMicroseconds(16000);                      | 
}                                                  | 
          delay(6000);                             | 
///////////////////////////////////////////////////| 
   digitalWrite(DIR_PIN1, LOW);                    | 
  for(int i = 0; i < 600; i++) {                   | 
    digitalWrite(STEP_PIN1, HIGH);                 | 
    delayMicroseconds(1300);                       | 
    digitalWrite(STEP_PIN1, LOW);                  | 
    delayMicroseconds(1300);                       | 
}                                                  | 
          delay(6000);                             | 
///////////////////////////////////////////////////| 
     digitalWrite(DIR_PIN3, LOW);                  | 
  for(int i = 0; i < 240; i++) {                   | 
    digitalWrite(STEP_PIN3, HIGH);                 | 
    delayMicroseconds(16000);                      | 
    digitalWrite(STEP_PIN3, LOW);                  | 
    delayMicroseconds(16000);                      |      
}                                                  | 
          delay(6000);                             | 
///////////////////////////////////////////////////| 
   digitalWrite(DIR_PIN1, HIGH);                   | 
  for(int i = 0; i < 4600; i++) {                  | 
    digitalWrite(STEP_PIN1, HIGH);                 | 
    delayMicroseconds(1300);                       |  
    digitalWrite(STEP_PIN1, LOW);                  | 
    delayMicroseconds(1300);                       | 
}                                                  | 
      delay(6000);                                 | 
///////////////////////////////////////////////////|
   digitalWrite(DIR_PIN2, LOW);                    | 
  for(int i = 0; i < 80; i++) {                    | 
    digitalWrite(STEP_PIN2, HIGH);                 | 
    delayMicroseconds(16000);                      | 
    digitalWrite(STEP_PIN2, LOW);                  | 
    delayMicroseconds(16000);                      | 
    Firebase.setString("/B1","0");                 | 
}   delay(6000);                                   |
 }                                                 |
  }                                                |
///////////////////////////////////////////////////| 
                  //SLOT-2                         | 
///////////////////////////////////////////////////|
                                                   | 
  fireStatusCC = Firebase.getString("B2");         |   
                                                   | 
                                                   | 
                                                   | 
  if (fireStatus == "1") {                         | 
                                                   | 
     Serial.print("PROCESS WORKING");              | 
          delay(3000);                             | 
///////////////////////////////////////////////////| 
     digitalWrite(DIR_PIN3, HIGH);                 | 
  for(int i = 0; i < 240; i++) {                   | 
    digitalWrite(STEP_PIN3, HIGH);                 | 
    delayMicroseconds(16000);                      | 
    digitalWrite(STEP_PIN3, LOW);                  | 
    delayMicroseconds(16000);                      | 
}                                                  | 
          delay(6000);                             | 
///////////////////////////////////////////////////| 
     digitalWrite(DIR_PIN3, LOW);                  | 
  for(int i = 0; i < 300; i++) {                   | 
    digitalWrite(STEP_PIN3, HIGH);                 | 
    delayMicroseconds(16000);                      | 
    digitalWrite(STEP_PIN3, LOW);                  | 
    delayMicroseconds(16000);                      | 
}                                                  | 
          delay(6000);                             |           
///////////////////////////////////////////////////|                             
   digitalWrite(DIR_PIN1, LOW);                    | 
  for(int i = 0; i < 4000; i++) {                  | 
    digitalWrite(STEP_PIN1, HIGH);                 | 
    delayMicroseconds(1300);                       | 
    digitalWrite(STEP_PIN1, LOW);                  | 
    delayMicroseconds(1300);                       | 
}                                                  | 
          delay(6000);                             | 
///////////////////////////////////////////////////| 
     digitalWrite(DIR_PIN3, HIGH);                 | 
  for(int i = 0; i < 300; i++) {                   | 
    digitalWrite(STEP_PIN3, HIGH);                 | 
    delayMicroseconds(16000);                      | 
    digitalWrite(STEP_PIN3, LOW);                  | 
    delayMicroseconds(16000);                      | 
}                                                  | 
          delay(6000);                             | 
///////////////////////////////////////////////////| 
   digitalWrite(DIR_PIN1, LOW);                    | 
  for(int i = 0; i < 600; i++) {                   | 
    digitalWrite(STEP_PIN1, HIGH);                 | 
    delayMicroseconds(1300);                       | 
    digitalWrite(STEP_PIN1, LOW);                  | 
    delayMicroseconds(1300);                       | 
}                                                  | 
          delay(6000);                             | 
///////////////////////////////////////////////////| 
     digitalWrite(DIR_PIN3, LOW);                  | 
  for(int i = 0; i < 240; i++) {                   | 
    digitalWrite(STEP_PIN3, HIGH);                 | 
    delayMicroseconds(16000);                      | 
    digitalWrite(STEP_PIN3, LOW);                  | 
    delayMicroseconds(16000);                      |      
}                                                  | 
          delay(6000);                             | 
///////////////////////////////////////////////////| 
   digitalWrite(DIR_PIN1, HIGH);                   | 
  for(int i = 0; i < 4600; i++) {                  | 
    digitalWrite(STEP_PIN1, HIGH);                 | 
    delayMicroseconds(1300);                       |  
    digitalWrite(STEP_PIN1, LOW);                  | 
    delayMicroseconds(1300);                       | 
}                                                  | 
      delay(6000);                                 | 
    Firebase.setString("/B2","0");                 | 
}   delay(6000);                                   |
 }                                                 |
  }                                                |
///////////////////////////////////////////////////| 
