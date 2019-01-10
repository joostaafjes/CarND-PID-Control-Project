#include "PIDController.h"

using namespace std;
/*
* TODO: Complete the PController class.
*/

double PIDController::UpdateSteer() {
  double cte_diff = cte - cte_prev;
  cte_prev = cte;
  cte_sum += cte;

  return -Kp * cte - Kd * cte_diff - Ki * cte_sum;
}

bool PIDController::UpdateParameters() {
  return true;
}

void PIDController::InitParameters() {}
