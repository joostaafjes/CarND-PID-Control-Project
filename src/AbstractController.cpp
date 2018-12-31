#include "AbstractController.h"

using namespace std;
/*
* TODO: Complete the PController class.
*/

AbstractController::AbstractController() = default;

AbstractController::~AbstractController() = default;

void AbstractController::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void AbstractController::UpdateError(double cte) {
  this->cte = cte;
}

double AbstractController::UpdateSteer() {

  return -Kp * cte;
}
