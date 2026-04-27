#pragma once

#include "AuthenticationManager.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);  // 🔥 TEST constructor
    explicit MainWindow(AuthenticationManager* authManager,
                        UserProfileManager* userManager,
                        PetProfileManager* petManager,
                        const std::string& currentUsername,
                        int currentUserId,
                        QWidget *parent = nullptr);
    ~MainWindow() override;
private:
    void setupDashboardUi();
    void loadPets();
    QString emojiForPetType(const std::string& type) const;
    void refreshDashboard();
    void openPetAtIndex(int index);

private slots:

    void on_btnCreatePet_clicked();

    void on_btnHome_clicked();

    void on_btnDevices_clicked();

    void on_btnNotifications_clicked();

    void on_btnPet1_clicked();

    void on_btnPet2_clicked();

    void on_btnPet3_clicked();

    void on_btnPet4_clicked();

private:
    Ui::MainWindow *ui;

    AuthenticationManager* authManager;
    UserProfileManager* userManager;
    PetProfileManager* petManager;

    std::string currentUsername;
    int currentUserId;

    std::vector<int> petIds;   // stores backend pet IDs in dashboard order
};
