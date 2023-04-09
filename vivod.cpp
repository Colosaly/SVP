#include "vivod.h"
#include "ui_vivod.h"

Vivod::Vivod(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Vivod)
{
    ui->setupUi(this);
    this->setWindowTitle("Таблица измерений");
}

Vivod::~Vivod()
{
    delete ui;
}

void Vivod::setData(int size, int id, int y, int m, int d, int w, QString FIO)
{
    if (counter==0)
    ui->tableWidget->setRowCount(1+size);
    ui->tableWidget->setItem(counter+1, 0, new QTableWidgetItem(QString::number(id)));
    ui->tableWidget->setItem(counter+1, 1, new QTableWidgetItem(FIO));
    ui->tableWidget->setItem(counter+1, 2, new QTableWidgetItem(QString::number(w)));
    ui->tableWidget->setItem(counter+1, 3, new QTableWidgetItem(QString::number(y)+"."+QString::number(m)+"."+QString::number(d)));
    counter++;
}


void Vivod::on_pushButton_clicked()
{
    counter=0;
    ui->tableWidget->setRowCount(1);
    this->close();
}

