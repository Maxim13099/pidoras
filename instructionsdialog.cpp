#include "instructionsdialog.h"
#include "ui_instructionsdialog.h"

InstructionsDialog::InstructionsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InstructionsDialog)
{
    ui->setupUi(this);
    setWindowTitle("Инструкция");
}

InstructionsDialog::~InstructionsDialog()
{
    delete ui;
}
