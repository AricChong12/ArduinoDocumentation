long duration;
float distance;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(15, OUTPUT);
  pinMode(18, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //trigger pulse
  digitalWrite(18, LOW);
  delayMicroseconds(2);
  digitalWrite(18, HIGH);
  delayMicroseconds(10);
  digitalWrite(18, LOW);

  //measure echo time
  duration = pulseIn(4, HIGH);

  //cal distance
  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  //check distance and control buzzer
  if(distance > 0 && distance < 30){
    //digitalWrite(15, HIGH);
    Stop();
  }else{
    //digitalWrite(15, LOW);
    forward();
  }

  delay(200);

}


void forward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
}

void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}







