#include <Wire.h>
int i,j,k,c;
int mat[16][2]={ {'1','0'},
                 {'1','1'},
                 {'2','0'},
                 {'2','1'},
                 {'3','0'},
                 {'3','1'},
                 {'4','0'},
                 {'4','1'},
                 {'5','0'},
                 {'5','1'},
                 {'6','0'},
                 {'6','1'},
                 {'7','0'},
                 {'7','1'},
                 {'8','0'},
                 {'8','1'} 
               };               
char cmd[15];
int relay1=A2;
int relay2=A1;
int relay3=A0;
int relay4=13;
int relay5=12;
int relay6=11;
int relay7=10;
int relay8=9;
void setup()
{
  Wire.begin(4);
  Wire.onReceive(command);
  Serial.begin(9600);
  Serial.println("Ready");
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(relay3,OUTPUT);
  pinMode(relay4,OUTPUT);
  pinMode(relay5,OUTPUT);
  pinMode(relay6,OUTPUT);
  pinMode(relay7,OUTPUT);
  pinMode(relay8,OUTPUT);
  digitalWrite(A2,LOW);
  digitalWrite(A1,LOW);
  digitalWrite(A0,LOW);
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  
}

void loop()
{
  if(Serial.available())
  {
    Clear();
    for(i=0;i<5;i++)
    {
      delay(100);
      cmd[i]=Serial.read();
     // Serial.print(cmd[i]);
    }
  }
  for(j=0;j<16;j++)
  {
    c=0;
    for(k=0;k<2;k++)
    {
      if(cmd[k]==mat[j][k])
      {
        c++;
        if(c==2)
        {
          c=0;
          switch(j)
          {
            case 0:
            digitalWrite(relay1,LOW);
            Serial.println("Relay 1 turned OFF");
            Clear();
            break;
            case 1:
            digitalWrite(relay1,HIGH);
            Serial.println("Relay 1 turned ON");
            Clear();
            break;
            case 2:
            digitalWrite(relay2,LOW);
            Serial.println("Relay 2 turned OFF");
            Clear();
            break;
            case 3:
            digitalWrite(relay2,HIGH);
            Serial.println("Relay 2 turned ON");
            Clear();
            break;
            case 4:
            digitalWrite(relay3,LOW);
            Serial.println("Relay 3 turned OFF");
            Clear();
            break;
            case 5:
            digitalWrite(relay3,HIGH);
            Serial.println("Relay 3 turned ON");
            Clear();
            break;
            case 6:
            digitalWrite(relay4,LOW);
            Serial.println("Relay 4 turned OFF");
            Clear();
            break;
            case 7:
            digitalWrite(relay4,HIGH);
            Serial.println("Relay 4 turned ON");
            Clear();
            break;
            case 8:
            digitalWrite(relay5,LOW);
            Serial.println("Relay 5 turned OFF");
            Clear();
            break;
            case 9:
            digitalWrite(relay5,HIGH);
            Serial.println("Relay 5 turned ON");
            Clear();
            break;
            case 10:
            digitalWrite(relay6,LOW);
            Serial.println("Relay 6 turned OFF");
            Clear();
            break;
            case 11:
            digitalWrite(relay6,HIGH);
            Serial.println("Relay 6 turned ON");
            Clear();
            break;
            case 12:
            digitalWrite(relay7,LOW);
            Serial.println("Relay 7 turned OFF");
            Clear();
            break;
            case 13:
            digitalWrite(relay7,HIGH);
            Serial.println("Relay 7 turned ON");
            Clear();
            break;
            case 14:
            digitalWrite(relay8,LOW);
            Serial.println("Relay 8 turned OFF");
            Clear();
            break;
            case 15:
            digitalWrite(relay8,HIGH);
            Serial.println("Relay 8 turned ON");
            Clear();
            break;
          }
        }
      }
    }
  }
}
void command(int relay)
{
  for(i=0;i<5;i++)
  {
    delay(100);
    cmd[i]=Wire.read();
    Serial.print(cmd[i]);
  }
}
void Clear()
{
  for(i=0;i<10;i++)
  {
    cmd[i]=' ';
  }
}
