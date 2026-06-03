#include <WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

// ==================== WIFI ====================
const char* ssid = "HOME";
const char* password = 123456789;

// ==================== THINGSPEAK ====================
unsigned long channelID = 3204288;
const char* writeAPIKey = "A3QQMHLHXM7FM4TM";

WiFiClient client;

// ==================== PINS ====================
#define DHTPIN 4
#define DHTTYPE DHT11

#define LDR_PIN 33
#define MQ2_PIN 35

#define RED_LED 14
#define GREEN_LED 12
#define BUZZER 25

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BUZZER, LOW);

  dht.begin();

  Serial.println("Environmental Black Box Recorder");
  Serial.println("Connecting to WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  ThingSpeak.begin(client);
}

void loop()
{
  // ==================== READ SENSORS ====================

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int gasValue = analogRead(MQ2_PIN);
  int lightValue = analogRead(LDR_PIN);

  // ==================== DISPLAY VALUES ====================

  Serial.println("================================");

  Serial.print("Temperature : ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity    : ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Gas Level   : ");
  Serial.println(gasValue);

  Serial.print("Light Level : ");
  Serial.println(lightValue);

  // ==================== ALERT LOGIC ====================

  bool danger = false;

  if (temperature > 35)
    danger = true;

  if (gasValue > 1800)
    danger = true;

  if (lightValue < 1000)
    danger = true;

  if (danger)
  {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER, HIGH);

    Serial.println("ALERT DETECTED!");
  }
  else
  {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BUZZER, LOW);

    Serial.println("NORMAL CONDITION");
  }

  // ==================== THINGSPEAK ====================

  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.setField(3, gasValue);
  ThingSpeak.setField(4, lightValue);

  int response = ThingSpeak.writeFields(channelID, writeAPIKey);

  if (response == 200)
  {
    Serial.println("Data uploaded to ThingSpeak");
  }
  else
  {
    Serial.print("ThingSpeak Error Code: ");
    Serial.println(response);
  }

  Serial.println("================================");

  // ThingSpeak minimum update interval
  delay(20000);
}
