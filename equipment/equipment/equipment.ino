#include "equipment.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Beginning");
  Serial6.begin(9600);
  Serial7.begin(9600);

  setPins();
  setPinStates();
}

void loop() 
{
  // put your main code here, to run repeatedly: 
  getJoyStick();

}

void setPins()
{
  pinMode(JOY_ELEV_PLUS, INPUT);
  pinMode(JOY_ELEV_MINUS, INPUT);
  pinMode(JOY_AZI_PLUS, INPUT);
  pinMode(JOY_AZI_MINUS, INPUT);
  pinMode(PE_4, OUTPUT);
  //pinMode(K_BOARD_RX, INPUT);

  pinMode(DIAL_AZI_CTL, OUTPUT);
  pinMode(DIAL_ELEV_CTL, OUTPUT);
  //pinMode(K_BOARD_TX, OUTPUT);
  //pinMode(LCD_TX, OUTPUT);
  
}

void setPinStates()
{
  digitalWrite(JOY_ELEV_PLUS, LOW);
  digitalWrite(JOY_ELEV_MINUS, LOW);
  digitalWrite(JOY_AZI_PLUS, LOW);
  digitalWrite(JOY_AZI_MINUS, LOW);
  digitalWrite(PE_4,LOW);
  analogWrite(DIAL_AZI_CTL, 0);
  analogWrite(DIAL_ELEV_CTL, 0);
}

void getJoyStick()
{
  if (digitalRead(JOY_ELEV_PLUS) == HIGH)
  {
    Serial.println("1. ask elevation down");
    minus = 1;
    changeElev();
  }
  if (digitalRead(JOY_ELEV_MINUS) == HIGH)
  {
    Serial.println("1. ask elevation up");
    plus = 1;
    changeElev();
  }
  if (digitalRead(JOY_AZI_PLUS) == HIGH)
  {
    Serial.println("1. ask azimuth down");
    minus = 1;
    changeAzi();
  }
  if (digitalRead(JOY_AZI_MINUS) == HIGH)
  {
    Serial.println("1. ask azimuth up");
    plus = 1;
    changeAzi();
  }
}

void changeElev()
{
  Serial.println("2. Changing elevation");
  if (plus == 1)
  {
    if (ELEV_DIAL < 255)
    {
      ELEV_DIAL += 1 ;
      Serial.println("3. Elevation Increase");
      digitalWrite(PE_4, HIGH);
      analogWrite(DIAL_ELEV_CTL, ELEV_DIAL);
      plus = 0;
    }
    else
    {
      Serial.println("3. Error: elevation cannot increase");
    }
  }
  if (minus == 1)
  {
    if (ELEV_DIAL > 0)
    {
      ELEV_DIAL = ELEV_DIAL - 1;
      Serial.println("3. Elevation Decrease");
      digitalWrite(PE_4, HIGH);
      analogWrite(DIAL_ELEV_CTL, ELEV_DIAL);
      minus = 0;
    }
    else
    {
      Serial.println("3. Error: elevation cannot decrease");
    }
  }
}

void changeAzi()
{
  Serial.println("2. Changing azimuth");
  if (plus == 1)
  {
    if (AZI_DIAL < 255)
    {
      AZI_DIAL += 1;
      Serial.println("3. Azimuth Increase");
      digitalWrite(PE_4, HIGH);
      analogWrite(DIAL_AZI_CTL, AZI_DIAL);
      plus = 0;
    }
    else
    {
      Serial.println("3. Error: Azimuth cannot increase");
    }
  }
  if (minus == 1)
  {
    if (AZI_DIAL > 0)
    {
      AZI_DIAL = AZI_DIAL - 1;
      Serial.println("3. Azimuth Decrease");
      digitalWrite(PE_4, HIGH);
      analogWrite(DIAL_AZI_CTL, AZI_DIAL);
      minus = 0;
    }
    else
    {
      Serial.println("3. Error: Azimuth cannot decrease");
    }
  }
}
