#ifndef VIVOD_H
#define VIVOD_H

#include <QMainWindow>
#include <QTableWidget>

namespace Ui {
class Vivod;
}

class Vivod : public QMainWindow
{
    Q_OBJECT

public:
    explicit Vivod(QWidget *parent = nullptr);
    ~Vivod();

public slots:
    void setData(int size, int id, int y, int m, int d, int w, QString FIO);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Vivod *ui;
    int counter=0;
};

#endif // VIVOD_H
