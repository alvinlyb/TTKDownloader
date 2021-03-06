#include "downloadstringutils.h"

#include <QColor>

QString DownloadUtils::String::removeStringBy(const QString &value, const QString &key)
{
    QString s = value;
    s.remove(key);
    if(s.contains(key))
    {
        s = removeStringBy(key);
    }
    return s;
}

QStringList DownloadUtils::String::splitString(const QString &value, const QString &key)
{
    QStringList strings = value.split(QString(" %1 ").arg(key));
    if(strings.isEmpty() || strings.count() == 1)
    {
        strings = value.split(key);
    }
    return strings;
}

QString DownloadUtils::String::artistName(const QString &value, const QString &key)
{
    QStringList s = splitString(value);
    if(s.count() >= 2)
    {
        int index = value.indexOf(key);
        return value.left(index).trimmed();
    }

    return value;
}

QString DownloadUtils::String::songName(const QString &value, const QString &key)
{
    QStringList s = splitString(value);
    if(s.count() >= 2)
    {
        int index = value.indexOf(key) + 1;
        return value.right(value.length() - index).trimmed();
    }

    return value;
}

QList<QColor> DownloadUtils::String::readColorConfig(const QString &value)
{
    QList<QColor> colors;
    QStringList rgbs = value.split(';', QString::SkipEmptyParts);
    foreach(const QString &rgb, rgbs)
    {
        QStringList var = rgb.split(',');
        if(var.count() != 3)
        {
            continue;
        }
        colors << QColor(var[0].toInt(), var[1].toInt(), var[2].toInt());
    }
    return colors;
}

QString DownloadUtils::String::writeColorConfig(const QColor &color)
{
    QString value;
    value.append(QString("%1,%2,%3").arg(color.red()).arg(color.green()).arg(color.blue()));
    return value;
}

QString DownloadUtils::String::writeColorConfig(const QList<QColor> &colors)
{
    QString value;
    foreach(const QColor &rgb, colors)
    {
        value.append(writeColorConfig(rgb) + ";");
    }
    return value;
}
