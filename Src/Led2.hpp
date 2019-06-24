#ifndef __LED_HPP__
#define __LED_HPP__

#include "stm32f1xx_ll_gpio.h"

class Led2 {
public:
  Led2(GPIO_TypeDef* _portR, uint32_t _PinMaskR, GPIO_TypeDef* _portG, uint32_t _PinMaskG);
  void SetR();
  void SetG();
  void SetY();
  void Set0();
private:  
  GPIO_TypeDef* portR;
  unsigned int PinMaskR;
  GPIO_TypeDef* portG;
  unsigned int PinMaskG;
};

#endif