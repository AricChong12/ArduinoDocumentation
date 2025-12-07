int enA = 27;
int in1 = 26;
int in2 = 25;
int enB = 13;
int in3 = 12;
int in4 = 14;

int LFSL = 34;
int LFSR = 36;

void setup() {
  // put your setup code here, to run once:
  pinMode(LFSL, INPUT);
  pinMode(LFSR, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  line_following();
  delay(20);
}

void forward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
}


void turnRight(){
  digitalWrite(in1, HIGH);
  digitalWirte(in2, LOW);
  analogWrite(enA, 200);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);
}

void turnLeft(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
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

void line_following(){
  int leftSensor = digitalRead(LFSL);
  int rightSensor = digitalRead(LFSR);

  // if left right not detect line, forward
  if(leftSensor == 1 && rightSensor == 1){
    forward();
  }
  //if left detect line only, turn right
  else if(leftSensor == 1 && rightSensor == 0){
    turnRight();
  }
  //if right detect line only, turn left
  else if(leftSensor == 0 && rightSensor == 1){
    turnLeft();
  }
  //if two line(0,0), turn slowly to find back (1,1)
  else if(leftSensor == 0 && rightSensor == 0){
    //turn left slowly until find back white line
    while(digitalRead(LFSL) == 0 && digitalRead(LFSR) == 0){
      turnLeft();
      delay(10);
    }
  }
}















