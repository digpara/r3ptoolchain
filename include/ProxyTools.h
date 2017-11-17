#ifndef PROXYTOOLS_H_
#define PROXYTOOLS_H_

#include "common.h"
#include <string>

namespace router {

class ProxyTools {
public:
  static ErrorCode::Code openThridPartyProxy(const std::string& localPort,const std::string& dnsPort,
      const std::string& serverIp, const std::string& listFilePath,
      std::string& result);

  static ErrorCode::Code closeThridPartyProxy(std::string& result);

  static ErrorCode::Code revProxyCreate(const std::string& name,
      const std::string& port, const std::string& redirectPort,
      std::string& result);

  static ErrorCode::Code revProxyAdd(const std::string& name,
      const std::string& url, std::string& result);

  static ErrorCode::Code revProxyReload(const std::string& name,
      std::string& result);

  static ErrorCode::Code revProxyDelete(const std::string& name,
      std::string& result);
};

}
#endif
