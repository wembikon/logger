#include "jamo/logger.h"

// Third parties can create their own logger objects
#include "jamo/impls/console_logger.h"
#include "jamo/impls/file_logger.h"
#include "jamo/impls/network_logger.h"

#include <iomanip>

int main(){
  jamo::ConsoleLogger cl;
  jamo::FileLogger fl;
  jamo::NetworkLogger nl;

  jamo::Logger logger({cl, fl, nl});
  logger.fatal("count ", 1, " two ", std::hex, 33, ", ", std::oct, 10);
  logger.fatal("test refresh");
  logger.error("count ", 1, " two ", std::hex, 33, ", ", std::oct, 10);
  logger.info ("count ", 1, " two ", std::hex, 33, ", ", std::oct, 10);
  logger.debug("count ", 1, " two ", std::hex, 33, ", ", std::oct, 10);
  logger.trace("count ", 1, " two ", std::hex, 33, ", ", std::oct, 10);

  logger.abort("count ", 1, " two ", std::hex, 33, ", ", std::oct, 10);
  return 0;
}
