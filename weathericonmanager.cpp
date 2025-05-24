// weathericonmanager.cpp
#include "weathericonmanager.h"

WeatherIconManager::WeatherIconManager(QLabel *iconLabel, QObject *parent)
    : QObject(parent), m_iconLabel(iconLabel) {}

void WeatherIconManager::setWeatherIcon(int weatherConditionCode)
{
    QString imageName;
    switch (weatherConditionCode)
    {
    case 200: imageName = "thunder_storm.png";break;
    case 201: imageName = "thunder_storm.png";break;
    case 202: imageName = "thunder_storm.png";break;
    case 210: imageName = "thunder_storm.png";break;
    case 211: imageName = "thunder_storm.png";break;
    case 212: imageName = "thunder_storm.png";break;
    case 221: imageName = "thunder_storm.png";break;
    case 230: imageName = "thunder_storm.png";break;
    case 231: imageName = "thunder_storm.png";break;
    case 232: imageName = "thunder_storm.png";break;

    case 300: imageName = "rain.png";break;
    case 301: imageName = "rain.png";break;
    case 302: imageName = "rain.png";break;
    case 310: imageName = "rain rain.png";break;
    case 311: imageName = "rain.png";break;
    case 312: imageName = "rain.png";break;
    case 313: imageName = "rain.png";break;
    case 314: imageName = "rain.png";break;
    case 321: imageName = "rain.png";break;

    case 500: imageName = "500-504.png";break;
    case 501: imageName = "500-504.png";break;
    case 502: imageName = "500-504.png";break;
    case 503: imageName = "500-504.png";break;
    case 504: imageName = "500-504.png";break;
    case 511: imageName = "snow.png";break;
    case 520: imageName = "rain.png";break;
    case 521: imageName = "rain.png";break;
    case 522: imageName = "rain.png";break;
    case 531: imageName = "rain.png";break;

    case 600: imageName = "snow.png";break;
    case 601: imageName = "snow.png";break;
    case 602: imageName = "snow.png";break;
    case 611: imageName = "snow.png";break;
    case 612: imageName = "snow.png";break;
    case 613: imageName = "snow.png";break;
    case 615: imageName = "snow.png";break;
    case 616: imageName = "snow.png";break;
    case 620: imageName = "snow.png";break;
    case 621: imageName = "snow.png";break;
    case 622: imageName = "snow.png";break;

    case 701: imageName = "mist.png";break;
    case 711: imageName = "mist.png";break;
    case 721: imageName = "mist.png";break;
    case 731: imageName = "mist.png";break;
    case 741: imageName = "mist.png";break;
    case 751: imageName = "Sand.png";break;
    case 761: imageName = "mist.png";break;
    case 762: imageName = "mist.png";break;
    case 771: imageName = "mist.png";break;
    case 781: imageName = "mist.png";break;
    case 800: imageName = "clear_sky.png"; break;
    case 801: imageName = "sunCloud.png"; break;
    case 802: imageName = "Scattered_clouds.png"; break;
    case 803: imageName = "Overcast_clouds.png"; break;
    case 804: imageName = "Overcast_clouds.png"; break;
    }
     m_iconLabel->setPixmap(":/image/images/" + imageName);
}
