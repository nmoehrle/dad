/*
 * Copyright (C) 2018, Nils Moehrle
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD 3-Clause license. See the LICENSE.txt file for details.
 */

#include <QApplication>
#include <QDrag>
#include <QFileInfo>
#include <QLabel>
#include <QMimeData>
#include <QSizePolicy>
#include <QTextStream>
#include <QUrl>

class Draggable : public QLabel
{
    QList<QUrl> urls;

    void mousePressEvent(QMouseEvent *event)
    {
        auto *drag = new QDrag(this);
        auto *mimeData = new QMimeData;

        mimeData->setUrls(urls);
        drag->setMimeData(mimeData);

        Qt::DropAction dropAction = drag->exec();
    }

public:
    Draggable(const QList<QUrl>&& urls, QWidget * parent = 0)
        : QLabel(parent), urls(urls)
    {
        this->setText(QString("%1 file%2").arg(
            QString::number(urls.size()),
            (urls.size() == 1) ? "" : "s")
        );
        this->setAlignment(Qt::AlignCenter);
        this->setContentsMargins(0, 0, 0, 0);
        this->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    }
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QList<QUrl> urls;
    if (argc > 1 || (argc == 2 && QString(argv[1]) == "-"))
    {
        for (int i = 1; i < argc; ++i)
        {
            QFileInfo fileInfo(argv[i]);
            urls.append(QUrl::fromLocalFile(fileInfo.absoluteFilePath()));
        }
    }
    else
    {
        QTextStream stream(stdin);
        QString line;
        while (stream.readLineInto(&line))
        {
            QFileInfo fileInfo(line);
            urls.append(QUrl::fromLocalFile(fileInfo.absoluteFilePath()));
        }
    }

    Draggable draggable(std::move(urls));
    draggable.show();

    return app.exec();
}

