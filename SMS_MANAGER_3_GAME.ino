//
//
//
    int botaopin=10,pino9=9,pino13=13,pino2=2,led1=3,led2=5,led3=6,led4=12,sndpin=11;
    int seq=0,apertos=0,botaostatus=1,botaoultimostatus=0,diff=0;
    int led[4] = {3 ,5 ,6 ,12};
    int tom[4] = {1915, 1700, 1519, 1432};
    long intervalo = 5000;

//
//
//
void setup()
{
     pinMode(sndpin, OUTPUT);
     pinMode(led1, OUTPUT);
     pinMode(led2,OUTPUT);
     pinMode(led3,OUTPUT);
     pinMode(led4,OUTPUT);
     pinMode(pino9,OUTPUT);
     pinMode(pino13, OUTPUT);
     pinMode(botaopin, INPUT);
     digitalWrite(botaopin, HIGH);
     Serial.begin(9600);
//
//
//
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);    
//
//
//
}
//
//
//
void loop()
{
//
//
//
digitalWrite(pino9, HIGH);
//
// Gera numero entre 1 e 4
//
seq=rand()%4+1;
Serial.print("sequencia: ");
Serial.println(seq);
delay (1000);
//
//
//
for (int x=0; x<seq;x++)
{
  Serial.println(led[x]);
  digitalWrite(led[x], LOW);
  tone(sndpin, tom[x]);
  delay(200);
  noTone(sndpin);
  delay(200);
  digitalWrite(led[x], HIGH);
  delay(200);
}
//
//
//
while (apertos != seq)
{
  long millisanterior = millis();
//
//
//
  while (millis() - millisanterior < intervalo)
  {
      botaostatus = digitalRead(botaopin);
      delay(170);
      if (botaostatus == 0) 
      {
        apertos++;
        Serial.print("number of button pushes:  ");
        Serial.println(apertos);
        Serial.println(botaostatus);
      }
  }
//
//
//
if (apertos == seq)
{
  Serial.println("acertou");
  tone(sndpin, 640);
  delay(1000);
  noTone(sndpin);
  delay(1000);
  break;
}
//
//
//
else
{
  Serial.println("fim do tempo:  ");
  tone(sndpin, 90);
  delay(1000);
  noTone(sndpin);
  delay(1000);
  break;
}
//
//
//
}    
apertos=0;
//
//
//
//
//
//
}
//
//
//
