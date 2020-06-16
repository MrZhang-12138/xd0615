int i=0;
void setup()
{
  for(i=0;i<=7;i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  for(i=0;i<=7;i++)
  {
     digitalWrite(i, HIGH);
     delay(200); 
     digitalWrite(i, LOW);
     delay(200); 
  }
  for(i=6;i>0;i--)
  {
     digitalWrite(i, HIGH);
     delay(200); 
     digitalWrite(i, LOW);
     delay(200); 
  }

}
