#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QTableView>
#include <QMouseEvent>
enum Direction{
    //用于移动窗口实现
    UP, DOWN, LEFT, RIGHT, LEFTTOP, LEFTBOTTOM, RIGHTBOTTOM, RIGHTTOP, NONE
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void databaseInit(QSqlDatabase db);

    void tableViewSetting();

    void resolutionFit();

    void on_MainWindowMinBt_clicked();

    void on_MainWindowCloseBt_clicked();

    void on_MainWindowMaxBt_clicked();

    void on_bt_quote_clicked();

    void on_bt_database_clicked();
    void on_NewQuote_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *QuoteModel;
    QSqlDatabase db;
    QSqlTableModel *CustomerModel;
    //窗口是否最大化0为否，1为是，初始为0
    bool WindowMaxState=0;

    void judgeRegionSetCursor(const QPoint&);
    const int Padding = 2;
    bool isLeftPressDown=false;  // 判断左键是否按下
    QPoint dragPosition;   // 窗口移动拖动时需要记住的点
    // 窗口大小改变时，记录改变方向
    Direction dir = NONE;
protected:
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
};

#endif // MAINWINDOW_H
