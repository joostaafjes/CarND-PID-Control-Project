//
// Created by Joost Aafjes on 29/12/2018.
//

#ifndef PID_ABSTRACTCONTROLLER_H
#define PID_ABSTRACTCONTROLLER_H


#include <cmath>

using namespace std;

class AbstractController {

 protected:
  double cte;

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

  /*
  * Constructor
  */
  AbstractController();

  /*
  * Destructor.
  */
  virtual ~AbstractController();

  /*
  * Initialize PController.
  */
  virtual void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PController error variables given cross track error.
  */
  void UpdateError(double cte);

  double UpdateSteer();

  /*
  * Calculate the total PController error.
  */
  virtual double TotalError();
};

#endif //PID_ABSTRACTCONTROLLER_H
