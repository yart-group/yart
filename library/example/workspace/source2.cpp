void printf() {
  cout << "." << endl;
}

template<typename T, typename ... Args>
void printf(T a, Args ... args){
  cout << a << ' ';
  printf(args ...);
}

template<typename T, typename ... Args>
class Test
{
  public:
    Test(T arg, Args ... args) {
      printf(arg, args ...);
    }

    virtual void operator () (T arg, Args ... args){
      printf(arg, args ...);
    }
};

template<typename T = string>
class echo
{
  public:
    echo(T x) {
    }
};

template</*typename T*/>
class echo<string>
{
  public:
    echo(string x) {
      cout << x << endl;
    }
};

template<typename T>
void wecho(T x){
  echo<T> v (x);
}

//preferencja dla funckji
// (tłumienie argumentów szablonowych poza wybranymi, tak jak preferencja string w clasie echo)
