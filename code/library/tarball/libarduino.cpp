
//kappa "port.h"

Port::Port() :
  _usable(false),
  _port(0),
  _min(1),
  _max(10)
{}

bool Port::setPort(int port)
{
  if(port < _min || port > _max) return false;
  _port = port;
  _usable = true;
  return true;
}
int Port::getPort()
{
  return ( _usable ? _port : -1 );
}
//kappa "meta.h"
//kappa "logger.h"
//kappa "debugmanager.h"

DebugManager::DebugManager() :
  _enabled(false),
  _logger(nullptr),
  _loggers(0)
{
  _logger = new Logger * [10];
  for(int i=0; i<10; i++)
    _logger[i] = nullptr;
}

DebugManager & DebugManager::operator << (const char * data)
{
  if(isEnabled() == false) return *this;

  for(int i=0; i<_loggers; i++)
    *_logger[i] << data;

  return *this;
}
DebugManager & DebugManager::operator << (double data)
{
  if(isEnabled() == false) return *this;

  for(int i=0; i<_loggers; i++)
    *_logger[i] << data;

  return *this;
}
DebugManager & DebugManager::operator << (Meta data)
{
  if(isEnabled() == false) return *this;

  for(int i=0; i<_loggers; i++)
    *_logger[i] << data;

  return *this;
}

bool DebugManager::add(Logger *logger)
{
  if(! logger) return false;

  for(int i=0; i<_loggers; i++)
    if(_logger[i] == logger)
      return false;

  _logger[_loggers] = logger;
  _loggers++;
  return true;
}
bool DebugManager::del(Logger *logger)
{
  if(! logger) return false;

  for(int i=0; i<_loggers; i++)
    if(_logger[i] == logger){
      for(; i<_loggers-1; i++)
        _logger[i] = _logger[i+1];
      _logger[i] = nullptr;
      _loggers--;
      return true;
    }

  return false;
}
//kappa "device.h"

//kappa "gadget.h"

bool Gadget::init()
{
  if( ! Device::init() ) return false;

  if( ! reconnect() )
    _state = NOT_WORKING;

  return isWorking();
}
//kappa "inputgadget.h"
//kappa "outputgadget.h"
//kappa "iogadget.h"
//kappa "cable.h"
//kappa "motor.h"

void Motor::setPowerOff()
{
  OutputGadget::setPowerOff();
  if(_motor) delete _motor;
  _motor = nullptr;
}


bool Motor::reconnect()
{
  if(port.isUsable() == false) return false;

  if(_motor) delete _motor;
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _motor = new MeDCMotor( port.getPort() );
#else
  _motor = new int;
#endif

  return true;
}

void Motor::write(double data)
{
  if(! isWorking()) return;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _motor->run(data);
#endif
}
//kappa "battery.h"
//kappa "sensor.h"
//kappa "infraredsensor.h"

void InfraredSensor::setPowerOff()
{
  Sensor::setPowerOff();
  if(_sensor) delete _sensor;
  _sensor = nullptr;
}

bool InfraredSensor::reconnect()
{
  if(port.isUsable() == false) return false;

  if(_sensor) delete _sensor;
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _sensor = new MeInfraredSensor( port.getPort() );
  _sensor->begin();
#else
  _sensor = new int;
#endif

  return true;
}

bool InfraredSensor::loop()
{
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _sensor->loop();
#endif
  return true;
}

double InfraredSensor::read()
{
  if(! isWorking()) return -1;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  return _sensor->getCode();
#else
  return 0;
#endif
}
//kappa "ultrasonicsensor.h"

void UltrasonicSensor::setPowerOff()
{
  Sensor::setPowerOff();
  if(_sensor) delete _sensor;
  _sensor = nullptr;
}

bool UltrasonicSensor::reconnect()
{
  if(port.isUsable() == false) return false;

  if(_sensor) delete _sensor;
#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _sensor = new MeUltrasonicSensor( port.getPort() );
#else
  _sensor = new int;
#endif

  return true;
}

double UltrasonicSensor::read()
{
  if(! isWorking()) return -1;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  return _sensor->distanceCm();
#else
  return 0;
#endif
}
//kappa "flash.h"

Flash::Flash()
{

}
//kappa "usb.h"

Usb::Usb()
{

}
//kappa "pilot.h"

bool Pilot::init()
{
  if(! Device::init()) return false;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _infraredSensor.port.setPort(6);
  _infraredSensor.init();
  if( _infraredSensor.isWorking() )
    return true;
  else
    return false;
#endif
  return true;
}
void Pilot::setPowerOn()
{
  Device::setPowerOn();
  _infraredSensor.setPowerOn();
}
void Pilot::setPowerOff()
{
  _infraredSensor.setPowerOff();
  Device::setPowerOff();
}

int Pilot::getCode()
{
  if(! isWorking()) return -1;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  _lastCode = _infraredSensor.read();
  _infraredSensor.loop();
  return _lastCode;
#else
  return 0;
#endif

}
int Pilot::getLast()
{
  if(! isWorking()) return -1;

#if COMPILE_FOR_ARDUINO_UPLOAD == true
  return _lastCode;
#else
  return 0;
#endif
}
//kappa "robot.h"
//kappa "motherboard/motherboard.h"

Robot::Robot() : _motherboard(nullptr)
{
  strcpy(_leftMotor.meta.name, "left motor");
  strcpy(_rightMotor.meta.name, "right motor");
  strcpy(_ultrasonicSensor.meta.name, "ultrasonic");
}

bool Robot::init()
{
  if(! Device::init()) return false;

  _leftMotor.port.setPort(9);
  _rightMotor.port.setPort(10);
  _ultrasonicSensor.port.setPort(3);

  bool success = true;
  success &= _leftMotor.init();
  success &= _rightMotor.init();
  success &= _ultrasonicSensor.init();

  return success;
}
void Robot::setPowerOn()
{
  Device::setPowerOn();
  _leftMotor.setPowerOn();
  _rightMotor.setPowerOn();
  _ultrasonicSensor.setPowerOn();
}
void Robot::setPowerOff()
{
  _leftMotor.setPowerOff();
  _rightMotor.setPowerOff();
  _ultrasonicSensor.setPowerOff();
  Device::setPowerOff();
}

bool Robot::mount(Motherboard *motherboard)
{
  if(motherboardMounted()) return false;
  _motherboard = motherboard;
  _motherboard->plug(this);
  _motherboard->plug(& _leftMotor);
  _motherboard->plug(& _rightMotor);
  _motherboard->plug(& _ultrasonicSensor);
  return true;
}
bool Robot::unmount()
{
  if(! motherboardMounted()) return false;
  _motherboard->unplug(& _leftMotor);
  _motherboard->unplug(& _rightMotor);
  _motherboard->unplug(& _ultrasonicSensor);
  _motherboard->unplug();
  _motherboard = nullptr;
  return true;
}
bool Robot::motherboardMounted()
{
  return _motherboard;
}
//kappa "motherboard.h"

Motherboard::Motherboard() :
  _kernel(nullptr),
  _robot(nullptr),
  _gadgets(0),
  _gadget(nullptr)
{
  _gadget = new Gadget*[10];
  for(int i=0; i<10; i++) _gadget[i] = nullptr;
}

void Motherboard::setPowerOff()
{
  Device::setPowerOff();
  unload();
}

bool Motherboard::plug(Gadget *gadget)
{
  if(!gadget) return false;

  for(int i=0; i<_gadgets; i++)
    if(_gadget[i] == gadget || !strcmp(_gadget[i]->meta.name, gadget->meta.name))
       return false;

  _gadget[_gadgets] = gadget;
  _gadgets++;
  return true;

}
bool Motherboard::plug(Robot *robot)
{
  if(!robot) return false;
  if(plugged()) return false;
  _robot = robot;
  return true;
}

bool Motherboard::unplug(Gadget *gadget)
{
  if(!gadget) return false;

  for(int i=0; i<_gadgets; i++){
    if(_gadget[i] == gadget){
      for(; i<_gadgets-1; i++){
        _gadget[i] = _gadget[i+1];
      }
      _gadget[i] = nullptr;
      _gadgets--;
      return true;
    }
  }

  return false;
}
bool Motherboard::unplug()
{
  if(!plugged()) return false;
  _robot = nullptr;
  return true;
}
bool Motherboard::unplug(Meta meta)
{
  for(int i=0; i<_gadgets; i++){
    if(_gadget[i]->meta.type == meta.type && !strcmp(_gadget[i]->meta.name, meta.name)){
      for(; i<_gadgets-1; i++){
        _gadget[i] = _gadget[i+1];
      }
      _gadget[i] = nullptr;
      _gadgets--;
      return true;
    }
  }

  return false;
}

bool Motherboard::plugged()
{
  return _robot;
}
bool Motherboard::plugged(Gadget *gadget)
{
  if(!gadget) return false;

  for(int i=0; i<_gadgets; i++)
    if(_gadget[i] == gadget)
       return true;

  return false;
}
bool Motherboard::plugged(Robot *robot)
{
  if(!robot) return false;
  return _robot == robot;
}
bool Motherboard::plugged(Meta meta)
{
  for(int i=0; i<_gadgets; i++)
    if(_gadget[i]->meta.type == meta.type && !strcmp(_gadget[i]->meta.name, meta.name))
       return true;

  return false;
}

Gadget * Motherboard::get(Meta meta)
{
  for(int i=0; i<_gadgets; i++)
    if(_gadget[i]->meta.type == meta.type && !strcmp(_gadget[i]->meta.name, meta.name))
       return _gadget[i];

  return nullptr;
}

bool Motherboard::load(Kernel *kernel)
{
  if(! isWorking()) return false;
  if(_kernel) return false;
  _kernel = kernel;
  return true;
}
bool Motherboard::unload()
{
  if(! isWorking()) return false;
  if(! _kernel) return false;
  _kernel = nullptr;
  return true;
}
//kappa "program.h"

bool Program::pair(Kernel *kernel)
{
  if(paired()) return false;
  _kernel = kernel;
  return true;
}
bool Program::unpair()
{
  if(! paired()) return false;
  _kernel = nullptr;
  return true;
}
bool Program::paired()
{
  return _kernel;
}
//kappa "driver.h"

Driver::Driver()
{
  meta.type = Meta::Driver;
  lastMsg = new char[20];

  strcpy(lastMsg, "created");
}

int Driver::main(int argc, char const * const * argv)
{
  if(!argc)
    return ! install();

  if(argc == 1 && !strcmp(argv[0], "uninstall"))
    return ! uninstall();

  return controller(argc, argv);
}
//kappa "programcontainer.h"

ProgramContainer::ProgramContainer() : _loads(0)
{
  _table = new Program*[30];

  for(int i=0; i<30; i++)
    _table[i] = nullptr;
}

bool ProgramContainer::add(Program * program)
{
  if(!program) return false;

  for(int i=0; i<_loads; i++)
    if(_table[i] == program || !strcmp(_table[i]->meta.name, program->meta.name))
      return false;

  _table[_loads] = program;
  _loads++;
  return true;
}

bool ProgramContainer::remove(Program * program)
{
  if(!program) return false;

  for(int i=0; i<_loads; i++){
    if(_table[i] == program){
      for(; i<_loads-1; i++)
        _table[i] = _table[i-1];
      _table[i] = nullptr;
      _loads--;
      return true;
    }
  }

  return false;
}
bool ProgramContainer::remove(Meta meta)
{
  for(int i=0; i<_loads; i++){
    if(_table[i]->meta.type == meta.type && !strcmp(_table[i]->meta.name, meta.name)){
      for(; i<_loads-1; i++)
        _table[i] = _table[i-1];
      _table[i] = nullptr;
      _loads--;
      return true;
    }
  }

  return false;
}

bool ProgramContainer::check(Program * program)
{
  if(!program) return false;

  for(int i=0; i<_loads; i++)
    if(_table[i] == program)
      return true;

  return false;
}
bool ProgramContainer::check(Meta meta)
{
  for(int i=0; i<_loads; i++)
    if(_table[i]->meta.type == meta.type && !strcmp(_table[i]->meta.name, meta.name))
      return true;

  return false;
}

Program * ProgramContainer::get(Meta meta)
{
  for(int i=0; i<_loads; i++)
    if(_table[i]->meta.type == meta.type && !strcmp(_table[i]->meta.name, meta.name))
      return _table[i];

  return nullptr;
}
//kappa "commandtable.h"


CommandTable::CommandTable() : _commands(0)
{
  _command = new const char * [30];
  _driver = new Program * [30];

  for(int i=0; i<30; i++){
    _command[i] = nullptr;
    _driver[i] = nullptr;
  }
}

bool CommandTable::add(const char *cmd, Program *driver)
{
  if(!cmd || !driver) return false;

  for(int i=0; i<_commands; i++)
    if(_driver[i] == driver && !strcmp(_command[i], cmd))
      return false;

  _command[_commands] = cmd;
  _driver[_commands] = driver;
  _commands++;
  return true;

}
bool CommandTable::del(const char *cmd, Program *driver)
{
  if(!cmd || !driver) return false;

  for(int i=0; i<_commands; i++)
    if(_driver[i] == driver && !strcmp(_command[i], cmd)){
      for(; i<_commands-1; i++){
        _command[i] = _command[i+1];
        _driver[i] = _driver[i+1];
      }
      _command[i] = nullptr;
      _driver[i] = nullptr;

      _commands--;
      return true;
    }

  return false;
}

int CommandTable::exec(int argc, char const * const * argv)
{
  int exit_code = -1;

  for(int i=0; i<_commands; i++){
    if(!strcmp(_command[i], argv[0])){
      exit_code = _driver[i]->controller(argc, argv);
      if(exit_code != -1) return exit_code;
    }
  }

  return -1;
}

//kappa "kernel.h"

//kappa <cstring>

bool Kernel::run()
{
  if(_enabled) return false;
  _enabled = true;
  return true;
}
bool Kernel::quit()
{
  if(!_enabled) return false;
  _enabled = false;
  return true;
}
bool Kernel::load(Program *program)
{
  if(!_enabled) return false;
  if(!program) return false;

  program->pair(this);

  if(program->meta.type == Meta::Program)
    return _programs.add(program);
  else
    return _drivers.add(program);
}
bool Kernel::unload(Meta meta)
{
  if(!_enabled) return false;

  if(meta.type == Meta::Program)
    return _programs.remove(meta);
  else
    return _drivers.remove(meta);

}
bool Kernel::start(Meta meta)
{
  if(!_enabled) return false;

  Program * program;

  if(meta.type == Meta::Program)
    program = _programs.get(meta);
  else
    program = _drivers.get(meta);

  if(!program) return false;

  if(meta.type == Meta::Driver)
    _startedDrivers.add(program);

  return ! ( program -> main() );
}
bool Kernel::stop(Meta meta)
{
  if(!_enabled) return false;

  Program * program;

  if(meta.type == Meta::Program)
    program = _startedPrograms.get(meta);
  else
    program = _startedDrivers.get(meta);

  if(!program) return false;

  program -> uninstall();

  if(meta.type == Meta::Program)
    _startedPrograms.remove(program);
  else
    _startedDrivers.remove(program);

  return true;
}
int Kernel::command(const char *cmd)
{
  if(!_enabled) return false;
  if(!cmd) return false;

  int argc = 0;
  char ** argv = new char * [10];
  for(int i=0; i<10; i++)
    argv[i] = new char[10];

  int a = 0;
  for(int i=0; ;i++)
  {
    if(cmd[i] == ' ' || cmd[i] == 0){
      strncpy(argv[argc], cmd+a, i-a);
      argv[argc][i-a] = 0;
      argc++;
      a=i+1;
    }

    if(cmd[i] == 0) break;
  }

  return _commandTable.exec(argc, argv);
}





