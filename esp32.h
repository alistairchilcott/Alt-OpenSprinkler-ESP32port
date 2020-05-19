#ifndef _ESP32_H
#define _ESP32_H

#if defined(ESP32)

/** Data file names for esp32 / in filename is needed to work correctly*/
#define IOPTS_FILENAME        "/iopts.dat"   // integer options data file
#define SOPTS_FILENAME        "/sopts.dat"   // string options data file
#define STATIONS_FILENAME     "/stns.dat"    // stations data file
#define NVCON_FILENAME        "/nvcon.dat"   // non-volatile controller data file, see OpenSprinkler.h --> struct NVConData
#define PROG_FILENAME         "/prog.dat"    // program data file
#define DONE_FILENAME         "/done.dat"    // used to indicate the completion of all files


#define MDNS_NAME "opensprinkler" // mDNS name for OS controler
#define OS_HW_VERSION    (OS_HW_VERSION_BASE+40)

//#define RFTX // uncoment when planning to use RX controler
//#define ETHPORT // uncoment when palnning to use wired etherner

#define SDA_PIN 5 // I2C pin definition
#define SCL_PIN 4
#define LCD_I2CADDR      0x3C // 128x64 OLED display I2C address

#define IOEXP_PIN        0x80 // base for pins on main IO expander

/*  ESP32 port support only AC mode as DC and Latch need dedicated HW
 *  Dont need this to declere and saerch for Main IO controler and  
 *  ac, dc or latch drivers. However you may use DC nad Latch when deciated HW builded - not tested
 */
#define MAIN_I2CADDR     0x20 // main IO expander I2C address
#define ACDR_I2CADDR     0x21 // ac driver I2C address
#define DCDR_I2CADDR     0x22 // dc driver I2C address 
#define LADR_I2CADDR     0x23 // latch driver I2C address

#define EXP_I2CADDR_BASE 0x24 // base of expander I2C address

 
  #define ETHER_BUFFER_SIZE   8192

  /* To accommodate different OS30 versions, we use software defines pins */ 
  extern byte PIN_BUTTON_1;
  extern byte PIN_BUTTON_2;
  extern byte PIN_BUTTON_3;
  extern byte PIN_RFRX;
  extern byte PIN_RFTX;
  extern byte PIN_BOOST;
  extern byte PIN_BOOST_EN;
  extern byte PIN_LATCH_COM;
  extern byte PIN_SENSOR1;
  extern byte PIN_SENSOR2;
  extern byte PIN_IOEXP_INT;


  #define E0_PIN_BUTTON_1      25 // button 1
  #define E0_PIN_BUTTON_2      0 // button 2
  #define E0_PIN_BUTTON_3      26 // button 3
  #define E0_PIN_RFRX          255
  #define E0_PIN_RFTX          255
  #define E0_PIN_BOOST         255// special HW needed
  #define E0_PIN_BOOST_EN      255// special HW needed
  #define E0_PIN_LATCH_COM     255// not needed for ESP32
  #define E0_PIN_SENSOR1       36 // sensor 1
  #define E0_PIN_SENSOR2       2 // sensor 2  
  #define E0_PIN_IOEXP_INT     255// not needed for ESP32
 
  #define PIN_ETHER_CS         255 // ENC28J60 CS (chip select pin) is 16 on OS 3.2.

  #define ON_BOARD_GPIN_LIST     {12,13,14,15,16,255,255,255} //  ESP32 on board gpins to be usead as sections, 255 - pin not defined
  #define PIN_FREE_LIST     {} // no free GPIO pin at the moment

  #define PIN_CURR_SENSE      39
  
  #define STATION_LOGIC  0 // GPIO logic ex. for relays conneted to grand 0 meens ON


#endif
#endif //_ESP32_H
