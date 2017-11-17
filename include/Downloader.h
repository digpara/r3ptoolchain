#pragma once

#include "common.h"
#include <string>
#include <vector>

namespace router {

enum DownloadStatus {
  DownloadStatusNone,
  Downloading = 1,
  DownloadPause = 2,
  DownloadCompleted = 4,
  DownloadStoped = 8,
  DownloadStatusFailed = 16,
  DownloadNotStart = 32
};

struct DownloadResult {
  DownloadResult() :
      code(ErrorCode::NoError), id(""), totalSize(0), downloadedSize(0), status(
          DownloadStatusNone) {
  }

  ErrorCode::Code code;
  std::string id;
  long long totalSize;
  long long downloadedSize;
  DownloadStatus status;
};

class Downloader {
public:
  //urls:以逗号分隔的Url.
  ErrorCode::Code multiDownload(const std::string& urls,
      const std::string& pathForUserData,std::vector<DownloadResult>& result);

  DownloadResult Download(const std::string& url, const std::string& targetPath,
      bool downloadAgain, const std::string& dupId,
      const bool isHidden = false);

  DownloadResult DownloadToUserData(const std::string& url, const std::string& pathForUserData,
      bool downloadAgain, const std::string& dupId, std::string& output);

  DownloadResult GetDownloadProgress(const std::string& id,
      const bool isHidden = false);
  DownloadResult PauseDownloadItems(const std::vector<std::string>& itemIds);
  DownloadResult ResumeDownloadItems(const std::vector<std::string>& itemIds);
  DownloadResult DeleteDownloadItems(const std::vector<std::string>& itemIds,
      bool removeFiles);

  router::ErrorCode::Code GetDownloadList(std::vector<DownloadResult> &list);

  router::ErrorCode::Code GetDownloadList(std::string& output);
};
}
