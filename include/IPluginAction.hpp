/*
 * IPlugin.hpp
 *
 *  Created on: 2014年4月19日
 *      Author: chengliang
 */

#ifndef IPluginAction_HPP_
#define IPluginAction_HPP_

#include <string>

enum PluginNotifyType {
  NONE = 0,
  USBDiskAdded = 1,
  USBDiskRemoved = 2,
  FileModify = 3,
  FileCreate = 4,
  FileDelete = 5,
  FileFrom = 6,
  FileTo = 7,
  DeviceConnected = 8,
  AccessAllDiskIpsChanged = 9
};

class IPluginAction {
public:
  IPluginAction() {
  }

  virtual ~IPluginAction() {
  }

  virtual std::string onThriftCalled(const std::string & para) = 0;

  virtual std::string onPluginStoped() = 0;

  virtual void onUDiskAdded(const std::string &) {
  }

  virtual void onUDiskRemoved(const std::string &) {
  }

  virtual void onFileNotify(const std::string &, PluginNotifyType) {
  }

  virtual void onDeviceConnected(const std::string&){
  }

  virtual void onAccessAllDiskIpsChanged(const std::string&) {
  }
};
#endif /* IPluginAction_HPP_ */
