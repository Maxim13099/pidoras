// weatherapiclient.h
#ifndef WEATHERAPICLIENT_H
#define WEATHERAPICLIENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class WeatherApiClient : public QObject
{
    Q_OBJECT
public:
    explicit WeatherApiClient(QObject *parent = nullptr);
    void fetchWeatherData(const QString &countryCode, const QString &zipCode, const QString &apiKey);

signals:
    void weatherDataReceived(QNetworkReply* reply);

private:
    QNetworkAccessManager *manager;
};

#endif // WEATHERAPICLIENT_H
