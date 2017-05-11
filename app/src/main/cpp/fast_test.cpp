
#include "log4z.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <android/log.h>

using namespace zsummer::log4z;

#ifdef WIN32
#include <windows.h>
#endif


#define LOGAAA(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_alw_myapplication_MainActivity_ccc() {

    //start log4z
    ILog4zManager::getRef().setLoggerPath(LOG4Z_MAIN_LOGGER_ID, "/storage/sdcard0/log2");
    ILog4zManager::getRef().start();
    ILog4zManager::getRef().setLoggerLevel(LOG4Z_MAIN_LOGGER_ID, LOG_LEVEL_TRACE);
    //LOGD: LOG WITH level LOG_DEBUG
    //LOGI: LOG WITH level LOG_INFO

    //begin test stream log input....
    LOGT("stream input *** " << "LOGT LOGT LOGT LOGT" << " *** ");
    LOGW("stream input *** " << "LOGW LOGW LOGW LOGW" << " *** ");
    LOGE("stream input *** " << "LOGE LOGE LOGE LOGE" << " *** ");
    LOGA("stream input *** " << "LOGA LOGA LOGA LOGA" << " *** ");
    LOGF("stream input *** " << "LOGF LOGF LOGF LOGF" << " *** ");

    __android_log_print(ANDROID_LOG_DEBUG, "eee", "aaaaaaaaaaaaaaaaa");
    //begin test stream log all types input....


    if (true) {
        LogData ld;
        ld._id = 0;
        ld._type = 2;
        ld._typeval = 0;
        ld._level = LOG_LEVEL_DEBUG;
        ld._time = time(NULL);
        ld._precise = 0;
        ld._contentLen = 7;
        strcpy(ld._content, "newname");
        LOGD(Log4zBinary(&ld, sizeof(ld) - LOG4Z_LOG_BUF_SIZE + ld._contentLen));
    }
    //test stl
    if (true) {
        typedef std::pair<int, std::pair<int, std::string> > PR;
        PR pr = std::make_pair(111, std::make_pair(222, "dddd"));
        std::vector<PR> vt;
        vt.push_back(pr);
        vt.push_back(pr);
        std::map<int, PR> mp;
        mp[1] = pr;
        mp[2] = pr;
        std::list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);
        lt.push_back(6);
        LOGD("vector=" << vt);
        LOGD("map=" << mp);
        LOGD("list=" << lt);
    }

    std::string str;
    str.resize(3000, 's');

    // cannot support VC6 or VS2003

    //begin test format log input....
    LOGFMTT("format input *** %s *** %d ***", "LOGFMTT", 123456);
    LOGFMTD("format input *** %s *** %d ***", "LOGFMTD", 123456);
    LOGFMTI("format input *** %s *** %d ***", "LOGFMTI", 123456);
    LOGFMTW("format input *** %s *** %d ***", "LOGFMTW", 123456);
    LOGFMTE("format input *** %s *** %d ***", "LOGFMTE", 123456);
    LOGFMTA("format input *** %s *** %d ***", "LOGFMTA", 123456);
    LOGFMTF("format input *** %s *** %d ***", "LOGFMTF", 123456);

    //begin test format log big string more than buff size input....
    LOGFMT_DEBUG(LOG4Z_MAIN_LOGGER_ID, "%s", str.c_str());

    //begin test stream log big string more than buff size input....
    LOGD(str);

    LOG_STREAM(LOG4Z_MAIN_LOGGER_ID, LOG_LEVEL_ALARM, "", 0, "111111");
    LOG_STREAM(LOG4Z_MAIN_LOGGER_ID, LOG_LEVEL_ALARM, NULL, 0, "222222");
    LOG_FORMAT(LOG4Z_MAIN_LOGGER_ID, LOG_LEVEL_ALARM, "", 0, "%s", "333333");
    LOG_FORMAT(LOG4Z_MAIN_LOGGER_ID, LOG_LEVEL_ALARM, NULL, 0, "%s", "444444");

    LOGA("main quit ...");
    return 0;
}

