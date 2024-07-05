#include <BleKeyboard.h>

const uint8_t VOL_UP_PIN = 13;
const uint8_t VOL_DOWN_PIN = 27;
const uint8_t MUTE_PIN = 26;

const uint8_t PIN_COUNT = 3;

uint8_t pins[PIN_COUNT] = { VOL_UP_PIN, VOL_DOWN_PIN, MUTE_PIN };

const MediaKeyReport* keys[PIN_COUNT] = {
  &KEY_MEDIA_VOLUME_UP,
  &KEY_MEDIA_VOLUME_DOWN,
  &KEY_MEDIA_MUTE,
};

BleKeyboard bleKeyboard("ChipsMacro_Beta01", "ChipsBoards");

void setup() {
  bleKeyboard.begin();

  int i = 0;
  for (i = 0; i < PIN_COUNT; i++) {
    pinMode(pins[i], INPUT_PULLUP);
  }
}

void loop() {
  if (bleKeyboard.isConnected()) {
    int i = 0;
    for (i = 0; i < PIN_COUNT; i++) {
      if (digitalRead(pins[i]) == LOW) {
        bleKeyboard.write(*keys[i]);
      }
      delay(50);
    }
  }
}
