#include "jamo/impls/file_logger.h"

#include <cstdio>

namespace jamo {

const std::string FileLogger::prefix = "[file   ]";

void FileLogger::abort(const std::string &msg){
  printf("[abort] %s\n", msg.c_str());
}
void FileLogger::fatal(const std::string &msg){
  printf("[fatal] %s\n", msg.c_str());
}
void FileLogger::error(const std::string &msg){
  printf("[error] %s\n", msg.c_str());
}
void FileLogger::info (const std::string &msg){
  printf("[info ] %s\n", msg.c_str());
}
void FileLogger::debug(const std::string &msg){
  printf("[debug] %s\n", msg.c_str());
}
void FileLogger::trace(const std::string &msg){
  printf("[trace] %s\n", msg.c_str());
}

}