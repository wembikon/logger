#include "jamo/console_logger.h"

namespace jamo {

const std::string ConsoleLogger::prefix = "[console]";

void ConsoleLogger::abort(const std::string &msg){
  std::cerr<<prefix<<"[abort]"<<" "<<msg<<std::endl;
}
void ConsoleLogger::fatal(const std::string &msg){
  std::cerr<<prefix<<"[fatal]"<<" "<<msg<<std::endl;
}
void ConsoleLogger::error(const std::string &msg){
  std::cerr<<prefix<<"[error]"<<" "<<msg<<std::endl;
}
void ConsoleLogger::info(const std::string &msg){
  std::cerr<<prefix<<"[info ]"<<" "<<msg<<std::endl;
}
void ConsoleLogger::debug(const std::string &msg){
  std::cerr<<prefix<<"[debug]"<<" "<<msg<<std::endl;
}
void ConsoleLogger::trace(const std::string &msg){
  std::cerr<<prefix<<"[trace]"<<" "<<msg<<std::endl;
}

}