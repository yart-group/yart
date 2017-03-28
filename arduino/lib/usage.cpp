bool strcmp(const char * a, const char * b){
  while( *(a++) == *(b++) ) ; a--; b--;
  if(*a == 0 || *b == 0) return true;
  if(*a != *b) return false;
  return true;
}


class BasicMovement : public Programmer::Kernel::Driver
{
  public:
    BasicMovement() : meta("basic movement") {}

    virtual int main(int argc, const char * argv[]) {
      if(argv == 0) return !install();
      if(argv == 1 && argv[0] == "uninstall") return !unistall();
      return -1;
    }

    virtual int controller(int argc, const char * argv[] ){
      if(argc != 3) return -1;
      if(argv[0] != "move") -1;
      int code = translate
    }

    int translate(const char * param){
      if(param == "FORWARD") return FORWARD;
      else if(param == "") return ...;
      else return -1;
    }

    bool install(){

    }

    bool uninstall(){

    }

    enum Direction {
      FORWARD,
      LEFT,
      RIGHT,
      BACK,
      STOP
    };

    void move(Direction direction, int speed){

    }


};
