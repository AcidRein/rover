#pragma once

class CurrentTemperature {
public:
  void temperatureChange(float value);
  float getTemperature() const;

private:
  float currentTemperature_ = 0.0f;
};
