#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

#define S 8
#define LT 9
#define BT 10
void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(S, OUTPUT);
  pinMode(LT,OUTPUT);
  pinMode(BT,OUTPUT);
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  digitalWrite(S,LOW);
}

byte income=0;
int i=0;

void loop()
{
  for(i=0;i<=9;i++)
  {
    income=income-'0';
    digitalWrite(4,income&0x1);
    digitalWrite(5,(income>>1)&0x1);
    digitalWrite(6,(income>>2)&0x1);
    digitalWrite(7,(income>>3)&0x1);
    delay(1000);
    income++;
  }
  for(i=0;i<=9;i++)
  {
    income=income-'0';
    digitalWrite(4,income&0x1);
    digitalWrite(5,(income>>1)&0x1);
    digitalWrite(6,(income>>2)&0x1);
    digitalWrite(7,(income>>3)&0x1);
    delay(1000);
    income--;
  }
}