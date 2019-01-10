#ifndef PID_H
#define PID_H

#include <cmath>
#include "AbstractController.h"

using namespace std;

class PController: public AbstractController {
 public:
  double UpdateSteer();
};

#endif /* PID_H */
