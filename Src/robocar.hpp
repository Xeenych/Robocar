#ifndef __ROBOCAR_HPP__
#define __ROBOCAR_HPP__

#include "sonar.hpp"
#include "led2.hpp"
#include "buzzer.hpp"
#include "motor.hpp"
#include "BiSonar.hpp"

class Robocar {
public:
  Robocar();
  void Run();
private:
  Sonar SonarL; // левый сонар
  Sonar SonarR; // правый сонар
  BiSonar Bisonar;
  Led2 LedL; // левый светодиод
  Led2 LedR; // правый сведодиод
  Buzzer Buzz; // сирена
  Motor Steer; // моторчик поворота
  Motor Throttle; // моторчик скорости
};

#endif