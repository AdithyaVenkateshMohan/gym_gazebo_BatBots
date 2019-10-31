
"use strict";

let DockInfraRed = require('./DockInfraRed.js');
let ButtonEvent = require('./ButtonEvent.js');
let DigitalOutput = require('./DigitalOutput.js');
let MotorPower = require('./MotorPower.js');
let VersionInfo = require('./VersionInfo.js');
let DigitalInputEvent = require('./DigitalInputEvent.js');
let WheelDropEvent = require('./WheelDropEvent.js');
let KeyboardInput = require('./KeyboardInput.js');
let Led = require('./Led.js');
let BumperEvent = require('./BumperEvent.js');
let Sound = require('./Sound.js');
let PowerSystemEvent = require('./PowerSystemEvent.js');
let ScanAngle = require('./ScanAngle.js');
let RobotStateEvent = require('./RobotStateEvent.js');
let ControllerInfo = require('./ControllerInfo.js');
let SensorState = require('./SensorState.js');
let CliffEvent = require('./CliffEvent.js');
let ExternalPower = require('./ExternalPower.js');
let AutoDockingActionGoal = require('./AutoDockingActionGoal.js');
let AutoDockingResult = require('./AutoDockingResult.js');
let AutoDockingGoal = require('./AutoDockingGoal.js');
let AutoDockingFeedback = require('./AutoDockingFeedback.js');
let AutoDockingActionResult = require('./AutoDockingActionResult.js');
let AutoDockingActionFeedback = require('./AutoDockingActionFeedback.js');
let AutoDockingAction = require('./AutoDockingAction.js');

module.exports = {
  DockInfraRed: DockInfraRed,
  ButtonEvent: ButtonEvent,
  DigitalOutput: DigitalOutput,
  MotorPower: MotorPower,
  VersionInfo: VersionInfo,
  DigitalInputEvent: DigitalInputEvent,
  WheelDropEvent: WheelDropEvent,
  KeyboardInput: KeyboardInput,
  Led: Led,
  BumperEvent: BumperEvent,
  Sound: Sound,
  PowerSystemEvent: PowerSystemEvent,
  ScanAngle: ScanAngle,
  RobotStateEvent: RobotStateEvent,
  ControllerInfo: ControllerInfo,
  SensorState: SensorState,
  CliffEvent: CliffEvent,
  ExternalPower: ExternalPower,
  AutoDockingActionGoal: AutoDockingActionGoal,
  AutoDockingResult: AutoDockingResult,
  AutoDockingGoal: AutoDockingGoal,
  AutoDockingFeedback: AutoDockingFeedback,
  AutoDockingActionResult: AutoDockingActionResult,
  AutoDockingActionFeedback: AutoDockingActionFeedback,
  AutoDockingAction: AutoDockingAction,
};
