#ifndef DEBUGGABLE_H
#define DEBUGGABLE_H
#include "../general/global.h"
namespace  interface {
#include <vector>
#include <memory>
#include <string>

class Debuggable
{
  public:
    template<typename OutputType>
    class DebugManager final
    {
      public:
        template<typename Output>
        class Logger
        {
          public:
            virtual Logger & operator <<(const Output ouput) noexcept = 0;

            DebugManager<Output> operator +(const Logger<Output> &);

          protected:
            Logger() = default;
            Logger(const Logger &) = default;
            Logger(const Logger &&) = default;
            Logger & operator =(const Logger &) = default;
            Logger & operator =(const Logger &&) = default;
            virtual ~Logger() = 0;
        };

        std::vector<std::shared_ptr<Logger<OutputType>>> loggers; // push_back or something can throw()?

        template<typename Any>
        DebugManager & operator <<(const Any output) const noexcept;

        DebugManager & operator +=(const Logger &); // chain ?
        //DebugManager & operator -=(const Logger &);
        //DebugManager & operator +=(const DebugManager &);
        //DebugManager & operator -=(const DebugManager &);

        // == and != and ((bool)(?))

      private:
        DebugManager() = default;
        DebugManager(const DebugManager &) = default;
        DebugManager(const DebugManager &&) = default;
        DebugManager & operator =(const DebugManager &) = default;
        DebugManager & operator =(const DebugManager &&) = default;
        ~DebugManager() = default;

        // [not explcit?] DebugManager( const std::tuple< Logger > ); // loggers set
    };

  protected:
    using stream_data_type = std::string;

    DebugManager<stream_data_type> _debug;

    Debuggable() = default;
    Debuggable(const Debuggable & debuggable) = default;
    Debuggable(const Debuggable && debuggable) = default;
};

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// Debuggable::DebugManager

Debuggable::DebugManager::Logger::~Logger() {}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// Debuggable::DebugManager

template<typename Any> /*inline*/
Debuggable::DebugManager & Debuggable::DebugManager::operator <<(const interface::Debuggable::DebugManager::Any output) const noexcept // until noexcept on logger<<
{
  for(auto os : loggers)
    *os << output;
  return *this;
}

Debuggable::DebugManager & Debuggable::DebugManager::operator +=(const Debuggable::DebugManager::Logger & logger)
{
  loggers.push_back( std::shared_ptr<Logger<OutputType>> { &logger } ); // what if shared_ptr deletes logger?
  return *this;
}


} // namespace
#endif // DEBUGGABLE_H
