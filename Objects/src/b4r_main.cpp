#include "B4RDefines.h"

B4R::Serial* b4r_main::_serial1;
B4R::Pin* b4r_main::_mq7pin;
Byte b4r_main::_mq7pinnumber;
static B4R::Serial be_gann1_3;
static B4R::Pin be_gann2_3;


 void b4r_main::_appstart(){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 29;BA.debugLine="Private Sub AppStart";
 //BA.debugLineNum = 30;BA.debugLine="Serial1.Initialize(115200)";
b4r_main::_serial1->Initialize((ULong) (115200));
 //BA.debugLineNum = 31;BA.debugLine="Delay(3000)";
Common_Delay((ULong) (3000));
 //BA.debugLineNum = 32;BA.debugLine="Log(\"AppStart\")";
B4R::Common::LogHelper(1,102,F("AppStart"));
 //BA.debugLineNum = 35;BA.debugLine="MQ7Pin.Initialize(MQ7PinNumber, MQ7Pin.MODE_OUTPU";
b4r_main::_mq7pin->Initialize(b4r_main::_mq7pinnumber,Pin_MODE_OUTPUT);
 //BA.debugLineNum = 37;BA.debugLine="CheckAirQuality(0)";
_checkairquality((Byte) (0));
 //BA.debugLineNum = 38;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_checkairquality(Byte _tag){
const UInt cp = B4R::StackMemory::cp;
UInt _rawvoltage = 0;
 //BA.debugLineNum = 40;BA.debugLine="Sub CheckAirQuality(tag As Byte)";
 //BA.debugLineNum = 42;BA.debugLine="Log(\"Turn the heater fully on\")";
B4R::Common::LogHelper(1,102,F("Turn the heater fully on"));
 //BA.debugLineNum = 43;BA.debugLine="MQ7Pin.AnalogWrite(255) ' HIGH = 255";
b4r_main::_mq7pin->AnalogWrite((UInt) (255));
 //BA.debugLineNum = 44;BA.debugLine="Log(\"Heat for 1 min\")";
B4R::Common::LogHelper(1,102,F("Heat for 1 min"));
 //BA.debugLineNum = 45;BA.debugLine="Delay(60000)";
Common_Delay((ULong) (60000));
 //BA.debugLineNum = 46;BA.debugLine="Log(\"Now reducing the heating power: turn the hea";
B4R::Common::LogHelper(1,102,F("Now reducing the heating power: turn the heater to approx 1.4V"));
 //BA.debugLineNum = 47;BA.debugLine="MQ7Pin.AnalogWrite(71.4) ' 255x1400/5000";
b4r_main::_mq7pin->AnalogWrite((UInt) (71.4));
 //BA.debugLineNum = 48;BA.debugLine="Log(\"Heat for 90 sec\")";
B4R::Common::LogHelper(1,102,F("Heat for 90 sec"));
 //BA.debugLineNum = 49;BA.debugLine="Delay(90000)";
Common_Delay((ULong) (90000));
 //BA.debugLineNum = 52;BA.debugLine="Log(\"CO2 via MQ7: we need to read the sensor at 5";
B4R::Common::LogHelper(1,102,F("CO2 via MQ7: we need to read the sensor at 5V, but must not let it heat up. So hurry!"));
 //BA.debugLineNum = 53;BA.debugLine="MQ7Pin.AnalogWrite(255)";
b4r_main::_mq7pin->AnalogWrite((UInt) (255));
 //BA.debugLineNum = 54;BA.debugLine="Delay(50) ' Getting an analog read apparently tak";
Common_Delay((ULong) (50));
 //BA.debugLineNum = 55;BA.debugLine="Dim rawvoltage As UInt = MQ7Pin.AnalogRead";
_rawvoltage = b4r_main::_mq7pin->AnalogRead();
 //BA.debugLineNum = 58;BA.debugLine="Log(\"*************************\")";
B4R::Common::LogHelper(1,102,F("*************************"));
 //BA.debugLineNum = 59;BA.debugLine="Log(\"MQ-7 PPM: \",rawvoltage)";
B4R::Common::LogHelper(2,102,F("MQ-7 PPM: "),4,_rawvoltage);
 //BA.debugLineNum = 64;BA.debugLine="If rawvoltage <= 200 Then";
if (_rawvoltage<=200) { 
 //BA.debugLineNum = 65;BA.debugLine="Log(\"Air-Quality: CO perfect\")";
B4R::Common::LogHelper(1,102,F("Air-Quality: CO perfect"));
 }else if(((_rawvoltage>200) && (_rawvoltage<800)) || _rawvoltage==800) { 
 //BA.debugLineNum = 67;BA.debugLine="Log(\"Air-Quality: CO normal\")";
B4R::Common::LogHelper(1,102,F("Air-Quality: CO normal"));
 }else if(((_rawvoltage>800) && (_rawvoltage<1800)) || _rawvoltage==1800) { 
 //BA.debugLineNum = 69;BA.debugLine="Log(\"Air-Quality: CO high\")";
B4R::Common::LogHelper(1,102,F("Air-Quality: CO high"));
 }else if(_rawvoltage>1800) { 
 //BA.debugLineNum = 71;BA.debugLine="Log(\"Air-Quality: ALARM CO very high\")";
B4R::Common::LogHelper(1,102,F("Air-Quality: ALARM CO very high"));
 }else {
 //BA.debugLineNum = 73;BA.debugLine="Log(\"MQ-7 - cant read any value - check the sens";
B4R::Common::LogHelper(1,102,F("MQ-7 - cant read any value - check the sensor!"));
 };
 //BA.debugLineNum = 75;BA.debugLine="Log(\"*************************\")";
B4R::Common::LogHelper(1,102,F("*************************"));
 //BA.debugLineNum = 76;BA.debugLine="CallSubPlus(\"CheckAirQuality\",1000,0)";
B4R::__c->CallSubPlus(_checkairquality,(ULong) (1000),(Byte) (0));
 //BA.debugLineNum = 77;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}

void b4r_main::initializeProcessGlobals() {
     B4R::StackMemory::buffer = (byte*)malloc(STACK_BUFFER_SIZE);
     b4r_main::_process_globals();

   
}
void b4r_main::_process_globals(){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 23;BA.debugLine="Sub Process_Globals";
 //BA.debugLineNum = 24;BA.debugLine="Public Serial1 As Serial";
b4r_main::_serial1 = &be_gann1_3;
 //BA.debugLineNum = 25;BA.debugLine="Private MQ7Pin As Pin                 'Output pin";
b4r_main::_mq7pin = &be_gann2_3;
 //BA.debugLineNum = 26;BA.debugLine="Private MQ7PinNumber As Byte = 0x00   'Pin number";
b4r_main::_mq7pinnumber = (Byte) (0x00);
 //BA.debugLineNum = 27;BA.debugLine="End Sub";
}
