#include "stm32f10x.h"                  // Device header
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM

void  gpioConfig(){
	
      GPIO_InitTypeDef GPIOInitStructure;
	
	    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); 
	 
	    GPIOInitStructure.GPIO_Mode = GPIO_Mode_AF_PP;               
	    GPIOInitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;  //tim2 channell    
	    GPIOInitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	    GPIO_Init(GPIOA,&GPIOInitStructure);

}


void timerConfig(){
  
      TIM_TimeBaseInitTypeDef TIMERInitStructure;
	
	    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	    TIMERInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;                   
	    TIMERInitStructure.TIM_CounterMode = TIM_CounterMode_Up;    
	    TIMERInitStructure.TIM_Period = 4799;                       
	    TIMERInitStructure.TIM_Prescaler = 100;                    
	
	    TIM_TimeBaseInit(TIM2,&TIMERInitStructure);
      TIM_Cmd(TIM2,ENABLE);
	
}

void pwmConfig(uint32_t timPulse){

      TIM_OCInitTypeDef TIMER_OCInitStructure;
	    
	    TIMER_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;                  //PWM1 %75 high ile baslar , PWM2 ise %25 high ile baslar . 
      TIMER_OCInitStructure.TIM_OCNPolarity = TIM_OCPolarity_High;         //yukardakiyle ayni mantik biz yüksek baslamasini sagladik.
      TIMER_OCInitStructure.TIM_OutputState =  TIM_OutputState_Enable;
	    TIMER_OCInitStructure.TIM_Pulse = timPulse;
	
	    TIM_OC1Init(TIM2,&TIMER_OCInitStructure);
	    TIM_OC1PreloadConfig(TIM2,TIM_OCPreload_Enable);
	
}

void delay(uint32_t time){
 
   while(time--);

}


int main(){
	
	  gpioConfig();
	  timerConfig();

    while(1){
		
		pwmConfig(359);    //0 derece
		delay(7200000);
		pwmConfig(480);    //90 derece
		delay(7200000);
		pwmConfig(240);    //180 derece
		delay(7200000);
		pwmConfig(1799); 
//		pwmConfig(359);    //0 derece
//		delay(7200000);
//		pwmConfig(480);    //90 derece
//		delay(7200000);
//		pwmConfig(240);    //180 derece
//		delay(7200000);s
		
		}

}


