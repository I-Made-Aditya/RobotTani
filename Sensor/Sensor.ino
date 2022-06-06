//Sensor Kanan
#define echoPin1 2 
#define trigPin1 3
//Sensor Kiri
#define echoPin2 4
#define trigPin2 5

#define pwmPin 5


struct DataSensor{
  long duration;
  long distance;
};


void setup() {
  pinMode(trigPin1, OUTPUT); 
  pinMode(echoPin1, INPUT); 
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT); 
  Serial.begin(9600); 
  Serial.println("Ultrasonic Sensor HC-SR04 Test");
  Serial.println("with Arduino UNO R3");
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
    Serial.print("Kanan : ");
    Serial.print(Skanan.distance);
    Serial.println(" cm");
    Serial.print("Kiri : ");
    Serial.print(Skiri.distance);
    Serial.println(" cm");
    Serial.println("=================");
    delay(500);

}
