#include <MQTT_ESP8266.h>

const char *MQTT_TOPICS[] = {"dummyPub", "Day"};
uint8_t topicsSize = sizeof(MQTT_TOPICS) / sizeof(MQTT_TOPICS[0]);

const char *topicName = {"Day"};
char topicPayload[] = {"Monday is terrible!"};
const uint16_t sizeT = sizeof(topicPayload) / sizeof(topicPayload[0]);

void setup()
{
  Serial.begin(115200);

  MQTTMakeConnection(); // build a mqtt connnection with the mqtt broker
  delay(500);
  subscribeTopic(MQTT_TOPICS, topicsSize);
}

void loop()
{
  publisheMsg(topicName, topicPayload, sizeT, true);
  MQTT_stayAwake();                    // Maintaining regularly connection to the server for incoming messages
  MQTT_check(MQTT_TOPICS, topicsSize); // reconnect with the MQTT Broker, if the connection is broken or lost
}
