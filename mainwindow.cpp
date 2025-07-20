#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include<cctype>
#include<QMessageBox>
#include<QStringList>
MainWindow::MainWindow(float toppingsPrice, float crustPrice, float sizePrice, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ToppingsPrice(toppingsPrice)
    , CrustTypePrice(crustPrice)
    , SizePrice(sizePrice)
{
    ui->setupUi(this);
    DefaultValues();
    UpdateTotalPrice();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::UpdateTotalPrice()
{
    ui->lblTotalPrice->setText("$" + QString::number(CalculateTotalPrice()));
}
float MainWindow::CalculateToppingsPrice()
{
    float toppingsprice = 0;

    if(ui->chkExtraChees->isChecked())
        toppingsprice += this->ToppingsPrice;
    if(ui->chkGreenPeppers->isChecked())
        toppingsprice += this->ToppingsPrice;
    if(ui->chkmushrooms->isChecked())
        toppingsprice += this->ToppingsPrice;
    if(ui->chkOlives->isChecked())
        toppingsprice += this->ToppingsPrice;
    if(ui->chkOnion->isChecked())
        toppingsprice += this->ToppingsPrice;
    if(ui->chkTomatoes->isChecked())
        toppingsprice += this->ToppingsPrice;

    return toppingsprice;
}


float MainWindow::CalculateCrustTypePrice()
{
    if(ui->rbThinCrust->isChecked())
        return CrustTypePrice;
    else
        return (CrustTypePrice * 2);
}


float MainWindow::CalculatePriceOfPizzaSize()
{

    if(ui->rbSmall->isChecked())
        return SizePrice;
    if(ui->rbMedium->isChecked())
        return (SizePrice * 2);
    else
        return (SizePrice * 3);
}



float MainWindow::CalculateTotalPrice()
{
    return (this->CalculateCrustTypePrice() + this->CalculatePriceOfPizzaSize() + this->CalculateToppingsPrice());
}

void MainWindow::ToppingsSelected()
{
        UpdateTotalPrice();
    QStringList selectedList;

    if (ui->chkExtraChees->isChecked()) selectedList << "Extra Chees";
    if (ui->chkGreenPeppers->isChecked()) selectedList << "Green Peppers";
    if (ui->chkmushrooms->isChecked()) selectedList << "Mushrooms";
    if (ui->chkOlives->isChecked()) selectedList << "Olives";
    if (ui->chkOnion->isChecked()) selectedList << "Onion";
    if (ui->chkTomatoes->isChecked()) selectedList << "Tomatoes";

    QString Selected = selectedList.join(", ");

    ui->lblToppings->setText(Selected);
}



void MainWindow::SizeOfPizza()
{
        UpdateTotalPrice();
    if(ui->rbSmall->isChecked()) ui->lblSize->setText("Small");
    if(ui->rbMedium->isChecked()) ui->lblSize->setText("Medium");
    else ui->lblSize->setText("Large");
}


void MainWindow::CrustType()
{
        UpdateTotalPrice();
    if(ui->rbThinCrust->isChecked()) ui->lblCrustType->setText("Thin Crust");
    else ui->lblCrustType->setText("Thick Crust");
}

void MainWindow::WhereToEat()
{
    if(ui->rbEatIn->isChecked()) ui->lblWhereToEat->setText("Eat In");
    else ui->lblWhereToEat->setText("Take Out");
}



void MainWindow::DefaultValues()
{

    UpdateTotalPrice();
    WhereToEat();
    CrustType();
    SizeOfPizza();
    ui->rbMedium->setChecked(true);
    ui->rbThinCrust->setChecked(true);
    ui->rbEatIn->setChecked(true);
}




void MainWindow::on_rbSmall_clicked()
{
    SizeOfPizza();
}


void MainWindow::on_rbMedium_clicked()
{
    SizeOfPizza();
}


void MainWindow::on_rbLarge_clicked()
{
    SizeOfPizza();
}


void MainWindow::on_rbThinCrust_clicked()
{
    CrustType();
}


void MainWindow::on_rbThickCrust_clicked()
{
    CrustType();
}


void MainWindow::on_chkExtraChees_clicked()
{
    ToppingsSelected();
}


void MainWindow::on_chkmushrooms_clicked()
{
    ToppingsSelected();
}


void MainWindow::on_chkTomatoes_clicked()
{
    ToppingsSelected();
}


void MainWindow::on_chkOnion_clicked()
{
    ToppingsSelected();
}


void MainWindow::on_chkOlives_clicked()
{
    ToppingsSelected();
}


void MainWindow::on_chkGreenPeppers_clicked()
{
    ToppingsSelected();
}


void MainWindow::on_rbEatIn_clicked()
{
    WhereToEat();
}


void MainWindow::on_rbTakeOut_clicked()
{
    WhereToEat();
}


void MainWindow::on_btnOrderPizza_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "Are you sure?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        QMessageBox::information(this, "Info", "Your order was placed");
        ui->gbSize->setEnabled(false);
        ui->gbToppings->setEnabled(false);
        ui->gbWhereToEat->setEnabled(false);
        ui->gbCrustType->setEnabled(false);
        ui->btnOrderPizza->setEnabled(false);
    }
    else
        QMessageBox::information(this, "Info", "Your order was canceled");
}



void MainWindow::on_btnResetForm_clicked()
{
    ui->gbSize->setEnabled(true);
    ui->gbToppings->setEnabled(true);
    ui->gbWhereToEat->setEnabled(true);
    ui->gbCrustType->setEnabled(true);
    ui->btnOrderPizza->setEnabled(true);

    ui->chkExtraChees->setChecked(false);
    ui->chkGreenPeppers->setChecked(false);
    ui->chkmushrooms->setChecked(false);
    ui->chkOlives->setChecked(false);
    ui->chkOnion->setChecked(false);
    ui->chkTomatoes->setChecked(false);

    DefaultValues();
    UpdateTotalPrice();
}

void MainWindow::on_btnClose_clicked()
{
    this->close();
}
