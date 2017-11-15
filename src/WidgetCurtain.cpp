#include "WidgetCurtain.h"


WidgetCurtain::WidgetCurtain(uint8_t ucItem)
{
    _Item = ucItem;
    memset(pCmdSwitchTopic,0,sizeof(pCmdSwitchTopic));
    memset(pDataStatusTopic,0,sizeof(pDataStatusTopic));
    sprintf(pCmdSwitchTopic,"channel/curtain_%d/cmd/switch",_Item);
    sprintf(pDataStatusTopic,"channel/curtain_%d/data/status",_Item);
}

WidgetCurtain::~WidgetCurtain()
{

}

void WidgetCurtain::begin(void (*UserCallBack)(void))
{
    _EventCb=UserCallBack;
    IntoRobot.subscribe(pCmdSwitchTopic, NULL, this);
}

char WidgetCurtain::getCurtainSwitch(void)
{
    return _switchKey;
}

void WidgetCurtain::displayCurtainStatus(uint8_t ucVal)
{
    IntoRobot.publish(pDataStatusTopic,ucVal);
}

void WidgetCurtain::control(uint8_t ucPin, uint8_t ucVal)
{
    pinMode(ucPin,OUTPUT);
    digitalWrite(ucPin, ucVal);
    displayCurtainStatus(ucVal);
}

void WidgetCurtain::widgetBaseCallBack(uint8_t *payload, uint32_t len)
{
 	if(payload[0] == '1')
	{
        _switchKey=1;
	}
	else
	{
        _switchKey=0;
	}
	_EventCb();
}
