#ifndef __SONAR_HPP__
#define __SONAR_HPP__

#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_tim.h"

class Sonar {
public:
  //Sonar();
  Sonar(GPIO_TypeDef* _port, uint32_t _PinMask, TIM_TypeDef* _TIMx, uint32_t _select);
  float Measure();
  void Start();
  float WaitResult();
  void Run();
  float Output;
  
private:
  GPIO_TypeDef* port;
  unsigned int PinMask;
  TIM_TypeDef* TIM;
  uint32_t ChannelA;
  uint32_t ChannelB;
  uint32_t select;
};

#endif