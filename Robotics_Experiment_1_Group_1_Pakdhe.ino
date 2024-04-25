#define ir1 A7
#define ir2 A6
#define ir3 A5
#define ir4 A4
#define ir5 A3
#define ir6 A2
#define ir7 A1
#define ir8 A0

int s1 = 0;
int s2 = 0;
int s3 = 0;
int s4 = 0;
int s5 = 0;
int s6 = 0;
int s7 = 0;
int s8 = 0;

const int sensorMin = 490;
const int sensorMax = 1000;

const int outputMin = 0;
const int outputMax = 1000;

int item = 800;
int putih = 800;

#define enA 3
#define in1 2
#define in2 4

#define enB 5
#define in3 7
#define in4 6

int leapTime1 = 2 * 1;
int leapTime2 = 2 * 4;


void bacaSensor_pakdhe();
void tampilinSensor_pakdhe(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);
void kontrolKecMot_pakdhe(int x1, int x2);
void setMD_pakdhe_pakdhe(int y1, int y2);
void sikuLeft_Pakdhe();
void sikuRight_Pakdhe();
void FL_Pakdhe();
void done();


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
  pinMode(ir6, INPUT);
  pinMode(ir7, INPUT);
  pinMode(ir8, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // digitalWrite(in1, LOW);
  // digitalWrite(in2, HIGH);
  // digitalWrite(in3, LOW);
  // digitalWrite(in4, HIGH);
  // analogWrite(enA, 255);
  // analogWrite(enB, 255);
  // delay(2000);

  // digitalWrite(in1, LOW);
  // digitalWrite(in2, HIGH);
  // digitalWrite(in3, LOW);
  // digitalWrite(in4, HIGH);
  // analogWrite(enA, 99);
  // analogWrite(enB, 99);
  // delay(2000);

  // for (int i = 0; i < putih; i++) {
  //   digitalWrite(in1, HIGH);
  //   digitalWrite(in2, LOW);
  //   digitalWrite(in3, HIGH);
  //   digitalWrite(in4, LOW);
  //   analogWrite(enA, i);
  //   analogWrite(enB, i);
  //   delay(20);
  // }

  bacaSensor_pakdhe();
  FL_Pakdhe();
  sikuLeft_Pakdhe();
  sikuRight_Pakdhe();
}

void tampilinSensor_pakdhe(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) {
  Serial.print("s1 = ");
  Serial.print(p1);
  Serial.print(", s2 = ");
  Serial.print(p2);
  Serial.print(", s3 = ");
  Serial.print(p3);
  Serial.print(", s4 = ");
  Serial.print(p4);
  Serial.print(" s5 = ");
  Serial.print(p5);
  Serial.print(", s6 = ");
  Serial.print(p6);
  Serial.print(", s7 = ");
  Serial.print(p7);
  Serial.print(", s8 = ");
  Serial.println(p8);
  // Serial.print(", max = ");
  // Serial.print(sMax);
  // Serial.print(", min = ");
  // Serial.println(sMin);
}

void bacaSensor_pakdhe() {
  // s1 = map(analogRead(ir1), sensorMin, sensorMax, outputMin, outputMax);
  // s2 = map(analogRead(ir2), sensorMin, sensorMax, outputMin, outputMax);
  // s3 = map(analogRead(ir3), sensorMin, sensorMax, outputMin, outputMax);
  // s4 = map(analogRead(ir4), sensorMin, sensorMax, outputMin, outputMax);
  // s5 = map(analogRead(ir5), sensorMin, sensorMax, outputMin, outputMax);
  // s6 = map(analogRead(ir6), sensorMin, sensorMax, outputMin, outputMax);
  // s7 = map(analogRead(ir7), sensorMin, sensorMax, outputMin, outputMax);
  // s8 = map(analogRead(ir8), sensorMin, sensorMax, outputMin, outputMax);

  s1 = analogRead(ir1);
  s2 = analogRead(ir2);
  s3 = analogRead(ir3);
  s4 = analogRead(ir4);
  s5 = analogRead(ir5);
  s6 = analogRead(ir6);
  s7 = analogRead(ir7);
  s8 = analogRead(ir8);

  // int sMax = maxVal(s1, s2, s3, s4, s5, s6, s7, s8);
  // int sMin = minVal(s1, s2, s3, s4, s5, s6, s7, s8);

  // tampilinSensor_pakdhe(s1, s2, s3, s4, s5, s6, s7, s8);
  delay(leapTime1);
}

void kontrolKecMot_pakdhe(int x1, int x2) {
  analogWrite(enA, x1);
  analogWrite(enB, x2);
}

void setMD_pakdhe(int y1, int y2) {
  if (y1 == 1) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else if (y1 == 2) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  } else if (y1 == 3) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
  if (y2 == 1) {
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  } else if (y2 == 2) {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  } else if (y2 == 3) {
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}

void done() {
  setMD_pakdhe(3, 3);
  kontrolKecMot_pakdhe(0, 0);
}

void sikuLeft_Pakdhe() {
  if (s1 > item && s2 > item && s7 < putih && s8 < putih) {
    setMD_pakdhe(1, 1);
    kontrolKecMot_pakdhe(100, 100);
    delay(leapTime1);
    while (true) {
      bacaSensor_pakdhe();
      setMD_pakdhe(2, 1);
      kontrolKecMot_pakdhe(255, 100);
      delay(leapTime1);
      if (s4 > item || s5 > item) {
        break;
      }
    }
  }
}

void sikuRight_Pakdhe() {
  if (s1 < putih && s2 < putih && s7 > item && s8 > item) {
    setMD_pakdhe(1, 1);
    kontrolKecMot_pakdhe(100, 100);
    delay(leapTime1);
    while (true) {
      bacaSensor_pakdhe();
      setMD_pakdhe(1, 2);
      kontrolKecMot_pakdhe(255, 100);
      delay(leapTime1);
      if (s4 > item || s5 > item) {
        break;
      }
    }
  }
}

void FL_Pakdhe() {
  if (s4 > item && s5 > item) {
    setMD_pakdhe(1, 1);
    kontrolKecMot_pakdhe(255, 255);
    bacaSensor_pakdhe();
  } else if (s4 < putih && s5 > item) {
    setMD_pakdhe(1, 1);
    kontrolKecMot_pakdhe(255, 100);
    bacaSensor_pakdhe();
  } else if (s4 > item && s5 < putih) {
    setMD_pakdhe(1, 1);
    kontrolKecMot_pakdhe(100, 255);
    bacaSensor_pakdhe();
  }
}