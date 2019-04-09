#include "jamo/logger.h"
#include "jamo/console_logger.h"
#include "jamo/file_logger.h"
#include "jamo/network_logger.h"

#include <vector>
#include <string>

#include <iostream>

void logError(const std::vector<jamo::Logger> &logger, const std::string &msg){
  for(auto l : logger){
    l.error(msg);
  }
}

void logInfo(const std::vector<jamo::Logger> &logger, const std::string &msg){
  for(auto l : logger){
    l.info(msg);
  }
}

void logDebug(const std::vector<jamo::Logger> &logger, const std::string &msg){
  for(auto l : logger){
    l.debug(msg);
  }
}

void logTrace(const std::vector<jamo::Logger> &logger, const std::string &msg){
  for(auto l : logger){
    l.trace(msg);
  }
}

int main(){
  jamo::ConsoleLogger cl;
  jamo::FileLogger fl;
  jamo::NetworkLogger nl;

  std::vector<jamo::Logger> logger { cl, fl, nl };
  logError(logger, "somekind of an error");
  logInfo(logger, "information");
  logDebug(logger, "debugging my program");
  logTrace(logger, "tracing the log");

  return 0;
}