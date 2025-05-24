#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "instructionsdialog.h"
#include <qDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , countryManager(new CountryListManager(this))
    , weatherClient(new WeatherApiClient(this))
    , dataParser(new WeatherDataParser(this))
{
    ui->setupUi(this);

    iconManager = new WeatherIconManager(ui->lblDescriptionImg, this);
    populateComboBox();
    ui->txtJsonString->hide();

    connect(weatherClient, &WeatherApiClient::weatherDataReceived,
            this, &MainWindow::onWeatherDataReceived);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateComboBox()
{
    ui->cmbCountry->addItems(countryManager->getCountryList());
}

int MainWindow::on_btnGo_clicked()
{
    QString CountryCode = ui->cmbCountry->currentText().split("-")[0].trimmed();
    QString zipCode = ui->txtZipCode->text();
    QString apiKey = "17c3041332f641f0307bb4bd79d0a0a9";

    qDebug() << "Country Code:" << CountryCode;
    qDebug() << "ZIP Code:" << zipCode;

    weatherClient->fetchWeatherData(CountryCode, zipCode, apiKey);
    return 0;
}

void MainWindow::onWeatherDataReceived(QNetworkReply* reply)
{
    qDebug() << "in onWeatherDataReceived()";

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        WeatherData data = dataParser->parseWeatherData(responseData);

        ui->txtJsonString->setText(data.jsonString);
        ui->lblTemperature->setText(QString::number(data.temp));
        ui->lblWind->setText(QString::number(data.windSpeed));
        ui->lblCity->setText(data.city);
        ui->lblFeelslike->setText(QString::number(data.feelsLike));
        ui->lblDescription->setText(data.description);
        ui->lblHumidity->setText(QString::number(data.humidity));
        ui->lblMax->setText(QString::number(data.tempMax));
        ui->lblMin->setText(QString::number(data.tempMin));
        ui->lblCountry_2->setText(data.country);

        iconManager->setWeatherIcon(data.conditionCode);
    } else {
        QString errorMsg = "Ошибка при получении данных: " + reply->errorString();
        qDebug() << errorMsg;

        QMessageBox::critical(this, "Ошибка", errorMsg);
    }

    reply->deleteLater();
}

void MainWindow::on_btnShowDetails_clicked()
{
    if(ui->txtJsonString->isVisible())
        ui->txtJsonString->hide();
    else
        ui->txtJsonString->show();
}

void MainWindow::on_instructionButton_clicked()
{
    InstructionsDialog *dialog = new InstructionsDialog(this);
    dialog->setModal(true);
    dialog->exec();
}

