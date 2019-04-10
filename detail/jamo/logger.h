/*
MIT License

Copyright (c) 2019 Adrian T. Visarra

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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
  return fmt(std::move(ss), std::forward<Args>(args)...);
}

} // formatter

class Logger {
public:
  inline Logger(std::vector<jamo::internal::Logger> loggers)
  : _loggers(std::move(loggers)){}
  inline void logAbort(const formatter::SS &ss){
    for(auto l : _loggers){
      l.abort(ss.str());      
    }
    exit(1);
  }
  inline void logFatal(const formatter::SS &ss){
    for(auto l : _loggers){
      l.fatal(ss.str());
    }
  }
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
  void abort(Args... args){
    logAbort(formatter::fmt(formatter::SS(_ss), std::forward<Args>(args)...));
  }
  template<typename... Args>
  void fatal(Args... args){
    logFatal(formatter::fmt(formatter::SS(_ss), std::forward<Args>(args)...));
  }
  template<typename... Args>
  void error(Args... args){
    logError(formatter::fmt(formatter::SS(_ss), std::forward<Args>(args)...));
  }
  template<typename... Args>
  void info (Args... args){
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