// weatherdataparser.cpp
#include "weatherdataparser.h"
#include <QJsonDocument>
#include <QJsonArray>

WeatherDataParser::WeatherDataParser(QObject *parent) : QObject(parent) {}

WeatherData WeatherDataParser::parseWeatherData(const QByteArray &responseData)
{
    WeatherData data;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
    QJsonObject jsonObj = jsonDoc.object();

    data.jsonString = jsonDoc.toJson(QJsonDocument::Indented);
    data.description = jsonObj["weather"].toArray()[0].toObject()["description"].toString();
    data.conditionCode = jsonObj["weather"].toArray()[0].toObject()["id"].toInt();
    data.windSpeed = jsonObj["wind"].toObject()["speed"].toDouble();
    data.city = jsonObj["name"].toString();
    data.temp = jsonObj["main"].toObject()["temp"].toDouble() - 273.15;
    data.tempMax = jsonObj["main"].toObject()["temp_max"].toDouble() - 273.15;
    data.tempMin = jsonObj["main"].toObject()["temp_min"].toDouble() - 273.15;
    data.feelsLike = jsonObj["main"].toObject()["feels_like"].toDouble() - 273.15;
    data.humidity = jsonObj["main"].toObject()["humidity"].toDouble();
    data.country = jsonObj["sys"].toObject()["country"].toString();

    return data;
}
