
"use strict";

let CommandVelocityTrajectory = require('./CommandVelocityTrajectory.js');
let CommandMotorSpeed = require('./CommandMotorSpeed.js');
let CommandAttitudeThrust = require('./CommandAttitudeThrust.js');
let CommandRollPitchYawrateThrust = require('./CommandRollPitchYawrateThrust.js');
let CommandRateThrust = require('./CommandRateThrust.js');
let CommandTrajectory = require('./CommandTrajectory.js');
let MotorSpeed = require('./MotorSpeed.js');

module.exports = {
  CommandVelocityTrajectory: CommandVelocityTrajectory,
  CommandMotorSpeed: CommandMotorSpeed,
  CommandAttitudeThrust: CommandAttitudeThrust,
  CommandRollPitchYawrateThrust: CommandRollPitchYawrateThrust,
  CommandRateThrust: CommandRateThrust,
  CommandTrajectory: CommandTrajectory,
  MotorSpeed: MotorSpeed,
};
