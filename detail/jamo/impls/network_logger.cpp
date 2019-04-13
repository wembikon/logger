#include "jamo/impls/network_logger.h"

#include <cstdio>

namespace jamo {

const std::string NetworkLogger::prefix = "[network]";

void NetworkLogger::abort(const std::string &msg){
  printf("[abort] %s\n", msg.c_str());
}
void NetworkLogger::fatal(const std::string &msg){
  printf("[fatal] %s\n", msg.c_str());
}
void NetworkLogger::error(const std::string &msg){
  printf("[error] %s\n", msg.c_str());
}
void NetworkLogger::info (const std::string &msg){
  printf("[info ] %s\n", msg.c_str());
}
void NetworkLogger::debug(const std::string &msg){
  printf("[debug] %s\n", msg.c_str());
}
void NetworkLogger::trace(const std::string &msg){
  printf("[trace] %s\n", msg.c_str());
}

}