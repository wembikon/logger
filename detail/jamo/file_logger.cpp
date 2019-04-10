#include "jamo/file_logger.h"

namespace jamo {

const std::string FileLogger::prefix = "[file   ]";

void FileLogger::abort(const std::string &msg){
  std::cerr<<prefix<<"[abort]"<<" "<<msg<<std::endl;
}
void FileLogger::fatal(const std::string &msg){
  std::cerr<<prefix<<"[fatal]"<<" "<<msg<<std::endl;
}
void FileLogger::error(const std::string &msg){
  std::cerr<<prefix<<"[error]"<<" "<<msg<<std::endl;
}
void FileLogger::info (const std::string &msg){
  std::cerr<<prefix<<"[info ]"<<" "<<msg<<std::endl;
}
void FileLogger::debug(const std::string &msg){
  std::cerr<<prefix<<"[debug]"<<" "<<msg<<std::endl;
}
void FileLogger::trace(const std::string &msg){
  std::cerr<<prefix<<"[trace]"<<" "<<msg<<std::endl;
}

}