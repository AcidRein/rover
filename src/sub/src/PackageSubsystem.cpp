/* Store incoming temperature changes */
#include "PackageSubsystem.hpp"

void CurrentTemperature::temperatureChange(float value) {
  currentTemperature_ += value;
}

float CurrentTemperature::getTemperature() const {
  return currentTemperature_;
}
