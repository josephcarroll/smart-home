#include "esphome.h"
#include <Wire.h>
#include "Adafruit_MCP9808.h"

class Mcp9808Sensor : public PollingComponent, public Sensor {
 public:

  Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

  // constructor
  Mcp9808Sensor() : PollingComponent(300000) {}

  void setup() override {
    tempsensor.begin(0x18);
    tempsensor.wake();
  }
  void update() override {
    float c = tempsensor.readTempC();
    publish_state(c);
  }
};