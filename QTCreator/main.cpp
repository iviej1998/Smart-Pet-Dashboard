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
#include <memory>

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
    std::shared_ptr<Database> database(
        new Database(
            std::string("172.30.155.209"),
            std::string("Jill"),
            std::string("password2"),
            std::string("smartpetdashboard_monitoringlogging_db"),
            3306
            )
        );

    if (!database->connect()) {
        std::cerr << "Database connection failed." << std::endl;
        return -1;
    }

    std::shared_ptr<PetProfileManager> petManager(
        new PetProfileManager(database)
        );

    std::shared_ptr<UserProfileManager> userManager(
        new UserProfileManager(petManager, database)
        );

    std::vector<UserProfile> users;
    AuthenticationManager authManager(users, *userManager, database.get());

    Login l(&authManager);
    l.show();
    //MainWindow w;
    //w.show();
    int result = a.exec();

    //database->disconnect();
    return result;
}