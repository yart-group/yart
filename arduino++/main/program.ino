
class Program {
  public:
    enum ExitCode {
      ok,
      startup_error,
      execution_error,
    }
  
    virtual ExitCode init() = 0;
    virtual ExitCode run() = 0;
}


class Programator {
  public:
}

