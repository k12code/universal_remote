#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <IRremoteESP8266.h>
#include <IRsend.h>

#define IR_SEND_PIN D2    // change pin according to your circuit
#define DELAY_BETWEEN_COMMANDS 1000
#define TX_FREQ 38

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

// Raw data obtained from ir_recv_dump sketch
uint16_t tvOnData[71] = {9172, 4544,  606, 566,  582, 564,  582, 566,  580, 566,  582, 566,  582, 566,  580, 566,  582, 566,  580, 1688,  580, 1688,  580, 1688,  580, 1688,  580, 1688,  580, 1688,  580, 1688,  580, 1688,  580, 566,  580, 1688,  580, 1688,  580, 566,  582, 1686,  582, 566,  582, 564,  582, 564,  580, 1688,  580, 566,  580, 566,  582, 1688,  580, 566,  580, 1688,  580, 1686,  580, 1688,  580, 40442,  9182, 2268,  586};

uint16_t tvOffData[73] = {4494, 4458,  600, 574,  574, 1676,  574, 1674,  574, 1676,  574, 574,  572, 576,  572, 576,  572, 580,  572, 574,  572, 1676,  574, 1676,  574, 1676,  574, 574,  574, 574,  572, 574,  574, 578,  574, 574,  572, 576,  572, 1676,  574, 1676,  572, 576,  574, 576,  572, 574,  574, 578,  572, 1676,  574, 1674,  572, 576,  568, 580,  568, 1680,  570, 1680,  572, 1678,  572, 1678,  572, 45592,  4494, 4454,  600, 1672,  572};

IRsend irsend(IR_SEND_PIN);

BLYNK_WRITE(V0) {
  //int pinValue = param.asInt();

  irsend.sendRaw(tvOnData, 71, TX_FREQ);    // here, 71 must match tvOnData array length
  Serial.println("TV ON");
}

BLYNK_WRITE(V1) {
  irsend.sendRaw(tvOffData, 73, TX_FREQ);    // here, 73 must match tvOffData array length
  Serial.println("TV OFF");
}

void setup(void) {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  irsend.begin();
}

void loop() {
  Blynk.run();
}
