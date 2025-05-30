#include "B4RDefines.h"

B4R::Serial* b4r_main::_serial1;
B4R::Pin* b4r_main::_mq7pin;
Byte b4r_main::_mq7pinnumber;
B4R::B4RESPWiFi* b4r_main::_wifi;
B4R::WiFiSocket* b4r_main::_wifistr;
B4R::MqttClient* b4r_main::_mqtt;
B4R::B4RString* b4r_main::_mqtthostname;
Int b4r_main::_mqttport;
B4R::B4RString* b4r_main::_wifissid;
B4R::B4RString* b4r_main::_wifipassword;
UInt b4r_main::_readvoltage;
B4R::B4RESP8266* b4r_main::_esp;
B4R::B4RString* b4r_main::_hostname;
B4R::B4RESP8266TimeTools* b4r_main::_timelib;
ULong b4r_main::_timestamp;
B4R::Pin* b4r_main::_pin16;
static B4R::Serial be_gann1_3;
static B4R::Pin be_gann2_3;
static B4R::B4RESPWiFi be_gann4_3;
static B4R::WiFiSocket be_gann5_3;
static B4R::MqttClient be_gann6_3;
static B4R::B4RString be_gann7_5;
static B4R::B4RString be_gann9_5;
static B4R::B4RString be_gann10_5;
static B4R::B4RESP8266 be_gann12_3;
static B4R::B4RString be_gann13_5;
static B4R::B4RESP8266TimeTools be_gann14_3;
static B4R::Pin be_gann16_3;


 void SetHostName(B4R::Object* o) {
	B4R::Array* b = (B4R::Array*)B4R::Object::toPointer(o);
	char* c = (char*)b->data;
	WiFi.hostname(c);
}

void stopAP (B4R::Object* u) {
	WiFi.softAPdisconnect(true);
}
void b4r_main::_appstart(){
const UInt cp = B4R::StackMemory::cp;
B4R::B4RString be_ann22_8;
B4R::Array* _bb = NULL;
B4R::Object be_ann23_6;
B4R::B4RString* _clientid = B4R::B4RString::EMPTY;
 //BA.debugLineNum = 51;BA.debugLine="Private Sub AppStart";
 //BA.debugLineNum = 52;BA.debugLine="Serial1.Initialize(115200)";
b4r_main::_serial1->Initialize((ULong) (115200));
 //BA.debugLineNum = 53;BA.debugLine="Delay(3000)";
Common_Delay((ULong) (3000));
 //BA.debugLineNum = 54;BA.debugLine="Log(\"AppStart\")";
B4R::Common::LogHelper(1,102,F("AppStart"));
 //BA.debugLineNum = 56;BA.debugLine="Dim bb() As Byte = \"LivingRoomMQ7\"";
_bb = (be_ann22_8.wrap("LivingRoomMQ7"))->GetBytes();
 //BA.debugLineNum = 57;BA.debugLine="RunNative(\"SetHostName\", bb)";
Common_RunNative(SetHostName,be_ann23_6.wrapPointer(_bb));
 //BA.debugLineNum = 58;BA.debugLine="RunNative(\"stopAP\", Null)";
Common_RunNative(stopAP,Common_Null);
 //BA.debugLineNum = 60;BA.debugLine="pin16.Initialize(16, pin16.MODE_OUTPUT)";
b4r_main::_pin16->Initialize((Byte) (16),Pin_MODE_OUTPUT);
 //BA.debugLineNum = 63;BA.debugLine="ConnectToWifi";
_connecttowifi();
 //BA.debugLineNum = 66;BA.debugLine="Dim ClientId As String = Rnd(0, 999999999) 'creat";
_clientid = B4R::B4RString::fromNumber((Long)(Common_Rnd((Long) (0),(Long) (999999999))));
 //BA.debugLineNum = 67;BA.debugLine="MQTT.Initialize2(WiFiStr.stream, MQTTHostName, MQ";
b4r_main::_mqtt->Initialize2(b4r_main::_wifistr->getStream(),b4r_main::_mqtthostname,(UInt) (b4r_main::_mqttport),_clientid,_mqtt_messagearrived,_mqtt_disconnected);
 //BA.debugLineNum = 68;BA.debugLine="MQTT_Connect(0)";
_mqtt_connect((Byte) (0));
 //BA.debugLineNum = 69;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_connecttowifi(){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 178;BA.debugLine="Sub ConnectToWifi";
 //BA.debugLineNum = 179;BA.debugLine="If WiFi.IsConnected Then";
if (b4r_main::_wifi->getIsConnected()) { 
 //BA.debugLineNum = 180;BA.debugLine="Log(\"Connected to \",WiFiSSID,\" network, Local IP";
B4R::Common::LogHelper(4,102,F("Connected to "),101,b4r_main::_wifissid->data,102,F(" network, Local IP "),101,b4r_main::_wifi->getLocalIp()->data);
 }else {
 //BA.debugLineNum = 182;BA.debugLine="pin16.DigitalWrite(True)";
b4r_main::_pin16->DigitalWrite(Common_True);
 //BA.debugLineNum = 183;BA.debugLine="Log(\"Connecting to WiFi\")";
B4R::Common::LogHelper(1,102,F("Connecting to WiFi"));
 //BA.debugLineNum = 184;BA.debugLine="If WiFi.Connect2(WiFiSSID, WiFiPassword) = False";
if (b4r_main::_wifi->Connect2(b4r_main::_wifissid,b4r_main::_wifipassword)==Common_False) { 
 //BA.debugLineNum = 185;BA.debugLine="ConnectToWifi";
_connecttowifi();
 };
 };
 //BA.debugLineNum = 188;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_mqtt_connect(Byte _unused){
const UInt cp = B4R::StackMemory::cp;
B4R::B4RString be_ann88_4;
 //BA.debugLineNum = 128;BA.debugLine="Sub MQTT_Connect(Unused As Byte)";
 //BA.debugLineNum = 129;BA.debugLine="If WiFi.IsConnected = False Then";
if (b4r_main::_wifi->getIsConnected()==Common_False) { 
 //BA.debugLineNum = 130;BA.debugLine="ConnectToWifi";
_connecttowifi();
 };
 //BA.debugLineNum = 133;BA.debugLine="If MQTT.Connect = False Then";
if (b4r_main::_mqtt->Connect()==Common_False) { 
 //BA.debugLineNum = 134;BA.debugLine="pin16.DigitalWrite(True)";
b4r_main::_pin16->DigitalWrite(Common_True);
 //BA.debugLineNum = 135;BA.debugLine="Log(\"Connecting to broker\")";
B4R::Common::LogHelper(1,102,F("Connecting to broker"));
 //BA.debugLineNum = 136;BA.debugLine="MQTT.Connect";
b4r_main::_mqtt->Connect();
 //BA.debugLineNum = 137;BA.debugLine="CallSubPlus(\"MQTT_Connect\", 1000, 0)";
B4R::__c->CallSubPlus(_mqtt_connect,(ULong) (1000),(Byte) (0));
 }else {
 //BA.debugLineNum = 139;BA.debugLine="pin16.DigitalWrite(False)";
b4r_main::_pin16->DigitalWrite(Common_False);
 //BA.debugLineNum = 140;BA.debugLine="Log(\"Connected to broker\")";
B4R::Common::LogHelper(1,102,F("Connected to broker"));
 //BA.debugLineNum = 141;BA.debugLine="MQTT.Subscribe(\"MQ7LivingRoomCloyd\", 0)";
b4r_main::_mqtt->Subscribe(be_ann88_4.wrap("MQ7LivingRoomCloyd"),(Byte) (0));
 //BA.debugLineNum = 142;BA.debugLine="ReadSensor";
_readsensor();
 };
 //BA.debugLineNum = 144;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_mqtt_disconnected(){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 171;BA.debugLine="Sub mqtt_Disconnected";
 //BA.debugLineNum = 172;BA.debugLine="pin16.DigitalWrite(True)";
b4r_main::_pin16->DigitalWrite(Common_True);
 //BA.debugLineNum = 173;BA.debugLine="Log(\"Disconnected from broker\")";
B4R::Common::LogHelper(1,102,F("Disconnected from broker"));
 //BA.debugLineNum = 174;BA.debugLine="MQTT.Close";
b4r_main::_mqtt->Close();
 //BA.debugLineNum = 175;BA.debugLine="MQTT_Connect(0)";
_mqtt_connect((Byte) (0));
 //BA.debugLineNum = 176;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_mqtt_messagearrived(B4R::B4RString* _topic,B4R::Array* _payload){
const UInt cp = B4R::StackMemory::cp;
B4R::Object be_ann93_8;
B4R::B4RString be_ann94_3;
B4R::B4RString be_ann95_3;
B4R::B4RString be_ann96_4;
B4R::B4RString* _s = B4R::B4RString::EMPTY;
B4R::B4RString be_ann100_12;
B4R::B4RString be_ann100_30;
B4R::B4RString be_ann100_48;
B4R::B4RString be_ann100_66;
B4R::B4RString be_ann100_84;
B4R::B4RString be_ann100_102;
B4R::B4RString* be_ann100_119e1[13];
B4R::Array be_ann100_119e2;
B4R::B4RString be_ann101_4;
B4R::B4RString be_ann103_3;
B4R::B4RString be_ann104_4;
B4R::B4RString be_ann104_6;
 //BA.debugLineNum = 146;BA.debugLine="Sub mqtt_MessageArrived (Topic As String, Payload(";
 //BA.debugLineNum = 147;BA.debugLine="Log(\"Message arrived. Topic=\", Topic, \" Payload=\"";
B4R::Common::LogHelper(4,102,F("Message arrived. Topic="),101,_topic->data,102,F(" Payload="),100,be_ann93_8.wrapPointer(_payload));
 //BA.debugLineNum = 149;BA.debugLine="If Topic = \"MQ7LivingRoomCloyd\" Then";
if ((_topic)->equals(be_ann94_3.wrap("MQ7LivingRoomCloyd"))) { 
 //BA.debugLineNum = 150;BA.debugLine="If Payload = \"Read voltage\" Then";
if ((_payload)->equals((be_ann95_3.wrap("Read voltage"))->GetBytes())) { 
 //BA.debugLineNum = 152;BA.debugLine="timelib.initialize(\"pool.ntp.org\",0)";
b4r_main::_timelib->initialize(be_ann96_4.wrap("pool.ntp.org"),0);
 //BA.debugLineNum = 153;BA.debugLine="timestamp = timelib.timestamp";
b4r_main::_timestamp = b4r_main::_timelib->timestamp();
 //BA.debugLineNum = 154;BA.debugLine="If timestamp <> 0 Then";
if (b4r_main::_timestamp!=0) { 
 //BA.debugLineNum = 155;BA.debugLine="Dim s As String";
_s = B4R::B4RString::EMPTY;
 //BA.debugLineNum = 156;BA.debugLine="s = JoinStrings(Array As String(readVoltage,\"|";
_s = B4R::__c->JoinStrings(be_ann100_119e2.create(be_ann100_119e1,13,100,B4R::B4RString::fromNumber((Long)(b4r_main::_readvoltage)),be_ann100_12.wrap("|"),B4R::__c->NumberFormat(b4r_main::_timelib->getyear(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann100_30.wrap("-"),B4R::__c->NumberFormat(b4r_main::_timelib->getmonth(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann100_48.wrap("-"),B4R::__c->NumberFormat(b4r_main::_timelib->getday(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann100_66.wrap("|"),B4R::__c->NumberFormat(b4r_main::_timelib->gethour(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann100_84.wrap(":"),B4R::__c->NumberFormat(b4r_main::_timelib->getminute(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann100_102.wrap(":"),B4R::__c->NumberFormat(b4r_main::_timelib->getseconds(b4r_main::_timestamp),(Byte) (2),(Byte) (0))));
 //BA.debugLineNum = 160;BA.debugLine="MQTT.Publish(\"MQ7LivingRoomCloyd\",s)";
b4r_main::_mqtt->Publish(be_ann101_4.wrap("MQ7LivingRoomCloyd"),(_s)->GetBytes());
 };
 }else if((_payload)->equals((be_ann103_3.wrap("Restart controller"))->GetBytes())) { 
 //BA.debugLineNum = 165;BA.debugLine="MQTT.Publish(\"MQ7LivingRoomCloyd\",\"Restarting c";
b4r_main::_mqtt->Publish(be_ann104_4.wrap("MQ7LivingRoomCloyd"),(be_ann104_6.wrap("Restarting controller by remote"))->GetBytes());
 //BA.debugLineNum = 166;BA.debugLine="ESP.Restart";
b4r_main::_esp->Restart();
 };
 };
 //BA.debugLineNum = 169;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_preparation1(Byte _tag){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 71;BA.debugLine="Sub Preparation1(tag As Byte)";
 //BA.debugLineNum = 72;BA.debugLine="Log(\"Turn the heater fully on\")";
B4R::Common::LogHelper(1,102,F("Turn the heater fully on"));
 //BA.debugLineNum = 73;BA.debugLine="MQ7Pin.AnalogWrite(1024) ' HIGH = 1024";
b4r_main::_mq7pin->AnalogWrite((UInt) (1024));
 //BA.debugLineNum = 74;BA.debugLine="Log(\"Heat for 1 min\")";
B4R::Common::LogHelper(1,102,F("Heat for 1 min"));
 //BA.debugLineNum = 75;BA.debugLine="CallSubPlus(\"Preparation2\",60000,0)";
B4R::__c->CallSubPlus(_preparation2,(ULong) (60000),(Byte) (0));
 //BA.debugLineNum = 76;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_preparation2(Byte _tag){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 78;BA.debugLine="Sub Preparation2(tag As Byte)";
 //BA.debugLineNum = 79;BA.debugLine="Log(\"Now reducing the heating power: turn the hea";
B4R::Common::LogHelper(1,102,F("Now reducing the heating power: turn the heater to approx 1.5V"));
 //BA.debugLineNum = 80;BA.debugLine="MQ7Pin.AnalogWrite(307.2) ' 1024x1500/5000; 1024";
b4r_main::_mq7pin->AnalogWrite((UInt) (307.2));
 //BA.debugLineNum = 81;BA.debugLine="Log(\"Heat for 90 sec\")";
B4R::Common::LogHelper(1,102,F("Heat for 90 sec"));
 //BA.debugLineNum = 82;BA.debugLine="CallSubPlus(\"ReadSensor1\",90000,0)";
B4R::__c->CallSubPlus(_readsensor1,(ULong) (90000),(Byte) (0));
 //BA.debugLineNum = 83;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}

void b4r_main::initializeProcessGlobals() {
     B4R::StackMemory::buffer = (byte*)malloc(STACK_BUFFER_SIZE);
     b4r_main::_process_globals();

   
}
void b4r_main::_process_globals(){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 32;BA.debugLine="Sub Process_Globals";
 //BA.debugLineNum = 33;BA.debugLine="Public Serial1 As Serial";
b4r_main::_serial1 = &be_gann1_3;
 //BA.debugLineNum = 34;BA.debugLine="Private MQ7Pin As Pin                 ' Output pi";
b4r_main::_mq7pin = &be_gann2_3;
 //BA.debugLineNum = 35;BA.debugLine="Private MQ7PinNumber As Byte = 0x00   ' Pin numbe";
b4r_main::_mq7pinnumber = (Byte) (0x00);
 //BA.debugLineNum = 36;BA.debugLine="Private WiFi As ESP8266WiFi";
b4r_main::_wifi = &be_gann4_3;
 //BA.debugLineNum = 37;BA.debugLine="Private WiFiStr As WiFiSocket";
b4r_main::_wifistr = &be_gann5_3;
 //BA.debugLineNum = 38;BA.debugLine="Private MQTT As MqttClient";
b4r_main::_mqtt = &be_gann6_3;
 //BA.debugLineNum = 39;BA.debugLine="Private MQTTHostName As String = \"mqtt.eclipsepro";
b4r_main::_mqtthostname = be_gann7_5.wrap("mqtt.eclipseprojects.io");
 //BA.debugLineNum = 40;BA.debugLine="Private MQTTPort As Int = 1883";
b4r_main::_mqttport = 1883;
 //BA.debugLineNum = 41;BA.debugLine="Private WiFiSSID As String = \"InternetOfThings\"";
b4r_main::_wifissid = be_gann9_5.wrap("InternetOfThings");
 //BA.debugLineNum = 42;BA.debugLine="Private WiFiPassword As String = \"SteelReserve\"";
b4r_main::_wifipassword = be_gann10_5.wrap("SteelReserve");
 //BA.debugLineNum = 43;BA.debugLine="Private readVoltage As UInt";
b4r_main::_readvoltage = 0;
 //BA.debugLineNum = 44;BA.debugLine="Private ESP As ESP8266";
b4r_main::_esp = &be_gann12_3;
 //BA.debugLineNum = 45;BA.debugLine="Private hostname As String = \"ESP8266_MQ7\" 'ignor";
b4r_main::_hostname = be_gann13_5.wrap("ESP8266_MQ7");
 //BA.debugLineNum = 46;BA.debugLine="Public timelib As ESPTimetools";
b4r_main::_timelib = &be_gann14_3;
 //BA.debugLineNum = 47;BA.debugLine="Public timestamp As ULong";
b4r_main::_timestamp = 0L;
 //BA.debugLineNum = 48;BA.debugLine="Private pin16 As Pin";
b4r_main::_pin16 = &be_gann16_3;
 //BA.debugLineNum = 49;BA.debugLine="End Sub";
}
void b4r_main::_readsensor(){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 190;BA.debugLine="Public Sub ReadSensor";
 //BA.debugLineNum = 193;BA.debugLine="MQ7Pin.Initialize(MQ7PinNumber, MQ7Pin.MODE_INPUT";
b4r_main::_mq7pin->Initialize(b4r_main::_mq7pinnumber,Pin_MODE_INPUT);
 //BA.debugLineNum = 194;BA.debugLine="Preparation1(0)";
_preparation1((Byte) (0));
 //BA.debugLineNum = 195;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_readsensor1(Byte _tag){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 85;BA.debugLine="Sub ReadSensor1(tag As Byte)";
 //BA.debugLineNum = 86;BA.debugLine="Log(\"We need to read the sensor at 5V, but must n";
B4R::Common::LogHelper(1,102,F("We need to read the sensor at 5V, but must not let it heat up. So hurry!"));
 //BA.debugLineNum = 87;BA.debugLine="MQ7Pin.AnalogWrite(1024)";
b4r_main::_mq7pin->AnalogWrite((UInt) (1024));
 //BA.debugLineNum = 88;BA.debugLine="Log(\"Delay for 50 milli\")";
B4R::Common::LogHelper(1,102,F("Delay for 50 milli"));
 //BA.debugLineNum = 89;BA.debugLine="CallSubPlus(\"ReadSensor2\",50,0) ' Getting an anal";
B4R::__c->CallSubPlus(_readsensor2,(ULong) (50),(Byte) (0));
 //BA.debugLineNum = 90;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_readsensor2(Byte _tag){
const UInt cp = B4R::StackMemory::cp;
UInt _rawvoltage = 0;
B4R::B4RString be_ann54_4;
B4R::B4RString* _s = B4R::B4RString::EMPTY;
B4R::B4RString be_ann58_12;
B4R::B4RString be_ann58_30;
B4R::B4RString be_ann58_48;
B4R::B4RString be_ann58_66;
B4R::B4RString be_ann58_84;
B4R::B4RString be_ann58_102;
B4R::B4RString* be_ann58_119e1[13];
B4R::Array be_ann58_119e2;
B4R::B4RString be_ann60_4;
 //BA.debugLineNum = 92;BA.debugLine="Sub ReadSensor2(tag As Byte)";
 //BA.debugLineNum = 93;BA.debugLine="Dim rawvoltage As UInt = MQ7Pin.AnalogRead / 2";
_rawvoltage = (UInt) (b4r_main::_mq7pin->AnalogRead()/(Double)2);
 //BA.debugLineNum = 95;BA.debugLine="Log(\"*************************\")";
B4R::Common::LogHelper(1,102,F("*************************"));
 //BA.debugLineNum = 96;BA.debugLine="Log(\"MQ-7 PPM: \",rawvoltage)";
B4R::Common::LogHelper(2,102,F("MQ-7 PPM: "),4,_rawvoltage);
 //BA.debugLineNum = 97;BA.debugLine="readVoltage = rawvoltage";
b4r_main::_readvoltage = _rawvoltage;
 //BA.debugLineNum = 100;BA.debugLine="timelib.initialize(\"pool.ntp.org\",0)";
b4r_main::_timelib->initialize(be_ann54_4.wrap("pool.ntp.org"),0);
 //BA.debugLineNum = 101;BA.debugLine="timestamp = timelib.timestamp";
b4r_main::_timestamp = b4r_main::_timelib->timestamp();
 //BA.debugLineNum = 102;BA.debugLine="If timestamp <> 0 Then";
if (b4r_main::_timestamp!=0) { 
 //BA.debugLineNum = 103;BA.debugLine="Dim s As String";
_s = B4R::B4RString::EMPTY;
 //BA.debugLineNum = 104;BA.debugLine="s = JoinStrings(Array As String(rawvoltage,\"|\",N";
_s = B4R::__c->JoinStrings(be_ann58_119e2.create(be_ann58_119e1,13,100,B4R::B4RString::fromNumber((Long)(_rawvoltage)),be_ann58_12.wrap("|"),B4R::__c->NumberFormat(b4r_main::_timelib->getyear(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann58_30.wrap("-"),B4R::__c->NumberFormat(b4r_main::_timelib->getmonth(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann58_48.wrap("-"),B4R::__c->NumberFormat(b4r_main::_timelib->getday(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann58_66.wrap("|"),B4R::__c->NumberFormat(b4r_main::_timelib->gethour(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann58_84.wrap(":"),B4R::__c->NumberFormat(b4r_main::_timelib->getminute(b4r_main::_timestamp),(Byte) (2),(Byte) (0)),be_ann58_102.wrap(":"),B4R::__c->NumberFormat(b4r_main::_timelib->getseconds(b4r_main::_timestamp),(Byte) (2),(Byte) (0))));
 //BA.debugLineNum = 107;BA.debugLine="Log(\"Sending ppm via MQTT: \",s)";
B4R::Common::LogHelper(2,102,F("Sending ppm via MQTT: "),101,_s->data);
 //BA.debugLineNum = 108;BA.debugLine="MQTT.Publish(\"MQ7LivingRoomCloyd\",s)";
b4r_main::_mqtt->Publish(be_ann60_4.wrap("MQ7LivingRoomCloyd"),(_s)->GetBytes());
 };
 //BA.debugLineNum = 112;BA.debugLine="If rawvoltage <= 100 Then";
if (_rawvoltage<=100) { 
 //BA.debugLineNum = 113;BA.debugLine="Log(\"Air-Quality: CO perfect\")";
B4R::Common::LogHelper(1,102,F("Air-Quality: CO perfect"));
 }else if(((_rawvoltage>100) && (_rawvoltage<400)) || _rawvoltage==400) { 
 //BA.debugLineNum = 115;BA.debugLine="Log(\"Air-Quality: CO normal\")";
B4R::Common::LogHelper(1,102,F("Air-Quality: CO normal"));
 }else if(((_rawvoltage>400) && (_rawvoltage<900)) || _rawvoltage==900) { 
 //BA.debugLineNum = 117;BA.debugLine="Log(\"Air-Quality: CO high\")";
B4R::Common::LogHelper(1,102,F("Air-Quality: CO high"));
 }else if(_rawvoltage>900) { 
 //BA.debugLineNum = 119;BA.debugLine="Log(\"Air-Quality: ALARM CO very high\")";
B4R::Common::LogHelper(1,102,F("Air-Quality: ALARM CO very high"));
 }else {
 //BA.debugLineNum = 121;BA.debugLine="Log(\"MQ-7 - cant read any value - check the sens";
B4R::Common::LogHelper(1,102,F("MQ-7 - cant read any value - check the sensor!"));
 };
 //BA.debugLineNum = 123;BA.debugLine="Log(\"*************************\")";
B4R::Common::LogHelper(1,102,F("*************************"));
 //BA.debugLineNum = 125;BA.debugLine="CallSubPlus(\"Preparation1\",1000,0)";
B4R::__c->CallSubPlus(_preparation1,(ULong) (1000),(Byte) (0));
 //BA.debugLineNum = 126;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
