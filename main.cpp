//#include "Database.cpp"
#include "Device.h"
#include "PPDog.h"
#include "PetOwner.h"
#include "PetProfile.h"
#include "QAUser.h"
#include "SmartFeeder.h"
#include "SmartLight.h"
#include "SystemAdmin.h"
#include "User.h"
#include "mainwindow.h"
#include "PPwindow.h"
#include "PPDog.h"
#include <QApplication>
#include <iostream>
#include <vector>
#include <QLocale>
#include <QTranslator>
using namespace std;




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Test1_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();

    PPWindow p;
    p.show();
    return QCoreApplication::exec();
}
