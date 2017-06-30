/*
  Cmd-f1 Emulator
  Based on Adafruit's Trinket Keyboard example

*/

#include <TrinketKeyboard.h>

bool pressed = false;

void setup()
{
  pinMode(2, INPUT); // button input
  digitalWrite(2, HIGH); // enble pull-up

  pinMode(0, OUTPUT); // 0 and ground are connected so make sure they match
  digitalWrite(0, LOW);

  pinMode(LED_BUILTIN, OUTPUT);

  // start USB keyboard emulation
  TrinketKeyboard.begin();

}

void loop()
{
  // update the keyboard (needs to be done every 10ms)  
  TrinketKeyboard.poll();

  digitalWrite(LED_BUILTIN, !digitalRead(2));

  if (digitalRead(2) == LOW)
  {
    if (!pressed) {
      // Cmd key (left gui) modifier = 0x08 F1 key = 0x3A);
      TrinketKeyboard.pressKey(KEYCODE_MOD_LEFT_GUI, KEYCODE_F1);
      // for debouncing : 
      delay(2); 
      pressed = true;
    }
    // send key up when released
  } else if (pressed) {
    TrinketKeyboard.pressKey(0, 0);
    pressed = false;
    // for debouncing 
    delay(2); 
  }

}
