#define BLYNK_PRINT Serial
#define motorRight_1 D2
#define motorLeft_1 D5

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "85sZtjGBo5eyi7ZPUhhgSptGoPptYjN7";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "StarTec_Jean Carlos";
char pass[] = "jean12345";

bool speed_all;
bool speed_left;
bool speed_right;

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  pinMode(D2, OUTPUT);
  pinMode(D5, OUTPUT);

  speed_all = false;
  speed_left = false;
  speed_right = false;
}
BLYNK_WRITE(V0){
  
  int pinValue_speed = param.asInt(); 
  
  if(pinValue_speed == 0){
    speed_all = false; 
    }
  if(pinValue_speed == 1){
    speed_all = true;
    }
  
 }
BLYNK_WRITE(V1){
  
  int pinValue_left = param.asInt(); 
  
  if(pinValue_left == 0){
    speed_left = false; 
    }
  if(pinValue_left == 1){
    speed_left = true;
    }
  
 }
BLYNK_WRITE(V2){
  
  int pinValue_right = param.asInt(); 
  
  if(pinValue_right == 0){
    speed_right = false; 
    }
  if(pinValue_right == 1){
    speed_right = true;
    }
  
 }

void loop()
{
  Blynk.run();
  
  if(speed_all == true){
      digitalWrite(motorRight_1, HIGH);
      digitalWrite(motorLeft_1, HIGH);

      if(speed_left == true){
      digitalWrite(motorRight_1, LOW);
    }
      if(speed_right == true){
      digitalWrite(motorLeft_1, LOW);
    }
  }
  else{
    digitalWrite(motorRight_1, LOW);
    digitalWrite(motorLeft_1, LOW);
  }
    
 
}
