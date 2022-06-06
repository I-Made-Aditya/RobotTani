#include <ezButton.h>
ezButton limitSwitch(13); //Limit Switch Pin
//Sensor Kanan
#define echoPin1 2 
#define trigPin1 3

//Sensor Kiri
#define echoPin2 4 
#define trigPin2 5

#define pwm 200
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9
#define enA 10
#define enB 11
#define Relay 12
#define LEDM A0 //Merah
#define LEDK A1 //Kuning
#define LEDI A2 //Ijo
#define LEDB A3 //Biru


struct DataSensor{
  long duration;
  long distance;
};

void Maju();
void Mundur();
void Berhenti();
void Putar();
void Siram();

void setup() {
  pinMode(trigPin1, OUTPUT); 
  pinMode(echoPin1, INPUT); 
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT); 
  pinMode(Relay, OUTPUT);
  pinMode(LEDM, OUTPUT);
  pinMode(LEDK, OUTPUT);
  pinMode(LEDI, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(Relay, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  limitSwitch.setDebounceTime(30);// set debounce time to 50 milliseconds
  Serial.begin(9600); 
}

void loop() {

    DataSensor Skanan, Skiri;
    
    //Data Sensor Kanan
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);
    Skanan.duration = pulseIn(echoPin1, HIGH);
    Skanan.distance = Skanan.duration/58.2; //Converting CM
    
    //Data Sensor Kiri
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    Skiri.duration = pulseIn(echoPin2, HIGH);
    Skiri.distance = Skiri.duration/58.2; //Converting CM

    //===========================================================================//
    Serial.print(Skanan.distance);
    Serial.println(" cm");
    Serial.print(Skiri.distance);
    Serial.println(" cm");
    
    if(Skanan.distance<=6||Skiri.distance<=6){
      digitalWrite(LEDM, HIGH);
      Berhenti();
      Siram();
      digitalWrite(LEDM, LOW);
      digitalWrite(LEDI, HIGH);
      Maju();
    }
    else if(limitSwitch.isPressed()){
      Berhenti();
      digitalWrite(LEDB, HIGH);
      Serial.println("Robot Berputar");
      Mundur();
      Putar();
      digitalWrite(LEDB, LOW);
      digitalWrite(LEDI, HIGH);
      Maju();
    }
    else{
      digitalWrite(LEDI, HIGH);
      Maju();
    }

}

void Maju(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(enA, pwm);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(enB, pwm);
}

void Mundur(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(enA, pwm);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(enB, pwm);
  delay(1000);
}
void Berhenti(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(enA, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(enA, LOW);
  delay(1000);
}

void Siram(){
  digitalWrite(Relay, HIGH);
  delay(2000);
  digitalWrite(Relay, LOW);
}

void Putar(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(enA, pwm);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(enA, pwm);
  delay(1000)
}
