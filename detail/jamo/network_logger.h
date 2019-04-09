#ifndef JAMO_NETWORK_LOGGER_H
#define JAMO_NETWORK_LOGGER_H

#include <iostream>
#include <string>

namespace jamo {

class NetworkLogger {
public:
  static const std::string prefix;
public:
  void error(const std::string &msg);
  void info(const std::string &msg);
  void debug(const std::string &msg);
  void trace(const std::string &msg);
};

}

#endif // JAMO_NETWORK_LOGGER_H