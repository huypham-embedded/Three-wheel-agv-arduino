
/*
================================================
       AGV 2 BANH
       ARDUINO UNO + L298N + HC-SR04
================================================

Chuc nang:
1. Tu dong di thang.
2. Do khoang cach bang cam bien sieu am.
3. Gap vat can duoi 25cm:
   - Dung xe.
   - Lui lai.
   - Quay phai.
4. Tiep tuc di chuyen.

Hai dong co su dung cung muc PWM.
*/

// ================================================
// 1. KHAI BAO CHAN L298N
// ================================================

// Dong co trai - Kenh A
#define ENA 3
#define IN1 5
#define IN2 6

// Dong co phai - Kenh B
#define ENB 11
#define IN3 9
#define IN4 10

// ================================================
// 2. KHAI BAO CAM BIEN HC-SR04
// ================================================

#define TRIG 7
#define ECHO 4

// ================================================
// 3. CAU HINH AGV
// ================================================

// Toc do chung cua hai dong co
int tocDoTien = 180;
int tocDoLui = 160;
int tocDoQuay = 180;

// Nguong phat hien vat can
int nguongVatCan = 25;

// Thoi gian lui va quay
int thoiGianLui = 350;
int thoiGianQuay = 400;

// ================================================
// 4. SETUP
// ================================================

void setup() {

  // Cau hinh chan dong co trai
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Cau hinh chan dong co phai
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Cau hinh cam bien sieu am
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // Serial Monitor
  Serial.begin(9600);

  // Dung xe khi khoi dong
  dungXe();

  Serial.println("AGV DA KHOI DONG!");
  delay(1000);
}

// ================================================
// 5. HAM DO KHOANG CACH
// ================================================

float doKhoangCach() {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  // Doc thoi gian phan hoi
  long thoiGian = pulseIn(ECHO, HIGH, 25000UL);

  // Khong nhan duoc phan hoi:
  // Xem nhu khong co vat can trong tam do
  if (thoiGian == 0) {
    return 400;
  }

  // Tinh khoang cach centimet
  float khoangCach = thoiGian * 0.0343 / 2;

  return khoangCach;
}

// ================================================
// 6. HAM DI CHUYEN TIEN
// ================================================

void tien() {

  // Hai dong co cung chieu tien
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  // Hai banh nhan cung toc do PWM
  analogWrite(ENA, tocDoTien);
  analogWrite(ENB, tocDoTien);

}

// ================================================
// 7. HAM DI CHUYEN LUI
// ================================================

void lui() {

  // Hai dong co cung chieu lui
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  // Hai banh nhan cung toc do PWM
  analogWrite(ENA, tocDoLui);
  analogWrite(ENB, tocDoLui);

}

// ================================================
// 8. HAM QUAY PHAI
// ================================================

void quayPhai() {

  // Banh trai tien
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Banh phai lui
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, tocDoQuay);
  analogWrite(ENB, tocDoQuay);

}

// ================================================
// 9. HAM QUAY TRAI
// ================================================

void quayTrai() {

  // Banh trai lui
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Banh phai tien
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, tocDoQuay);
  analogWrite(ENB, tocDoQuay);

}

// ================================================
// 10. HAM DUNG XE
// ================================================

void dungXe() {

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}

// ================================================
// 11. HAM TRANH VAT CAN
// ================================================

void tranhVatCan() {

  Serial.println("PHAT HIEN VAT CAN!");

  // Giai doan 1: Dung xe
  dungXe();
  delay(200);

  // Giai doan 2: Lui lai
  Serial.println("AGV DANG LUI");

  lui();
  delay(thoiGianLui);

  // Giai doan 3: Dung lai
  dungXe();
  delay(200);

  // Giai doan 4: Quay phai
  Serial.println("AGV DANG QUAY PHAI");

  quayPhai();
  delay(thoiGianQuay);

  // Giai doan 5: Dung lai
  dungXe();
  delay(200);

}

// ================================================
// 12. CHUONG TRINH CHINH
// ================================================

void loop() {

  // Doc khoang cach
  float kc = doKhoangCach();

  Serial.print("Khoang cach vat can: ");
  Serial.print(kc);
  Serial.println(" cm");

  // Kiem tra vat can
  if (kc > nguongVatCan) {

    // Khong co vat can gan
    Serial.println("AGV DANG DI THANG");

    tien();

  }

  else {

    // Co vat can
    tranhVatCan();

  }

  delay(50);

}
