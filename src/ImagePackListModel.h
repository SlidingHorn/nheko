// SPDX-FileCopyrightText: 2021 Nheko Contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QAbstractListModel>
#include <QQmlEngine>
#include <QSharedPointer>

class SingleImagePackModel;
class ImagePackListModel : public QAbstractListModel
{
        Q_OBJECT
public:
        enum Roles
        {
                DisplayName = Qt::UserRole,
                AvatarUrl,
                FromAccountData,
                FromCurrentRoom,
                StateKey,
                RoomId,
        };

        ImagePackListModel(const std::string &roomId, QObject *parent = nullptr);
        QHash<int, QByteArray> roleNames() const override;
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role) const override;

        Q_INVOKABLE SingleImagePackModel *packAt(int row);

private:
        std::string room_id;

        std::vector<QSharedPointer<SingleImagePackModel>> packs;
};
