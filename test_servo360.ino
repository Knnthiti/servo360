#include <ESP32Servo.h>
Servo myservo;
int val;
int set = 0, T;
void setup()
{
  myservo.attach(22);
  Serial.begin(115200);
  //myservo.write(0);
}
void loop()
{
  val = Serial.parseInt();      //ค่าจำนวนเต็มที่กรอกลง Serial (หากไม่กรอกไรเลยจะมีค่าเป็น 0)และเก็บค่าใน val=ตำแหน่งที่ต้องการให้servoหมุนไปอยู่
  if (Serial.available() > 0) { //ตรวจสอบค่าบน Serial ว่ามีค่ามากกว่า 0
    Serial.println(val);
    if (val > set) {            //ตรวจว่า val มีค่ามากกว่า set(เป็นตำแหน่งที่ servo อยู่ก่อนหน้านี้)
      Serial.print("val = ");
      Serial.println(val);
      T = (val - set) * 100;    //เวลาที่ใช้หมุน servo
      myservo.write(0);         //หมุนขวาด้วยความเร็วสูดสุด(0=max,1500=min)
      delay(T); 
      myservo.write(1500);     //servo หยุดหมุน
      set = val;               //บันทึกตำแหน่งล่าสุด
      Serial.print("set = ");
      Serial.println(set);
    }
    if (val < set) {          //ตรวจว่า val มีค่าน้อยกว่า set(เป็นตำแหน่งที่ servo อยู่ก่อนหน้านี้)
      Serial.print("val = ");
      Serial.println(val);
      T = (set - val) * 100;  //เวลาที่ใช้หมุน servo
      myservo.write(3000);    //หมุนซ้ายด้วยความเร็วสูดสุด(3000=max,1500=min)
      delay(T);
      myservo.write(1500);     //servo หยุดหมุน
      set = val;               //บันทึกตำแหน่งล่าสุด
      Serial.print("set = ");
      Serial.println(set);
    }
  }


  /*
    myservo.writeMicroseconds(0);
    delay(1800);
    myservo.writeMicroseconds(1450);
    delay(1800);
    myservo.writeMicroseconds(3000);
    delay(1800);
    myservo.writeMicroseconds(1450);
    delay(1800);

    myservo.write(180);
    delay(1000);
    myservo.write(0);
    delay(1000);*/
}
