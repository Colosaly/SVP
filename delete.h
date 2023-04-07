#ifndef DELETE_H
#define DELETE_H

#include <QMainWindow>
#include <vvod.h>

namespace Ui {
class Delete;
}

class Delete : public QMainWindow
{
    Q_OBJECT

public:
    explicit Delete(QWidget *parent = nullptr);
    ~Delete();

signals:
    void deletionData(int id);


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Delete *ui;
    int id;
};

#endif // DELETE_H

