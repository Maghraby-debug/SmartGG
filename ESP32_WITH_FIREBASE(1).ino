#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"
#define WIFI_SSID "Maghraby"
#define WIFI_PASSWORD "M87654321"
#define API_KEY "Fbiu12sP7EMrStFBEoi6vWR66n1vX05lARMtyifW"
#define DATABASE_URL "https://smart-garage-test-29106-default-rtdb.firebaseio.com/"


#include <Stepper.h>
const int steps_per_rev = 200;
#define IN0 0
#define IN1 2
#define IN2 4
#define IN3 5

#define IN4 6
#define IN5 7
#define IN6 8
#define IN7 9

#define IN8 10
#define IN9 11
#define IN10 12
#define IN11 13
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
unsigned long sendDataPrevMillis = 0;
bool signupOK = false;
enum MotorState {
  STOPPED,
  CLOCKWISE1,
  CLOCKWISE2,
  CLOCKWISE3,
  CLOCKWISE4,
  ANTICLOCKWISE,
  ANTICLOCKWISE1,
  ANTICLOCKWISE2,
  ANTICLOCKWISE3,
  ANTICLOCKWISE4
};

MotorState motor1State = STOPPED;
MotorState motor2State = STOPPED;
MotorState motor3State = STOPPED;

Stepper motor1(steps_per_rev, IN0, IN1, IN2, IN3);
Stepper motor2(steps_per_rev, IN4, IN5, IN6, IN7);
Stepper motor3(steps_per_rev, IN8, IN9, IN10, IN11);
////////////////////////////////////////////////////////////////////////////////// [El t3refat]

int sdata1 = 0;
int sdata2 = 0;
int sdata3 = 0;
int load1, load2, load3;
int IR1 = 14;
int IR2 = 15;
int IR3 = 18;
//////////////////////////////////////////////////////////////////////////////////
void STARTUP(){
switch (motor1State) {
    case STOPPED:
          motor1State = CLOCKWISE1;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(steps_per_rev);
             } while (i < 3);
delay(3000);
}
switch(motor1State){
    case CLOCKWISE1:
        motor1State = ANTICLOCKWISE1;
        int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(-steps_per_rev);
             } while (i < 3);
delay(2000);
}
}
////////////////////////////////////////////////////////////////////////////////////
void SLOT1() {
  switch(motor2State){
    case STOPPED:
          motor2State = CLOCKWISE1;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(steps_per_rev);
             } while (i < 5);
  }
delay(3000);
   switch(motor3State){
    case STOPPED:
          motor3State = CLOCKWISE1;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(steps_per_rev);
             } while (i < 3);
   }
delay(3000);
    switch(motor1State){
    case ANTICLOCKWISE1:
          motor1State = CLOCKWISE2;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(steps_per_rev);
             } while (i < 3);
    }
delay(3000);
    switch(motor1State){
    case CLOCKWISE2:
          motor1State = ANTICLOCKWISE2;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(-steps_per_rev);
             } while (i < 3);
    }
delay(3000);
    switch(motor3State){
    case CLOCKWISE1:
          motor3State = ANTICLOCKWISE1;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(-steps_per_rev);
             } while (i < 3);
    }
  switch(motor2State){
    case CLOCKWISE2:
          motor2State = ANTICLOCKWISE1;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(steps_per_rev);
             } while (i < 5);
          motor1State = STOPPED;
          motor2State = STOPPED;
          motor3State = STOPPED;
  }
if(Firebase.RTDB.setString(&fbdo, "/B1", "0")){
  delay(10);
}
delay(2000);
}
////////////////////////////////////////////////////////////////////////////////////
void SLOT2() {
  switch(motor2State){
    case STOPPED:
          motor2State = CLOCKWISE1;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(steps_per_rev);
             } while (i < 9);
  }
delay(3000);
   switch(motor3State){
    case STOPPED:
          motor3State = CLOCKWISE1;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(steps_per_rev);
             } while (i < 7);
   }
delay(3000);
    switch(motor1State){
    case ANTICLOCKWISE1:
          motor1State = CLOCKWISE2;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(steps_per_rev);
             } while (i < 3);
    }
delay(3000);
    switch(motor1State){
    case CLOCKWISE2:
          motor1State = ANTICLOCKWISE2;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(-steps_per_rev);
             } while (i < 3);
    }
delay(3000);
    switch(motor3State){
    case CLOCKWISE1:
          motor3State = ANTICLOCKWISE1;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(-steps_per_rev);
             } while (i < 7);
    }
  switch(motor2State){
    case CLOCKWISE2:
          motor2State = ANTICLOCKWISE1;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(steps_per_rev);
             } while (i < 9);
          motor1State = STOPPED;
          motor2State = STOPPED;
          motor3State = STOPPED;
  }
if(Firebase.RTDB.setString(&fbdo, "/B2", "0")){
  delay(10);
}
delay(2000);
}
////////////////////////////////////////////////////////////////////////////////////
void SLOT3() {
  switch(motor2State){
    case STOPPED:
          motor2State = CLOCKWISE1;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(steps_per_rev);
             } while (i < 13);
  }
delay(3000);
   switch(motor3State){
    case STOPPED:
          motor3State = CLOCKWISE1;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(steps_per_rev);
             } while (i < 11);
   }
delay(3000);
    switch(motor1State){
    case ANTICLOCKWISE1:
          motor1State = CLOCKWISE2;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(steps_per_rev);
             } while (i < 3);
    }
delay(3000);
    switch(motor1State){
    case CLOCKWISE2:
          motor1State = ANTICLOCKWISE2;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(-steps_per_rev);
             } while (i < 3);
    }
delay(3000);
    switch(motor3State){
    case CLOCKWISE1:
          motor3State = ANTICLOCKWISE1;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(-steps_per_rev);
             } while (i < 11);
    }
  switch(motor2State){
    case CLOCKWISE2:
          motor2State = ANTICLOCKWISE1;
          int i = 0;
          do {
            delay(50);
             i++;
             motor1.step(steps_per_rev);
             } while (i < 13);
          motor1State = STOPPED;
          motor2State = STOPPED;
          motor3State = STOPPED;
  }
if(Firebase.RTDB.setString(&fbdo, "/B3", "0")){
  delay(10);
}
delay(2000);
}
////////////////////////////////////////////////////////////////////////////////////
void SENSORS() {
sdata1 = digitalRead(IR1);
sdata2 = digitalRead(IR2);
sdata3 = digitalRead(IR3);
if(sdata1 == 1) {
if(Firebase.RTDB.setString(&fbdo, "/Sensor1A", "Available")){
  delay(10);
}
if(Firebase.RTDB.setString(&fbdo, "/Sensor1B", "")){
  delay(10);
}
}
else if(sdata1 == 0){
if(Firebase.RTDB.setString(&fbdo, "/Sensor1B", "Unavailable")){
  delay(10);
}
if(Firebase.RTDB.setString(&fbdo, "/Sensor1A", "")){
  delay(10);
}
}

if(sdata2 == 1) {
if(Firebase.RTDB.setString(&fbdo, "/Sensor2A", "Available")){
  delay(10);
}
if(Firebase.RTDB.setString(&fbdo, "/Sensor2B", "")){
  delay(10);
}
}
else if(sdata2 == 0){
if(Firebase.RTDB.setString(&fbdo, "/Sensor2B", "Unavailable")){
  delay(10);
}
if(Firebase.RTDB.setString(&fbdo, "/Sensor2A", "")){
  delay(10);
}
}

if(sdata3 == 1) {
if(Firebase.RTDB.setString(&fbdo, "/Sensor3A", "Available")){
  delay(10);
}
if(Firebase.RTDB.setString(&fbdo, "/Sensor3B", "")){
  delay(10);
}
}
else if(sdata3 == 0){
if(Firebase.RTDB.setString(&fbdo, "/Sensor3B", "Unavailable")){
  delay(10);
}
if(Firebase.RTDB.setString(&fbdo, "/Sensor3A", "")){
  delay(10);
}
}
}
////////////////////////////////////////////////////////////////////////////////// [Void Setup]
void setup() {
Serial.begin(115200);
pinMode(IR1, INPUT);
pinMode(IR2, INPUT);  
pinMode(IR3, INPUT);
////////////////////////////////////////////////////////////////////////////////// [Wifi]
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("ok");
    signupOK = true;
  } else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }
    config.token_status_callback = tokenStatusCallback;  //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void loop() {
//////////////////////////////////////////////////////////////////////////////////
SENSORS();
//////////////////////////////////////////////////////////////////////////////////
if(Firebase.RTDB.get(&fbdo,"/B1")) {
if(fbdo.dataType() == "string") {
load1 = fbdo.stringData().toInt();
}
}

if(Firebase.RTDB.get(&fbdo,"/B2")) {
if(fbdo.dataType() == "string") {
load2 = fbdo.stringData().toInt();
}
}

if(Firebase.RTDB.get(&fbdo,"/B3")) {
if(fbdo.dataType() == "string") {
load3 = fbdo.stringData().toInt();
}
}

if(load1 == 1){
STARTUP();
SLOT1();
}
if(load2 == 1){
STARTUP();
SLOT2(); 
}
if(load3 == 1){
STARTUP();
SLOT3();
}
}
