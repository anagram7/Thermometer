#ifndef _H_Clonable
#define _H_Clonable

//#include <iostream>

namespace mas {

class Clonable {
public:
  virtual Clonable* Clone() const = 0;
  virtual ~Clonable() {};
};

}

#endif

