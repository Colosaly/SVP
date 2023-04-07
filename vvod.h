#ifndef VVOD_H
#define VVOD_H

#include <QMainWindow>
#include <QMainWindow>
#include <QSpinBox>
#include <QLineEdit>
#include <vector>

namespace Ui {
class Vvod;
}

class Vvod : public QMainWindow
{
    Q_OBJECT

public:
    explicit Vvod(QWidget *parent = 0);
    ~Vvod();

signals:
    void sendData(int id, int y, int m, int d, int w, QString FIO);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Vvod *ui;
    int id;
    int d;
    int m;
    int y;
    int w;
    QString FIO;
};

#endif // VVOD_H
