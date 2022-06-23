#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_TEMPLATE_ID "TMPLnRt1R9Qz"
#define BLYNK_DEVICE_NAME "Tugas Akhir IoT"
#define BLYNK_AUTH_TOKEN "tx54DfyoEDp7B0UpJvFxnNpbHveiLpc7"
#define but 16
#define pot A0

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";
char pass[] = "";

BlynkTimer timer;

void myTimerEvent()
{
    Blynk.virtualWrite(V5, millis() / 1000);
}

void setup()
{
    // Debug console
    Serial.begin(115200);
    pinMode(push_button, INPUT_PULLUP);
    analogReference(DEFAULT);
    Blynk.begin(auth, ssid, pass);
    timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
    int butData = digitalRead(but);
    int potData = analogRead(pot);
    Serial.println("Push Button : " + String(butData));
    Serial.println("Potensio    : " + String(potData));
    Blynk.virtualWrite(V0, potData);
    Blynk.virtualWrite(V1, butData);
    if (potData > 800)
        Blynk.virtualWrite(V2, 1);
    else
        Blynk.virtualWrite(V2, 0);
    Blynk.run();
    timer.run(); // Initiates BlynkTimer
}
