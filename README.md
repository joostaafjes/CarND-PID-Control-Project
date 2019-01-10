# CarND-Controls-PController
Self-Driving Car Engineer Nanodegree Program

---

## Reflection

### Description P, I and D components

PID (Proportional Integral Derivative) controller is a way of controlling a process with a specific setpoint that should be reached as smoothly as possible. Below the P, I and D factors are described.

#### Proportional (P)

The P term is the most direct parameter that is proportional to the error (difference between current position and desired position). By only using this parameter the controller is generally not diverting to the target but is either not reaching the target or by overshooting.

#### Integral (I)

The integral terms integrate the differences the errors over the past and this causes a smoothing effect and can correct structural errors in the vehicle.

#### Derivative (D)

The derivative term is related to the derivative of the error and smoothen rappid changes.

### Hyperparameter optimization

I have used the following approach to optimize the parameters.

#### Determine initial values for Twiddle

I have used Twiddle to determine the parameters one by one:
1. First use Twiddle to determine P with the PController: P -> 0.0372526
2. Use Twiddle to determine the best D with this P: D -> 1.5
3. Use Twiddle to determine the best I with these P and D: I -> 0.0001

With these manual tuning the vehicle was able to drive about 1/2 a round

#### Use Twiddle to optimize parameters

After these I used Twiddle to optimize this. The parameter in the previous section were used as initial values.

After 100 iterations the following optimized parameters were achieved:
- P: 0.0736962
- D: 1.43243
- I: 0.000122645

The following has been adapted/customized to the Twiddle algorithm learned in the lesson:
- The number of steps were increased to 600
- To save time during learning maximum steering angle was introduced. If exceeded, the cycle was aborted.
- To save time during learning maximum CTE error was introduced. If exceeded, the cycle was aborted.

To be sure that every cycle was started with the same conditions, a reset had to be built in that could let the simulator use some time to go the start position (in combination with a 10 sec sleep)

See below the result of 1 round in the simulator

[![PID Controller with simulator](https://img.youtube.com/vi/fV79y79B4F0/0.jpg)](https://www.youtube.com/watch?v=fV79y79B4F0)

fV79y79B4F0

#### Discussion

- Local minimum: it looks like the Twiddle algoritme is not diverting to the best solution but to a optimum that is relative. 
- Delay: it looks like the delay in the simulator (that probably is related to vehicle characteristics) is causing issues.
- The found solution doesn't look like a smooth and optimal solution. I assume improvement should be made (I haven't found them yet and looking forward to the next lessons :-)

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

Fellow students have put together a guide to Windows set-up for the project [here](https://s3-us-west-1.amazonaws.com/udacity-selfdrivingcar/files/Kidnapped_Vehicle_Windows_Setup.pdf) if the environment you have set up for the Sensor Fusion projects does not work for this project. There's also an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PController-Control-Project/pull/3).

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

