#ifndef JAMO_LOGGER_H
#define JAMO_LOGGER_H

#include <memory>
#include <string>

namespace jamo {

class Logger {
private:
  struct Concept {
    virtual ~Concept(){}
    virtual void error(const std::string &msg) = 0;
    virtual void info(const std::string &msg) = 0;
    virtual void debug(const std::string &msg) = 0;
    virtual void trace(const std::string &msg) = 0;
  };
  template<typename Impl>
  struct Policy : Concept {
    Policy(Impl &&o) : _o(o){}
    void error(const std::string &msg) override{
      _o.error(msg);
    }
    void info(const std::string &msg) override{
      _o.info(msg);
    }
    void debug(const std::string &msg) override{
      _o.debug(msg);
    }
    void trace(const std::string &msg) override{
      _o.trace(msg);
    }
    Impl _o;
  };
public:
  template<typename Impl>
  Logger(Impl &&o) : _o(std::make_shared<Policy<Impl>>(std::forward<Impl>(o))){}
  void error(const std::string &msg){
    _o->error(msg);
  }
  void info(const std::string &msg){
    _o->info(msg);
  }
  void debug(const std::string &msg){
    _o->debug(msg);
  }
  void trace(const std::string &msg){
    _o->trace(msg);
  }
private:
  std::shared_ptr<Concept> _o;
};

}

#endif // JAMO_LOGGER_H