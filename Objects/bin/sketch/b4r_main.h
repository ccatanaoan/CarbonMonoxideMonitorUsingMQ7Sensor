
#ifndef b4r_main_h
#define b4r_main_h

class b4r_main {
public:

static void initializeProcessGlobals();
static void _appstart();
static void _checkairquality(Byte _tag);
static void _process_globals();
static B4R::Serial* _serial1;
static B4R::Pin* _mq7pin;
static Byte _mq7pinnumber;
};

#endif