#include "jamo/impls/console_logger.h"

#include <cstdio>

namespace jamo {

const std::string ConsoleLogger::prefix = "[console]";

void ConsoleLogger::abort(const std::string &msg){
  printf("[abort] %s\n", msg.c_str());
}
void ConsoleLogger::fatal(const std::string &msg){
  printf("[fatal] %s\n", msg.c_str());
}
void ConsoleLogger::error(const std::string &msg){
  printf("[error] %s\n", msg.c_str());
}
void ConsoleLogger::info (const std::string &msg){
  printf("[info ] %s\n", msg.c_str());
}
void ConsoleLogger::debug(const std::string &msg){
  printf("[debug] %s\n", msg.c_str());
}
void ConsoleLogger::trace(const std::string &msg){
  printf("[trace] %s\n", msg.c_str());
}

}