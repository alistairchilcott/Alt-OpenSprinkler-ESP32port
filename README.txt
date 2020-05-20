This is an ESP32 port of OpenSprinkler 2.1.9 firmware. As ESP32 has many GPIO pins, the main stations (8) are handled by ESP32 instead of any PCF8574's. All buttons are managed by the main ESP32 board too. Firmware is tested and works as AC version (DC and LA require a dedicated HW eg. voltage buster). As I do not have an ethernet board, RFTX or any Zone Expander's this functionality is not tested, however may work. 

The testing emvriemt was built based on 
1. ESP32 Oled Wemos board - https://randomnerdtutorials.com/esp32-built-in-oled-ssd1306/ 
2. DS3231 RTC
3. 6 channel relays board very similar to that one http://wiki.sunfounder.cc/index.php?title=8_Channel_5V_Relay_Module
4. 3 x switches/buttons

Whole HW configuration is defined by the esp32.h file. Where you can define GPIO pins for, sensors, buttons, main station, I2C, analog. Main station logics may be defined as (HIGH or LOW)

After 2 weeks of testing it looks like almost all works including OTA update.

Know limitation 
1. only AC configuration for now. 
2. ESP32 has many spare gpio pins to use (you can define them in PIN_FREE_LIST. However a way as UI is written prevents us from using it. Free GPIO pins are hard coded into javascript UI and available for PI a AVI version only. 
3. you need to be very careful when choosing GPIO pins for stations, buttons or sensors as some ESP32 may be 1 or 0 during startup or reboot, may not have a pullup resistors or transmit PWM signal... please refere to this article https://randomnerdtutorials.com/esp32-pinout-reference-gpios/ 
4. current measurement needs a special device (measurement resistor + amplifier) end even then analog read for ESP32 is up to 3,3v where for 1V for ESP8266
5. you may have a problem with a relay board as in most cases 5V is needed. However you may shortcut the led diode and this allowed to drive optoisolators correctly with 3,3V signal however to make a relay coils trigel you need power board with 5V JVCC pin !!!
6. SPIFFS partion formating is not tested and may not work. If not... compile and upload any ESP32 SPIFF exampel skech... 

Compilation process:
1. you need a Ardunio IDE and ESP32 espressif pack - follow this instrution https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/
2. you need to have  necessary libraries, including SSD1306, RCSwitch, and UIPEthernet. 
    - https://github.com/ThingPulse/esp8266-oled-ssd1306
    - https://github.com/sui77/rc-switch
    - https://github.com/UIPEthernet/UIPEthernet 
3. select "ESP32 dev module" 
4. edit esp32.h to define your HW config
5. hit upload under skech menu

As a bonus you can define mDNS device name (MDNS_NAME) and access device eg opensprinkler.local instead of IP address

Final comment. This is an experimental software in alpha stage, please be very careful connecting any external devices as errors may damage your device. You can use it, but it's at your own risk !
