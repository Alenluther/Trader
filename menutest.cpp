#include "menutest.h"
#include "ui_menutest.h"

MenuTest::MenuTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuTest)
{
    ui->setupUi(this);
    mainWindow=new MainWindow;
    this->setStyleSheet("border:none;background:white;border-radius:5px;");
    //设置窗口透明
    this->setAttribute(Qt::WA_TranslucentBackground);
    //设置无边框窗口
    this->setWindowFlag(Qt::FramelessWindowHint);
}

MenuTest::~MenuTest()
{
    delete ui;
}

void MenuTest::on_pushButton_clicked()
{
   mainWindow->show();
   this->close();
}

void MenuTest::on_bt_close_clicked()
{
    this->close();
}
void MenuTest::mouseMoveEvent(QMouseEvent *event){
    this->move(event->globalPos() - this->dPos);
}
void MenuTest::mousePressEvent(QMouseEvent *event){

    this->windowPos = this->pos();
    this->mousePos = event->globalPos();
    this->dPos = mousePos - windowPos;
}

