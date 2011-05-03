#pragma once

#include <threadhelper.h>
#include "NetworkControlerImpl.h"
#include "../Model/MediaComm.h"
#include "../UserInterface/Renderer/BlockList.h"

class CoverDownloadController :
  public ThreadHelperImpl<CoverDownloadController>,
  public NetworkControlerImpl
{
public:
  CoverDownloadController();
  ~CoverDownloadController();

  void SetBlockUnit(BlockUnit* unit);
  void SetFrame(HWND hwnd);

  void _Thread();
  BOOL HttpGetResponse(std::wstring szFilePath, std::wstring requesturl, std::string& responsestr);
  BOOL ParseRespondString(std::string& parsestr, std::wstring& title, std::wstring& cover);
  BOOL HttpDownloadCover(std::wstring downloadurl, std::wstring& downloadpath,
                         std::wstring cover);
  BOOL ChangeLayer();

  std::wstring GetSystemTimeString();

private:
  std::list<BlockUnit*> m_list;
  HWND m_hwnd;
};