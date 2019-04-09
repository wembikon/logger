#include "jamo/logger.h"

// Third parties can create their own logger objects
#include "jamo/console_logger.h"
#include "jamo/file_logger.h"
#include "jamo/network_logger.h"

#include <iomanip>

int main(){
  jamo::ConsoleLogger cl;
  jamo::FileLogger fl;
  jamo::NetworkLogger nl;

  jamo::Logger logger({cl, fl, nl});
  logger.info("count ", 1, " two ", std::hex, 33, ", ", std::oct, 10);

  return 0;
}