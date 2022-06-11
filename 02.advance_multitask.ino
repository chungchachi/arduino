#include <TridentTD_EasyFreeRTOS32.h>


TridentOS   DHT_task, Blink_task, WiFi_task, AsyncWebServer_task ,MPU6050_DMP6_Teapot ;
void DHT_func(void*), Blink_func(void*), WiFi_func(void*), AsyncWebServer_func(void*), MPU_func(void*);

int     xBlink_Delay;    
float   xDHT_temp;       
float   xDHT_humid;       
float   xax;
float   xay;
float   xaz;




void setup(){  
  Serial.begin(115200); Serial.println();
    
  DHT_task.start( DHT_func );
  MPU6050_DMP6_Teapot.start( MPU_func ); 
  WiFi_task.start( WiFi_func );  
}

void loop(){}  
