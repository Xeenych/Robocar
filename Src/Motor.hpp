#ifndef __MOTOR_HPP__
#define __MOTOR_HPP__

#include "stm32f1xx_ll_tim.h"
#include "stm32f1xx_ll_gpio.h"

class Motor {
public:
  Motor(TIM_TypeDef* _TIMx, uint32_t _Channel, uint16_t _top, uint16_t _center, uint16_t _offset);

  void SetSpeed(int16_t speed);
private:
  TIM_TypeDef* TIM;
  uint16_t top;
  uint16_t center;
  uint16_t offset;
  uint32_t Channel;
};

#endif