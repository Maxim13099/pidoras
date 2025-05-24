// weathericonmanager.h
#ifndef WEATHERICONMANAGER_H
#define WEATHERICONMANAGER_H

#include <QObject>
#include <QLabel>

class WeatherIconManager : public QObject
{
    Q_OBJECT
public:
    explicit WeatherIconManager(QLabel *iconLabel, QObject *parent = nullptr);
    void setWeatherIcon(int weatherConditionCode);

private:
    QLabel *m_iconLabel;
};

#endif // WEATHERICONMANAGER_H
