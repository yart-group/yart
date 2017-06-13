
class CoutLoggerWrapper
{
  public:
    template<typename Output>
    CoutLoggerWrapper & operator << (Output output){
      CoutLogger<Output> os;
      os << output;
      return * this;
    }
};

void echof(){
  cout << ":" << endl;
}

template<typename T, typename ... Args>
void echof(T a, Args ... args){
  cout << a << ' ';
  echof(args ...);
}

template<typename T, typename ... Args>
void echof<string, Args>(T a, Args ... args){
  cout << "string(" << a << ") ";
  echof(args ...);
}
