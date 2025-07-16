/* 
This file will simulate a temperature receiver by returning random floats.
Floats are expected to increase between 0.1 - 2.0 celcius
*/

#include <random>
#include <ctime>

#include "PackageSubsystem.hpp"

float temperatureChange() {
    std::srand(std::time(0));
    float randFloat = (std::rand() % 20 + 1) / 10.0f; // Expected values: 0.1 - 2.0
    return randFloat; 
} 