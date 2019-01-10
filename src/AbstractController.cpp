#include "AbstractController.h"

using namespace std;
/*
* TODO: Complete the PController class.
*/

AbstractController::AbstractController() = default;

//AbstractController::~AbstractController() = default;

void AbstractController::UpdateError(double cte) {
  this->cte = cte;
}

double AbstractController::UpdateSteer() {

  return -Kp * cte;
}

