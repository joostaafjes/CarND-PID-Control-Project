#include <iostream>
#include "TwiddlePIDController.h"

using namespace std;
/*
* TODO: Complete the PController class.
*/

void TwiddlePIDController::Init(double Kp, double Ki, double Kd) {
  param[0] = Kp;
  param[1] = Kd;
  param[2] = Ki;
}

double TwiddlePIDController::UpdateSteer() {
  double cte_diff = cte - cte_prev;
  cte_prev = cte;
  cte_sum += cte;

  steps++;
  if (steps >= min_steps) {
//    std::cout << "CTE:" << cte << ", cte_2_sum:" << cte_2_sum << "(" << steps << ")" << std::endl;
    cte_2_sum += pow(cte, 2);
  }

  double Termp = -param[0] * cte;
  double Termd = -param[1] * cte_diff;
  double Termi = -param[2] * cte_sum;
//  std::cout << "P:" << Termp << ",D:" << Termd << ",I:" << Termi << std::endl;

  steer = Termp + Termd + Termi;
//  steer = -param[0] * cte - param[1] * cte_diff - param[2] * cte_sum;

  return steer;
}

void TwiddlePIDController::InitParameters() {
  param[param_index] += dparam[param_index];
  iterations++;
}

bool TwiddlePIDController::UpdateParameters() {

  /*
   * Continue with current parameters
   */
//  if (fabs(param[0]) + fabs(param[1]) + fabs(param[2]) < tolerance) {
//    return true;
//  }

  if (steps <= min_steps && cte < cte_error_threshold && steer >= steer_lower && steer <= steer_upper) {
    return true;
  }

  /*
   * if error below threshold and current best...
   */
//  if (cte < cte_error_threshold && cte_2_sum < best_error && steps < max_steps) {
  if (steps > min_steps && steps < max_steps) {
    /*
     * continue with next step
     */
//    std:cout << "steps > min_steps && steps < max_steps" << std::endl;
    return true;
  }

//  if (cte < cte_error_threshold && cte_2_sum < best_error && steps == max_steps) {
//  if (cte_2_sum < best_error && steps == 2 * max_steps) {
  if (AvgError() < best_error) {
    /*
     * improvement
     */
    dparam[param_index] *= 1.1;
    best_error = AvgError();
    std::cout << "Improvement: " << param[0] << "," << param[1] << "," << param[2] << " (" << param_index << ") -> " << best_error <<
                           " - " << dparam[0] << "," << dparam[1] << "," << dparam[2] << std::endl;
    param_index = (param_index + 1) % no_of_params;
    ResetCounters();
    InitParameters();
    first_run = true;
    std::cout << "        try: " << param[0] << "," << param[1] << "," << param[2] << " (" << param_index << ") -> " <<
              " - " << dparam[0] << "," << dparam[1] << "," << dparam[2] << std::endl;
    return false;
  } else {
    if (cte > cte_error_threshold) {
      std::cout << "cte > cte_error_threshold (" << cte << ")-> retry..." << std::endl;
    }
    if (steer < steer_lower || steer > steer_upper) {
      std::cout << "Steer outside ["<< steer_lower << ", " << steer_upper << "] domain (" << steer << ")-> retry..." << std::endl;
    }
    if (first_run) {
      std::cout << "No improvement, try negative path with same parameter" << std::endl;
      param[param_index] -= 2 * dparam[param_index];
      first_run = !first_run;
      ResetCounters();
      iterations++;
    } else {
      std::cout << "No improvement, both pos and neg failed so try smaller delta but first continue with next param" << std::endl;
      param[param_index] += dparam[param_index];
      dparam[param_index] *= 0.9;
      param_index = (param_index + 1) % no_of_params;
      first_run = true;
      ResetCounters();
      InitParameters();
    }
    std::cout << "        try: " << param[0] << "," << param[1] << "," << param[2] << " (" << param_index << ") -> " <<
              " - " << dparam[0] << "," << dparam[1] << "," << dparam[2] << std::endl;
    return false;
  }

}

void TwiddlePIDController::ResetCounters() {
  steps = 0;
  cte = 0;
  cte_prev = 0;
  cte_sum = 0;
  cte_2_sum = 0;
}

double TwiddlePIDController::TotalError() {
  return cte_2_sum;
}

double TwiddlePIDController::AvgError() {
  if (steps <= min_steps) {
    return DBL_MAX;
  } else {
    return cte_2_sum / (steps - min_steps);
  }
}
