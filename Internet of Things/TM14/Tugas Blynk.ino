#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_TEMPLATE_ID "TMPLnRt1R9Qz"
#define BLYNK_DEVICE_NAME "Tugas Akhir IoT"
#define BLYNK_AUTH_TOKEN "tx54DfyoEDp7B0UpJvFxnNpbHveiLpc7"
#define push_button 0
#define pot A0

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "nara";
char pass[] = "00000000";

BlynkTimer timer;

void myTimerEvent()
{
    // You can send any value at any time.
    // Please don't send more that 10 values per second.
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
    int data = digitalRead(push_button);
    int pot_data = analogRead(pot);
    Serial.println("PB : " + String(data));
    Serial.println("Pot : " + String(pot_data));
    Blynk.virtualWrite(V0, pot_data);
    Blynk.virtualWrite(V1, data);
    if (pot_data > 800)
        Blynk.virtualWrite(V2, 1);
    else
        Blynk.virtualWrite(V2, 0);
    Blynk.run();
    timer.run(); // Initiates BlynkTimer
}
