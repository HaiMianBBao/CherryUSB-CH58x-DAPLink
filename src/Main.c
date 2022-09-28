#include "CH58x_common.h"

void DebugInit(void)
{
    GPIOA_SetBits(GPIO_Pin_9);
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA);
    UART1_DefInit();
}

void usb_dc_low_level_init(void)
{
    DelayMs(100);
    PFIC_EnableIRQ(USB_IRQn);
}
int main()
{
    SetSysClock(CLK_SOURCE_PLL_80MHz);
    DebugInit();
    printf("CherryUSB CH58x DAPLink Demo \r\n");
    SysTick_Config(SysTick_LOAD_RELOAD_Msk);
    extern int dap_main(void);
    dap_main();
    while(1)
    {
    }
}
