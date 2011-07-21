#pragma once

#include <atlimage.h>

class MCStatusBar
{
/* Normal part */
public:
  MCStatusBar();
  ~MCStatusBar();

/* Properties */
public:
  void SetRect(const CRect &rc);
  void SetText(const std::wstring &str);
  void SetVisible(bool bVisible);
  void SetBKColor(COLORREF cr);

  CRect GetRect() const;
  bool GetVisible() const;
  COLORREF GetBKColor() const;
  std::wstring GetText() const;

/* Operations */
public:
  void Update(WTL::CDC& dc);

/* Event handler */
protected:
  void OnPaint(WTL::CDC& dc);

/* Private data */
private:
  CRect m_rc;  // this rect is relative to the m_hwnd's client area!!!
  bool m_bVisible;
  
  std::wstring m_str;
  COLORREF m_crBKColor;

  Gdiplus::Font *m_pfnText;
  Gdiplus::SolidBrush *m_pbrText;
  Gdiplus::StringFormat *m_pstrfm;
};