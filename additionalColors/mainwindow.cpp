#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#include <QImage>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),r(0),g(0),b(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QImage img(300,300,QImage::Format_RGB888);

    img.fill(Qt::white);

    for(int y = 0; y < img.height(); ++y)
    {
        if( y %2 == 0)
        {
            //qDebug()<<(img.height()/2)+50;

            for(int x = 0 ; x < (img.height()/2)+50 ; ++x)
            {
                img.setPixel(x,y,qRgb(r,g,b));
            }

            // qDebug()<<"четное число =    " << y;
        }
        else
        {
            // qDebug()<<(img.height()/2) - 50;

            for(int x = (img.height()/2) - 50 ; x < img.height() ; ++x)
            {
                img.setPixel(x,y,qRgb(0,0,255));
            }
            // qDebug()<<"не четное число = " << y;
        }

    }

    ui->label->setPixmap(QPixmap::fromImage(img));

    qDebug()<< " цикл " <<r;
}

void MainWindow::on_pushButton_2_clicked()
{
    if(r <= 250)
        r+=5;

    emit on_pushButton_clicked();

    ui->label_5->setText("R= " + QString::number(r));

}

void MainWindow::on_pushButton_3_clicked()
{
    if(r >= 5 && r <= 255)
        r-=5;

    emit on_pushButton_clicked();

    ui->label_5->setText("R= " + QString::number(r));

}

void MainWindow::on_pushButton_5_clicked()
{
    if(g <= 250)
        g+=5;

    emit on_pushButton_clicked();

    ui->label_6->setText("G= " + QString::number(g));
}

void MainWindow::on_pushButton_4_clicked()
{
    if(g >= 5 && g <= 255)
        g-=5;

    emit on_pushButton_clicked();

    ui->label_6->setText("G= " + QString::number(g));
}

void MainWindow::on_pushButton_7_clicked()
{
    if(b <= 250)
        b+=5;

    emit on_pushButton_clicked();

    ui->label_7->setText("B= " + QString::number(b));
}

void MainWindow::on_pushButton_6_clicked()
{
    if(b >= 5 && b <= 255)
        b-=5;

    emit on_pushButton_clicked();

    ui->label_7->setText("B= " + QString::number(b));
}
