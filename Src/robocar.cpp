#include "main.h"
#include "robocar.hpp"


Robocar::Robocar() :
  SonarR(GPIOC, LL_GPIO_PIN_8, TIM4, 1), 
  SonarL(GPIOC, LL_GPIO_PIN_9, TIM4, 0), 
  LedL (GPIOA, LL_GPIO_PIN_9, GPIOA, LL_GPIO_PIN_8 ),
  LedR (GPIOA, LL_GPIO_PIN_11, GPIOA, LL_GPIO_PIN_10 ),
  Buzz (TIM2, LL_TIM_CHANNEL_CH1), 
  Steer (TIM3, LL_TIM_CHANNEL_CH1, 10000, 950, 200),
  Throttle (TIM8, LL_TIM_CHANNEL_CH1, 10000,0,10000),
  Bisonar (&SonarL, &SonarR) {
}


int cntSonar=0;
float data[50];

void Robocar::Run() {
  LL_TIM_IC_GetCaptureCH1(TIM4);
  LL_TIM_IC_GetCaptureCH2(TIM4);
  LL_TIM_IC_GetCaptureCH3(TIM4);
  LL_TIM_IC_GetCaptureCH4(TIM4);
    //while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)); // отсчитываем 1ms

    //SonarL.Run();
    //SonarR.Run();
    //float d = SonarL.Measure();
    BiSonarData result = Bisonar.Trigger2();;
    //for (int i=0;i<50;i++) {
      //result = Bisonar.Trigger2();
      //data[i] = result.R;
    //}

    
    if (result.L > 200)
      LedL.SetG();
    else if (result.L > 100)
      LedL.SetY();
    else
      LedL.SetR();
    
    if (result.R > 200)
      LedR.SetG();
    else if (result.R > 100)
      LedR.SetY();
    else
      LedR.SetR();
    
    Steer.SetSpeed(0);
    
    

    
    //BiSonarData result2 = Bisonar.Trigger();
    
    //LedL.SetG();
    //while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
    //LedL.SetR();
    //while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
    //while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
    //LedL.Set0();
    //Buzz.Enable();
    //Buzz.Run();
    /*
    for (int i=0;i<1000000;i++) {
      LL_GPIO_SetOutputPin(LEFT_G_GPIO_Port, LEFT_R_Pin);
      LL_GPIO_ResetOutputPin(LEFT_G_GPIO_Port, LEFT_G_Pin);
    }
    for (int i=0;i<1000000;i++) {
      LL_GPIO_SetOutputPin(LEFT_G_GPIO_Port, LEFT_G_Pin);
      LL_GPIO_SetOutputPin(LEFT_G_GPIO_Port, LEFT_R_Pin);
    }
    
    for (int i=0;i<1000000;i++) {
      LL_GPIO_ResetOutputPin(LEFT_G_GPIO_Port, LEFT_R_Pin);
      LL_GPIO_SetOutputPin(LEFT_G_GPIO_Port, LEFT_G_Pin);
    }*/
}