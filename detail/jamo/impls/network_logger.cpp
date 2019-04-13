#include "jamo/impls/network_logger.h"

namespace jamo {

const std::string NetworkLogger::prefix = "[network]";

void NetworkLogger::abort(const std::string &msg){
  std::cerr<<prefix<<"[abort]"<<" "<<msg<<std::endl;
}
void NetworkLogger::fatal(const std::string &msg){
  std::cerr<<prefix<<"[fatal]"<<" "<<msg<<std::endl;
}
void NetworkLogger::error(const std::string &msg){
  std::cerr<<prefix<<"[error]"<<" "<<msg<<std::endl;
}
void NetworkLogger::info (const std::string &msg){
  std::cerr<<prefix<<"[info ]"<<" "<<msg<<std::endl;
}
void NetworkLogger::debug(const std::string &msg){
  std::cerr<<prefix<<"[debug]"<<" "<<msg<<std::endl;
}
void NetworkLogger::trace(const std::string &msg){
  std::cerr<<prefix<<"[trace]"<<" "<<msg<<std::endl;
}

}