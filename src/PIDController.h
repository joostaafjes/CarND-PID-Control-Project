#ifndef PD_CONTROLLER_H
#define PD_CONTROLLER_H

#include <cmath>
#include "AbstractController.h"

using namespace std;

class PIDController: public AbstractController {
 protected:
  double cte_prev = 0;
  double cte_sum = 0;
 public:
  double UpdateSteer();
};

#endif /* PID_H */
