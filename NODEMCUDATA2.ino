

#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h> 
const int trigPin = 4;  //D4
const int echoPin = 3;  //D3
const char *localhost = "192.168.43.234";


float duration;
int distance;
const char* ssid = "Sagar Mahajan";
const char* pwd = "Sagar12345";
WiFiServer server(80);  
void setup() 
{
      Serial.begin(115200); 
      Serial.write("a");
      delay(10);
      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
      
      Serial.write("Connecting to wifi ");
      Serial.println(ssid);
    
      WiFi.begin(ssid, pwd);
      
      
      while (WiFi.status() != WL_CONNECTED)
      {
        delay(500);
        Serial.print("."); 
      }
        Serial.println("");
    
        
        Serial.println("Wifi connected");  
        server.begin();     
        Serial.println("Server started.");
        Serial.print("This is your ip address: ");
        Serial.print("http://");
        Serial.print(WiFi.localIP());
    
}

void loop()
{       
         WiFiClient client = server.available();
        if (!client)
        {
          return;
        }
        
        Serial.print("testing");
        Serial.println("New client connection");
        while(!client.available())
        {
          delay(1);
        }
         
    
        digitalWrite(trigPin, LOW); 
        delayMicroseconds(2); 
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10); 
        digitalWrite(trigPin, LOW);
        
        duration = pulseIn(echoPin, HIGH);
        
        distance = duration * 0.0340 / 2;
        HTTPClient http;
        String url = "localhost/mydatabase/ultradisplay.php?distance="+12;
        Serial.println(url);     
            http.begin(url);
           
            
            int httpCode = http.GET();
            if(httpCode > 0)
            {
              Serial.printf("[HTTP] GET...code: %d\n", httpCode);
              if(httpCode == HTTP_CODE_OK)
              {
                  String payload = http.getString();
                  Serial.println(payload);
              }
           }
           else
           {
                Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
           }
              http.end();
              delay(3000); 
      
    
        
          
          
         
        
       
    }
    
