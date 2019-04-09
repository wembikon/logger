#ifndef JAMO_LOGGER_H
#define JAMO_LOGGER_H

#include "jamo/internal/logger.h"

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

namespace jamo {

namespace formatter {

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

template<typename T>
SS && fmt(SS &&ss, const T &v)
{
  ss<<v;
  return std::move(ss);
}

template<typename T, typename... Args>
SS && fmt(SS &&ss, const T &v, Args... args)
{
  ss<<v;
  fmt(std::move(ss), std::forward<Args>(args)...);
  return std::move(ss);
}

} // formatter

class Logger {
public:
  inline Logger(std::vector<jamo::internal::Logger> loggers)
  : _loggers(std::move(loggers)){}
  inline void logError(const formatter::SS &ss){
    for(auto l : _loggers){
      l.error(ss.str());
    }
  }
  inline void logInfo(const formatter::SS &ss){
    for(auto l : _loggers){
      l.info(ss.str());
    }
  }
  inline void logDebug(const formatter::SS &ss){
    for(auto l : _loggers){
      l.debug(ss.str());
    }
  }
  inline void logTrace(const formatter::SS &ss){
    for(auto l : _loggers){
      l.trace(ss.str());
    }
  }
  template<typename... Args>
  void error(Args... args){
    logError(formatter::fmt(formatter::SS(_ss), std::forward<Args>(args)...));
  }
  template<typename... Args>
  void info(Args... args){
    logInfo(formatter::fmt(formatter::SS(_ss), std::forward<Args>(args)...));
  }
  template<typename... Args>
  void debug(Args... args){
    logDebug(formatter::fmt(formatter::SS(_ss), std::forward<Args>(args)...));
  }
  template<typename... Args>
  void trace(Args... args){
    logTrace(formatter::fmt(formatter::SS(_ss), std::forward<Args>(args)...));
  }
private:
  std::stringstream _ss; // the buffer
  std::vector<jamo::internal::Logger> _loggers;
};

} // jamo

#endif // JAMO_LOGGER_H