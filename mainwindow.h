#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QString>
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
    MainWindow(float toppingsPrice, float crustPrice, float sizePrice, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_rbSmall_clicked();

    void on_rbMedium_clicked();

    void on_rbLarge_clicked();

    void on_rbThinCrust_clicked();

    void on_rbThickCrust_clicked();

    void on_chkExtraChees_clicked();

    void on_chkmushrooms_clicked();

    void on_chkTomatoes_clicked();

    void on_chkOnion_clicked();

    void on_chkOlives_clicked();

    void on_chkGreenPeppers_clicked();

    void on_rbEatIn_clicked();

    void on_rbTakeOut_clicked();

    void on_btnOrderPizza_clicked();

    void on_btnResetForm_clicked();

    void on_btnClose_clicked();

private:
    Ui::MainWindow *ui;

    void UpdateTotalPrice();
    float CalculateToppingsPrice();
    float CalculateCrustTypePrice();
    float CalculatePriceOfPizzaSize();
    float CalculateTotalPrice();

    void ToppingsSelected();

   // void OrderSummary();
    void SizeOfPizza();
    void CrustType();
    void Toppings();
    void WhereToEat();
    void DefaultValues();

//    float TotalPrice;
    float ToppingsPrice;
    float CrustTypePrice;
    float SizePrice;
};
#endif // MAINWINDOW_H
