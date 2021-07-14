/*
 * bunker_robot.hpp
 *
 * Created on: Jul 14, 2021 23:08
 * Description:
 *
 * Copyright (c) 2021 Ruixiang Du (rdu)
 */

#ifndef BUNKER_ROBOT_HPP
#define BUNKER_ROBOT_HPP

#include <memory>

#include "ugv_sdk/details/interface/robot_interface.hpp"
#include "ugv_sdk/details/interface/bunker_interface.hpp"

namespace westonrobot {
class BunkerRobot : public RobotInterface, public BunkerInterface {
 public:
  BunkerRobot(ProtocolVersion protocol = ProtocolVersion::AGX_V2);
  ~BunkerRobot();

  void Connect(std::string can_name) override;

  void EnableCommandedMode() override;

  void SetMotionCommand(double linear_vel, double angular_vel) override;

  void ResetRobotState() override;

  ProtocolVersion GetProtocolVersion() override;

  // get robot state
  BunkerCoreState GetRobotState() override;

 private:
  RobotInterface* robot_;
};
}  // namespace westonrobot

#endif /* BUNKER_ROBOT_HPP */
