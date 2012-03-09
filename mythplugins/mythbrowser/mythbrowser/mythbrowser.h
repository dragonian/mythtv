#ifndef MYTHBROWSER_H
#define MYTHBROWSER_H

#include <QUrl>

#include <mythuiwebbrowser.h>
#include <mythuibuttonlist.h>
#include <mythscreentype.h>
#include <mythdialogbox.h>
#include <mythuiprogressbar.h>

#include "bookmarkmanager.h"
#include "mythactions.h"

class WebPage;

class MythBrowser : public MythScreenType
{
  Q_OBJECT

  public:
    MythBrowser(MythScreenStack *parent,
           QStringList &urlList, float zoom);
    ~MythBrowser();

    bool Create(void);
    bool keyPressEvent(QKeyEvent *);

    void setDefaultSaveDirectory(const QString saveDir) { m_defaultSaveDir = saveDir; }
    void setDefaultSaveFilename(const QString saveFile) { m_defaultSaveFilename = saveFile; }
    MythImage* getDefaultFavIcon(void) { return m_defaultFavIcon; }

    bool doMenu(const QString &action);
    bool doInfo(const QString &action);
    bool doEscape(const QString &action);
    bool doDelete(const QString &action);
    bool doPrevTab(const QString &action);
    bool doNextTab(const QString &action);

  public slots:
    void slotOpenURL(const QString &url);

  protected slots:
    void slotZoomIn();
    void slotZoomOut();

    void slotBack();
    void slotForward();

    void slotEnterURL(void);

    void slotAddTab(const QString &url = "", bool doSwitch = true);
    void slotDeleteTab(void);

    void slotAddBookmark(void);

    void slotLoadStarted(void);
    void slotLoadFinished(bool OK);
    void slotLoadProgress(int progress);
    void slotTitleChanged(const QString &title);
    void slotStatusBarMessage(const QString &text);
    void slotTabSelected(MythUIButtonListItem *item);
    void slotTabLosingFocus(void);

  private:
    MythUIWebBrowser* activeBrowser(void);

    void switchTab(int newTab);

    QStringList               m_urlList;

    MythUIButtonList         *m_pageList;
    QList<WebPage*>           m_browserList;
    MythUIProgressBar        *m_progressBar;
    MythUIText               *m_titleText;
    MythUIText               *m_statusText;

    int       m_currentBrowser;
    QUrl      m_url;
    float     m_zoom;
    QString   m_defaultSaveDir;
    QString   m_defaultSaveFilename;

    Bookmark  m_editBookmark;

    MythDialogBox *m_menuPopup;

    MythImage     *m_defaultFavIcon;

    friend class WebPage;

    MythActions<MythBrowser> *m_actions;
};

#endif
