#pragma once

namespace router {

namespace ErrorCode {
enum Code {
  NoError = 0,
  ParameterInvalid = 1,
  ManifestError = 2,
  FileNotExist = 3,
  ApiCallFail = 4,
  DupDownload = 5,
  DirectoryNotExist = 6,
  InvalidParameter = 7,
  ConfigException = 8,
  LockError = 9,
  SDKPermissionDenied = 10,
  HttpRequestFailed = 11,
  GetDeviceListFailed = 12,
  CallPluginCenterFailed = 13,
  CallPluginCenterNoReturn = 14,
  DownloadTaskFailed = 15,
};
}

}

