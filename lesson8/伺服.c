#include <Servo.h>  //调用Arduino中Sevro库函数

int pos = 0;        //设置转动角度变量

Servo servo;      //创建Servo对象用以控制伺服电机

void setup()
{
  servo.attach(6);    //将引脚6与Servo对象连接起来
}

void loop()
{
  for (pos = 0; pos <= 180; pos += 45) //使伺服电机从0度转至180度，每次转动45度
  {
    servo.write(pos);                  //转动至pos值对应的角度
    delay(1000);                       //暂停1000ms确保电机转动至相应角度
  }
  for (pos = 180; pos >= 0; pos -= 45) //使伺服电机从180度转至0度，每次转动45度
  {
    servo.write(pos);                  //转动至pos值对应的角度
    delay(1000);                       //暂停1000ms确保电机转动至相应角度
  }
}