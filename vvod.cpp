#include "vvod.h"
#include "ui_vvod.h"

Vvod::Vvod(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Vvod)
{
    ui->setupUi(this);
    ui->spinBox->setMaximum(9999);
    ui->spinBox_2->setMinimum(1900);
    ui->spinBox_2->setMaximum(9999);
    ui->spinBox_3->setMaximum(12);
    ui->spinBox_3->setMinimum(1);
    ui->spinBox_4->setMinimum(1);
    ui->spinBox_4->setMaximum(31);
    ui->spinBox_5->setMaximum(999);
    this->setWindowTitle("Ввод записи");
}

Vvod::~Vvod()
{
    delete ui;
}

void Vvod::on_pushButton_clicked()
{
    id=ui->spinBox->value();
    y=ui->spinBox_2->value();
    m=ui->spinBox_3->value();
    d=ui->spinBox_4->value();
    w=ui->spinBox_5->value();
    FIO=ui->lineEdit->text();
    emit sendData(id, y, m, d, w, FIO);
}

void Vvod::on_pushButton_2_clicked()
{
    this->close();
}
