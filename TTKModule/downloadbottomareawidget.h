#ifndef DOWNLOADBOTTOMAREAWIDGET_H
#define DOWNLOADBOTTOMAREAWIDGET_H

/* =================================================
 * This file is part of the TTK Downloader project
 * Copyright (c) 2016 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QMenu>
#include <QSystemTrayIcon>
#include "downloadobject.h"
#include "downloadglobaldefine.h"

class DownloadSystemTrayMenu;
class DownloadWindowExtras;
class DownloadNetworkSpeedTestThread;

namespace Ui {
    class DownloadApplication;
}

/*! @brief The class of the app bottom area widget.
 * @author Greedysky <greedysky@163.com>
 */
class DOWNLOAD_GUI_EXPORT DownloadBottomAreaWidget : public QWidget
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit DownloadBottomAreaWidget(QWidget *parent = 0);

    ~DownloadBottomAreaWidget();

    /*!
     * Get class object name.
     */
    static QString getClassName();
    /*!
     * Get class object instance.
     */
    static DownloadBottomAreaWidget *instance();
    /*!
     * Set up app ui.
     */
    void setupUi(Ui::DownloadApplication* ui);

    /*!
     * Set system close config or not.
     */
    void setSystemCloseConfig(bool status) { m_systemCloseConfig = status;}
    /*!
     * Get system close config state.
     */
    bool getSystemCloseConfig() { return m_systemCloseConfig;}
    /*!
     * Get system tray visible state.
     */
    bool systemTrayIsVisible() { return m_systemTray->isVisible();}
    /*!
     * Set system tray message show title and context.
     */
    void showMessage(const QString &title, const QString &text);

#if defined DOWNLOAD_DEBUG && defined Q_OS_WIN && defined DOWNLOAD_GREATER_NEW
    /*!
     * Set current value.
     */
    void setValue(int value) const;
    /*!
     * Set current range from start to end.
     */
    void setRange(int min, int max) const;
#endif

public Q_SLOTS:
    /*!
     * System tray icon activate.
     */
    void iconActivated(QSystemTrayIcon::ActivationReason);
    /*!
     * Send current upload and download speed data.
     */
    void updateNetworkData(ulong upload, ulong download);

protected:
    /*!
     * Create system tray icon.
     */
    void createSystemTrayIcon();

    Ui::DownloadApplication *m_ui;
    bool m_systemCloseConfig;
    QMenu m_toolPopupMenu;
    QSystemTrayIcon *m_systemTray;
    DownloadSystemTrayMenu *m_systemTrayMenu;
    DownloadWindowExtras *m_windowExtras;
    DownloadNetworkSpeedTestThread *m_speedThread;

    static DownloadBottomAreaWidget *m_instance;
};

#endif // DOWNLOADBOTTOMAREAWIDGET_H
