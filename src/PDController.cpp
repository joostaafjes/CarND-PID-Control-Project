#include "PDController.h"

using namespace std;
/*
* TODO: Complete the PController class.
*/

double PDController::UpdateSteer() {
  double cte_diff = cte - cte_prev;
  cte_prev = cte;

  return -Kp * cte - Kd * cte_diff;
}

