#include "B4RDefines.h"

B4R::Array* b4r_httpjob::_requestcache;
B4R::Array* b4r_httpjob::_responsecache;
Int b4r_httpjob::_responseindex;
B4R::Array* b4r_httpjob::_mjobname;
B4R::Array* b4r_httpjob::_mverb;
B4R::ByteConverter* b4r_httpjob::_bc;
bool b4r_httpjob::_ssl;
Int b4r_httpjob::_port;
Int b4r_httpjob::_hostindex;
Int b4r_httpjob::_hostlen;
Int b4r_httpjob::_pathindex;
Int b4r_httpjob::_pathlen;
Int b4r_httpjob::_payloadindex;
Int b4r_httpjob::_payloadlen;
Int b4r_httpjob::_headersindex;
Int b4r_httpjob::_headerslen;
B4R::AsyncStreams* b4r_httpjob::_astream;
B4R::WiFiSocket* b4r_httpjob::_socket;
B4R::WiFiSSLSocket* b4r_httpjob::_sslsocket;
B4R::Array* b4r_httpjob::_eol;
b4r_main* b4r_httpjob::_main;
b4r_timenist* b4r_httpjob::_timenist;
static Byte be_gann1_4e1[500];
static B4R::Array be_gann1_4e2;
static Byte be_gann2_4e1[5000];
static B4R::Array be_gann2_4e2;
static Byte be_gann4_4e1[32];
static B4R::Array be_gann4_4e2;
static Byte be_gann5_4e1[8];
static B4R::Array be_gann5_4e2;
static B4R::ByteConverter be_gann6_3;
static B4R::AsyncStreams be_gann10_3;
static B4R::WiFiSocket be_gann11_3;
static B4R::WiFiSSLSocket be_gann12_3;
static Byte be_gann13_15e1[2];
static B4R::Array be_gann13_15e2;


 void b4r_httpjob::_addheader(B4R::Array* _key,B4R::Array* _value){
const UInt cp = B4R::StackMemory::cp;
B4R::Object be_ann22_14;
B4R::B4RString be_ann22_16;
B4R::Object be_ann22_18;
B4R::Object be_ann22_20;
B4R::Object be_ann22_22;
B4R::Object* be_ann22_23e1[4];
B4R::Array be_ann22_23e2;
B4R::Array* _b = NULL;
 //BA.debugLineNum = 26;BA.debugLine="Public Sub AddHeader(Key() As Byte, Value() As Byt";
 //BA.debugLineNum = 27;BA.debugLine="Dim b() As Byte = JoinBytes(Array(Key, \": \".GetBy";
_b = B4R::__c->JoinBytes(be_ann22_23e2.create(be_ann22_23e1,4,100,be_ann22_14.wrapPointer(_key),be_ann22_18.wrapPointer(be_ann22_16.wrap(": ")->GetBytes()),be_ann22_20.wrapPointer(_value),be_ann22_22.wrapPointer(b4r_httpjob::_eol)));
 //BA.debugLineNum = 28;BA.debugLine="bc.ArrayCopy2(b, 0, requestCache, headersIndex +";
b4r_httpjob::_bc->ArrayCopy2(_b,(UInt) (0),b4r_httpjob::_requestcache,(UInt) (b4r_httpjob::_headersindex+b4r_httpjob::_headerslen),(UInt) (_b->length));
 //BA.debugLineNum = 29;BA.debugLine="headersLen = headersLen + b.Length";
b4r_httpjob::_headerslen = (Int) (b4r_httpjob::_headerslen+_b->length);
 //BA.debugLineNum = 30;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_httpjob::_astream_error(){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 92;BA.debugLine="Private Sub AStream_Error";
 //BA.debugLineNum = 93;BA.debugLine="ParseResult";
_parseresult();
 //BA.debugLineNum = 94;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_httpjob::_astream_newdata(B4R::Array* _buffer){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 83;BA.debugLine="Private Sub AStream_NewData (Buffer() As Byte)";
 //BA.debugLineNum = 84;BA.debugLine="If responseIndex + Buffer.Length > responseCache.";
if (b4r_httpjob::_responseindex+_buffer->length>b4r_httpjob::_responsecache->length) { 
 //BA.debugLineNum = 85;BA.debugLine="Log(\"ResponseCache is full (\", Buffer.Length, \")";
B4R::Common::LogHelper(3,102,F("ResponseCache is full ("),3,_buffer->length,102,F(")"));
 //BA.debugLineNum = 86;BA.debugLine="Return";
B4R::StackMemory::cp = cp;
if (true) return ;
 };
 //BA.debugLineNum = 88;BA.debugLine="bc.ArrayCopy2(Buffer, 0, responseCache, responseI";
b4r_httpjob::_bc->ArrayCopy2(_buffer,(UInt) (0),b4r_httpjob::_responsecache,(UInt) (b4r_httpjob::_responseindex),(UInt) (_buffer->length));
 //BA.debugLineNum = 89;BA.debugLine="responseIndex = responseIndex + Buffer.Length";
b4r_httpjob::_responseindex = (Int) (b4r_httpjob::_responseindex+_buffer->length);
 //BA.debugLineNum = 90;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_httpjob::_download(B4R::Array* _link){
const UInt cp = B4R::StackMemory::cp;
B4R::B4RString be_ann28_4;
 //BA.debugLineNum = 32;BA.debugLine="Public Sub Download (Link() As Byte)";
 //BA.debugLineNum = 33;BA.debugLine="ParseLink(Link, Null)";
_parselink(_link,(B4R::Array*)B4R::Object::toPointer(Common_Null));
 //BA.debugLineNum = 34;BA.debugLine="bc.ArrayCopy(\"GET\", mVerb)";
b4r_httpjob::_bc->ArrayCopy((be_ann28_4.wrap("GET"))->GetBytes(),b4r_httpjob::_mverb);
 //BA.debugLineNum = 35;BA.debugLine="SendRequest(0)";
_sendrequest((Byte) (0));
 //BA.debugLineNum = 36;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_httpjob::_initialize(B4R::B4RString* _jobname){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 19;BA.debugLine="Public Sub Initialize(JobName As String)";
 //BA.debugLineNum = 20;BA.debugLine="bc.ArrayCopy(JobName, mJobname)";
b4r_httpjob::_bc->ArrayCopy((_jobname)->GetBytes(),b4r_httpjob::_mjobname);
 //BA.debugLineNum = 21;BA.debugLine="headersIndex = 0";
b4r_httpjob::_headersindex = 0;
 //BA.debugLineNum = 22;BA.debugLine="headersLen = 0";
b4r_httpjob::_headerslen = 0;
 //BA.debugLineNum = 24;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_httpjob::_parselink(B4R::Array* _link,B4R::Array* _payload){
const UInt cp = B4R::StackMemory::cp;
Int _hoststart = 0;
B4R::B4RString be_ann115_7;
B4R::B4RString be_ann118_7;
B4R::B4RString be_ann122_2;
B4R::B4RString be_ann125_11;
Int _i = 0;
Byte be_ann126_4e1[0];
B4R::Array be_ann126_4e2;
B4R::Array* _path = NULL;
B4R::B4RString be_ann129_2;
B4R::Array* _host = NULL;
B4R::B4RString be_ann133_11;
Int _colonstart = 0;
 //BA.debugLineNum = 128;BA.debugLine="Private Sub ParseLink (Link() As Byte, Payload() A";
 //BA.debugLineNum = 129;BA.debugLine="Dim hostStart As Int";
_hoststart = 0;
 //BA.debugLineNum = 130;BA.debugLine="If bc.StartsWith(Link, \"https://\") Then";
if (b4r_httpjob::_bc->StartsWith(_link,(be_ann115_7.wrap("https://"))->GetBytes())) { 
 //BA.debugLineNum = 131;BA.debugLine="ssl = True";
b4r_httpjob::_ssl = Common_True;
 //BA.debugLineNum = 132;BA.debugLine="hostStart = 8";
_hoststart = 8;
 }else if(b4r_httpjob::_bc->StartsWith(_link,(be_ann118_7.wrap("http://"))->GetBytes())) { 
 //BA.debugLineNum = 134;BA.debugLine="ssl = False";
b4r_httpjob::_ssl = Common_False;
 //BA.debugLineNum = 135;BA.debugLine="hostStart = 7";
_hoststart = 7;
 }else {
 //BA.debugLineNum = 137;BA.debugLine="SetError(\"Invalid link\")";
_seterror((be_ann122_2.wrap("Invalid link"))->GetBytes());
 //BA.debugLineNum = 138;BA.debugLine="Return";
B4R::StackMemory::cp = cp;
if (true) return ;
 };
 //BA.debugLineNum = 140;BA.debugLine="Dim i As Int = bc.IndexOf2(Link, \"/\", hostStart)";
_i = b4r_httpjob::_bc->IndexOf2(_link,(be_ann125_11.wrap("/"))->GetBytes(),(UInt) (_hoststart));
 //BA.debugLineNum = 141;BA.debugLine="Dim path() As Byte";
_path =be_ann126_4e2.wrap(be_ann126_4e1,0);
 //BA.debugLineNum = 142;BA.debugLine="If i = -1 Then";
if (_i==-1) { 
 //BA.debugLineNum = 143;BA.debugLine="i = Link.Length";
_i = _link->length;
 //BA.debugLineNum = 144;BA.debugLine="path = \"/\"";
_path = (be_ann129_2.wrap("/"))->GetBytes();
 };
 //BA.debugLineNum = 146;BA.debugLine="Dim host() As Byte = bc.SubString2(Link, hostStar";
_host = b4r_httpjob::_bc->SubString2(_link,(UInt) (_hoststart),(UInt) (_i));
 //BA.debugLineNum = 147;BA.debugLine="If i < Link.Length Then path = bc.SubString(Link,";
if (_i<_link->length) { 
_path = b4r_httpjob::_bc->SubString(_link,(UInt) (_i));};
 //BA.debugLineNum = 148;BA.debugLine="Dim colonStart As Int = bc.IndexOf(host, \":\")";
_colonstart = b4r_httpjob::_bc->IndexOf(_host,(be_ann133_11.wrap(":"))->GetBytes());
 //BA.debugLineNum = 149;BA.debugLine="If colonStart > -1 Then";
if (_colonstart>-1) { 
 //BA.debugLineNum = 150;BA.debugLine="port = bc.StringFromBytes(bc.SubString(host, col";
b4r_httpjob::_port = (Int)(atof(b4r_httpjob::_bc->StringFromBytes(b4r_httpjob::_bc->SubString(_host,(UInt) (_colonstart+1)))->data));
 //BA.debugLineNum = 151;BA.debugLine="host = bc.SubString2(host, 0, colonStart)";
_host = b4r_httpjob::_bc->SubString2(_host,(UInt) (0),(UInt) (_colonstart));
 }else {
 //BA.debugLineNum = 153;BA.debugLine="If ssl Then port = 443 Else port = 80";
if (b4r_httpjob::_ssl) { 
b4r_httpjob::_port = 443;}
else {
b4r_httpjob::_port = 80;};
 };
 //BA.debugLineNum = 155;BA.debugLine="SetRequestCache(host, path, Payload)";
_setrequestcache(_host,_path,_payload);
 //BA.debugLineNum = 156;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_httpjob::_parseresult(){
const UInt cp = B4R::StackMemory::cp;
B4R::B4RString be_ann84_2;
B4R::Array* _response = NULL;
Int _i = 0;
B4R::Array* _statusline = NULL;
B4R::B4RString be_ann90_11;
Int _i1 = 0;
B4R::B4RString be_ann91_11;
Int _i2 = 0;
Int _status = 0;
B4R::B4RString be_ann94_8;
B4R::Array* _newpath = NULL;
B4R::Object be_ann98_4;
_jobresult be_ann104_3;
_jobresult* _jr = NULL;
Byte be_ann106_19e1[4];
B4R::Array be_ann106_19e2;
Byte be_ann109_8e1[0];
B4R::Array be_ann109_8e2;
 //BA.debugLineNum = 96;BA.debugLine="Private Sub ParseResult";
 //BA.debugLineNum = 97;BA.debugLine="If responseIndex = 0 Then";
if (b4r_httpjob::_responseindex==0) { 
 //BA.debugLineNum = 98;BA.debugLine="SetError(\"Response not available.\")";
_seterror((be_ann84_2.wrap("Response not available."))->GetBytes());
 //BA.debugLineNum = 99;BA.debugLine="Return";
B4R::StackMemory::cp = cp;
if (true) return ;
 };
 //BA.debugLineNum = 101;BA.debugLine="Dim response() As Byte = bc.SubString2(responseCa";
_response = b4r_httpjob::_bc->SubString2(b4r_httpjob::_responsecache,(UInt) (0),(UInt) (b4r_httpjob::_responseindex));
 //BA.debugLineNum = 102;BA.debugLine="Dim i As Int = bc.IndexOf(response, EOL)";
_i = b4r_httpjob::_bc->IndexOf(_response,b4r_httpjob::_eol);
 //BA.debugLineNum = 103;BA.debugLine="Dim statusLine() As Byte = bc.SubString2(response";
_statusline = b4r_httpjob::_bc->SubString2(_response,(UInt) (0),(UInt) (_i));
 //BA.debugLineNum = 104;BA.debugLine="Dim i1 As Int = bc.IndexOf(statusLine, \" \")";
_i1 = b4r_httpjob::_bc->IndexOf(_statusline,(be_ann90_11.wrap(" "))->GetBytes());
 //BA.debugLineNum = 105;BA.debugLine="Dim i2 As Int = bc.IndexOf2(statusLine, \" \", i1 +";
_i2 = b4r_httpjob::_bc->IndexOf2(_statusline,(be_ann91_11.wrap(" "))->GetBytes(),(UInt) (_i1+1));
 //BA.debugLineNum = 106;BA.debugLine="Dim status As Int = bc.StringFromBytes(bc.SubStri";
_status = (Int)(atof(b4r_httpjob::_bc->StringFromBytes(b4r_httpjob::_bc->SubString2(_statusline,(UInt) (_i1+1),(UInt) (_i2)))->data));
 //BA.debugLineNum = 107;BA.debugLine="If Floor(status / 100) = 3 Then 'handle redirecti";
if (Common_Floor(_status/(Double)100)==3) { 
 //BA.debugLineNum = 108;BA.debugLine="i1 = bc.IndexOf(response, \"Location:\")";
_i1 = b4r_httpjob::_bc->IndexOf(_response,(be_ann94_8.wrap("Location:"))->GetBytes());
 //BA.debugLineNum = 109;BA.debugLine="If i1 > -1 Then";
if (_i1>-1) { 
 //BA.debugLineNum = 110;BA.debugLine="i2 = bc.IndexOf2(response, EOL, i1 + 1)";
_i2 = b4r_httpjob::_bc->IndexOf2(_response,b4r_httpjob::_eol,(UInt) (_i1+1));
 //BA.debugLineNum = 111;BA.debugLine="Dim NewPath() As Byte = bc.Trim(bc.SubString2(r";
_newpath = b4r_httpjob::_bc->Trim(b4r_httpjob::_bc->SubString2(_response,(UInt) (_i1+9),(UInt) (_i2)));
 //BA.debugLineNum = 112;BA.debugLine="Log(\"Redirecting to: \", NewPath)";
B4R::Common::LogHelper(2,102,F("Redirecting to: "),100,be_ann98_4.wrapPointer(_newpath));
 //BA.debugLineNum = 113;BA.debugLine="ParseLink(NewPath, bc.SubString2(requestCache,";
_parselink(_newpath,b4r_httpjob::_bc->SubString2(b4r_httpjob::_requestcache,(UInt) (b4r_httpjob::_payloadindex),(UInt) (b4r_httpjob::_payloadindex+b4r_httpjob::_payloadlen)));
 //BA.debugLineNum = 114;BA.debugLine="CallSubPlus(\"SendRequest\", 1, 0) 'to avoid stac";
B4R::__c->CallSubPlus(_sendrequest,(ULong) (1),(Byte) (0));
 //BA.debugLineNum = 115;BA.debugLine="Return";
B4R::StackMemory::cp = cp;
if (true) return ;
 };
 };
 //BA.debugLineNum = 118;BA.debugLine="Dim jr As JobResult";
_jr = &be_ann104_3;
 //BA.debugLineNum = 119;BA.debugLine="jr.Success = Floor(status / 100) = 2";
_jr->Success = Common_Floor(_status/(Double)100)==2;
 //BA.debugLineNum = 120;BA.debugLine="i = bc.IndexOf(response, Array As Byte(13, 10, 13";
_i = b4r_httpjob::_bc->IndexOf(_response,be_ann106_19e2.create(be_ann106_19e1,4,1,(Byte) (13),(Byte) (10),(Byte) (13),(Byte) (10)));
 //BA.debugLineNum = 121;BA.debugLine="jr.Response = bc.SubString(response, i + 4)";
_jr->Response = b4r_httpjob::_bc->SubString(_response,(UInt) (_i+4));
 //BA.debugLineNum = 122;BA.debugLine="jr.JobName = mJobname";
_jr->JobName = b4r_httpjob::_mjobname;
 //BA.debugLineNum = 123;BA.debugLine="jr.ErrorMessage = Array As Byte()";
_jr->ErrorMessage = be_ann109_8e2.wrap(be_ann109_8e1,0);
 //BA.debugLineNum = 124;BA.debugLine="jr.Status = status";
_jr->Status = _status;
 //BA.debugLineNum = 125;BA.debugLine="Main.JobDone(jr)";
b4r_httpjob::_main->_jobdone(_jr);
 //BA.debugLineNum = 126;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_httpjob::_post(B4R::Array* _link,B4R::Array* _payload){
const UInt cp = B4R::StackMemory::cp;
B4R::B4RString be_ann33_4;
 //BA.debugLineNum = 38;BA.debugLine="Public Sub Post (Link() As Byte, Payload() As Byte";
 //BA.debugLineNum = 39;BA.debugLine="ParseLink(Link, Payload)";
_parselink(_link,_payload);
 //BA.debugLineNum = 40;BA.debugLine="bc.ArrayCopy(\"POST\", mVerb)";
b4r_httpjob::_bc->ArrayCopy((be_ann33_4.wrap("POST"))->GetBytes(),b4r_httpjob::_mverb);
 //BA.debugLineNum = 41;BA.debugLine="SendRequest(0)";
_sendrequest((Byte) (0));
 //BA.debugLineNum = 42;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_httpjob::_process_globals(){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 2;BA.debugLine="Sub Process_Globals";
 //BA.debugLineNum = 3;BA.debugLine="Private requestCache(500) As Byte";
b4r_httpjob::_requestcache =be_gann1_4e2.wrap(be_gann1_4e1,500);
 //BA.debugLineNum = 4;BA.debugLine="Private responseCache(5000) As Byte";
b4r_httpjob::_responsecache =be_gann2_4e2.wrap(be_gann2_4e1,5000);
 //BA.debugLineNum = 5;BA.debugLine="Private responseIndex As Int";
b4r_httpjob::_responseindex = 0;
 //BA.debugLineNum = 6;BA.debugLine="Private mJobname(32) As Byte";
b4r_httpjob::_mjobname =be_gann4_4e2.wrap(be_gann4_4e1,32);
 //BA.debugLineNum = 7;BA.debugLine="Private mVerb(8) As Byte";
b4r_httpjob::_mverb =be_gann5_4e2.wrap(be_gann5_4e1,8);
 //BA.debugLineNum = 8;BA.debugLine="Private bc As ByteConverter";
b4r_httpjob::_bc = &be_gann6_3;
 //BA.debugLineNum = 9;BA.debugLine="Private ssl As Boolean";
b4r_httpjob::_ssl = false;
 //BA.debugLineNum = 10;BA.debugLine="Private port As Int";
b4r_httpjob::_port = 0;
 //BA.debugLineNum = 11;BA.debugLine="Private hostIndex, hostLen, pathIndex, pathLen, p";
b4r_httpjob::_hostindex = 0;
b4r_httpjob::_hostlen = 0;
b4r_httpjob::_pathindex = 0;
b4r_httpjob::_pathlen = 0;
b4r_httpjob::_payloadindex = 0;
b4r_httpjob::_payloadlen = 0;
b4r_httpjob::_headersindex = 0;
b4r_httpjob::_headerslen = 0;
 //BA.debugLineNum = 12;BA.debugLine="Private astream As AsyncStreams";
b4r_httpjob::_astream = &be_gann10_3;
 //BA.debugLineNum = 13;BA.debugLine="Private socket As WiFiSocket";
b4r_httpjob::_socket = &be_gann11_3;
 //BA.debugLineNum = 14;BA.debugLine="Private sslsocket As WiFiSSLSocket";
b4r_httpjob::_sslsocket = &be_gann12_3;
 //BA.debugLineNum = 15;BA.debugLine="Public EOL() As Byte = Array As Byte(13, 10)";
b4r_httpjob::_eol = be_gann13_15e2.create(be_gann13_15e1,2,1,(Byte) (13),(Byte) (10));
 //BA.debugLineNum = 16;BA.debugLine="Type JobResult (JobName() As Byte, ErrorMessage()";
;
 //BA.debugLineNum = 17;BA.debugLine="End Sub";
}
void b4r_httpjob::_sendrequest(Byte _unused){
const UInt cp = B4R::StackMemory::cp;
B4R::B4RString* _host = B4R::B4RString::EMPTY;
B4R::B4RStream* _st = NULL;
B4R::B4RString be_ann51_2;
B4R::B4RString be_ann56_9;
B4R::B4RString be_ann56_30;
B4R::B4RString be_ann57_4;
B4R::B4RString be_ann58_4;
B4R::Array* _payload = NULL;
B4R::B4RString be_ann61_4;
 //BA.debugLineNum = 44;BA.debugLine="Private Sub SendRequest (unused As Byte)";
 //BA.debugLineNum = 45;BA.debugLine="Dim host As String = bc.StringFromBytes(bc.SubStr";
_host = b4r_httpjob::_bc->StringFromBytes(b4r_httpjob::_bc->SubString2(b4r_httpjob::_requestcache,(UInt) (b4r_httpjob::_hostindex),(UInt) (b4r_httpjob::_hostindex+b4r_httpjob::_hostlen)));
 //BA.debugLineNum = 46;BA.debugLine="Dim st As Stream = Null";
_st = (B4R::B4RStream*)B4R::Object::toPointer(Common_Null);
 //BA.debugLineNum = 48;BA.debugLine="If ssl Then";
if (b4r_httpjob::_ssl) { 
 //BA.debugLineNum = 49;BA.debugLine="sslsocket.Close";
b4r_httpjob::_sslsocket->Close();
 //BA.debugLineNum = 50;BA.debugLine="If sslsocket.ConnectHost(host, port) Then";
if (b4r_httpjob::_sslsocket->ConnectHost(_host,(UInt) (b4r_httpjob::_port))) { 
 //BA.debugLineNum = 51;BA.debugLine="st = sslsocket.Stream";
_st = b4r_httpjob::_sslsocket->getStream();
 };
 }else {
 //BA.debugLineNum = 54;BA.debugLine="socket.Close";
b4r_httpjob::_socket->Close();
 //BA.debugLineNum = 55;BA.debugLine="If socket.ConnectHost(host, port) Then";
if (b4r_httpjob::_socket->ConnectHost(_host,(UInt) (b4r_httpjob::_port))) { 
 //BA.debugLineNum = 56;BA.debugLine="st = socket.Stream";
_st = b4r_httpjob::_socket->getStream();
 };
 };
 //BA.debugLineNum = 59;BA.debugLine="If st = Null Then";
if (_st== NULL) { 
 //BA.debugLineNum = 60;BA.debugLine="SetError(\"Failed to connect\")";
_seterror((be_ann51_2.wrap("Failed to connect"))->GetBytes());
 //BA.debugLineNum = 61;BA.debugLine="Return";
B4R::StackMemory::cp = cp;
if (true) return ;
 };
 //BA.debugLineNum = 64;BA.debugLine="responseIndex = 0";
b4r_httpjob::_responseindex = 0;
 //BA.debugLineNum = 65;BA.debugLine="astream.Initialize(st, \"Astream_NewData\", \"Astrea";
b4r_httpjob::_astream->Initialize(_st,_astream_newdata,_astream_error);
 //BA.debugLineNum = 66;BA.debugLine="astream.Write(mVerb).Write(\" \").Write(bc.SubStrin";
b4r_httpjob::_astream->Write(b4r_httpjob::_mverb)->Write((be_ann56_9.wrap(" "))->GetBytes())->Write(b4r_httpjob::_bc->SubString2(b4r_httpjob::_requestcache,(UInt) (b4r_httpjob::_pathindex),(UInt) (b4r_httpjob::_pathindex+b4r_httpjob::_pathlen)))->Write((be_ann56_30.wrap(" HTTP/1.0"))->GetBytes())->Write(b4r_httpjob::_eol);
 //BA.debugLineNum = 68;BA.debugLine="astream.Write(\"Host: \").Write(host).Write(EOL)";
b4r_httpjob::_astream->Write((be_ann57_4.wrap("Host: "))->GetBytes())->Write((_host)->GetBytes())->Write(b4r_httpjob::_eol);
 //BA.debugLineNum = 69;BA.debugLine="astream.Write(\"Connection: close\").Write(EOL)";
b4r_httpjob::_astream->Write((be_ann58_4.wrap("Connection: close"))->GetBytes())->Write(b4r_httpjob::_eol);
 //BA.debugLineNum = 70;BA.debugLine="Dim payload() As Byte = bc.SubString2(requestCach";
_payload = b4r_httpjob::_bc->SubString2(b4r_httpjob::_requestcache,(UInt) (b4r_httpjob::_payloadindex),(UInt) (b4r_httpjob::_payloadindex+b4r_httpjob::_payloadlen));
 //BA.debugLineNum = 71;BA.debugLine="If payload.Length > 0 Then";
if (_payload->length>0) { 
 //BA.debugLineNum = 72;BA.debugLine="astream.Write(\"Content-Length: \").Write(NumberFo";
b4r_httpjob::_astream->Write((be_ann61_4.wrap("Content-Length: "))->GetBytes())->Write((B4R::__c->NumberFormat(_payload->length,(Byte) (0),(Byte) (0)))->GetBytes())->Write(b4r_httpjob::_eol);
 };
 //BA.debugLineNum = 74;BA.debugLine="If headersLen > 0 Then";
if (b4r_httpjob::_headerslen>0) { 
 //BA.debugLineNum = 75;BA.debugLine="astream.Write(bc.SubString2(requestCache, header";
b4r_httpjob::_astream->Write(b4r_httpjob::_bc->SubString2(b4r_httpjob::_requestcache,(UInt) (b4r_httpjob::_headersindex),(UInt) (b4r_httpjob::_headersindex+b4r_httpjob::_headerslen)));
 };
 //BA.debugLineNum = 77;BA.debugLine="astream.Write(EOL)";
b4r_httpjob::_astream->Write(b4r_httpjob::_eol);
 //BA.debugLineNum = 78;BA.debugLine="If payload.Length > 0 Then";
if (_payload->length>0) { 
 //BA.debugLineNum = 79;BA.debugLine="astream.Write(payload)";
b4r_httpjob::_astream->Write(_payload);
 };
 //BA.debugLineNum = 81;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_httpjob::_seterror(B4R::Array* _msg){
const UInt cp = B4R::StackMemory::cp;
_jobresult be_ann155_3;
_jobresult* _jr = NULL;
Byte be_ann158_8e1[0];
B4R::Array be_ann158_8e2;
 //BA.debugLineNum = 171;BA.debugLine="Private Sub SetError (msg() As Byte)";
 //BA.debugLineNum = 172;BA.debugLine="Dim jr As JobResult";
_jr = &be_ann155_3;
 //BA.debugLineNum = 173;BA.debugLine="jr.JobName = mJobname";
_jr->JobName = b4r_httpjob::_mjobname;
 //BA.debugLineNum = 174;BA.debugLine="jr.ErrorMessage = msg";
_jr->ErrorMessage = _msg;
 //BA.debugLineNum = 175;BA.debugLine="jr.Response = Array As Byte()";
_jr->Response = be_ann158_8e2.wrap(be_ann158_8e1,0);
 //BA.debugLineNum = 176;BA.debugLine="jr.Success = False";
_jr->Success = Common_False;
 //BA.debugLineNum = 177;BA.debugLine="jr.Status = 0";
_jr->Status = 0;
 //BA.debugLineNum = 178;BA.debugLine="Main.JobDone(jr)";
b4r_httpjob::_main->_jobdone(_jr);
 //BA.debugLineNum = 179;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_httpjob::_setrequestcache(B4R::Array* _host,B4R::Array* _path,B4R::Array* _payload){
const UInt cp = B4R::StackMemory::cp;
Byte be_ann143_14e1[0];
B4R::Array be_ann143_14e2;
 //BA.debugLineNum = 158;BA.debugLine="Private Sub SetRequestCache(host() As Byte, path()";
 //BA.debugLineNum = 159;BA.debugLine="If payload = Null Then payload = Array As Byte()";
if (_payload== NULL) { 
_payload = be_ann143_14e2.wrap(be_ann143_14e1,0);};
 //BA.debugLineNum = 160;BA.debugLine="payloadIndex = headersIndex + headersLen";
b4r_httpjob::_payloadindex = (Int) (b4r_httpjob::_headersindex+b4r_httpjob::_headerslen);
 //BA.debugLineNum = 161;BA.debugLine="payloadLen = payload.Length";
b4r_httpjob::_payloadlen = _payload->length;
 //BA.debugLineNum = 162;BA.debugLine="bc.ArrayCopy2(payload, 0, requestCache, payloadIn";
b4r_httpjob::_bc->ArrayCopy2(_payload,(UInt) (0),b4r_httpjob::_requestcache,(UInt) (b4r_httpjob::_payloadindex),(UInt) (b4r_httpjob::_payloadlen));
 //BA.debugLineNum = 163;BA.debugLine="hostIndex = payloadIndex + payloadLen";
b4r_httpjob::_hostindex = (Int) (b4r_httpjob::_payloadindex+b4r_httpjob::_payloadlen);
 //BA.debugLineNum = 164;BA.debugLine="hostLen = host.Length";
b4r_httpjob::_hostlen = _host->length;
 //BA.debugLineNum = 165;BA.debugLine="bc.ArrayCopy2(host, 0, requestCache, hostIndex, h";
b4r_httpjob::_bc->ArrayCopy2(_host,(UInt) (0),b4r_httpjob::_requestcache,(UInt) (b4r_httpjob::_hostindex),(UInt) (b4r_httpjob::_hostlen));
 //BA.debugLineNum = 166;BA.debugLine="pathIndex = hostIndex + hostLen";
b4r_httpjob::_pathindex = (Int) (b4r_httpjob::_hostindex+b4r_httpjob::_hostlen);
 //BA.debugLineNum = 167;BA.debugLine="pathLen = path.Length";
b4r_httpjob::_pathlen = _path->length;
 //BA.debugLineNum = 168;BA.debugLine="bc.ArrayCopy2(path, 0, requestCache, pathIndex, p";
b4r_httpjob::_bc->ArrayCopy2(_path,(UInt) (0),b4r_httpjob::_requestcache,(UInt) (b4r_httpjob::_pathindex),(UInt) (b4r_httpjob::_pathlen));
 //BA.debugLineNum = 169;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
