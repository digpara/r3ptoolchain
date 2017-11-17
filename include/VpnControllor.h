/*
 * VpnControllor.h
 *
 *  Created on: 2014年3月6日
 *      Author: chengliang
 */

#ifndef VpnContorllor_H_
#define VpnContorllor_H_

#include "common.h"
#include <string>
#include "thrift/IThriftNotifier.hpp"
#include <vector>
namespace router {

struct VpnInfo {
  VpnInfo(const std::string& name, const std::string& server,
      const std::string& userName, const std::string& password,
      const std::string& proto);

  std::string name_;
  std::string server_;
  std::string userName_;
  std::string password_;
  std::string proto_;
  int status;
};

class VpnControllor {
public:

  VpnControllor();

  virtual ~VpnControllor();

  static ErrorCode::Code createVpn(const VpnInfo& info, std::string& result);

  static ErrorCode::Code getVpnInfo(const std::string& name,
      std::string& result);

  static ErrorCode::Code openVpn(const std::string& name, std::string& result);

  static ErrorCode::Code closeVpn(const std::string& name, std::string& result);

  static ErrorCode::Code getVpnStatus(const std::string& name,
      std::string& result);

  static ErrorCode::Code registRtTable(const std::string& tableName,
      std::string& result);

  static ErrorCode::Code checkRtTable(const std::string& tableName,
      std::string& result);

  static ErrorCode::Code addToRtTable(const std::string& tableName,
      const std::string& port, const std::string& items, std::string& result);

  static ErrorCode::Code deleteInRtTable(const std::string& tableName,
      const std::string& port, const std::string& itme, std::string& result);

  static ErrorCode::Code cleanRtTable(const std::string& tableName,
      std::string& result);

  static ErrorCode::Code getRtTableList(const std::string& tableName,
      std::string& result, int offset = 0, int count = 0);

  static ErrorCode::Code addSrc(const std::string& tableName,
      const std::string& itme, std::string& result);

  static ErrorCode::Code deleteSrc(const std::string& tableName,
      const std::string& itme, std::string& result);

  static ErrorCode::Code getSrcList(const std::string& tableName,
      std::string& result);

  static ErrorCode::Code changeSrc(const std::string& tableName,
      const std::string& oldsrc, const std::string& newsrc,
      std::string& result);

};

}
#endif /* VpnContorllor_H_ */
