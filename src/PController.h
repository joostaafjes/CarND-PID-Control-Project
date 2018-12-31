#ifndef PID_H
#define PID_H

#include <cmath>
#include "AbstractController.h"

using namespace std;

class PController: AbstractController {
  double UpdateSteer();
};

#endif /* PID_H */
