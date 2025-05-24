// weatherapiclient.cpp
#include "weatherapiclient.h"

WeatherApiClient::WeatherApiClient(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
}

void WeatherApiClient::fetchWeatherData(const QString &countryCode, const QString &zipCode, const QString &apiKey)
{
    QString url = QString("https://api.openweathermap.org/data/2.5/weather?zip=%1,%2&appid=%3")
    .arg(zipCode).arg(countryCode).arg(apiKey);

    QNetworkRequest request((QUrl(url)));
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, [this, reply]() {
        emit weatherDataReceived(reply);
    });
}
