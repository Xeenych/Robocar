#ifndef __BISONAR_HPP__
#define __BISONAR_HPP__

#include "Sonar.hpp"

typedef struct {
  float L;
  float R;
} BiSonarData;

class BiSonar {
public:
  BiSonar(Sonar* _L, Sonar* _R);
  BiSonarData Trigger();
  BiSonarData Trigger2();
private:
  Sonar* L;
  Sonar* R;
};

#endif