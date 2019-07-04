#include "B4RDefines.h"

B4R::Serial* b4r_main::_serial1;
B4R::Pin* b4r_main::_mq7pin;
Byte b4r_main::_mq7pinnumber;
B4R::B4RESPWiFi* b4r_main::_wifi;
B4R::WiFiSocket* b4r_main::_wifistr;
B4R::MqttClient* b4r_main::_mqtt;
B4R::MqttConnectOptions* b4r_main::_mqttopt;
B4R::B4RString* b4r_main::_mqttuser;
B4R::B4RString* b4r_main::_mqttpassword;
B4R::B4RString* b4r_main::_mqtthostname;
Int b4r_main::_mqttport;
B4R::B4RString* b4r_main::_wifissid;
B4R::B4RString* b4r_main::_wifipassword;
UInt b4r_main::_readvoltage;
B4R::B4RESP8266* b4r_main::_esp;
B4R::B4RString* b4r_main::_hostname;
B4R::B4RESP8266TimeTools* b4r_main::_timelib;
ULong b4r_main::_timestamp;
b4r_timenist* b4r_main::_timenist;
static B4R::Serial be_gann1_3;
static B4R::Pin be_gann2_3;
static B4R::B4RESPWiFi be_gann4_3;
static B4R::WiFiSocket be_gann5_3;
static B4R::MqttClient be_gann6_3;
static B4R::MqttConnectOptions be_gann7_3;
static B4R::B4RString be_gann8_5;
static B4R::B4RString be_gann9_5;
static B4R::B4RString be_gann10_5;
static B4R::B4RString be_gann12_5;
static B4R::B4RString be_gann13_5;
static B4R::B4RESP8266 be_gann15_3;
static B4R::B4RString be_gann16_5;
static B4R::B4RESP8266TimeTools be_gann17_3;


 void b4r_main::_appstart(){
const UInt cp = B4R::StackMemory::cp;
B4R::B4RString* _clientid = B4R::B4RString::EMPTY;
 //BA.debugLineNum = 44;BA.debugLine="Private Sub AppStart";
 //BA.debugLineNum = 45;BA.debugLine="Serial1.Initialize(115200)";
b4r_main::_serial1->Initialize((ULong) (115200));
 //BA.debugLineNum = 46;BA.debugLine="Delay(3000)";
Common_Delay((ULong) (3000));
 //BA.debugLineNum = 47;BA.debugLine="Log(\"AppStart\")";
B4R::Common::LogHelper(1,102,F("AppStart"));
 //BA.debugLineNum = 50;BA.debugLine="ConnectToWifi";
_connecttowifi();
 //BA.debugLineNum = 53;BA.debugLine="Dim ClientId As String = Rnd(0, 999999999) 'creat";
_clientid = B4R::B4RString::fromNumber((Long)(Common_Rnd((Long) (0),(Long) (999999999))));
 //BA.debugLineNum = 54;BA.debugLine="MQTT.Initialize2(WiFiStr.stream, MQTTHostName, MQ";
b4r_main::_mqtt->Initialize2(b4r_main::_wifistr->getStream(),b4r_main::_mqtthostname,(UInt) (b4r_main::_mqttport),_clientid,_mqtt_messagearrived,_mqtt_disconnected);
 //BA.debugLineNum = 55;BA.debugLine="MQTTOpt.Initialize(MQTTUser, MQTTPassword)";
b4r_main::_mqttopt->Initialize(b4r_main::_mqttuser,b4r_main::_mqttpassword);
 //BA.debugLineNum = 56;BA.debugLine="MQTT_Connect(0)";
_mqtt_connect((Byte) (0));
 //BA.debugLineNum = 57;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_connecttowifi(){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 164;BA.debugLine="Sub ConnectToWifi";
 //BA.debugLineNum = 165;BA.debugLine="Log(\"Connecting to WiFi\")";
B4R::Common::LogHelper(1,102,F("Connecting to WiFi"));
 //BA.debugLineNum = 166;BA.debugLine="If WiFi.Connect2(WiFiSSID, WiFiPassword) = False";
if (b4r_main::_wifi->Connect2(b4r_main::_wifissid,b4r_main::_wifipassword)==Common_False) { 
 //BA.debugLineNum = 167;BA.debugLine="ConnectToWifi";
_connecttowifi();
 };
 //BA.debugLineNum = 170;BA.debugLine="If WiFi.IsConnected Then";
if (b4r_main::_wifi->getIsConnected()) { 
 //BA.debugLineNum = 171;BA.debugLine="Log(\"Connected to \",WiFiSSID,\" network, Local IP";
B4R::Common::LogHelper(4,102,F("Connected to "),101,b4r_main::_wifissid->data,102,F(" network, Local IP "),101,b4r_main::_wifi->getLocalIp()->data);
 //BA.debugLineNum = 174;BA.debugLine="TimeIsAvailable";
_timeisavailable();
 }else {
 //BA.debugLineNum = 176;BA.debugLine="ConnectToWifi";
_connecttowifi();
 //BA.debugLineNum = 177;BA.debugLine="Log(\"Not Connected to WiFi\")";
B4R::Common::LogHelper(1,102,F("Not Connected to WiFi"));
 };
 //BA.debugLineNum = 179;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_mqtt_connect(Byte _unused){
const UInt cp = B4R::StackMemory::cp;
B4R::B4RString be_ann87_4;
 //BA.debugLineNum = 118;BA.debugLine="Sub MQTT_Connect(Unused As Byte)";
 //BA.debugLineNum = 119;BA.debugLine="If WiFi.IsConnected = False Then";
if (b4r_main::_wifi->getIsConnected()==Common_False) { 
 //BA.debugLineNum = 120;BA.debugLine="ConnectToWifi";
_connecttowifi();
 };
 //BA.debugLineNum = 123;BA.debugLine="If MQTT.Connect = False Then";
if (b4r_main::_mqtt->Connect()==Common_False) { 
 //BA.debugLineNum = 124;BA.debugLine="Log(\"Connecting to broker\")";
B4R::Common::LogHelper(1,102,F("Connecting to broker"));
 //BA.debugLineNum = 125;BA.debugLine="MQTT.Connect2(MQTTOpt)";
b4r_main::_mqtt->Connect2(b4r_main::_mqttopt);
 //BA.debugLineNum = 126;BA.debugLine="CallSubPlus(\"MQTT_Connect\", 1000, 0)";
B4R::__c->CallSubPlus(_mqtt_connect,(ULong) (1000),(Byte) (0));
 }else {
 //BA.debugLineNum = 128;BA.debugLine="Log(\"Connected to broker\")";
B4R::Common::LogHelper(1,102,F("Connected to broker"));
 //BA.debugLineNum = 129;BA.debugLine="MQTT.Subscribe(\"MQ7\", 0)";
b4r_main::_mqtt->Subscribe(be_ann87_4.wrap("MQ7"),(Byte) (0));
 };
 //BA.debugLineNum = 131;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_mqtt_disconnected(){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 158;BA.debugLine="Sub mqtt_Disconnected";
 //BA.debugLineNum = 159;BA.debugLine="Log(\"Disconnected from broker\")";
B4R::Common::LogHelper(1,102,F("Disconnected from broker"));
 //BA.debugLineNum = 160;BA.debugLine="MQTT.Close";
b4r_main::_mqtt->Close();
 //BA.debugLineNum = 161;BA.debugLine="MQTT_Connect(0)";
_mqtt_connect((Byte) (0));
 //BA.debugLineNum = 162;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_mqtt_messagearrived(B4R::B4RString* _topic,B4R::Array* _payload){
const UInt cp = B4R::StackMemory::cp;
B4R::Object be_ann91_8;
B4R::B4RString be_ann92_3;
B4R::B4RString be_ann93_3;
B4R::B4RString be_ann94_4;
B4R::B4RString* _s = B4R::B4RString::EMPTY;
B4R::B4RString be_ann98_12;
B4R::B4RString be_ann98_30;
B4R::B4RString be_ann98_48;
B4R::B4RString be_ann98_66;
B4R::B4RString be_ann98_84;
B4R::B4RString be_ann98_102;
B4R::B4RString* be_ann98_119e1[13];
B4R::Array be_ann98_119e2;
B4R::B4RString be_ann100_4;
B4R::B4RString be_ann103_3;
B4R::B4RString be_ann104_4;
B4R::B4RString be_ann104_6;
 //BA.debugLineNum = 133;BA.debugLine="Sub mqtt_MessageArrived (Topic As String, Payload(";
 //BA.debugLineNum = 134;BA.debugLine="Log(\"Message arrived. Topic=\", Topic, \" Payload=\"";
B4R::Common::LogHelper(4,102,F("Message arrived. Topic="),101,_topic->data,102,F(" Payload="),100,be_ann91_8.wrapPointer(_payload));
 //BA.debugLineNum = 136;BA.debugLine="If Topic = \"MQ7\" Then";
if ((_topic)->equals(be_ann92_3.wrap("MQ7"))) { 
 //BA.debugLineNum = 137;BA.debugLine="If Payload = \"Read voltage\" Then";
if ((_payload)->equals((be_ann93_3.wrap("Read voltage"))->GetBytes())) { 
 //BA.debugLineNum = 139;BA.debugLine="timelib.initialize(\"pool.ntp.org\",0)";
b4r_main::_timelib->initialize(be_ann94_4.wrap("pool.ntp.org"),0);
 //BA.debugLineNum = 140;BA.debugLine="timestamp = timelib.timestamp";
b4r_main::_timestamp = b4r_main::_timelib->timestamp();
 //BA.debugLineNum = 141;BA.debugLine="If timestamp <> 0 Then";
if (b4r_main::_timestamp!=0) { 
 //BA.debugLineNum = 142;BA.debugLine="Dim s As String";
_s = B4R::B4RString::EMPTY;
 //BA.debugLineNum = 143;BA.debugLine="s = JoinStrings(Array As String(readVoltage,\"|";
_s = B4R::__c->JoinStrings(be_ann98_119e2.create(be_ann98_119e1,13,100,B4R::B4RString::fromNumber((Long)(b4r_main::_readvoltage)),be_ann98_12.wrap("|"),B4R::__c->NumberFormat(b4r_main::_timelib->getyear(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann98_30.wrap("-"),B4R::__c->NumberFormat(b4r_main::_timelib->getmonth(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann98_48.wrap("-"),B4R::__c->NumberFormat(b4r_main::_timelib->getday(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann98_66.wrap("|"),B4R::__c->NumberFormat(b4r_main::_timelib->gethour(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann98_84.wrap(":"),B4R::__c->NumberFormat(b4r_main::_timelib->getminute(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann98_102.wrap(":"),B4R::__c->NumberFormat(b4r_main::_timelib->getseconds(b4r_main::_timestamp),(Byte) (2),(Byte) (0))));
 //BA.debugLineNum = 146;BA.debugLine="If WiFi.IsConnected Then";
if (b4r_main::_wifi->getIsConnected()) { 
 //BA.debugLineNum = 147;BA.debugLine="MQTT.Publish(\"MQ7\",s)";
b4r_main::_mqtt->Publish(be_ann100_4.wrap("MQ7"),(_s)->GetBytes());
 };
 };
 }else if((_payload)->equals((be_ann103_3.wrap("Restart controller"))->GetBytes())) { 
 //BA.debugLineNum = 152;BA.debugLine="MQTT.Publish(\"MQ7\",\"Restarting controller by re";
b4r_main::_mqtt->Publish(be_ann104_4.wrap("MQ7"),(be_ann104_6.wrap("Restarting controller by remote"))->GetBytes());
 //BA.debugLineNum = 153;BA.debugLine="ESP.Restart";
b4r_main::_esp->Restart();
 };
 };
 //BA.debugLineNum = 156;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_preparation1(Byte _tag){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 59;BA.debugLine="Sub Preparation1(tag As Byte)";
 //BA.debugLineNum = 60;BA.debugLine="Log(\"Turn the heater fully on\")";
B4R::Common::LogHelper(1,102,F("Turn the heater fully on"));
 //BA.debugLineNum = 61;BA.debugLine="MQ7Pin.AnalogWrite(1024) ' HIGH = 1024";
b4r_main::_mq7pin->AnalogWrite((UInt) (1024));
 //BA.debugLineNum = 62;BA.debugLine="Log(\"Heat for 1 min\")";
B4R::Common::LogHelper(1,102,F("Heat for 1 min"));
 //BA.debugLineNum = 63;BA.debugLine="CallSubPlus(\"Preparation2\",60000,0)";
B4R::__c->CallSubPlus(_preparation2,(ULong) (60000),(Byte) (0));
 //BA.debugLineNum = 64;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_preparation2(Byte _tag){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 66;BA.debugLine="Sub Preparation2(tag As Byte)";
 //BA.debugLineNum = 67;BA.debugLine="Log(\"Now reducing the heating power: turn the hea";
B4R::Common::LogHelper(1,102,F("Now reducing the heating power: turn the heater to approx 1.5V"));
 //BA.debugLineNum = 68;BA.debugLine="MQ7Pin.AnalogWrite(307.2) ' 1024x1500/5000; 1024";
b4r_main::_mq7pin->AnalogWrite((UInt) (307.2));
 //BA.debugLineNum = 69;BA.debugLine="Log(\"Heat for 90 sec\")";
B4R::Common::LogHelper(1,102,F("Heat for 90 sec"));
 //BA.debugLineNum = 70;BA.debugLine="CallSubPlus(\"ReadSensor1\",90000,0)";
B4R::__c->CallSubPlus(_readsensor1,(ULong) (90000),(Byte) (0));
 //BA.debugLineNum = 71;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}

void b4r_main::initializeProcessGlobals() {
     B4R::StackMemory::buffer = (byte*)malloc(STACK_BUFFER_SIZE);
     b4r_main::_process_globals();
b4r_timenist::_process_globals();

   
}
void b4r_main::_process_globals(){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 23;BA.debugLine="Sub Process_Globals";
 //BA.debugLineNum = 24;BA.debugLine="Public Serial1 As Serial";
b4r_main::_serial1 = &be_gann1_3;
 //BA.debugLineNum = 25;BA.debugLine="Private MQ7Pin As Pin                 ' Output pi";
b4r_main::_mq7pin = &be_gann2_3;
 //BA.debugLineNum = 26;BA.debugLine="Private MQ7PinNumber As Byte = 0x00   ' Pin numbe";
b4r_main::_mq7pinnumber = (Byte) (0x00);
 //BA.debugLineNum = 27;BA.debugLine="Private WiFi As ESP8266WiFi";
b4r_main::_wifi = &be_gann4_3;
 //BA.debugLineNum = 28;BA.debugLine="Private WiFiStr As WiFiSocket";
b4r_main::_wifistr = &be_gann5_3;
 //BA.debugLineNum = 29;BA.debugLine="Private MQTT As MqttClient";
b4r_main::_mqtt = &be_gann6_3;
 //BA.debugLineNum = 30;BA.debugLine="Private MQTTOpt As MqttConnectOptions";
b4r_main::_mqttopt = &be_gann7_3;
 //BA.debugLineNum = 31;BA.debugLine="Private MQTTUser As String = \"vynckfaq\"";
b4r_main::_mqttuser = be_gann8_5.wrap("vynckfaq");
 //BA.debugLineNum = 32;BA.debugLine="Private MQTTPassword As String = \"KHSV1Q1qSUUY\"";
b4r_main::_mqttpassword = be_gann9_5.wrap("KHSV1Q1qSUUY");
 //BA.debugLineNum = 33;BA.debugLine="Private MQTTHostName As String = \"m14.cloudmqtt.c";
b4r_main::_mqtthostname = be_gann10_5.wrap("m14.cloudmqtt.com");
 //BA.debugLineNum = 34;BA.debugLine="Private MQTTPort As Int = 11816";
b4r_main::_mqttport = 11816;
 //BA.debugLineNum = 35;BA.debugLine="Private WiFiSSID As String = \"RiseAboveThisHome\"";
b4r_main::_wifissid = be_gann12_5.wrap("RiseAboveThisHome");
 //BA.debugLineNum = 36;BA.debugLine="Private WiFiPassword As String = \"SteelReserve\"";
b4r_main::_wifipassword = be_gann13_5.wrap("SteelReserve");
 //BA.debugLineNum = 37;BA.debugLine="Private readVoltage As UInt";
b4r_main::_readvoltage = 0;
 //BA.debugLineNum = 38;BA.debugLine="Private ESP As ESP8266";
b4r_main::_esp = &be_gann15_3;
 //BA.debugLineNum = 39;BA.debugLine="Private hostname As String = \"ESP8266_MQ7\" 'ignor";
b4r_main::_hostname = be_gann16_5.wrap("ESP8266_MQ7");
 //BA.debugLineNum = 40;BA.debugLine="Public timelib As ESPTimetools";
b4r_main::_timelib = &be_gann17_3;
 //BA.debugLineNum = 41;BA.debugLine="Public timestamp As ULong";
b4r_main::_timestamp = 0L;
 //BA.debugLineNum = 42;BA.debugLine="End Sub";
}
void b4r_main::_readsensor1(Byte _tag){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 73;BA.debugLine="Sub ReadSensor1(tag As Byte)";
 //BA.debugLineNum = 74;BA.debugLine="Log(\"We need to read the sensor at 5V, but must n";
B4R::Common::LogHelper(1,102,F("We need to read the sensor at 5V, but must not let it heat up. So hurry!"));
 //BA.debugLineNum = 75;BA.debugLine="MQ7Pin.AnalogWrite(1024)";
b4r_main::_mq7pin->AnalogWrite((UInt) (1024));
 //BA.debugLineNum = 76;BA.debugLine="Log(\"Delay for 50 milli\")";
B4R::Common::LogHelper(1,102,F("Delay for 50 milli"));
 //BA.debugLineNum = 77;BA.debugLine="CallSubPlus(\"ReadSensor2\",50,0) ' Getting an anal";
B4R::__c->CallSubPlus(_readsensor2,(ULong) (50),(Byte) (0));
 //BA.debugLineNum = 78;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_readsensor2(Byte _tag){
const UInt cp = B4R::StackMemory::cp;
UInt _rawvoltage = 0;
B4R::B4RString be_ann53_4;
B4R::B4RString* _s = B4R::B4RString::EMPTY;
B4R::B4RString be_ann57_12;
B4R::B4RString be_ann57_30;
B4R::B4RString be_ann57_48;
B4R::B4RString be_ann57_66;
B4R::B4RString be_ann57_84;
B4R::B4RString be_ann57_102;
B4R::B4RString* be_ann57_119e1[13];
B4R::Array be_ann57_119e2;
B4R::B4RString be_ann60_4;
 //BA.debugLineNum = 80;BA.debugLine="Sub ReadSensor2(tag As Byte)";
 //BA.debugLineNum = 81;BA.debugLine="Dim rawvoltage As UInt = MQ7Pin.AnalogRead / 2";
_rawvoltage = (UInt) (b4r_main::_mq7pin->AnalogRead()/(Double)2);
 //BA.debugLineNum = 83;BA.debugLine="Log(\"*************************\")";
B4R::Common::LogHelper(1,102,F("*************************"));
 //BA.debugLineNum = 84;BA.debugLine="Log(\"MQ-7 PPM: \",rawvoltage)";
B4R::Common::LogHelper(2,102,F("MQ-7 PPM: "),4,_rawvoltage);
 //BA.debugLineNum = 85;BA.debugLine="readVoltage = rawvoltage";
b4r_main::_readvoltage = _rawvoltage;
 //BA.debugLineNum = 88;BA.debugLine="timelib.initialize(\"pool.ntp.org\",0)";
b4r_main::_timelib->initialize(be_ann53_4.wrap("pool.ntp.org"),0);
 //BA.debugLineNum = 89;BA.debugLine="timestamp = timelib.timestamp";
b4r_main::_timestamp = b4r_main::_timelib->timestamp();
 //BA.debugLineNum = 90;BA.debugLine="If timestamp <> 0 Then";
if (b4r_main::_timestamp!=0) { 
 //BA.debugLineNum = 91;BA.debugLine="Dim s As String";
_s = B4R::B4RString::EMPTY;
 //BA.debugLineNum = 92;BA.debugLine="s = JoinStrings(Array As String(rawvoltage,\"|\",N";
_s = B4R::__c->JoinStrings(be_ann57_119e2.create(be_ann57_119e1,13,100,B4R::B4RString::fromNumber((Long)(_rawvoltage)),be_ann57_12.wrap("|"),B4R::__c->NumberFormat(b4r_main::_timelib->getyear(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann57_30.wrap("-"),B4R::__c->NumberFormat(b4r_main::_timelib->getmonth(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann57_48.wrap("-"),B4R::__c->NumberFormat(b4r_main::_timelib->getday(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann57_66.wrap("|"),B4R::__c->NumberFormat(b4r_main::_timelib->gethour(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann57_84.wrap(":"),B4R::__c->NumberFormat(b4r_main::_timelib->getminute(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann57_102.wrap(":"),B4R::__c->NumberFormat(b4r_main::_timelib->getseconds(b4r_main::_timestamp),(Byte) (2),(Byte) (0))));
 //BA.debugLineNum = 95;BA.debugLine="Log(\"Sending ppm via MQTT: \",s)";
B4R::Common::LogHelper(2,102,F("Sending ppm via MQTT: "),101,_s->data);
 //BA.debugLineNum = 96;BA.debugLine="If WiFi.IsConnected Then";
if (b4r_main::_wifi->getIsConnected()) { 
 //BA.debugLineNum = 97;BA.debugLine="MQTT.Publish(\"MQ7\",s)";
b4r_main::_mqtt->Publish(be_ann60_4.wrap("MQ7"),(_s)->GetBytes());
 };
 };
 //BA.debugLineNum = 102;BA.debugLine="If rawvoltage <= 100 Then";
if (_rawvoltage<=100) { 
 //BA.debugLineNum = 103;BA.debugLine="Log(\"Air-Quality: CO perfect\")";
B4R::Common::LogHelper(1,102,F("Air-Quality: CO perfect"));
 }else if(((_rawvoltage>100) && (_rawvoltage<400)) || _rawvoltage==400) { 
 //BA.debugLineNum = 105;BA.debugLine="Log(\"Air-Quality: CO normal\")";
B4R::Common::LogHelper(1,102,F("Air-Quality: CO normal"));
 }else if(((_rawvoltage>400) && (_rawvoltage<900)) || _rawvoltage==900) { 
 //BA.debugLineNum = 107;BA.debugLine="Log(\"Air-Quality: CO high\")";
B4R::Common::LogHelper(1,102,F("Air-Quality: CO high"));
 }else if(_rawvoltage>900) { 
 //BA.debugLineNum = 109;BA.debugLine="Log(\"Air-Quality: ALARM CO very high\")";
B4R::Common::LogHelper(1,102,F("Air-Quality: ALARM CO very high"));
 }else {
 //BA.debugLineNum = 111;BA.debugLine="Log(\"MQ-7 - cant read any value - check the sens";
B4R::Common::LogHelper(1,102,F("MQ-7 - cant read any value - check the sensor!"));
 };
 //BA.debugLineNum = 113;BA.debugLine="Log(\"*************************\")";
B4R::Common::LogHelper(1,102,F("*************************"));
 //BA.debugLineNum = 115;BA.debugLine="CallSubPlus(\"Preparation1\",1000,0)";
B4R::__c->CallSubPlus(_preparation1,(ULong) (1000),(Byte) (0));
 //BA.debugLineNum = 116;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_timeisavailable(){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 181;BA.debugLine="Public Sub TimeIsAvailable";
 //BA.debugLineNum = 184;BA.debugLine="MQ7Pin.Initialize(MQ7PinNumber, MQ7Pin.MODE_INPUT";
b4r_main::_mq7pin->Initialize(b4r_main::_mq7pinnumber,Pin_MODE_INPUT);
 //BA.debugLineNum = 185;BA.debugLine="Preparation1(0)";
_preparation1((Byte) (0));
 //BA.debugLineNum = 186;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
