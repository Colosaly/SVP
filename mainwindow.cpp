#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Vvodwindow = new Vvod();
    Vivodwindow = new Vivod();
    Deletewindow = new Delete();
    connect(Vvodwindow, &Vvod::sendData, this, &MainWindow::recieveData);
    connect(this, &MainWindow::sendData, Vivodwindow, &Vivod::setData);
    connect(Deletewindow, &Delete::deletionData, this, &MainWindow::recievedelData);
}

MainWindow::patient::patient(int id_, int y_, int m_, int d_, int w_, QString FIO_)
{
    id = id_;
    y = y_;
    m = m_;
    d = d_;
    w = w_;
    FIO = FIO_;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Vvodwindow->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    Vivodwindow->show();
    for (int i=0; i<pat.size(); i++)
    {
        emit sendData(pat.size(), pat[i].id, pat[i].y, pat[i].m, pat[i].d, pat[i].w, pat[i].FIO);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    Deletewindow->show();
}

void MainWindow::recieveData(int id, int y, int m, int d, int w, QString FIO)
{
    bool f;
    for (int i=0; i<pat.size(); i++)
        if (pat[i].id==id)
            f=1;
    if (!f)
    pat.push_back(patient(id, y, m, d, w, FIO));
    else
        QMessageBox::critical(this,"Used id","The id is already used");
}

void MainWindow::recievedelData(int id)
{
    for (int i=0; i<pat.size(); i++)
        if (id == pat[i].id)
            pat.erase(pat.begin()+i);
}

