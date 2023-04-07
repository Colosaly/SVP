#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <vvod.h>
#include <vivod.h>
#include <delete.h>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void sendData(int size, int id, int y, int m, int d, int w, QString FIO);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void recieveData(int id, int y, int m, int d, int w, QString FIO);
    void recievedelData(int id);

private:
    Ui::MainWindow *ui;
    Vvod *Vvodwindow;
    Vivod *Vivodwindow;
    Delete *Deletewindow;
    struct patient{
        QString FIO;
        int id;
        int y;
        int m;
        int d;
        int w;
        patient(int id_, int y_, int m_, int d_, int w_, QString FIO_);
    };
    std::vector <patient> pat;
};

#endif // MAINWINDOW\_H
