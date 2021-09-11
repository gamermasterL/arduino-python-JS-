
int piezoPin = 3;
int echoPin = 13;
int trigPin = 12;

void setup() {
  //모듈 핀모드(pinMode) 선언
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(piezoPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);

  float distance = duration / 29.0 / 2.0;

  
/*
 * 측정된 거리값을 사용하여 거리에 맞는 음계 출력(6옥타브 음계 출력)
 * 50cm 미만일 때 소리가 출력됩니다. 50cm를 초과하면 소리 X
 * 5cm간격으로 5, 10, 15, 20, 25씩 소리가 출력됩니다.
 */
  if (distance < 50) {
    if (distance <= 5) {
      tone(piezoPin, 1047);            //도
    } else if (distance <= 10) {
      tone(piezoPin, 1174);            //레     
    } else if (distance <= 15) {
      tone(piezoPin, 1318);            //미
    } else if (distance <= 20) {
      tone(piezoPin, 1396);            //파
    } else if (distance <= 25) {
      tone(piezoPin, 1567);            //솔
    } else if (distance <= 30) {
      tone(piezoPin, 1760);            //라
    } else if (distance <= 35) {
      tone(piezoPin, 1975);            //시
    } else if (distance <= 40) {
      tone(piezoPin, 2093);            //도
    }
  }
  else {
    noTone(piezoPin);
  }
  delay(100);
}