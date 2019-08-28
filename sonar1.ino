// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11 ;
const int ledPin = 13;
const int ledPin1 = A3;

// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}


void loop() {
   digitalWrite(ledPin1, HIGH);
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
    
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
  
   duration = pulseIn(echoPin, HIGH);
  
   distance= duration*0.034/2;
  
   safetyDistance = distance;
   if (safetyDistance <=50)
   {
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledPin, HIGH);
   }
   else
   {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin, LOW);
   }
  Serial.print("Distance: ");
  Serial.println(distance);
} 
