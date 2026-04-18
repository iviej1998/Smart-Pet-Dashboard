#include "Device.h"
#include "PPDog.h"
#include "PPFish.h"
#include "PetOwner.h"
#include "PetProfile.h"
#include "QAUser.h"
#include "SmartFeeder.h"
#include "SmartLight.h"
#include "SystemAdmin.h"

#include "Login.h"
#include "mainwindow.h"
#include "PPwindow.h"
#include "Database.h"
#include "UserProfile.h"
#include "PetProfileManager.h"
#include "UserProfileManager.h"
#include "AuthenticationManager.h"

#include <QApplication>
#include <iostream>
#include <vector>
#include <QLocale>
#include <QTranslator>

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

    auto database = std::make_shared<Database>();
    auto petManager = std::make_shared<PetProfileManager>(database);
    auto userManager = std::make_shared<UserProfileManager>(petManager, database);

    std::vector<UserProfile> users;
    AuthenticationManager authManager(users, *userManager);

    MainWindow w;
    w.show();
    //Login l(&authManager);
    //l.show();

    return a.exec();
}