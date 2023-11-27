/*
 *
 *
YouTube: https://www.youtube.com/c/voidloopRobotechAutomation
Facebook: https://www.facebook.com/groups/289579082069596/
Fcebook: https://www.facebook.com/groups/228864595179720/
Facebook: https://www.facebook.com/groups/2518809408247417/
Facebook: https://www.facebook.com/groups/voidloop/
Facebook: https://www.facebook.com/voidlooprobo/
Instagram: https://www.instagram.com/voidlooprobotech/
Telegram: https://t.me/voidloopnodemcu
Telegram: https://t.me/voidlooprobotech
Whatsapp: https://chat.whatsapp.com/IIyB2IyjyQ71eSfn1jnl3c
 *
 *
 */
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("void loop ()");
  lcd.setCursor(3, 1);
  lcd.print("Subscribe");
}

void loop() {
  // put your main code here, to run repeatedly:
}
