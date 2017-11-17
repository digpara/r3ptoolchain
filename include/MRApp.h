#ifndef MRAPP_H_
#define MRAPP_H_

#include <string>
#include <vector>

namespace MRAppfilesystem{
enum FileSystemChangedType {
  UnKnown,
  FileModify,
  FileCreate,
  FileDelete,
  FileFrom,
  FileTo,
};

}

class MRApp{
public:
  MRApp();
  virtual ~MRApp();

  virtual void onLaunched(const std::vector<std::string>& parameters) = 0;
  virtual void onExit();
  virtual std::string onParameterRecieved(const std::string&);
  virtual void onUDiskAdded(const std::string&);
  virtual void onUDiskRemoved(const std::string&);
  virtual void onFileSystemChanged(const std::string&, MRAppfilesystem::FileSystemChangedType);
  virtual void onDeviceConnected(const std::string&);
  virtual void onAccessAllDiskIpsChanged(const std::string&);
  virtual std::string getPluginId();
};

#endif
