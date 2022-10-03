#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

char ssid[] = SECRET_SSID;    // Network SSID (name)
char pass[] = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)

// #define THING_ID "3367f4ce-18a7-4884-a6fd-b0070f967621"

void onLightChange();

bool toggle;
int angle;
bool light;

void initProperties(){
  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(toggle, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(angle, READ, ON_CHANGE, NULL, 3.000000);
  ArduinoCloud.addProperty(light, READWRITE, ON_CHANGE, onLightChange);
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(ssid, pass);
