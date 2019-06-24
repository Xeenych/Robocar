#include "motor.hpp"


Motor::Motor(TIM_TypeDef* _TIMx, uint32_t _Channel, uint16_t _top, uint16_t _center, uint16_t _offset) {
  TIM=_TIMx;
  Channel=_Channel;
  top=_top;
  center=_center;
  offset=_offset;
  LL_TIM_SetAutoReload(TIM, top);
  LL_TIM_CC_EnableChannel(TIM, Channel);
  LL_TIM_EnableCounter(TIM);
  SetSpeed(0);
}

void Motor::SetSpeed(int16_t off) {
  if (off>offset)
    off = offset;
  if (off<-offset)
    off = -offset;
  
  //uint16_t abs = (off>=0)? off : -off;
  
  LL_TIM_OC_SetCompareCH1(TIM, center+off);
}