/*
 * Plugin.h
 *
 *  Created on: 2014年5月27日
 *      Author: chengliang
 */

#ifndef PLUGIN_H_
#define PLUGIN_H_
#include "IPluginAction.hpp"
#include "common.h"
namespace router {

class Plugin {
public:
  static Plugin& sGetInstance();

  void registPlugin(IPluginAction* notifier);

  bool setPid();
  bool setPid(const std::string & pid);
  bool startThrift();

  ErrorCode::Code sendPush(const std::string & title,
      const std::string & description);

private:
  Plugin();
  virtual ~Plugin();
  bool setPort(const std::string & port);
};

} /* namespace router */
#endif /* PLUGIN_H_ */
