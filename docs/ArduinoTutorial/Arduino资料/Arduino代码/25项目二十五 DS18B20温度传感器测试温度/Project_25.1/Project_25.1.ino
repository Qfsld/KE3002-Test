#include <Wire.h>
#include <DallasTemperature.h>  //导入DS18B20的库

float val1;
float val2;
OneWire oneWire(3); //定义数字口3
DallasTemperature sensors(&oneWire);
DeviceAddress insideThermometer;

float ds18b20_getTemp(int w) 
{
  sensors.requestTemperatures();
  if (w == 0) 
  {
    return sensors.getTempC(insideThermometer);
  }
  else 
  {
    return sensors.getTempF(insideThermometer);
  }
}

void setup() 
{
  val1 = 0;
  val2 = 0;
  Serial.begin(9600);//设置波特率
  sensors.getAddress(insideThermometer, 0);
  sensors.setResolution(insideThermometer, 9);
}

void loop() 
{
  val1 = ds18b20_getTemp(0);//获取温度C
  val2 = ds18b20_getTemp(1);//获取温度F
  Serial.print(val1);
  Serial.print("C        ");
  Serial.print(val2);
  Serial.println("F");
  delay(100);
}
