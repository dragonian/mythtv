// -*- Mode: c++ -*-
#ifndef KEYGRABBER_H_
#define KEYGRABBER_H_

// MythUI
#include "mythscreentype.h"

class MythUIText;
class MythUIButton;

/** \class KeyGrabPopupBox
 *  \brief Captures a key.
 *
 */
class KeyGrabPopupBox : public MythScreenType
{
    Q_OBJECT

  public:
    explicit KeyGrabPopupBox(MythScreenStack *parent);
    ~KeyGrabPopupBox() = default;

    bool keyPressEvent(QKeyEvent *) override; // MythScreenType
    bool Create(void) override; // MythScreenType

  signals:
    void HaveResult(QString);

  private slots:
    void SendResult();

  private:
    bool     m_waitingForKeyRelease;
    bool     m_keyReleaseSeen;
    QString  m_capturedKey;

    MythUIText   *m_messageText;
    MythUIButton *m_okButton;
    MythUIButton *m_cancelButton;
};

#endif // KEYGRABBER_H_
