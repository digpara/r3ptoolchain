/*
 * DataTransfer.h
 *
 *  Created on: 2014年3月6日
 *      Author: chengliang
 */

#ifndef DATATRANSFER_H_
#define DATATRANSFER_H_

#include "common.h"
#include <string>
#include <map>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "thrift/IThriftNotifier.hpp"
#include <json/json.h>

namespace router {

enum MediaCategory
{
  MediaImage,
  MediaVideo,
  MediaAudio,
};

class MediaFile{
public:
  MediaFile(){};
  virtual ~MediaFile(){};

  virtual void parseFromJson(json_object* jOneTask);

  std::string path_;
  long long size_;
  std::string url_;
  long long timestamp_;
};

class ImageMediaFile:public MediaFile{
public:
  ImageMediaFile(){};
  virtual ~ImageMediaFile(){};

  virtual void parseFromJson(json_object* jOneTask);
  std::string thumbUrl_;
  std::string thumbPath_;
  std::string thumb720Path_;
  long long thumb720size_;
};

class AudioMediaFile:public MediaFile{
public:
  AudioMediaFile(){};
  virtual ~AudioMediaFile(){};

  virtual void parseFromJson(json_object* jOneTask);

  long long duration_;
};

class VideoMediaFile:public MediaFile{
public:
  VideoMediaFile(){};
  virtual ~VideoMediaFile(){};

  virtual void parseFromJson(json_object* jOneTask);

  std::string movieId_;
  std::string movieName_;
  long long duration_;
};


class DataTransfer {
public:

  DataTransfer();
  virtual ~DataTransfer();

  static bool setPid();
  static bool start(IThriftNotifier* notifier);

  static ErrorCode::Code saveData(const std::string& key,
      const std::string & value);
  static ErrorCode::Code getData(const std::string& key, std::string& value);

  static std::string getDeviceId();

  static ErrorCode::Code getMediaFiles(MediaCategory category,
      long cursor, long count,long ts,
      std::vector<boost::shared_ptr<MediaFile> >& list);

private:
  static bool setPort(const std::string & port);
  static bool sCreateDirectory(const std::string& targetPath);

  static ErrorCode::Code saveDataToConfig(const std::string& key,
      const std::string & value);
  static ErrorCode::Code getDataFromConfig(const std::string& key,
      std::string& value);

  static std::map <std::string, std::string> sDataMap_;
};

}
#endif /* DATATRANSFER_H_ */
