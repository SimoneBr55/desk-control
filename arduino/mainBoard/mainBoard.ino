#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ezButton.h>

//LCD Stuff
LiquidCrystal_I2C lcd(0x27, 16, 2);  // init lcd object

//LED Strip Stuff
const int white = 6;
const int blue = 11;
const int red = 10;
const int green = 9;

//Button Stuff
const int ledSwitchButton = 22; // This button switches mode and powers on/off.
const int ledBrightnessButton = 24; // This button will change the brightness while pressed.
const int ledColorButton = 26; // This button will change color while pressed (if mode correct).

ezButton bt_switch(ledSwitchButton);
ezButton bt_bright(ledBrightnessButton);
ezButton bt_color(ledColorButton);

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.clear();
}

void loop() {

  
  int btn = buttonPressed();
  bool lcd_refresh = actionPressed(btn);
  repaint(btn);
}

int buttonPressed() {
  int out;
  bt_switch.loop();
  bt_bright.loop();
  bt_color.loop();
  /*int switch_state = bt_switch.getState();
  int bright_state = bt_bright.getState();
  int color_state = bt_color.getState();*/

  if(bt_switch.isPressed()) out = 1;
  if(bt_bright.isPressed()) out = 2;
  if(bt_color.isPressed()) out = 3;
  
  return out;
}

boolean actionPressed(int btn){
}

void repaint(int btn){
}
