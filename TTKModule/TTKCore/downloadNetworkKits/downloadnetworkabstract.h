#ifndef DOWNLOADNETWORKABSTRACT_H
#define DOWNLOADNETWORKABSTRACT_H

/* =================================================
 * This file is part of the TTK Downloader project
 * Copyright (c) 2016 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QNetworkReply>
#include <QSslConfiguration>
#include "downloadalgorithmutils.h"

/*! @brief The class of abstract downloading data.
 * @author Greedysky <greedysky@163.com>
 */
class DOWNLOAD_NETWORK_EXPORT DownloadNetworkAbstract : public QObject
{
    Q_OBJECT
public:
    typedef enum StateCode
    {
        Init = 0xFFFFF00,   /*!< Network state init*/
        Success = 0,        /*!< Network state success*/
        Error = -1,         /*!< Network state error*/
        UnKnow = 2,         /*!< Network state unknow*/
    }StateCode;

    /*!
     * Object contsructor.
     */
    explicit DownloadNetworkAbstract(QObject *parent = 0);

    virtual ~DownloadNetworkAbstract();

    /*!
     * Get class object name.
     */
    static QString getClassName();
    /*!
     * Release the network object.
     */
    virtual void deleteAll();

Q_SIGNALS:
    /*!
     * Send download data from net.
     */
    void downLoadDataChanged(const QString &data);

public Q_SLOTS:
    /*!
     * Download data from net finished.
     * Subclass should implement this function.
     */
    virtual void downLoadFinished() = 0;
    /*!
     * Download reply error.
     */
    virtual void replyError(QNetworkReply::NetworkError error);
#ifndef QT_NO_SSL
    /*!
     * Download ssl reply error.
     */
    virtual void sslErrors(QNetworkReply *reply, const QList<QSslError> &errors);
    /*!
     * Download ssl reply error strings.
     */
    void sslErrorsString(QNetworkReply *reply, const QList<QSslError> &errors);
#endif

protected:
    StateCode m_stateCode;
    QNetworkReply *m_reply;
    QNetworkAccessManager *m_manager;

};

#endif // DOWNLOADNETWORKABSTRACT_H
