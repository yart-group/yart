#include "microcontroller.h"

#include "robot.h"

bool Microcontroller::plugRobot(Robot *robot){
  int robotId = robot->getId();
  int gadgets = robot->gadget.size();

  // nie chce mi sie implementorać iteratorów w moim vector<> kappa
  //gadget.insert(gadget.end(), robot->gadget.begin(), robot->gadget.end());

  for(int i=0; i<gadgets; ++i){
    gadget.push_back( (robot->gadget)[i] );
    _ids.push_back( robotId );
  }
}
bool Microcontroller::unplugRobot(int id){
  // TODO
}
bool Microcontroller::isRobotPlugged(int id){
  // TODO
}
int Microcontroller::getPluggedRobotsAmount(){
  // TODO
}
