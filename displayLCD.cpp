#include "displayCLD.h"
// #include <U8g2lib.h>
#include "displayresources.h"
#include "define.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "sensor.h"

#define Forte_Green 0x25F8

displayCLD::displayCLD(/* args */)
{
  this->bus = new Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCK, TFT_MOSI, TFT_MISO);
  this->display = new Arduino_ILI9341(this->bus, TFT_RESET);
}

displayCLD::~displayCLD()
{
}

void displayCLD::begin()
{
  this->display->begin();
  this->display->fillScreen(BLACK);
  this->display->setRotation(1);
  this->display->setUTF8Print(true);
}

void displayCLD::logoFortebiotech()
{
  this->display->fillScreen(BLACK);
  this->display->fillTriangle(80, 60, 132, 30, 132, 90, this->display->color565(16, 55, 50));
  this->display->fillTriangle(130, 100, 78, 70, 78, 130, this->display->color565(16, 55, 50));
  this->display->fillTriangle(88, 140, 132, 110, 132, 170, this->display->color565(16, 45, 20));
  this->display->fillTriangle(142, 30, 252, 10, 142, 68, this->display->color565(10, 30, 35));
  this->display->fillTriangle(142, 140, 142, 170, 192, 130, this->display->color565(16, 65, 30));
  this->display->setFont(u8g2_font_unifont_t_vietnamese1);
  this->display->setTextSize(2);
  this->display->setTextColor(this->display->color565(16, 55, 70));
  this->display->setCursor(150, 90);
  this->display->print("FORTE");
  this->display->setCursor(150, 120);
  this->display->print("BIOTECH");
  this->display->setFont(u8g2_font_helvB08_tf);
  this->display->setTextColor(Forte_Green);
  this->display->setTextSize(1);
  this->display->setCursor(80, 190);
  this->display->print("TEST   PRAWNS   WITH   RAPID");   
  this->display->setCursor(100, 220);
  this->display->print("PROFIT   NO   LIMIT");
  this->display->setCursor(5, 230);
  this->display->print("V1.0");
  this->display->setFont(u8g2_font_unifont_t_vietnamese1);
  delay(3000);
  dbg_display("logo thanh cong");
}

void displayCLD::screen_Start()
{
  this->display->fillScreen(BLACK);
  this->display->setTextSize(1);
  this->display->fillRect(108, 0, 108, 20, Forte_Green);
  this->display->setCursor(110, 15);
  this->display->setTextColor(BLACK);
  this->display->println("FORTE BIOTECH");
  this->display->drawBitmap(1, 1, logoFBT, 35, 34, Forte_Green);
  this->display->drawBitmap(285, 209, shrimp, 35, 29, Forte_Green);
  this->display->drawRect(0, 0, 320, 240, Forte_Green);
  this->display->drawRect(108, 0, 108, 20, Forte_Green);
  this->display->drawCircle(35, 110, 25, Forte_Green);
  this->display->fillCircle(35, 110, 20, Forte_Green);
  this->display->setTextSize(2);
  this->display->setTextColor(Forte_Green);
  this->display->setCursor(75, 100);
  this->display->println("Press Blue");
  this->display->setCursor(95, 140);
  this->display->print("to start");
  this->display->setTextSize(1);
  this->display->setCursor(5, 230);
  this->display->print("IP:192.168.1.4");    
    Serial.println("Nguyen Minh Tan");
    Serial.println("192.168.1.4");
  // dbg_display("Nhan nut do de bat dau");
  //   while (digitalRead(blueButton)) {} //NOTE: sua lai nut nhan
}

void displayCLD::read_screen(int step_)
{
  this->display->fillScreen(BLACK);
  this->display->setTextSize(2);
  this->display->setTextColor(Forte_Green);
  String current_measure;
  switch (step_)
  {
    case 0:
      current_measure = "ACT";
      break;
    case 1:
      current_measure = "EHP";
      break;
    case 2:
      current_measure = "EMS";
      break;
    case 3:
      current_measure = "WSSV";
      break;
  }
  this->display->setCursor(5, 30);
  this->display->print("Measured Sample: ");
  if (current_measure == "ACT")
  {
    this->display->setTextColor(GREEN);
  }
  else if (current_measure == "EHP")
  {
    this->display->setTextColor(BLUE);
  }
  else if (current_measure == "EMS")
  {
    this->display->setTextColor(RED);
  }
  else if (current_measure == "WSSV")
  {
    this->display->setTextColor(YELLOW);
  }
  this->display->println(current_measure);
  this->display->setTextColor(Forte_Green);
  this->display->setCursor(5, 80);
  this->display->println("Insert sample tube");
  this->display->drawRect(0, 0, 320, 240, Forte_Green);
  this->display->drawRect(185, 0, 135, 35, Forte_Green);
  this->display->drawRect(30, 140, 310, 80, RED);
  this->display->drawRect(29, 139, 310, 82, RED);
  for (int i = 0; i <= 310; i += 10)
  {
    static int x1 = 0, y1 = 100, x2 = 10, y2 = 110, y3 = 120;
    this->display->drawLine(x1 + i, y1, x2 + i, y2, PINK);
    this->display->drawLine(x1 + i, y3, x2 + i, y2, PINK);
  }
  this->display->drawCircle(55, 180, 22, RED);
  this->display->fillCircle(55, 180, 17, RED);
  this->display->setTextSize(2);
  this->display->setTextColor(RED);
  this->display->setCursor(90, 175);
  this->display->println("Press Red");
  this->display->setCursor(140, 205);
  this->display->print("to measure");
}

void displayCLD::waiting_Readsensor()
{
  // digitalWrite(ON_LED, HIGH);
  this->display->fillScreen(BLACK);
  this->display->drawBitmap(285, 1, logoFBT, 35, 34, Forte_Green);
  this->display->drawRect(0, 0, 320, 240, Forte_Green);
  this->display->setTextSize(3);
  this->display->setTextColor(RED);
  this->display->setCursor(15, 90);
  this->display->print("MEASURING");
  this->display->setTextSize(2);
  this->display->setTextColor(Forte_Green);
  this->display->setCursor(10 , 150);
  this->display->println("Please wait....");
  // this->display->setCursor(85, 180);
  // this->display->println("giây lát!!!");
  _sensor.flagReadSensor = true;
}

void displayCLD::prepare()
{
  this->display->fillScreen(BLACK);
  this->display->setTextSize(2);
  this->display->setTextColor(Forte_Green);
  this->display->setCursor(5, 60);
  this->display->println("Insert sample tube and close the lid");
   this->display->drawRect(0, 0, 320, 240, Forte_Green);
  // this->display->drawRect(185, 0, 135, 35, Forte_Green);
  this->display->drawRect(30, 140, 310, 80, RED);
this->display->drawRect(29, 139, 310, 82, RED);
  for (int i = 0; i <= 310; i += 10)
  {
    static int x1 = 0, y1 = 100, x2 = 10, y2 = 110, y3 = 120;
    this->display->drawLine(x1 + i, y1, x2 + i, y2, PINK);
    this->display->drawLine(x1 + i, y3, x2 + i, y2, PINK);
  }
  this->display->drawCircle(55, 180, 22, RED);
  this->display->fillCircle(55, 180, 17, RED);
  this->display->setTextSize(2);
  this->display->setTextColor(RED);
  this->display->setCursor(90, 175);
  this->display->println("Press Red");
  this->display->setCursor(90, 205);
  this->display->print("to measure #");
  this->display->print(this->couter);
 // this->display->print(" time");
}

void displayCLD::screen_Result()
{
  this->display->fillScreen(BLACK);
  this->display->setTextSize(2);
  this->display->setTextColor(YELLOW);
  this->display->setCursor(5, 35);
  this->display->printf("# %d measurement:", this->couter);
  this->display->setTextSize(7);
  this->display->setTextColor(RED);

  if (_sensor.result_Sensor[0][this->couter - 1] < 10)
    this->display->setCursor(135, 140);
  else if (_sensor.result_Sensor[0][this->couter - 1] < 100)
    this->display->setCursor(110, 140);
  else if (_sensor.result_Sensor[0][this->couter - 1] < 1000)
    this->display->setCursor(85, 140);
  else
    this->display->setCursor(50, 140);

  this->display->println(_sensor.result_Sensor[0][this->couter - 1]);

  this->display->setTextSize(1);
  this->display->setCursor(0, 190);
  this->display->setTextColor(Forte_Green);
  this->display->println("Blue: Redo");
  this->display->setTextColor(RED);
  this->display->println("Red: Continue");
  this->display->setTextColor(WHITE);
  this->display->println("White: Previous result");
}

void displayCLD::screen_Average_Result()
{
  this->display->fillScreen(BLACK);

  this->display->setTextSize(2);
  this->display->setTextColor(RED); // ong 1
  this->display->setCursor(1, 40);
  this->display->printf("#1 Time:  %d \n\r", _sensor.result_Sensor[0][0]);
  // this->display->setCursor(1, 100);
  this->display->printf("#2 Time:  %d \n\r", _sensor.result_Sensor[0][1]);
  // this->display->setCursor(1, 160);
  this->display->printf("#3 Time:  %d \n\r", _sensor.result_Sensor[0][2]);
  // this->display->setCursor(1, 220);
  this->display->setTextColor(YELLOW); // ong 1
  this->display->printf("Average: %d", _sensor.AverageResult[0]);

  this->display->setTextSize(1);
  this->display->setTextColor(Forte_Green); // ong 1
  this->display->setCursor(1, 230);
  this->display->print("Blue: Start over");
}

void displayCLD::screen_Calib()
{
  // dbg_display("nhan do calib, nhan xanh ket thuc, nhan trang de format");
  this->display->fillScreen(BLACK);
  this->display->setTextSize(2);
  this->display->setTextColor(WHITE);
  this->display->setCursor(30, 35);
  this->display->println("CALIBRATION MODE");
  this->display->setCursor(35, 80);
  this->display->print("Sample ");
  this->display->setTextColor(ORANGE);
  if (_sensor.typecalib == 0)
    this->display->print("highest");
  else
    this->display->print("lowest");

  this->display->setCursor(0, 190);
  this->display->setTextSize(1);
  this->display->setTextColor(Forte_Green);
  this->display->println("Blue: exit");
  this->display->setTextColor(RED);
  this->display->println("Red: calibrate");
  this->display->setTextColor(WHITE);
  this->display->println("White: delete calibration");
}

void displayCLD::waiting_Calib()
{
  this->display->fillScreen(BLACK);
  this->display->drawBitmap(285, 1, logoFBT, 35, 34, Forte_Green);
  this->display->drawRect(0, 0, 320, 240, Forte_Green);
  this->display->setTextSize(2);
  this->display->setTextColor(RED);
  this->display->setCursor(15, 90);
  this->display->print("CALIBRATING");
  this->display->setTextSize(2);
  this->display->setTextColor(Forte_Green);
  this->display->setCursor(15, 150);
  this->display->println("Please wait....");
  // this->display->setCursor(85, 180);
  // this->display->println("giây lát!!!");
}

void displayCLD::screen_Calib_Complete()
{
  this->display->fillScreen(BLACK);
  this->display->setTextSize(2);
  this->display->setTextColor(ORANGE);
  this->display->setCursor(35, 35);
  this->display->println("calibration mode");
  this->display->setTextSize(3);
  this->display->setCursor(45, 130);
  this->display->setTextColor(Forte_Green);
  this->display->println("Success");
  delay(3000);
}

void displayCLD::loop()
{
  if (this->changeScreen)
  {
    switch (this->type_infor)
    {
      case escreenStart:
        {
          dbg_display("escreenStart");
          this->screen_Start();
          _sensor.clear();
          break;
        }
      case ewaitingReadsensor:
        {
          dbg_display("ewaitingReadsensor");
          waiting_Readsensor();
          break;
        }

      case eprepare:
        {
          dbg_display("eprepare");
          this->prepare();
          break;
        }

      case escreenResult:
        {
          dbg_display("escreenResult lan %d", this->couter);
          this->screen_Result();
          break;
        }

      case escreenAverageResult:
        {
          dbg_display("escreenAverageResult");
          _sensor.Average_Result();
          this->screen_Average_Result();
          break;
        }

      case ecalibSensor:
        {
          dbg_display("ecalibSensor");
          this->screen_Calib();
          break;
        }

      default:
        break;
    }
    this->changeScreen = false;
  }
}

displayCLD _displayCLD;
