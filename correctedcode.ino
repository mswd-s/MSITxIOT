
#include <FirebaseESP8266.h>
#include  <ESP8266WiFi.h>

#define ssid "Placementcell"  //WiFi SSID
#define password "870****615"  //WiFi Password
#define FIREBASE_HOST "msitxxxxxxxxxxxxxxxxxxx.firebaseio.com"  
#define FIREBASE_AUTH "jZhoxxxxxxxxxxxxxxxxxxxxxxxxxxxxTR6CvFAv"
#define wifiLed D4
FirebaseData firebaseData;

int first_1 = 16;
int first_2 = 14;
int first_3 = 12;
int first_4 = 13;

//int load=1;
void setup() {
  Serial.begin(9600);
/* Serial.begin(9600);
   WiFi.begin (ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);*/
   pinMode(first_1,OUTPUT);//initialize the Device OUTPUT  
    pinMode(first_2,OUTPUT);//initialize the Device OUTPUT  
    pinMode(first_3,OUTPUT);//initialize the Device OUTPUT  
    pinMode(first_4,OUTPUT);//initialize the Device OUTPUT
    pinMode(wifiLed,OUTPUT); 
    WiFi.begin (ssid, password);
Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
delay(100);
}
void loop() {
Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  if (WiFi.status() != WL_CONNECTED){ 
   Serial.println("WiFi Not Connected");
    digitalWrite(wifiLed, HIGH); //Turn off WiFi LED
  }
  else{ 
    Serial.println("WiFi Connected");
    digitalWrite(wifiLed, LOW); //Turn on WiFi LED
}




Firebase.get(firebaseData, "/D1");
String D = firebaseData.stringData();

  if (D=="1"){
  digitalWrite(first_1,HIGH);
}else if (D=="0"){
  digitalWrite(first_1,LOW);
}
  
Firebase.get(firebaseData, "/D2");
String De = firebaseData.stringData();

  
  if (De=="1"){
  digitalWrite(first_2,HIGH);
}else if (De=="0"){
  digitalWrite(first_2,LOW);
}

  
  
Firebase.get(firebaseData, "/D3");
String Der = firebaseData.stringData();

  
  if (Der=="1"){
  digitalWrite(first_3,HIGH);
}else if (Der=="0"){
  digitalWrite(first_3,LOW);
}

  
Firebase.get(firebaseData, "/D4");
String Det = firebaseData.stringData();

if (Det=="1"){
  digitalWrite(first_4,HIGH);
}else if (Det=="0"){
  digitalWrite(first_4,LOW);
}
//delay(100);
//String D = firebaseData.stringData();
//Serial.println(D);

/*
 if (Firebase.getString(firebaseData,"/D5")) {
    
      String De1 = firebaseData.stringData();
          if (De1=="1"){
              digitalWrite(first_1,HIGH);
              Serial.println("first on");//Device1 is ON
          }
          else if (De1=="0"){
              digitalWrite(first_1,LOW);//Device1 if OFF
              Serial.println("first off");
           }}
            delay(300);
  if (Firebase.getString(firebaseData,"/D6")) {
 
      String De2 = firebaseData.stringData();
          if (De2=="1"){
              digitalWrite(first_2,HIGH);//Device2 is ON
              Serial.println("first 2 on");
          }
              else if (De2=="0"){
              digitalWrite(first_2,LOW);// Device2 os OFF
              Serial.println("first 2 off");
            }}
            delay(300);
  if (Firebase.getString(firebaseData,"/D7")) {
    
      String De3 = firebaseData.stringData();
          if (De3=="1"){
              digitalWrite(first_3,HIGH);//Device3 is ON
              Serial.println("first 3 on");
          }
              else if (De3=="0"){
              digitalWrite(first_3,LOW);//Device3 is OFF
              Serial.println("first 3 off");
            }}
                      delay(300);
  if (Firebase.getString(firebaseData,"/D8")) {
   
      String De4 = firebaseData.stringData();
          if (De4=="1"){
              digitalWrite(first_4,HIGH);//Device4 is ON
              Serial.println("first 4 on");
          }
              else if (De4=="0"){
              digitalWrite(first_4,LOW);//Device4 is OFF
              Serial.println("first 4 off");
            }}
*/
  }
