#ifndef PLUGINTOOLS_H_
#define PLUGINTOOLS_H_

#include "common.h"
#include <string>

namespace router {

class PluginTools {
public:
  static ErrorCode::Code saveData(const std::string& key,
      const std::string & value);
  static ErrorCode::Code getData(const std::string& key, std::string& value);
  static std::string getDeviceId();  
  static ErrorCode::Code sendPush(const std::string & title,
      const std::string & description);
  static ErrorCode::Code getIdForVendor(
       std::string & idForVendor);
  //sdk level 5
  static int sCallSystem(const std::string& command, std::string& output);

  static void doSpeedTest();

  static void matoolEbit(const std::string& command, int matoolFlag, std::string& output);

  static void requestAccessAllDiskIps();
};

}
#endif
