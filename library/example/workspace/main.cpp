#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

#include "source1.cpp"
#include "source2.cpp"
#include "source3.cpp"

int main()
{
  cout << "main()" << endl;


  /**
  DebugManagerWrapper<int,double,float,char,string,bool> dmw;
  dmw << 10 << 3.14 << "string" << 'c';
  **/

  DebugManager<string> dm;

  dm.loggers.push_back(shared_ptr<Logger<string>> { new CoutLogger<string> } );
  dm.loggers.push_back(shared_ptr<Logger<string>> { new CerrLogger<string> } );

  dm << "tekst" << "tekst2";

  printf("tekst", 100, 3.14, 'x');

  Test<int,string,string,double,char> test { 10, "tekst", "tekst2", 3.14, 'a' };
  test( 10, "tekst", "tekst2", 3.14, 'a' );

  wecho(string("string echo"));
  wecho(10);
  wecho('x');
  wecho("normal echo");

  echof("pi =", ' ', 3.14);

  /**
  dm.loggers.push_back(shared_ptr<LoggerConcept> { new CoutLoggerWrapper } );
  dm.loggers.push_back(shared_ptr<LoggerConcept> { new CerrLoggerWrapper } );

  dm << "pi = " << 3.14 << " " << 'e' << " = " << 3000000; // << endl
  **/
}
