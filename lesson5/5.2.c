#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 8
#define S2 9
#define S3 10
#define S4 11

#define LT 6
#define BT 7

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
  
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);
  
  pinMode(LT,OUTPUT);
  pinMode(BT,OUTPUT);
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);

}

byte income = 0;
int i = 0; 
byte a=0,b=0,c=0,d=0;   //设置变量存储读出来的数

void digital_1(void)    //读出末位数的函数
{
  for(i=0;i<=3;i++)
  {
    if(Serial.available()>0)
    {
      digitalWrite(S1,HIGH);
      digitalWrite(S2,HIGH);
      digitalWrite(S3,HIGH);
      digitalWrite(S4,LOW);      //将最后一个数码管设置为未锁存
    
      income=Serial.read();
      income=income-'0';
      if(i==0)
      {
        a=income;
        Serial.println(a);
      }
      if(i==1)
      {
        b=income;
        Serial.println(b);
      }
      if(i==2)
      {
        c=income;
        Serial.println(c);
      }
      if(i==3)
      {
        d=income;
        Serial.println(d);
      }
   }
    
    digitalWrite(2,income&0x1);
    digitalWrite(3,(income>>1)&0x1);
    digitalWrite(4,(income>>2)&0x1);
    digitalWrite(5,(income>>3)&0x1);

   }
}

void digital_2(void)
{
  if(Serial.available()>0)
  {
    digitalWrite(S1,HIGH);
    digitalWrite(S2,HIGH);
    digitalWrite(S3,LOW);
    digitalWrite(S4,HIGH);
  
    a=a-'0';
    digitalWrite(2,a&0x1);
    digitalWrite(3,(a>>1)&0x1);
    digitalWrite(4,(a>>2)&0x1);
    digitalWrite(5,(a>>3)&0x1);
  }
}

void digital_3(void)
{
  digitalWrite(S1,HIGH);
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  digitalWrite(S4,HIGH);
  
  if(Serial.available()>0)
  {
    b=b-'0';
    digitalWrite(2,b&0x1);
    digitalWrite(3,(b>>1)&0x1);
    digitalWrite(4,(b>>2)&0x1);
    digitalWrite(5,(b>>3)&0x1);
  }
}

void digital_4(void)
{
  digitalWrite(S1,LOW);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  digitalWrite(S4,HIGH);
  
  if(Serial.available()>0)
  {
    c=c-'0';
    digitalWrite(2,c&0x1);
    digitalWrite(3,(c>>1)&0x1);
    digitalWrite(4,(c>>2)&0x1);
    digitalWrite(5,(c>>3)&0x1);
  }
}

void loop()
{
  digital_1();
  digital_2();
  digital_3();
  digital_4();
}