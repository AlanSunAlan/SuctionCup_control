# SuctionCup_control
ROS package for controlling the suction cup which is connected to an arduino UNO board

## **Installing dependencies**
  run the following command to install rosserial and rosserial-python
> sudo apt-get install ros-kinetic-rosserial
> sudo apt-get install ros-kinetic-rosserial
  
## **Clone the package to your workspace src directory**
## **catkin_make your workspace**
## **To use the package**

1. Include the launch file(**suction_cup.launch**) in the **launch** folder to your own launch file
1. After launching the file, the suction_control_service is on. Call the service providing the request string:
  * **"power_on"**: Turn the power of the pump on;
  * **"power_off"**: Turn the power of the pump off;
  * **"suction_in"**: The suction cup begins to "breath in" air so that the object can attach to the cup
  * **"suction_still"**:Nearly useless now. The suction cup slightly blow some air out.
  * **"suction_out"**: The suction cup blows air out so that the object can be dettached from the cup.


