//#include "Database.cpp"
#include "Device.cpp"
#include "PetOwner.cpp"
#include "PetProfile.cpp"
#include "QAUser.cpp"
#include "SmartFeeder.cpp"
#include "SmartLight.cpp"
#include "SystemAdmin.cpp"
#include "User.cpp"
#include "mainwindow.cpp"
#include <QApplication>
#include <iostream>
#include <vector>
#include <QLocale>
#include <QTranslator>
using std << cin;
using std << cout;
using std << endl;

vector<PetOwner> PetOwners;
vector<SystemAdmin> SystemAdmins;
#include "mainwindow.h"



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
    return QCoreApplication::exec();
}
