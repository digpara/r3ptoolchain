/*
 * DeviceManager.h
 *
 *  Created on: 2014年3月6日
 *      Author: chengliang
 */

#ifndef DeviceManager_H_
#define DeviceManager_H_

#include "common.h"
#include <string>
#include "thrift/IThriftNotifier.hpp"
#include <vector>
namespace router {

struct DeviceInfo {
public:
  std::string ip;
  std::string mac;
};

struct RouterInfo {
public:
  std::string name;
  std::string version;
  std::string romType;
};

class DeviceManager {
public:
  static DeviceManager& sGetInstance();

  ErrorCode::Code getConnectedDeviceList(std::vector<DeviceInfo> & outputList);

  ErrorCode::Code setDeviceWanAccess(const std::string& mac, bool enable);

  ErrorCode::Code getRouterInfo(RouterInfo & output);
private:

  DeviceManager();
  virtual ~DeviceManager();
};

}
#endif /* DeviceManager_H_ */
