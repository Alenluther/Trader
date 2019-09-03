#ifndef MENUTEST_H
#define MENUTEST_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class MenuTest;
}

class MenuTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuTest(QWidget *parent = 0);
    ~MenuTest();

private slots:
    void on_pushButton_clicked();

    void on_bt_close_clicked();

private:
    Ui::MenuTest *ui;
    MainWindow *mainWindow;
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
protected:
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);

};

#endif // MENUTEST_H
