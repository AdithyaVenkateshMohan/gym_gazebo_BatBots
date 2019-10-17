
"use strict";

let FileRemove = require('./FileRemove.js')
let CommandLong = require('./CommandLong.js')
let FileOpen = require('./FileOpen.js')
let FileList = require('./FileList.js')
let FileMakeDir = require('./FileMakeDir.js')
let FileWrite = require('./FileWrite.js')
let SetMode = require('./SetMode.js')
let FileChecksum = require('./FileChecksum.js')
let CommandInt = require('./CommandInt.js')
let WaypointPull = require('./WaypointPull.js')
let CommandBool = require('./CommandBool.js')
let ParamPush = require('./ParamPush.js')
let StreamRate = require('./StreamRate.js')
let CommandHome = require('./CommandHome.js')
let FileClose = require('./FileClose.js')
let ParamPull = require('./ParamPull.js')
let FileTruncate = require('./FileTruncate.js')
let WaypointSetCurrent = require('./WaypointSetCurrent.js')
let WaypointPush = require('./WaypointPush.js')
let WaypointClear = require('./WaypointClear.js')
let CommandTOL = require('./CommandTOL.js')
let FileRename = require('./FileRename.js')
let CommandTriggerControl = require('./CommandTriggerControl.js')
let FileRead = require('./FileRead.js')
let ParamGet = require('./ParamGet.js')
let FileRemoveDir = require('./FileRemoveDir.js')
let ParamSet = require('./ParamSet.js')

module.exports = {
  FileRemove: FileRemove,
  CommandLong: CommandLong,
  FileOpen: FileOpen,
  FileList: FileList,
  FileMakeDir: FileMakeDir,
  FileWrite: FileWrite,
  SetMode: SetMode,
  FileChecksum: FileChecksum,
  CommandInt: CommandInt,
  WaypointPull: WaypointPull,
  CommandBool: CommandBool,
  ParamPush: ParamPush,
  StreamRate: StreamRate,
  CommandHome: CommandHome,
  FileClose: FileClose,
  ParamPull: ParamPull,
  FileTruncate: FileTruncate,
  WaypointSetCurrent: WaypointSetCurrent,
  WaypointPush: WaypointPush,
  WaypointClear: WaypointClear,
  CommandTOL: CommandTOL,
  FileRename: FileRename,
  CommandTriggerControl: CommandTriggerControl,
  FileRead: FileRead,
  ParamGet: ParamGet,
  FileRemoveDir: FileRemoveDir,
  ParamSet: ParamSet,
};
