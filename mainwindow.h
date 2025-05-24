// mainwindow.h (модифицированная)
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "countrylistmanager.h"
#include "weatherapiclient.h"
#include "weatherdataparser.h"
#include "weathericonmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    int on_btnGo_clicked();
    void onWeatherDataReceived(QNetworkReply* reply);
    void on_btnShowDetails_clicked();

    void on_instructionButton_clicked();

private:
    Ui::MainWindow *ui;
    CountryListManager *countryManager;
    WeatherApiClient *weatherClient;
    WeatherDataParser *dataParser;
    WeatherIconManager *iconManager;

    void populateComboBox();
};

#endif // MAINWINDOW_H
