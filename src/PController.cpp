#include "PController.h"

using namespace std;
/*
* TODO: Complete the PController class.
*/

double PController::UpdateSteer() {
  return -Kp * cte;
}

