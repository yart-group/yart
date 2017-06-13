
template<typename OutputType>
class Logger
{
  public:
    virtual Logger & operator << (OutputType output) = 0;
};

template<typename OutputType>
class CoutLogger : public Logger<OutputType>
{
  public:
    CoutLogger & operator << (OutputType output){
      cout << "cout(" << output << ")" << endl;
      return * this;
    }
};

template<typename OutputType>
class CerrLogger : public Logger<OutputType>
{
  public:
    CerrLogger & operator << (OutputType output){
      cout << "cerr(" << output << ")" << endl;
      return * this;
    }
};

template<typename OutputType>
class DebugManager
{
  public:
    vector<shared_ptr<Logger<OutputType>>> loggers;

    template<typename OType>
    DebugManager & operator << (OType output)
    {
      cout << "===== DM =====" << endl;
      for(auto logger : loggers)
        *logger << output;
      cout << "==============" << endl;
      return *this;
    }
};
