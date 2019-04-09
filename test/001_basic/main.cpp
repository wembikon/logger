#include "jamo/internal/logger.h"

#include "jamo/console_logger.h"
#include "jamo/file_logger.h"
#include "jamo/network_logger.h"
#include "jamo/logger.h"

#include <vector>
#include <string>
#include <sstream>

#include <iostream>

struct SS {
  SS(std::stringstream &ss):_ss(ss){}
  template<typename T>
  SS &operator<<(T &&v){
    _ss<<v;
    return *this;
  }
  ~SS(){
    _ss.seekp(std::ios::beg);
  }
  std::string str() const{
    return _ss.str();
  }
  std::stringstream &_ss;
};

inline SS ss_impl(std::stringstream &s) {
  return SS(s);
}

// We define a static stringstream because constructing it is too slow
// http://cplusplus.bordoon.com/speeding_up_string_conversions.html
static std::stringstream g_ss;
#define ss() ss_impl(g_ss)

void logError3(const std::vector<jamo::internal::Logger> &logger, const SS &ss){
  for(auto l : logger){
    l.error(ss.str());
  }
}

// Always constructing the string stream makes it slow
inline std::ostringstream oss() {
  return std::ostringstream();
}

void logError2(const std::vector<jamo::internal::Logger> &logger, const std::ostringstream &ss){
  for(auto l : logger){
    l.error(ss.str());
  }
}

void logError(const std::vector<jamo::internal::Logger> &logger, const std::string &msg){
  for(auto l : logger){
    l.error(msg);
  }
}

void logInfo(const std::vector<jamo::internal::Logger> &logger, const std::string &msg){
  for(auto l : logger){
    l.info(msg);
  }
}

void logDebug(const std::vector<jamo::internal::Logger> &logger, const std::string &msg){
  for(auto l : logger){
    l.debug(msg);
  }
}

void logTrace(const std::vector<jamo::internal::Logger> &logger, const std::string &msg){
  for(auto l : logger){
    l.trace(msg);
  }
}

int main(){
  jamo::ConsoleLogger cl;
  jamo::FileLogger fl;
  jamo::NetworkLogger nl;

  std::vector<jamo::internal::Logger> logger { cl, fl, nl };
  
  logError3(logger, ss()<<"this is a "<<2<<" test of "<<0x0A<<" formatting");
  logError2(logger, oss()<<"this is a "<<2<<" test of "<<0x0A<<" formatting");

  /*logError(logger, "somekind of an error");
  logInfo(logger, "information");
  logDebug(logger, "debugging my program");
  logTrace(logger, "tracing the log");*/

  return 0;
}