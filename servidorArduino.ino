// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPL4pbo_RsB"
#define BLYNK_DEVICE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "AGcW8gpOa2Rfw_VNsOhpwT66JaKyfsR_"

#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#define DHTPIN D2
#define DHTTYPE DHT11

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "iPhone";
char pass[] = "hola1234";


BlynkTimer timer;


const int LDR = A0;

float t;
float h;
float f;
int valor;

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  pinMode(LDR,INPUT);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  Serial.print("Conectando...");
  while (WiFi.status()!= WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Conexión OK!");
  Serial.print("IP Local: ");
  Serial.println(WiFi.localIP());
}



void loop()
{

  delay (1000);


  int a = analogRead(LDR);
  //Serial.println(a);
  valor = map(a, 0, 150, 0, 100); 
  Serial.print(valor); Serial.println(" % de luz");

   Blynk.virtualWrite(V8,valor);

}