/*
MIT License

Copyright (c) 2019 Adrian T. Visarra

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef JAMO_INTERNAL_LOGGER_H
#define JAMO_INTERNAL_LOGGER_H

#include <memory>
#include <string>

namespace jamo::internal {

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

#endif // JAMO_INTERNAL_LOGGER_H