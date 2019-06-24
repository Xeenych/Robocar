#include "Buzzer.hpp"
#include <MAth.h>
Buzzer::Buzzer(TIM_TypeDef* _TIMx, uint32_t _Channel) {
  TIM=_TIMx;
  Channel=_Channel;
  LL_TIM_SetAutoReload(TIM, 1);
  LL_TIM_CC_EnableChannel(TIM, Channel);
  LL_TIM_EnableCounter(TIM);
  cycle=0;
  step=15;
  enabled=0;
}

void Buzzer::Buzz(unsigned int tone) {
  LL_TIM_OC_SetCompareCH1(TIM, tone/2);
  LL_TIM_SetAutoReload(TIM, tone);
}

void Buzzer::Disable() {
  enabled=0;
}

void Buzzer::Enable() {
  enabled=1;
}

void Buzzer::Run() {
  if (cycle>500)
    step = -2;
  if (cycle <= 0)
    step = 2;

  cycle+=step;
  if (enabled)
    Buzz(500 + (cycle)*2);
  else
    Buzz(0);
}