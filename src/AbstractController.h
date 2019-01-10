//
// Created by Joost Aafjes on 29/12/2018.
//

#ifndef PID_ABSTRACTCONTROLLER_H
#define PID_ABSTRACTCONTROLLER_H


#include <cmath>

using namespace std;

class AbstractController {

 protected:
  double cte = 0.0;

 public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */
  double Kp;
  double Ki;
  double Kd;

  int iterations = 0;

  /*
  * Constructor
  */
  AbstractController();

  /*
  * Destructor.
  */
//  virtual ~AbstractController();

  /*
  * Initialize PController.
  */
  void Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Kd = Kd;
    this->Ki = Ki;
  }

  /*
  * Update the PController error variables given cross track error.
  */
  void UpdateError(double cte);

  double UpdateSteer();

  void InitParameters() {
  }

  bool UpdateParameters() {
    return true;
  };

  /*
  * Calculate the total PController error.
  */
  double TotalError() {
    return 0;
  }
};

#endif //PID_ABSTRACTCONTROLLER_H
