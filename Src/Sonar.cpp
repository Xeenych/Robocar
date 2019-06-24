#include "sonar.hpp"

Sonar::Sonar(GPIO_TypeDef* _port, uint32_t _PinMask, TIM_TypeDef* _TIMx, uint32_t _select) {
  port=_port;
  PinMask=_PinMask;
  TIM = _TIMx;
  select=_select;
  if (select==0) {
    ChannelA=LL_TIM_CHANNEL_CH1;
    ChannelB=LL_TIM_CHANNEL_CH2;
  }
  else {
    ChannelA=LL_TIM_CHANNEL_CH3;
    ChannelB=LL_TIM_CHANNEL_CH4;
  }
  LL_GPIO_SetOutputPin(port, PinMask);
  LL_TIM_EnableCounter(TIM);
  LL_TIM_CC_EnableChannel(TIM, ChannelA);
  LL_TIM_CC_EnableChannel(TIM, ChannelB);
  Output=2000.0;
}

// У датчика максимальное время ожидания импульса - 140мс = ~2245cm


void Sonar::Run() {
    if (LL_TIM_IsActiveFlag_CC2(TIM)) {
      LL_GPIO_SetOutputPin(port, PinMask);
      uint16_t ccr1 = LL_TIM_IC_GetCaptureCH1(TIM);
      uint16_t ccr2 = LL_TIM_IC_GetCaptureCH2(TIM);
      uint16_t delta = (uint16_t)(ccr2 - ccr1);
      float cm = 4.0 * delta * 340.0/2.0/10000.0; // счетчик по 4us
      Output=cm;
    }
    else {
      //LL_TIM_DisableCounter(TIM);
      //LL_TIM_SetCounter(TIM, 0);
      //LL_TIM_EnableCounter(TIM);
      LL_GPIO_ResetOutputPin(port, PinMask);
    }
}


void Sonar::Start() {
  LL_TIM_DisableCounter(TIM);
  LL_TIM_SetCounter(TIM, 0);
  LL_TIM_ClearFlag_CC1(TIM);
  LL_TIM_ClearFlag_CC2(TIM);
  LL_TIM_ClearFlag_CC3(TIM);
  LL_TIM_ClearFlag_CC4(TIM);
  LL_TIM_EnableCounter(TIM);
  LL_GPIO_ResetOutputPin(port, PinMask);
  
}

float Sonar::WaitResult() {
  const uint32_t infinity = 50000;
  uint16_t ccr1, ccr2;
  
  uint16_t cnt = LL_TIM_GetCounter(TIM);
    
  if (select==0) {
    while (!LL_TIM_IsActiveFlag_CC1(TIM)) {
      uint16_t counter = LL_TIM_GetCounter(TIM);
      if ((uint16_t)(counter - cnt)> infinity) {
        LL_GPIO_SetOutputPin(port, PinMask);
        return 1000.0;
      }
    }

    
    while (!LL_TIM_IsActiveFlag_CC2(TIM))
      if ((uint16_t)(LL_TIM_GetCounter(TIM) - cnt)> infinity) {
        LL_GPIO_SetOutputPin(port, PinMask);
        return 1000.0;
      }
    ccr1 = LL_TIM_IC_GetCaptureCH1(TIM);
    ccr2 = LL_TIM_IC_GetCaptureCH2(TIM);
  }
  else {
    while (!LL_TIM_IsActiveFlag_CC3(TIM))
      if ((uint16_t)(LL_TIM_GetCounter(TIM) - cnt)> infinity) {
        LL_GPIO_SetOutputPin(port, PinMask);
        return 1000.0;
      }
    while (!LL_TIM_IsActiveFlag_CC4(TIM))
      if ((uint16_t)(LL_TIM_GetCounter(TIM) - cnt)> infinity) {
        LL_GPIO_SetOutputPin(port, PinMask);
        return 1000.0;
      }
    ccr1 = LL_TIM_IC_GetCaptureCH3(TIM);
    ccr2 = LL_TIM_IC_GetCaptureCH4(TIM);
  }
  LL_GPIO_SetOutputPin(port, PinMask);
  uint16_t delta = (uint16_t)(ccr2 - ccr1);
  
  float cm = 4.0 * delta * 340.0/2.0/10000.0; // счетчик по 4us
  return cm;
}

float Sonar::Measure() {

  //LL_TIM_DisableCounter(TIM);
  //LL_TIM_SetCounter(TIM, 0);
  //LL_TIM_EnableCounter(TIM);

  Start();
  float res = WaitResult();
  return res;
  
}
