// countrylistmanager.h
#ifndef COUNTRYLISTMANAGER_H
#define COUNTRYLISTMANAGER_H

#include <QStringList>
#include <QObject>

class CountryListManager : public QObject
{
    Q_OBJECT
public:
    explicit CountryListManager(QObject *parent = nullptr);
    QStringList getCountryList() const;

private:
    QStringList countryCodes;
    void initializeCountryList();
};

#endif // COUNTRYLISTMANAGER_H
