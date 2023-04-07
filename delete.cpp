#include "delete.h"
#include "ui_delete.h"
#include "vvod.h"


Delete::Delete(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
    ui->spinBox->setMaximum(9999);
}

Delete::~Delete()
{
    delete ui;
}

void Delete::on_pushButton_clicked()
{
    id = ui->spinBox->value();
    emit deletionData(id);
}

void Delete::on_pushButton_2_clicked()
{
    this->close();
}
