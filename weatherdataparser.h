// weatherdataparser.h
#ifndef WEATHERDATAPARSER_H
#define WEATHERDATAPARSER_H

#include <QObject>
#include <QJsonObject>

struct WeatherData {
    QString description;
    int conditionCode;
    double windSpeed;
    QString city;
    double temp;
    double tempMax;
    double tempMin;
    double feelsLike;
    double humidity;
    QString country;
    QString jsonString;
};

class WeatherDataParser : public QObject
{
    Q_OBJECT
public:
    explicit WeatherDataParser(QObject *parent = nullptr);
    WeatherData parseWeatherData(const QByteArray &responseData);
};

#endif // WEATHERDATAPARSER_H
