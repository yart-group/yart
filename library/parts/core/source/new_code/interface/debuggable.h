#ifndef DEBUGGABLE_H
#define DEBUGGABLE_H
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
            virtual ~Logger() = 0;
        };

        std::vector<std::shared_ptr<Logger<OutputType>>> loggers;

        DebugManager & operator <<(OutputType output);

        template<typename T>
        DebugManager & operator <<(T output);

      private:
        DebugManager() = default;
        DebugManager(const DebugManager &) = default;
        DebugManager(const DebugManager &&) = default;
        DebugManager & operator =(const DebugManager &) = default;
        DebugManager & operator =(const DebugManager &&) = default;
        ~DebugManager() = default;
    };

  protected:
    DebugManager<std::string> _debug;

    Debuggable() = default;
    Debuggable(const Debuggable & debuggable) = default;
    Debuggable(const Debuggable && debuggable) = default;
};

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
//


} // namespace
#endif // DEBUGGABLE_H
