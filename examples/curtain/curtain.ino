/*
 ************************************************************************
 * 作者:  IntoRobot Team
 * 版本:  V1.0.0
 * 日期:  03-30-15
 ************************************************************************
 功能描述：
 窗帘控制：

 所需器件:
 1.LED灯泡
 2.继电器模块

 接线说明:
 继电器模块
 1.DC+：                      +5V
 2.DC-：                      GND
 3.IN：                       D0
 4.NO：                       灯的正极
 5.COM：                      +5V
 6.NC：                       悬空
 7.触发选择端：选择跳线与high短接, 即高电平触发。
 */

#include <WidgetCurtain.h>

#define CONTROL_PIN    D0

WidgetCurtain curtain = WidgetCurtain();

void curtainSwitchCb(void)
{
    if(curtain.getCurtainSwitch())
    {
        curtain.control(CONTROL_PIN,1);	// 打开
    }
    else
    {
        curtain.control(CONTROL_PIN,0);	//关闭
    }
}

void setup()
{
    curtain.begin(curtainSwitchCb);
}

void loop()
{
}
