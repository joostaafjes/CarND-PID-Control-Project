#ifndef PD_CONTROLLER_H
#define PD_CONTROLLER_H

#include <cmath>
#include "AbstractController.h"

using namespace std;

class PDController: public AbstractController {
 protected:
  double cte_prev = 0;
 public:
  double UpdateSteer();
};

#endif /* PID_H */
