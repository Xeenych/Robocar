#include "BiSonar.hpp"

BiSonar::BiSonar(Sonar* _L, Sonar* _R) {
  L=_L;
  R=_R;
}

BiSonarData BiSonar::Trigger() {
  BiSonarData ret;
  ret.R=R->Measure();
  ret.L=L->Measure();
  
  return ret;
}


BiSonarData BiSonar::Trigger2() {
  BiSonarData ret;
  R->Start();
  L->Start();

  ret.L=L->WaitResult();
  ret.R=R->WaitResult();
 
  return ret;
}