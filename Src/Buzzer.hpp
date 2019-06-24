#ifndef __BUZZER_HPP__
#define __BUZZER_HPP__


#include "stm32f1xx_ll_tim.h"

class Buzzer {
public:
  Buzzer(TIM_TypeDef* _TIMx, uint32_t _Channelp);
  void Buzz(unsigned int tone);
  void Run();
  void Enable();
  void Disable();
private:
  TIM_TypeDef* TIM;
  uint32_t Channel;
  int cycle;
  int step;
  int enabled;
};

#endif