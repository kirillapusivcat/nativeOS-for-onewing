#include <Wire.h>
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RTClib.h>

// Test Build. Open sourse build - absolutely free; build ver: 1.0 NATIVE_OS_BUDGIE_EDITION_EXPERIMENTAL status:unstable;

// init

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

#ifdef ESP32
  #define FPSerial Serial1
#else
  #include <SoftwareSerial.h>
  SoftwareSerial FPSerial(16, 17);
#endif

DFRobotDFPlayerMini player;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
RTC_DS3231 rtc;

const int abtnpin = 5;
const int bbtnpin = 4;
const int cbtnpin = 12;
const int dbtnpin = 14;

int abtnact;
int bbtnact;
int cbtnact;
int dbtnact;

// modes
int Displaysts = HIGH;
int MODE = 0;
int APP = 0;

// time

String rtcseconds;
String rtcminutes;
String rtchours;
String rtcdays;
String rtcmonths;
String rtcyears;

// months names
String month_name;
String month_names[12]={"Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};

void get_month_name(int month_int) {
  month_name = month_names[month_int - 1];
}

// fls

int DFPlayerrd;

//Apps

void openApp(int appnum;) {
  APP = MODE
}

// bitmap imgs

//BOOT_IMG_INIT

// 1YANVS
static const uint8_t image_data_1YANVS[1024] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xea, 0xff, 0xfd, 0xaf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xb5, 0x5f, 0xf5, 0x75, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0x5b, 0xab, 0x5b, 0xaa, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0xad, 0x75, 0xad, 0x5d, 0x5f, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x76, 0xae, 0xf5, 0xab, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0xd5, 0xff, 0xff, 0x75, 0x5f, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0x5f, 0xff, 0xff, 0xee, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xea, 0xff, 0xff, 0xff, 0xfd, 0x5f, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xad, 0xff, 0xff, 0xff, 0xff, 0xab, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xaa, 0xd7, 0xff, 0xff, 0xaf, 0xff, 0xf5, 0x57, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xdb, 0x5f, 0xff, 0xfe, 0xdf, 0xff, 0xf6, 0xaa, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfe, 0xad, 0x7f, 0xff, 0xff, 0x67, 0xff, 0xfa, 0xdb, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x6a, 0xff, 0xff, 0xff, 0x5f, 0xff, 0xfe, 0xad, 0x7f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfd, 0x56, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x75, 0xbf, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfd, 0xbb, 0xff, 0xeb, 0xff, 0xff, 0xff, 0xff, 0x55, 0x7f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfa, 0xca, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xad, 0xbf, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfd, 0x6f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb5, 0x5f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfe, 0xab, 0xff, 0xff, 0xff, 0xfd, 0x7f, 0xff, 0xd6, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x57, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xef, 0xdb, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xdb, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xb7, 0xd5, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xaf, 0xf4, 0xd2, 0x5f, 0xff, 0xfe, 0xdf, 0xd7, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xd7, 0xeb, 0x5d, 0xa9, 0x5b, 0xd5, 0x57, 0xeb, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xb7, 0xed, 0x7d, 0x6d, 0xad, 0x5e, 0xaf, 0xdb, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x57, 0xea, 0xba, 0xaa, 0xb5, 0x7f, 0xd7, 0xd5, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfe, 0xab, 0xf5, 0x4b, 0x55, 0x55, 0x5f, 0xdf, 0xaa, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfa, 0xdb, 0xf5, 0xb5, 0x6b, 0x55, 0x7f, 0xaf, 0xdb, 0x5f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfb, 0x57, 0xfa, 0xaa, 0xad, 0x6b, 0x57, 0x7f, 0xaa, 0xbf, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfd, 0x55, 0xfa, 0xad, 0xbf, 0xad, 0x55, 0x5f, 0x55, 0x7f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfd, 0x55, 0x7e, 0xd5, 0x5f, 0xd5, 0x55, 0x7f, 0x5a, 0xbf, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfd, 0x6a, 0xff, 0x55, 0x5f, 0x55, 0x5a, 0xfd, 0x6b, 0x7f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x55, 0x7f, 0xaa, 0xa5, 0x55, 0xab, 0xfd, 0x55, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x56, 0x9f, 0xed, 0x5a, 0xb6, 0xaf, 0xf5, 0x55, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xaa, 0xd7, 0xfa, 0xd5, 0x55, 0x7f, 0xeb, 0x57, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x55, 0xff, 0x55, 0xab, 0xff, 0xad, 0xfb, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xd6, 0xff, 0xfe, 0xff, 0xfe, 0xab, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x3f, 0xff, 0xff, 0xe9, 0x5f, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x4b, 0xff, 0xff, 0x56, 0xaf, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x6a, 0x56, 0xd4, 0xaa, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xaa, 0xaa, 0xaa, 0xaa, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xea, 0xaa, 0xaa, 0xaa, 0xaa, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x57, 0xd5, 0x55, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xaa, 0xbf, 0xfa, 0xab, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x7f, 0xfd, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x99, 0x00, 0x23, 0x08, 0x44, 0x88, 0x00, 0x84, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x38, 0x57, 0x07, 0x88, 0x51, 0x21, 0xb8, 0x10, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xbc, 0xcc, 0xaf, 0x6a, 0x49, 0x19, 0x86, 0xb9, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x3c, 0xc0, 0x0f, 0x02, 0x19, 0x8b, 0x10, 0x39, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xf9, 0xc7, 0x64, 0xe3, 0xf9, 0xff, 0x9f, 0xcf, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xf9, 0xc1, 0x25, 0xc1, 0xfb, 0xff, 0x9f, 0xdf, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x11, 0xc9, 0x04, 0xe9, 0x08, 0x43, 0x98, 0x43, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfe, 0x4b, 0xcd, 0x11, 0xc3, 0x69, 0x13, 0xbe, 0x4b, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfe, 0x49, 0xc9, 0x91, 0xe9, 0x22, 0x5b, 0x9a, 0x53, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x1b, 0xc3, 0x19, 0xc9, 0x08, 0x43, 0x88, 0x43, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

// BOOTSCREEN

static const uint8_t image_data_BOOT[1024] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xf4, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x52, 0x4b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xeb, 0xd1, 0x25, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xaa, 0x20, 0xa9, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x43, 0x55, 0x55, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xab, 0xaa, 0xaa, 0xd7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xfe, 0x96, 0xd5, 0x55, 0x2b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xfe, 0xbf, 0xa1, 0x2a, 0xab, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x55, 0xa4, 0xa4, 0x95, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xbe, 0xd4, 0xda, 0x4a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xeb, 0x6f, 0x6a, 0x91, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfe, 0xaa, 0xaa, 0x48, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xeb, 0xcd, 0xa9, 0x25, 0x2f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x6a, 0xa5, 0x52, 0xa5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfd, 0xb6, 0xba, 0xad, 0x55, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xf7, 0xda, 0xcd, 0xaa, 0xd5, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfd, 0x6d, 0x6a, 0x55, 0x6e, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xef, 0xb6, 0xa9, 0x55, 0x2b, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xf5, 0x5a, 0xb4, 0xa4, 0xa0, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xdf, 0xeb, 0x52, 0x52, 0x9a, 0xa7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xf5, 0x55, 0x69, 0x09, 0x44, 0x8a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfe, 0xda, 0xaa, 0xa4, 0x32, 0x57, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xeb, 0x57, 0xaa, 0x25, 0x4a, 0x28, 0x2f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfd, 0xaa, 0x54, 0x94, 0x91, 0xc5, 0x7b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xf6, 0xdd, 0x52, 0x41, 0x26, 0x1a, 0x88, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfb, 0x52, 0xa9, 0x14, 0x88, 0xc2, 0xa1, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfd, 0x55, 0x44, 0x89, 0x24, 0x99, 0x5b, 0x2f, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfa, 0xaa, 0xa8, 0x64, 0x82, 0x25, 0x0e, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x54, 0x4a, 0x12, 0x54, 0x80, 0xb3, 0x45, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xab, 0x25, 0x41, 0x08, 0x55, 0x28, 0xa5, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xe9, 0x52, 0x2c, 0xa2, 0x92, 0x8e, 0x5a, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xf5, 0x0a, 0x92, 0x54, 0x48, 0x81, 0x36, 0xbf, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xfe, 0xa9, 0x40, 0x92, 0x92, 0x61, 0xd1, 0x3f, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xa4, 0x54, 0x0a, 0x49, 0x1a, 0x2c, 0x2f, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xe9, 0x22, 0xa1, 0x54, 0xaa, 0xa5, 0xb7, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x98, 0x08, 0x02, 0x52, 0xb5, 0xeb, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x4e, 0xa5, 0x08, 0x0a, 0x96, 0x95, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf2, 0xa0, 0xa0, 0x80, 0x55, 0x0a, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x08, 0x21, 0x00, 0x52, 0x7f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xaa, 0x52, 0x84, 0x55, 0x21, 0x2f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xc5, 0x4a, 0x50, 0x02, 0x89, 0x55, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x29, 0x3f, 0xea, 0x90, 0x54, 0x13, 0x7f, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x5f, 0xff, 0xfe, 0x8a, 0x22, 0x88, 0xaf, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xea, 0x8f, 0xff, 0xff, 0xe1, 0x49, 0x24, 0x0b, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xf3, 0xff, 0xff, 0xfc, 0x92, 0x40, 0x80, 0x7f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xf8, 0xff, 0xff, 0xff, 0x49, 0x2a, 0x10, 0x3f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xfe, 0xff, 0xff, 0xff, 0xe4, 0x91, 0x02, 0x03, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x4c, 0xa1, 0xc0, 0x7f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x22, 0xa8, 0x7f, 0x7f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x90, 0x12, 0x7f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xea, 0x81, 0x7f, 0xff, 
0xff, 0xff, 0xff, 0xfe, 0xf7, 0xff, 0xcf, 0xff, 0xfd, 0x3d, 0x3f, 0xff, 0xfc, 0x08, 0x7f, 0xff, 
0xff, 0xff, 0xff, 0xfc, 0x23, 0x58, 0x4b, 0xba, 0xf8, 0x88, 0xff, 0xff, 0xff, 0xa1, 0x1f, 0xff, 
0xff, 0xff, 0xff, 0xfc, 0x02, 0x88, 0x88, 0x90, 0x79, 0xc4, 0x1f, 0xff, 0xff, 0xf2, 0x47, 0xff, 
0xff, 0xff, 0xff, 0xfe, 0xe2, 0x0c, 0x4c, 0x22, 0xf8, 0x0d, 0x1f, 0xff, 0xff, 0xff, 0xb1, 0xff, 
0xff, 0xff, 0xff, 0xfe, 0xff, 0xee, 0xff, 0x7d, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x7f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb
};

// BOOT Setup

void setup() {
    pinMode(abtnpin, INPUT_PULLUP);
    pinMode(bbtnpin, INPUT_PULLUP);
    pinMode(cbtnpin, INPUT_PULLUP);
    pinMode(dbtnpin, INPUT_PULLUP);
    Serial.begin(115200);
    Wire.begin();

    #ifdef ESP32
      FPSerial.begin(9600, SERIAL_8N1, 16, 17);
    #else
      FPSerial.begin(9600);
    #endif

    if (!player.begin(FPSerial)) {
    Serial.println(F("Unable to begin ERROR CODE:444650"));
    while(true);
  }
  if (DFPlayerrd != LOW) {
    DFPlayerrd = HIGH;
  }
  
    if (!rtc.begin()) {
      Serial.println("Unable to begin ERROR CODE: 828467");
      while(true);
    }

    player.volume(20);

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();

    // 1 YANVS display
    display.drawBitmap(0, 0, image_data_1YANVS, 128, 64, 1);
    display.display();
    player.play(2);
    delay(3000);
    display.clearDisplay();
    
    // BOOT_IMAGE display
    display.drawBitmap(0, 0, image_data_BOOT, 128, 64, 1);
    display.display();
    player.play(1);
    delay(5000);
    display.clearDisplay();

    // welcome back text
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    display.println("Welcome back!");
    display.display();
    player.play(2);
    delay(2000);
    display.clearDisplay();

    // BOOT_END
}

// OS Loop

void loop() {
  // time init
  DateTime now = rtc.now();

  if (now.minute() < 10) {
    rtcminutes = "0" + String(now.minute());
  } else {
    rtcminutes = String(now.minute());
  }

  if (now.second() < 10) {
    rtcseconds = "0" + String(now.second());
  } else {
    rtcseconds = String(now.second());
  }

  rtchours = String(now.hour());
  rtcdays = String(now.day());
  rtcmonths = String(now.month());
  get_month_name(now.month());
  rtcyears = String(now.year());

  // App prewiew
  if (Displaysts == HIGH) {
    if (MODE == 0 && APP == 0) {
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0,20);
      display.print(String(now.hour()) + ":" + rtcminutes + ":" + rtcseconds);
      display.setTextSize(1);
      display.setCursor(0,50);
      display.print(rtcdays + " " + month_name + " " + rtcyears);
      display.display();
    } else {
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0,10);
      display.print(MODE);
      display.setTextSize(2);
      display.setCursor(32,32);
      display.print("Blank");
      display.display();
    }
  } else if (Displaysts == LOW) {
    display.clearDisplay();
    display.display();
  }

  // read keypad value
  
  abtnact = digitalRead(abtnpin);
  bbtnact = digitalRead(bbtnpin);
  cbtnact = digitalRead(cbtnpin);
  dbtnact = digitalRead(dbtnpin);

  if (bbtnact == 0 && MODE == 0) {
    if (Displaysts == HIGH){
      Displaysts = LOW;
    } else if (Displaysts == LOW) {
      Displaysts = HIGH;
    }
  } else if (bbtnact == 0 && MODE != 0 && APP == 0) {
    openApp(MODE);
  }

  if (abtnact == 0 && Displaysts == HIGH && APP == 0) {
    MODE++;
  } else if (cbtnact == 0 && MODE != 0 && Displaysts == HIGH && APP == 0) {
    MODE--;
  }

  if (dbtnact == 0) {
    MODE = 0;
    APP = 0;
  }

  delay(200);

}
