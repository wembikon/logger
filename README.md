# logger
simple logger for c++ that can log to console, file and network

# note
the file and network loggers are mocked just to lay down the point of the architecture. the actual
implementation are details that can be done by users

# c++ version
recommended version is 17 and above but works perfectly with 11 and 14

# usage
just clone the repo and include the files in your build system
```
#include "jamo/logger.h"

// Third parties can create their own logger objects. It should just have the following capabilities
// void fatal(const std::string &)
// void error(const std::string &)
// void info (const std::string &)
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
  logger.fatal("count ", 1, " two ", std::hex, 33, ", ", std::oct, 10);
  logger.error("count ", 1, " two ", std::hex, 33, ", ", std::oct, 10);
  logger.info ("count ", 1, " two ", std::hex, 33, ", ", std::oct, 10);
  logger.debug("count ", 1, " two ", std::hex, 33, ", ", std::oct, 10);
  logger.trace("count ", 1, " two ", std::hex, 33, ", ", std::oct, 10);
  
  logger.abort("count ", 1, " two ", std::hex, 33, ", ", std::oct, 10);
  return 0;
}
```

# output
```
[console][fatal] count 1 two 21, 12
[file   ][fatal] count 1 two 21, 12
[network][fatal] count 1 two 21, 12
[console][error] count 1 two 21, 12
[file   ][error] count 1 two 21, 12
[network][error] count 1 two 21, 12
[console][info ] count 1 two 21, 12
[file   ][info ] count 1 two 21, 12
[network][info ] count 1 two 21, 12
[console][debug] count 1 two 21, 12
[file   ][debug] count 1 two 21, 12
[network][debug] count 1 two 21, 12
[console][trace] count 1 two 21, 12
[file   ][trace] count 1 two 21, 12
[network][trace] count 1 two 21, 12
[console][abort] count 1 two 21, 12
[file   ][abort] count 1 two 21, 12
[network][abort] count 1 two 21, 12
```
