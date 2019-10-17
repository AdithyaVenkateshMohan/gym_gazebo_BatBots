
"use strict";

let ScanAngle = require('./ScanAngle.js');
let CliffEvent = require('./CliffEvent.js');
let Sound = require('./Sound.js');
let BumperEvent = require('./BumperEvent.js');
let VersionInfo = require('./VersionInfo.js');
let Led = require('./Led.js');
let PowerSystemEvent = require('./PowerSystemEvent.js');
let WheelDropEvent = require('./WheelDropEvent.js');
let DigitalOutput = require('./DigitalOutput.js');
let RobotStateEvent = require('./RobotStateEvent.js');
let SensorState = require('./SensorState.js');
let DigitalInputEvent = require('./DigitalInputEvent.js');
let MotorPower = require('./MotorPower.js');
let ControllerInfo = require('./ControllerInfo.js');
let KeyboardInput = require('./KeyboardInput.js');
let ExternalPower = require('./ExternalPower.js');
let DockInfraRed = require('./DockInfraRed.js');
let ButtonEvent = require('./ButtonEvent.js');
let AutoDockingActionFeedback = require('./AutoDockingActionFeedback.js');
let AutoDockingAction = require('./AutoDockingAction.js');
let AutoDockingFeedback = require('./AutoDockingFeedback.js');
let AutoDockingActionGoal = require('./AutoDockingActionGoal.js');
let AutoDockingGoal = require('./AutoDockingGoal.js');
let AutoDockingResult = require('./AutoDockingResult.js');
let AutoDockingActionResult = require('./AutoDockingActionResult.js');

module.exports = {
  ScanAngle: ScanAngle,
  CliffEvent: CliffEvent,
  Sound: Sound,
  BumperEvent: BumperEvent,
  VersionInfo: VersionInfo,
  Led: Led,
  PowerSystemEvent: PowerSystemEvent,
  WheelDropEvent: WheelDropEvent,
  DigitalOutput: DigitalOutput,
  RobotStateEvent: RobotStateEvent,
  SensorState: SensorState,
  DigitalInputEvent: DigitalInputEvent,
  MotorPower: MotorPower,
  ControllerInfo: ControllerInfo,
  KeyboardInput: KeyboardInput,
  ExternalPower: ExternalPower,
  DockInfraRed: DockInfraRed,
  ButtonEvent: ButtonEvent,
  AutoDockingActionFeedback: AutoDockingActionFeedback,
  AutoDockingAction: AutoDockingAction,
  AutoDockingFeedback: AutoDockingFeedback,
  AutoDockingActionGoal: AutoDockingActionGoal,
  AutoDockingGoal: AutoDockingGoal,
  AutoDockingResult: AutoDockingResult,
  AutoDockingActionResult: AutoDockingActionResult,
};
