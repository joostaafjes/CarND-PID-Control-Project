#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include <cmath>
#include "AbstractController.h"

using namespace std;

class PIDController: public AbstractController {
 protected:
  double cte_prev = 0.0;
  double cte_sum = 0.0;
 public:
  double UpdateSteer();
  bool UpdateParameters();
  void InitParameters();
};

#endif /* PID_H */
