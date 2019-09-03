#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlTableModel>
#include <QMainWindow>
#include <QSqlRecord>
#include <QSqlQuery>
#include <ctime>
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置屏幕分辨率
    resolutionFit();
    //数据库连接
    databaseInit(db);
    //数据库可视化
    tableViewSetting();
    //设置窗口透明
    this->setAttribute(Qt::WA_TranslucentBackground);
    //设置无边框窗口
    this->setWindowFlag(Qt::FramelessWindowHint);
    // 追踪鼠标
    this->centralWidget()->setMouseTracking(true);
    this->setMouseTracking(true);
    //设置整个窗口的风格(styleSheet)
    this->setStyleSheet("border:none;background:white;border-radius:5px;");

}

MainWindow::~MainWindow()
{
    delete ui;
}
//作用如其名
void MainWindow::databaseInit(QSqlDatabase db){
    //添加MYSQL数据库
    db = QSqlDatabase::addDatabase("QMYSQL");
    //连接数据库
    db.setHostName("cdb-5g81c1wl.gz.tencentcdb.com");
    db.setPort(10041);
    db.setDatabaseName("alentest");
    db.setUserName("QT");
    db.setPassword("QTproject666");
    //打开数据库
    db.open();
    if(!db.open())//打开数据库失败
    {
        QMessageBox::warning(this,"打开数据库失败",db.lastError().text());
        return;
    }
}

//作用如其名
void MainWindow::tableViewSetting(){
    //(待封装)
    //CustomerTableView Setting
    CustomerModel = new QSqlTableModel(this);
    CustomerModel->setTable("Customer");
    ui->CustomerTableView->setModel(CustomerModel);
    CustomerModel->select();
    ui->CustomerTableView->resizeColumnsToContents();
    ui->CustomerTableView->resizeRowsToContents();
    //QuoteTableView Setting
    //设置模型
    QuoteModel = new QSqlTableModel(this);
    QuoteModel->setTable("QUOTE");
    //模型放在VIEW里面
    ui->QuoteTableView->setModel(QuoteModel);
    //显示
    QuoteModel->select();
    QuoteModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QuoteModel->setHeaderData(0,Qt::Horizontal,"柜型");
    QuoteModel->setHeaderData(1,Qt::Horizontal,"产品形状");
    ui->QuoteTableView->resizeColumnsToContents();
    ui->QuoteTableView->resizeRowsToContents();

}

//设置初始屏幕分辨率
void MainWindow::resolutionFit(){
    //获取设备屏幕分辨率
    QScreen *screenRect = QGuiApplication::primaryScreen();
    QSize g_nActScreenW = screenRect->availableSize();
    //将初始大小设置为整个屏幕的0.7倍
    this->resize(g_nActScreenW*0.7);
}

//以下三个方法为右上角最小化最大化关闭按钮实现
void MainWindow::on_MainWindowMinBt_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}

void MainWindow::on_MainWindowCloseBt_clicked()
{
    this->close();
}

void MainWindow::on_MainWindowMaxBt_clicked()
{
    if(WindowMaxState){
        //如果已经是最大窗口
        this->setWindowState(Qt::WindowNoState);
        WindowMaxState=0;
        ui->MainWindowMaxBt->setText("□");
    }
    else{
        this->setWindowState(Qt::WindowMaximized);
        WindowMaxState=1;
        ui->MainWindowMaxBt->setText("⇋");
    }

}

//此方法包括下面Mouse开头的重写方法实现可移动无边框窗口(待封装）
void MainWindow::judgeRegionSetCursor(const QPoint& currentPoint){
    // 获取窗体在屏幕上的位置区域，tl为topleft点，rb为rightbottom点
        QRect rect = this->rect();
        QPoint tl = mapToGlobal(rect.topLeft());
        QPoint rb = mapToGlobal(rect.bottomRight());

        int x = currentPoint.x();
        int y = currentPoint.y();
        if (tl.x() + Padding +5 >= x && tl.x() <= x && tl.y() + Padding +5 >= y && tl.y() <= y) {
            // 左上角
            dir = LEFTTOP;
            this->setCursor(QCursor(Qt::SizeFDiagCursor));  // 设置鼠标形状
        }
        else if (x >= rb.x() - Padding -5 && x <= rb.x() && y >= rb.y() - Padding -5 && y <= rb.y()) {
            // 右下角
            dir = RIGHTBOTTOM;
            this->setCursor(QCursor(Qt::SizeFDiagCursor));
        }
        else if (x <= tl.x() + Padding + 5 && x >= tl.x() && y >= rb.y() - Padding - 5 && y <= rb.y()) {
            //左下角
            dir = LEFTBOTTOM;
            this->setCursor(QCursor(Qt::SizeBDiagCursor));
        }
        else if (x <= rb.x() && x >= rb.x() - Padding - 5 && y >= tl.y() && y <= tl.y() + Padding + 5) {
            // 右上角
            dir = RIGHTTOP;
            this->setCursor(QCursor(Qt::SizeBDiagCursor));
        }
        else if (x <= tl.x() + Padding && x >= tl.x() && y > tl.y()+5 && y < rb.y()-5) {
            // 左边
            dir = LEFT;
            this->setCursor(QCursor(Qt::SizeHorCursor));
        }
        else if (x <= rb.x() && x >= rb.x() - Padding && y > tl.y()+5 && y < rb.y()-5) {
            // 右边
            dir = RIGHT;
            this->setCursor(QCursor(Qt::SizeHorCursor));
        }
        else if (y >= tl.y() && y <= tl.y() + Padding && x > tl.x()+5 && x < rb.x()-5) {
            // 上边
            dir = UP;
            this->setCursor(QCursor(Qt::SizeVerCursor));
        }
        else if (y <= rb.y() && y >= rb.y() - Padding && x > tl.x()+5 && x < rb.x()-5) {
            // 下边
            dir = DOWN;
            this->setCursor(QCursor(Qt::SizeVerCursor));
        }
        else {
            // 默认
            dir = NONE;
            this->setCursor(QCursor(Qt::ArrowCursor));
        }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
            isLeftPressDown = false;
            if (dir != NONE) {
                this->releaseMouse();
                this->setCursor(QCursor(Qt::ArrowCursor));
            }
        }
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    switch (event->button()) {
        case Qt::LeftButton:
            isLeftPressDown = true;
            if (dir != NONE) {
                this->mouseGrabber();
            }
            else {
                dragPosition = event->globalPos() - this->frameGeometry().topLeft();
            }
            break;
        default:
            QMainWindow::mousePressEvent(event);
        }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
        QPoint gloPoint = event->globalPos();
        QRect rect = this->rect();
        QPoint tl = mapToGlobal(rect.topLeft());
        QPoint rb = mapToGlobal(rect.bottomRight());
        if (this->isMaximized()){
            return;
        }
        if (!isLeftPressDown) {
            this->judgeRegionSetCursor(gloPoint);

        }

        else {

            if (dir != NONE) {
                QRect rMove(tl, rb);

                switch (dir) {
                case LEFT:
                    if (rb.x() - gloPoint.x() <= this->minimumWidth())
                        rMove.setX(tl.x());
                    else
                        rMove.setX(gloPoint.x());
                    break;
                case RIGHT:
                    rMove.setWidth(gloPoint.x() - tl.x());
                    break;
                case UP:
                    if (rb.y() - gloPoint.y() <= this->minimumHeight())
                        rMove.setY(tl.y());
                    else
                        rMove.setY(gloPoint.y());
                    break;
                case DOWN:
                    rMove.setHeight(gloPoint.y() - tl.y());
                    break;
                case LEFTTOP:
                    if (rb.x() - gloPoint.x() <= this->minimumWidth())
                        rMove.setX(tl.x());
                    else
                        rMove.setX(gloPoint.x());
                    if (rb.y() - gloPoint.y() <= this->minimumHeight())
                        rMove.setY(tl.y());
                    else
                        rMove.setY(gloPoint.y());
                    break;
                case RIGHTTOP:
                    rMove.setWidth(gloPoint.x() - tl.x());
                    rMove.setY(gloPoint.y());
                    break;
                case LEFTBOTTOM:
                    rMove.setX(gloPoint.x());
                    rMove.setHeight(gloPoint.y() - tl.y());
                    break;
                case RIGHTBOTTOM:
                    rMove.setWidth(gloPoint.x() - tl.x());
                    rMove.setHeight(gloPoint.y() - tl.y());
                    break;
                default:
                    break;
                }
                this->setGeometry(rMove);
            }
            else {
                move(event->globalPos() - dragPosition);
                event->accept();
            }
        }
        QMainWindow::mouseMoveEvent(event);
}

//报价单显示
void MainWindow::on_bt_quote_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//数据库显示

void MainWindow::on_bt_database_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_NewQuote_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
