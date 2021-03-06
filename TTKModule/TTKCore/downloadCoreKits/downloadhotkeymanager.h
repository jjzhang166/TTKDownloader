#ifndef DOWNLOADHOTKEYMANAGER_H
#define DOWNLOADHOTKEYMANAGER_H

/* =================================================
 * This file is part of the TTK Downloader project
 * Copyright (c) 2016 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "downloadsingleton.h"

#define M_HOTKEY_PTR (DownloadSingleton<DownloadHotKeyManager>::createInstance())

class QxtGlobalShortcut;

/*! @brief The class of the global hotkey setting manager.
 * @author Greedysky <greedysky@163.com>
 */
class DOWNLOAD_CORE_EXPORT DownloadHotKeyManager : public QObject
{
    Q_OBJECT
public:
    /*!
     * Get class object name.
     */
    static QString getClassName();

    /*!
     * To connect parent slot object.
     */
    void connectParentObject(QObject *object, const QString &sn, const char *slot);

    /*!
     * Set hotKey by given index and string key.
     */
    void setHotKey(int index, const QString &key);
    /*!
     * Set hotKey by given index and virtual key.
     */
    void setHotKey(int index, int key);
    /*!
     * Get the string key by given hotKey index.
     */
    QString hotKey(int index);

    /*!
     * Enable or disable the hotkey by index.
     */
    void setEnabled(int index, bool enabled);
    /*!
     * check the given hotkey is enabled or not.
     */
    bool enabled(int index);
    /*!
     * Enable or disable all hotkeys.
     */
    void enabledAll(bool enabled);

    /*!
     * Mapping the virtual key to string key.
     */
    QString toString(int key, int modifiers);
    /*!
     * Get hotkey count.
     */
    int count() const;

    /*!
     * Get key string.
     */
    QStringList getKeys() const;

protected:

    QList<QxtGlobalShortcut*> m_hotkeys;

    DECLARE_SINGLETON_CLASS(DownloadHotKeyManager)
};

#endif // DOWNLOADHOTKEYMANAGER_H
