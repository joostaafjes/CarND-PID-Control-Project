#ifndef PD_CONTROLLER_H
#define PD_CONTROLLER_H

#include <cmath>
#include <cfloat>
#include "AbstractController.h"

using namespace std;

class TwiddlePIDController: public AbstractController {
 private:
  const double tolerance = 0.003;
  const int min_steps = 500;
  const int max_steps = 600;
  const double steer_lower = -10.0;
  const double steer_upper = 10.0;
  const double cte_error_threshold = 20;
  const int no_of_params = 3;
  double best_error = DBL_MAX;
  void ResetCounters();
  int param_index = 0;
  double param[3] = {0.0, 0.0, 0.0};
  bool first_run = true;
//  double dparam[3] = {0.01, 0.1,  0.0};
//  double dparam[3] = {1.0, 1.0,  0.001};
//  double dparam[3] = {1.0, 1.0, 1.0};
//  double dparam[3] = {1.0, 0.0, 0.0};
//  double dparam[3] = {0.01, 0.0001, 0.1};
  double dparam[3] = {0.01, 0.1, 0.0001};
 protected:
  double cte_prev = 0;
  double cte_sum = 0;
  double cte_2_sum = 0;
  double steer;
 public:
  void Init(double Kp, double Ki, double Kd);
  double UpdateSteer();
  double TotalError();
  double AvgError();
  void InitParameters();
  bool UpdateParameters();
  double steps = 0;
};

#endif /* PID_H */
