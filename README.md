# logger
simple logger service that can log to console, file and network

# usage
```
#include "jamo/logger.h"

// Third parties can create their own logger objects. It should just have the following capabilities
// void error(const std::string &)
// void info(const std::string &)
// void debug(const std::string &)
// void trace(const std::string &)

// Out of the box loggers
#include "jamo/console_logger.h"
#include "jamo/file_logger.h"
#include "jamo/network_logger.h"

#include <iomanip> // std::hex, oct

int main(){
  jamo::ConsoleLogger cl;
  jamo::FileLogger fl;
  jamo::NetworkLogger nl;

  jamo::Logger logger({cl, fl, nl});
  // Here is a formatting example which is very fast
  logger.info("count ", 1, " two ", std::hex, 33, ", ", std::oct, 10);

  return 0;
}
```
