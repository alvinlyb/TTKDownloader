#ifndef DOWNLOADLOCALPEER_H
#define DOWNLOADLOCALPEER_H

/* =================================================
 * This file is part of the TTK Downloader project
 * Copyright (C) 2015 - 2017 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include <QObject>
#include "downloadprivate.h"
#include "downloadrunglobaldefine.h"

class DownloadLocalPeerPrivate;

/*! @brief The class of the download local peer.
 * @author Greedysky <greedysky@163.com>
 */
class DOWNLOAD_RUN_EXPORT DownloadLocalPeer : public QObject
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
    */
    explicit DownloadLocalPeer(QObject *parent = 0, const QString &appId = QString());

    /*!
     * Current client is running or not.
    */
    bool isClient();

    /*!
     * Send current message when the client in.
    */
    bool sendMessage(const QString &message, int timeout);

    /*!
     * Get current server id.
    */
    QString applicationId() const;

Q_SIGNALS:
    /*!
     * Emit when the current message received.
    */
    void messageReceived(const QString &message);

protected Q_SLOTS:
    /*!
     * Current message received.
    */
    void receiveConnection();

private:
    DOWNLOAD_DECLARE_PRIVATE(DownloadLocalPeer)

};

#endif // DOWNLOADLOCALPEER_H
