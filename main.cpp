#include "mainwindow.h"
#include "database.h"
#include <QApplication>
#include <QFontDatabase>
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    qInstallMessageHandler([](QtMsgType, const QMessageLogContext &, const QString &msg){
        std::cerr << msg.toStdString() << std::endl;
    }); // need this for qDebug to work apparently

    QApplication a(argc, argv);
    QFontDatabase::addApplicationFont(":/assets/fonts/Inter-VariableFont_opsz,wght.ttf");

    Database::init(
        "", // REST API url
        "" // publishable DB key
        );

    MainWindow w;
    w.show();
    return a.exec();
}
