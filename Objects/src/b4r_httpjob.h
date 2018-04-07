
#ifndef b4r_httpjob_h
#define b4r_httpjob_h
class b4r_main;
class b4r_timenist;
class _jobresult;

class b4r_httpjob {
public:

static void _addheader(B4R::Array* _key,B4R::Array* _value);
static void _astream_error();
static void _astream_newdata(B4R::Array* _buffer);
static void _download(B4R::Array* _link);
static void _initialize(B4R::B4RString* _jobname);
static void _parselink(B4R::Array* _link,B4R::Array* _payload);
static void _parseresult();
static void _post(B4R::Array* _link,B4R::Array* _payload);
static void _process_globals();
static B4R::Array* _requestcache;
static B4R::Array* _responsecache;
static Int _responseindex;
static B4R::Array* _mjobname;
static B4R::Array* _mverb;
static B4R::ByteConverter* _bc;
static bool _ssl;
static Int _port;
static Int _hostindex;
static Int _hostlen;
static Int _pathindex;
static Int _pathlen;
static Int _payloadindex;
static Int _payloadlen;
static Int _headersindex;
static Int _headerslen;
static B4R::AsyncStreams* _astream;
static B4R::WiFiSocket* _socket;
static B4R::WiFiSSLSocket* _sslsocket;
static B4R::Array* _eol;
static b4r_main* _main;
static b4r_timenist* _timenist;
static void _sendrequest(Byte _unused);
static void _seterror(B4R::Array* _msg);
static void _setrequestcache(B4R::Array* _host,B4R::Array* _path,B4R::Array* _payload);
};
class _jobresult{
public:
B4R::Array* JobName;
B4R::Array* ErrorMessage;
bool Success;
B4R::Array* Response;
Int Status;
};

#endif