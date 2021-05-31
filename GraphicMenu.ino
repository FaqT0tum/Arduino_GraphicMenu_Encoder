//Author FaqTOtum
//June 2021
//FREE FOR ANY NON COMMERCIAL PROJECT

#include "icon.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);

int DT = 14;       // Endored Detection (pin)
int CLK = 16;      // Encoder Clockwise (pin)
int push = 5;      // button Encoder (pin)

int selPin = 10;
int reset = LOW;
int sel = 0;
int exi = LOW;
int first = 0;
int selSens = 0;
int exiSub = LOW;

void setup() 
  {
  
  display.clearDisplay();

  pinMode(selPin, INPUT_PULLUP);  
  pinMode (DT, INPUT);
  pinMode (CLK, INPUT);
  pinMode (push, INPUT);

  display.begin(SH1106_SWITCHCAPVCC, 0x3C);  // initialize Display
  display.display();
  
  }

void loop() 
  {
  if(first==0)
    {
    start();
    }
  if(digitalRead(push)==LOW)
    {
    do
      {
      menu(sel);
      rotary();
      }
    while (exi==LOW);
    }
  exi = LOW;
  sel = 0;
  delay(350);  
  }

int rotary()
  {
  if((digitalRead(DT)==HIGH) && (digitalRead(CLK)==LOW) && (reset==LOW))
    {
    reset=HIGH;
    if(sel<=4) // set number of menu items
      {
      sel++;
      }
    }  
  if((digitalRead(DT)==LOW) && (digitalRead(CLK)==HIGH) && (reset==LOW))
    {
    reset=HIGH;
    if((sel<=5) && (sel>=0)) // set number of menu items (+1)
        {
        sel--;
        }
      else
        {
        sel=0;  
        }
    }
  if((digitalRead(DT)==HIGH) && (digitalRead(CLK)==HIGH))
    {
    reset=LOW;
    } 
  return (sel);
  }

int menu(int sel)
  {
  switch (sel) // MENU
    {
      case 0: // item 1
        display.clearDisplay();
        display.drawBitmap(0, 0, menu1, 128, 64, WHITE);
        display.display();
        delay(200);
        if(digitalRead(push)==LOW) //Enter to SubMenu
          {
          subMenu1();
          }
      break;

      case 1: // item 2
        display.clearDisplay();
        display.drawBitmap(0, 0, menu2, 128, 64, WHITE);
        display.display();
        if(digitalRead(push)==LOW) //Enter to SubMenu
          {
          subMenu2();
          }
      break;

      case 3: // item 3
        display.clearDisplay();
        display.drawBitmap(0, 0, menu3, 128, 64, WHITE);
        display.display();
        if(digitalRead(push)==LOW) //Enter to SubMenu
          {
          subMenu3();
          }
      break;

      case 4: // Exit
        display.clearDisplay();
        display.drawBitmap(0, 0, ext, 128, 64, WHITE);
        display.display();
        if(digitalRead(push)==LOW)
          {
          exi=HIGH;
          }
      break;
    }
  first=0;
  return(exi, first);  
  }

void setDisp()
  {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  }

void subMenu1()
  {
  delay(500);
  do 
    {
    display.clearDisplay();
    display.drawBitmap(0, 0, menuSub, 128, 64, WHITE);
    display.display();
    if(digitalRead(push)==LOW)
      {
      exiSub=HIGH;
      }
    }
  while (exiSub==LOW);
  delay(500);
  exiSub=LOW;
  }

void subMenu2()
  {
  delay(500);
  do 
    {
    display.clearDisplay();
    display.drawBitmap(0, 0, menuSub, 128, 64, WHITE);
    display.display();
    if(digitalRead(push)==LOW)
      {
      exiSub=HIGH;
      }
    }
  while (exiSub==LOW);
  delay(500);
  exiSub=LOW;
  }

void subMenu3()
  {
  delay(500);
  do 
    {
    display.clearDisplay();
    display.drawBitmap(0, 0, menuSub, 128, 64, WHITE);
    display.display();
    if(digitalRead(push)==LOW)
      {
      exiSub=HIGH;
      }
    }
  while (exiSub==LOW);
  delay(500);
  exiSub=LOW;
  }

int start() 
  {
  display.clearDisplay();
  display.drawBitmap(0, 0, faq, 128, 64, WHITE);
  display.display();
  first=1;
  return(first);
  }
