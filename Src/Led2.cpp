#include "led2.hpp"

Led2::Led2(GPIO_TypeDef* _portR, uint32_t _PinMaskR, GPIO_TypeDef* _portG, uint32_t _PinMaskG) {
  portR = _portR;
  portG = _portG;
  PinMaskR = _PinMaskR;
  PinMaskG = _PinMaskG;
  Set0();
}

void Led2::SetR() {
  LL_GPIO_SetOutputPin(portR, PinMaskR);
  LL_GPIO_ResetOutputPin(portG, PinMaskG);
}
void Led2::SetG() {
  LL_GPIO_SetOutputPin(portG, PinMaskG);
  LL_GPIO_ResetOutputPin(portR, PinMaskR);
}
void Led2::SetY() {
  LL_GPIO_SetOutputPin(portR, PinMaskR);
  LL_GPIO_SetOutputPin(portG, PinMaskG);
}
void Led2::Set0() {
  LL_GPIO_ResetOutputPin(portR, PinMaskR);
  LL_GPIO_ResetOutputPin(portG, PinMaskG);
}
