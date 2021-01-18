#include<wire.h>
const int MPU_addr = 0x68; // I2C address of the MPU-6050
int16_t X, Y, Z;
void setup()
{
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop()
{
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true); // request a total of 14 registers
  X = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  Y = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  Z = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)

  Serial.print("AcX = "); Serial.print(X);
  Serial.print(" | AcY = "); Serial.print(Y);
  Serial.print(" | AcZ = "); Serial.println(Z);

  delay(333);
  if (X > 3000 && X < 7000 )
  {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }
  else if (X < -3000 && X > -7000 )
  {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  else if (Y < -3000 && Y > -7000 )
  {
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  else if (Y > 3000 && Y < 7000 )
  {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }

  else
  {
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
}
#include<wire.h>
const int MPU_addr = 0x68; // I2C address of the MPU-6050
int16_t X, Y, Z;
void setup()
{
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop()
{
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true); // request a total of 14 registers
  X = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  Y = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  Z = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)

  Serial.print("AcX = "); Serial.print(X);
  Serial.print(" | AcY = "); Serial.print(Y);
  Serial.print(" | AcZ = "); Serial.println(Z);

  delay(333);
  if (X > 3000 && X < 7000 )
  {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }
  else if (X < -3000 && X > -7000 )
  {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  else if (Y < -3000 && Y > -7000 )
  {
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  else if (Y > 3000 && Y < 7000 )
  {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }

  else
  {
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
}
