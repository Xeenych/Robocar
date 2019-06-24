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
  Sonar SonarL; // ����� �����
  Sonar SonarR; // ������ �����
  BiSonar Bisonar;
  Led2 LedL; // ����� ���������
  Led2 LedR; // ������ ���������
  Buzzer Buzz; // ������
  Motor Steer; // �������� ��������
  Motor Throttle; // �������� ��������
};

#endif