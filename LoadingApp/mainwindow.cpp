#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QMessageBox>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QDebug>

#include <QVector3D>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DRender/QCamera>
#include <Qt3DExtras/QForwardRenderer>

#include <QFile>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>

#include <QTreeWidgetItem>
#include <QTableWidget>

#include <Qt3DExtras/QConeMesh>
#include <Qt3DExtras/QCylinderMesh>

#include <Qt3DExtras/QPlaneMesh>
#include <Qt3DExtras/QDiffuseMapMaterial>
#include <Qt3DCore/QTransform>

QColor selectedColor1;
QColor selectedColor2;
QColor selectedColor3;
QColor selectedColor4;
QColor selectedColor5;
QColor selectedColor6;
QColor selectedColor7;
QColor selectedColor8;
QColor selectedColor9;
QColor selectedColor10;
QColor selectedColor11;

QSet<QString> selectedColorsSet;

int pro_no = 5;

QString str[10][7];



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
    view(nullptr), rootEntity(nullptr), containerEntity(nullptr), viewContainer(nullptr)

{
    ui->setupUi(this);

    ui->SelectAdd->hide();

    setBoldButton(ui->ProductButton);

    connect(ui->SelectVPforLoading, &QPushButton::clicked, this, &MainWindow::on_SelectVPforLoading_clicked);

    connect(ui->Clear, &QPushButton::clicked, this, &MainWindow::on_Clear_clicked);      

    ui->widgetAddProduct->hide();

    ui->scrollAreaWidgetContents->setLayout(new QVBoxLayout);

    selectedColorsSet.clear();

    QIntValidator *intValidator = new QIntValidator(0, 100000, this);

    QDoubleValidator *doubleValidator = new QDoubleValidator(0, 100000.000, 3, this);

    ui->Length1->setValidator(intValidator);
    ui->Width1->setValidator(intValidator);
    ui->Height1->setValidator(intValidator);
    ui->Weight1->setValidator(intValidator);
    ui->Qty1->setValidator(intValidator);

    ui->Length2->setValidator(intValidator);
    ui->Width2->setValidator(intValidator);
    ui->Height2->setValidator(intValidator);
    ui->Weight2->setValidator(intValidator);
    ui->Qty2->setValidator(intValidator);

    ui->Length3->setValidator(intValidator);
    ui->Width3->setValidator(intValidator);
    ui->Height3->setValidator(intValidator);
    ui->Weight3->setValidator(intValidator);
    ui->Qty3->setValidator(intValidator);

    ui->Length4->setValidator(intValidator);
    ui->Width4->setValidator(intValidator);
    ui->Height4->setValidator(intValidator);
    ui->Weight4->setValidator(intValidator);
    ui->Qty4->setValidator(intValidator);

    ui->Length5->setValidator(intValidator);
    ui->Width5->setValidator(intValidator);
    ui->Height5->setValidator(intValidator);
    ui->Weight5->setValidator(intValidator);
    ui->Qty5->setValidator(intValidator);

    ui->Length6->setValidator(intValidator);
    ui->Width6->setValidator(intValidator);
    ui->Height6->setValidator(intValidator);
    ui->Weight6->setValidator(intValidator);
    ui->Qty6->setValidator(intValidator);

    ui->Length7->setValidator(intValidator);
    ui->Width7->setValidator(intValidator);
    ui->Height7->setValidator(intValidator);
    ui->Weight7->setValidator(intValidator);
    ui->Qty7->setValidator(intValidator);

    ui->Length8->setValidator(intValidator);
    ui->Width8->setValidator(intValidator);
    ui->Height8->setValidator(intValidator);
    ui->Weight8->setValidator(intValidator);
    ui->Qty8->setValidator(intValidator);

    ui->Length9->setValidator(intValidator);
    ui->Width9->setValidator(intValidator);
    ui->Height9->setValidator(intValidator);
    ui->Weight9->setValidator(intValidator);
    ui->Qty9->setValidator(intValidator);

    ui->Length10->setValidator(intValidator);
    ui->Width10->setValidator(intValidator);
    ui->Height10->setValidator(intValidator);
    ui->Weight10->setValidator(intValidator);
    ui->Qty10->setValidator(intValidator);

    ui->ConLen1->setValidator(doubleValidator);
    ui->ConHei1->setValidator(doubleValidator);
    ui->ConWidth1->setValidator(doubleValidator);
    ui->ConWei1->setValidator(doubleValidator);

    ui->stackedWidget->setCurrentIndex(1);

    ui->Pname6->hide();
    ui->Length6->hide();
    ui->Width6->hide();
    ui->Height6->hide();
    ui->Weight6->hide();
    ui->Qty6->hide();
    ui->lable6->hide();
    ui->lable6_2->hide();
    ui->lable6_3->hide();
    ui->lable6_4->hide();
    ui->Color6->hide();
    ui->Line6->hide();
    ui->comboBox6->hide();

    ui->Pname7->hide();
    ui->Length7->hide();
    ui->Width7->hide();
    ui->Height7->hide();
    ui->Weight7->hide();
    ui->Qty7->hide();
    ui->lable7->hide();
    ui->lable7_2->hide();
    ui->lable7_3->hide();
    ui->lable7_4->hide();
    ui->Color7->hide();
    ui->Line7->hide();
    ui->comboBox7->hide();

    ui->Pname8->hide();
    ui->Length8->hide();
    ui->Width8->hide();
    ui->Height8->hide();
    ui->Weight8->hide();
    ui->Qty8->hide();
    ui->lable8->hide();
    ui->lable8_2->hide();
    ui->lable8_3->hide();
    ui->lable8_4->hide();
    ui->Color8->hide();
    ui->Line8->hide();
    ui->comboBox8->hide();

    ui->Pname9->hide();
    ui->Length9->hide();
    ui->Width9->hide();
    ui->Height9->hide();
    ui->Weight9->hide();
    ui->Qty9->hide();
    ui->lable9->hide();
    ui->lable9_2->hide();
    ui->lable9_3->hide();
    ui->lable9_4->hide();
    ui->Color9->hide();
    ui->Line9->hide();
    ui->comboBox9->hide();

    ui->Pname10->hide();
    ui->Length10->hide();
    ui->Width10->hide();
    ui->Height10->hide();
    ui->Weight10->hide();
    ui->Qty10->hide();
    ui->lable10->hide();
    ui->lable10_2->hide();
    ui->lable10_3->hide();
    ui->lable10_4->hide();
    ui->Color10->hide();
    ui->Line10->hide();
    ui->comboBox10->hide();


    ui->scrollArea->setWidgetResizable(true);


    connect(ui->Color1, &QPushButton::clicked, this, &MainWindow::handleColorPick1);
    connect(ui->Color2, &QPushButton::clicked, this, &MainWindow::handleColorPick2);
    connect(ui->Color3, &QPushButton::clicked, this, &MainWindow::handleColorPick3);
    connect(ui->Color4, &QPushButton::clicked, this, &MainWindow::handleColorPick4);
    connect(ui->Color5, &QPushButton::clicked, this, &MainWindow::handleColorPick5);
    connect(ui->Color6, &QPushButton::clicked, this, &MainWindow::handleColorPick6);
    connect(ui->Color7, &QPushButton::clicked, this, &MainWindow::handleColorPick7);
    connect(ui->Color8, &QPushButton::clicked, this, &MainWindow::handleColorPick8);
    connect(ui->Color9, &QPushButton::clicked, this, &MainWindow::handleColorPick9);
    connect(ui->Color10, &QPushButton::clicked, this, &MainWindow::handleColorPick10);
    connect(ui->AddProductInContainerColor, &QPushButton::clicked, this, &MainWindow::handleColorPick11);


    connect(ui->SelectProductforLoading, &QPushButton::clicked,
            this, &MainWindow::on_SelectProductforLoading_clicked);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ProductButton_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);

    setBoldButton(ui->ProductButton);
}


void MainWindow::on_ContainerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

    setBoldButton(ui->ContainerButton);

}


void MainWindow::on_LoadingButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

    setBoldButton(ui->LoadingButton);
}

void MainWindow::setBoldButton(QPushButton* active)
{
    QList<QPushButton*> buttons = {
        ui->ProductButton,
        ui->ContainerButton,
        ui->LoadingButton,
        ui->SelectVP,
        ui->SelectTruck,
        ui->SelectContainer,
        ui->SelectWarehouse
    };

    for (QPushButton* btn : buttons) {
        QFont font = btn->font();
        font.setBold(btn == active);  // bold only the clicked one
        btn->setFont(font);
    }
}



void MainWindow::on_AddInContainer_clicked()
{

    str[0][0] = ui -> Pname1 -> text();
    str[0][1] = ui -> Length1 -> text();
    str[0][2] = ui -> Width1 -> text();
    str[0][3] = ui -> Height1 -> text();
    str[0][4] = ui -> Weight1 -> text();
    str[0][5] = ui -> Qty1 -> text();
    str[0][6] =  selectedColor1.name();

    str[1][0]  = ui -> Pname2 -> text();
    str[1][1]  = ui -> Length2 -> text();
    str[1][2]  = ui -> Width2 -> text();
    str[1][3]  = ui -> Height2 -> text();
    str[1][4]  = ui -> Weight2 -> text();
    str[1][5]  = ui -> Qty2 -> text();
    str[1][6]  =  selectedColor2.name();

    str[2][0]  = ui -> Pname3 -> text();
    str[2][1]  = ui -> Length3 -> text();
    str[2][2]  = ui -> Width3 -> text();
    str[2][3]  = ui -> Height3 -> text();
    str[2][4]  = ui -> Weight3 -> text();
    str[2][5]  = ui -> Qty3 -> text();
    str[2][6]  =  selectedColor3.name();

    str[3][0]  = ui -> Pname4 -> text();
    str[3][1]  = ui -> Length4 -> text();
    str[3][2]  = ui -> Width4 -> text();
    str[3][3]  = ui -> Height4 -> text();
    str[3][4]  = ui -> Weight4 -> text();
    str[3][5]  = ui -> Qty4 -> text();
    str[3][6]  =  selectedColor4.name();

    str[4][0]  = ui -> Pname5 -> text();
    str[4][1]  = ui -> Length5 -> text();
    str[4][2]  = ui -> Width5 -> text();
    str[4][3]  = ui -> Height5 -> text();
    str[4][4]  = ui -> Weight5 -> text();
    str[4][5]  = ui -> Qty5 -> text();
    str[4][6]  =  selectedColor5.name();

    str[5][0]  = ui -> Pname6 -> text();
    str[5][1]  = ui -> Length6 -> text();
    str[5][2]  = ui -> Width6 -> text();
    str[5][3]  = ui -> Height6 -> text();
    str[5][4]  = ui -> Weight6 -> text();
    str[5][5]  = ui -> Qty6 -> text();
    str[5][6]  =  selectedColor6.name();

    str[6][0]  = ui -> Pname7 -> text();
    str[6][1]  = ui -> Length7 -> text();
    str[6][2]  = ui -> Width7 -> text();
    str[6][3]  = ui -> Height7 -> text();
    str[6][4]  = ui -> Weight7 -> text();
    str[6][5]  = ui -> Qty7 -> text();
    str[6][6]  =  selectedColor7.name();

    str[7][0]  = ui -> Pname8 -> text();
    str[7][1]  = ui -> Length8 -> text();
    str[7][2]  = ui -> Width8 -> text();
    str[7][3]  = ui -> Height8 -> text();
    str[7][4]  = ui -> Weight8 -> text();
    str[7][5]  = ui -> Qty8 -> text();
    str[7][6]  =  selectedColor8.name();

    str[8][0]  = ui -> Pname9 -> text();
    str[8][1]  = ui -> Length9 -> text();
    str[8][2]  = ui -> Width9 -> text();
    str[8][3]  = ui -> Height9 -> text();
    str[8][4]  = ui -> Weight9 -> text();
    str[8][5]  = ui -> Qty9 -> text();
    str[8][6]  =  selectedColor9.name();

    str[9][0]  = ui -> Pname10 -> text();
    str[9][1]  = ui -> Length10 -> text();
    str[9][2]  = ui -> Width10 -> text();
    str[9][3]  = ui -> Height10 -> text();
    str[9][4]  = ui -> Weight10 -> text();
    str[9][5]  = ui -> Qty10 -> text();
    str[9][6]  =  selectedColor10.name();


    if(str[0][0].isEmpty() && str[1][0].isEmpty()&& str[2][0].isEmpty() && str[3][0].isEmpty() && str[4][0].isEmpty() ){

        QMessageBox::warning(this, "Missing Field", "Enter at least 1 Product!");

    }


    for (int i = 0; i < pro_no; i++) {

        QString num = QString::number(i+1);
        if(!str[i][0].isEmpty()) {

            for (int j = 0; j < 6; j++) {

                if(str[i][j].isEmpty()){

                    QMessageBox::warning(this, "Missing Field", "Enter Proper Information of " + num + " Product."); // missing product info warning
                    return;
                }
            }

            if(str[i][6] == "#000000") {

                QMessageBox::warning(this, "Missing Field", "Choose Unique Color");
                return;
            }
        }

    }

    if(!str[0][0].isEmpty() || !str[1][0].isEmpty() || !str[2][0].isEmpty() ||  !str[3][0].isEmpty() || !str[4][0].isEmpty() ){

        ui->stackedWidget->setCurrentIndex(2);
            setBoldButton(ui->ContainerButton);

    }


}


void MainWindow::handleColorPick1() {
    QColor color = QColorDialog::getColor();
    if (!color.isValid()) return;

    QString colorHex = color.name().toLower();

    if (selectedColorsSet.contains(colorHex)) {
        QMessageBox::warning(this, "Duplicate Color", "This color has already been selected. Please choose a unique color.");
        return;
    }


    selectedColorsSet.remove(selectedColor1.name().toLower());

    selectedColor1 = color;
    selectedColorsSet.insert(colorHex);

    ui->Color1->setStyleSheet(QString("background-color: %1; color: black;").arg(colorHex));
}



void MainWindow::handleColorPick2()
{
    QColor color = QColorDialog::getColor();
    if (!color.isValid()) return;

    QString colorHex = color.name().toLower();

    if (selectedColorsSet.contains(colorHex)) {
        QMessageBox::warning(this, "Duplicate Color", "This color has already been selected. Please choose a unique color.");
        return;
    }

    selectedColorsSet.remove(selectedColor2.name().toLower());

    selectedColor2 = color;
    selectedColorsSet.insert(colorHex);

    ui->Color2->setStyleSheet(QString("background-color: %1; color: black;").arg(colorHex));
}


void MainWindow::handleColorPick3()
{
    QColor color = QColorDialog::getColor();
    if (!color.isValid()) return;

    QString colorHex = color.name().toLower();

    if (selectedColorsSet.contains(colorHex)) {
        QMessageBox::warning(this, "Duplicate Color", "This color has already been selected. Please choose a unique color.");
        return;
    }

    selectedColorsSet.remove(selectedColor3.name().toLower());

    selectedColor3 = color;
    selectedColorsSet.insert(colorHex);

    ui->Color3->setStyleSheet(QString("background-color: %1; color: black;").arg(colorHex));
}


void MainWindow::handleColorPick4()
{
    QColor color = QColorDialog::getColor();
    if (!color.isValid()) return;

    QString colorHex = color.name().toLower();

    if (selectedColorsSet.contains(colorHex)) {
        QMessageBox::warning(this, "Duplicate Color", "This color has already been selected. Please choose a unique color.");
        return;
    }

    selectedColorsSet.remove(selectedColor4.name().toLower());

    selectedColor4 = color;
    selectedColorsSet.insert(colorHex);

    ui->Color4->setStyleSheet(QString("background-color: %1; color: black;").arg(colorHex));

}


void MainWindow::handleColorPick5()
{
    QColor color = QColorDialog::getColor();
    if (!color.isValid()) return;

    QString colorHex = color.name().toLower();

    if (selectedColorsSet.contains(colorHex)) {
        QMessageBox::warning(this, "Duplicate Color", "This color has already been selected. Please choose a unique color.");
        return;
    }

    selectedColorsSet.remove(selectedColor5.name().toLower());

    selectedColor5 = color;
    selectedColorsSet.insert(colorHex);

    ui->Color5->setStyleSheet(QString("background-color: %1; color: black;").arg(colorHex));
}


void MainWindow::handleColorPick6()
{
    QColor color = QColorDialog::getColor();
    if (!color.isValid()) return;

    QString colorHex = color.name().toLower();

    if (selectedColorsSet.contains(colorHex)) {
        QMessageBox::warning(this, "Duplicate Color", "This color has already been selected. Please choose a unique color.");
        return;
    }

    selectedColorsSet.remove(selectedColor6.name().toLower());

    selectedColor6 = color;
    selectedColorsSet.insert(colorHex);

    ui->Color6->setStyleSheet(QString("background-color: %1; color: black;").arg(colorHex));
}


void MainWindow::handleColorPick7()
{
    QColor color = QColorDialog::getColor();
    if (!color.isValid()) return;

    QString colorHex = color.name().toLower();

    if (selectedColorsSet.contains(colorHex)) {
        QMessageBox::warning(this, "Duplicate Color", "This color has already been selected. Please choose a unique color.");
        return;
    }

    selectedColorsSet.remove(selectedColor7.name().toLower());

    selectedColor7 = color;
    selectedColorsSet.insert(colorHex);

    ui->Color7->setStyleSheet(QString("background-color: %1; color: black;").arg(colorHex));
}


void MainWindow::handleColorPick8()
{
    QColor color = QColorDialog::getColor();
    if (!color.isValid()) return;

    QString colorHex = color.name().toLower();

    if (selectedColorsSet.contains(colorHex)) {
        QMessageBox::warning(this, "Duplicate Color", "This color has already been selected. Please choose a unique color.");
        return;
    }

    selectedColorsSet.remove(selectedColor8.name().toLower());

    selectedColor8 = color;
    selectedColorsSet.insert(colorHex);

    ui->Color8->setStyleSheet(QString("background-color: %1; color: black;").arg(colorHex));
}


void MainWindow::handleColorPick9()
{
    QColor color = QColorDialog::getColor();
    if (!color.isValid()) return;

    QString colorHex = color.name().toLower();

    if (selectedColorsSet.contains(colorHex)) {
        QMessageBox::warning(this, "Duplicate Color", "This color has already been selected. Please choose a unique color.");
        return;
    }

    selectedColorsSet.remove(selectedColor9.name().toLower());

    selectedColor9 = color;
    selectedColorsSet.insert(colorHex);

    ui->Color9->setStyleSheet(QString("background-color: %1; color: black;").arg(colorHex));

}


void MainWindow::handleColorPick10()
{
    QColor color = QColorDialog::getColor();
    if (!color.isValid()) return;

    QString colorHex = color.name().toLower();

    if (selectedColorsSet.contains(colorHex)) {
        QMessageBox::warning(this, "Duplicate Color", "This color has already been selected. Please choose a unique color.");
        return;
    }

    selectedColorsSet.remove(selectedColor10.name().toLower());

    selectedColor10 = color;
    selectedColorsSet.insert(colorHex);

    ui->Color10->setStyleSheet(QString("background-color: %1; color: black;").arg(colorHex));
}

int count=0;

void MainWindow::on_Add_clicked()
{

    if(count==0){
        ui->Pname6->show();
        ui->Length6->show();
        ui->Width6->show();
        ui->Height6->show();
        ui->Weight6->show();
        ui->Qty6->show();
        ui->lable6->show();
        ui->lable6_2->show();
        ui->lable6_3->show();
        ui->lable6_4->show();
        ui->Color6->show();
        ui->Line6->show();
        ui->comboBox6->show();
    }

    if(count==1){
        ui->Pname7->show();
        ui->Length7->show();
        ui->Width7->show();
        ui->Height7->show();
        ui->Weight7->show();
        ui->Qty7->show();
        ui->lable7->show();
        ui->lable7_2->show();
        ui->lable7_3->show();
        ui->lable7_4->show();
        ui->Color7->show();
        ui->Line7->show();
        ui->comboBox7->show();
    }

    if(count==2){
        ui->Pname8->show();
        ui->Length8->show();
        ui->Width8->show();
        ui->Height8->show();
        ui->Weight8->show();
        ui->Qty8->show();
        ui->lable8->show();
        ui->lable8_2->show();
        ui->lable8_3->show();
        ui->lable8_4->show();
        ui->Color8->show();
        ui->Line8->show();
        ui->comboBox8->show();
    }

    if(count==3){
        ui->Pname9->show();
        ui->Length9->show();
        ui->Width9->show();
        ui->Height9->show();
        ui->Weight9->show();
        ui->Qty9->show();
        ui->lable9->show();
        ui->lable9_2->show();
        ui->lable9_3->show();
        ui->lable9_4->show();
        ui->Color9->show();
        ui->Line9->show();
        ui->comboBox9->show();
    }

    if(count==4){
        ui->Pname10  ->show();
        ui->Length10->show();
        ui->Width10->show();
        ui->Height10->show();
        ui->Weight10->show();
        ui->Qty10->show();
        ui->lable10->show();
        ui->lable10_2->show();
        ui->lable10_3->show();
        ui->lable10_4->show();
        ui->Color10->show();
        ui->Line10->show();
        ui->comboBox10->show();
    }

    count++;
    pro_no++;

}

void MainWindow::on_DeleteAll_clicked()
{
    MainWindow::on_Line1_clicked();
    MainWindow::on_Line2_clicked();
    MainWindow::on_Line3_clicked();
    MainWindow::on_Line4_clicked();
    MainWindow::on_Line5_clicked();
    MainWindow::on_Line6_clicked();
    MainWindow::on_Line7_clicked();
    MainWindow::on_Line8_clicked();
    MainWindow::on_Line9_clicked();
    MainWindow::on_Line10_clicked();

    ui->Pname6->hide();
    ui->Length6->hide();
    ui->Width6->hide();
    ui->Height6->hide();
    ui->Weight6->hide();
    ui->Qty6->hide();
    ui->lable6->hide();
    ui->lable6_2->hide();
    ui->lable6_3->hide();
    ui->lable6_4->hide();
    ui->Color6->hide();
    ui->Line6->hide();
    ui->comboBox6->hide();

    ui->Pname7->hide();
    ui->Length7->hide();
    ui->Width7->hide();
    ui->Height7->hide();
    ui->Weight7->hide();
    ui->Qty7->hide();
    ui->lable7->hide();
    ui->lable7_2->hide();
    ui->lable7_3->hide();
    ui->lable7_4->hide();
    ui->Color7->hide();
    ui->Line7->hide();
    ui->comboBox7->hide();

    ui->Pname8->hide();
    ui->Length8->hide();
    ui->Width8->hide();
    ui->Height8->hide();
    ui->Weight8->hide();
    ui->Qty8->hide();
    ui->lable8->hide();
    ui->lable8_2->hide();
    ui->lable8_3->hide();
    ui->lable8_4->hide();
    ui->Color8->hide();
    ui->Line8->hide();
    ui->comboBox8->hide();

    ui->Pname9->hide();
    ui->Length9->hide();
    ui->Width9->hide();
    ui->Height9->hide();
    ui->Weight9->hide();
    ui->Qty9->hide();
    ui->lable9->hide();
    ui->lable9_2->hide();
    ui->lable9_3->hide();
    ui->lable9_4->hide();
    ui->Color9->hide();
    ui->Line9->hide();
    ui->comboBox9->hide();

    ui->Pname10->hide();
    ui->Length10->hide();
    ui->Width10->hide();
    ui->Height10->hide();
    ui->Weight10->hide();
    ui->Qty10->hide();
    ui->lable10->hide();
    ui->lable10_2->hide();
    ui->lable10_3->hide();
    ui->lable10_4->hide();
    ui->Color10->hide();
    ui->Line10->hide();
    ui->comboBox10->hide();

    count = 0;
    pro_no = 5;

}


void MainWindow::on_Line1_clicked()
{
    ui->Pname1->clear();
    ui->Length1->clear();
    ui->Width1->clear();
    ui->Height1->clear();
    ui->Weight1->clear();
    ui->Qty1->clear();

    for (int j = 0; j < 6; j++)
        str[0][j].clear();

    ui->Color1->setStyleSheet("background-color: white;");

    selectedColorsSet.remove(selectedColor1.name().toLower());
    selectedColor1 = QColor();


}


void MainWindow::on_Line2_clicked()
{
    ui->Pname2->clear();
    ui->Length2->clear();
    ui->Width2->clear();
    ui->Height2->clear();
    ui->Weight2->clear();
    ui->Qty2->clear();

    for (int j = 0; j < 6; j++)
        str[1][j].clear();

    ui->Color2->setStyleSheet("background-color: white;");

    selectedColorsSet.remove(selectedColor1.name().toLower());
    selectedColor1 = QColor();
}

void MainWindow::on_Line3_clicked()
{
    ui->Pname3->clear();
    ui->Length3->clear();
    ui->Width3->clear();
    ui->Height3->clear();
    ui->Weight3->clear();
    ui->Qty3->clear();

    for (int j = 0; j < 6; j++)
        str[2][j].clear();

    ui->Color3->setStyleSheet("background-color: white;");

}

void MainWindow::on_Line4_clicked()
{
    ui->Pname4->clear();
    ui->Length4->clear();
    ui->Width4->clear();
    ui->Height4->clear();
    ui->Weight4->clear();
    ui->Qty4->clear();

    for (int j = 0; j < 6; j++)
        str[3][j].clear();

    ui->Color4->setStyleSheet("background-color: white;");
}


void MainWindow::on_Line5_clicked()
{
    ui->Pname5->clear();
    ui->Length5->clear();
    ui->Width5->clear();
    ui->Height5->clear();
    ui->Weight5->clear();
    ui->Qty5->clear();

    for (int j = 0; j < 6; j++)
        str[4][j].clear();

    ui->Color5->setStyleSheet("background-color: white;");
}

void MainWindow::on_Line6_clicked()
{
    ui->Pname6->clear();
    ui->Length6->clear();
    ui->Width6->clear();
    ui->Height6->clear();
    ui->Weight6->clear();
    ui->Qty6->clear();

    for (int j = 0; j < 6; j++)
        str[5][j].clear();

    ui->Color6->setStyleSheet("background-color: white;");

}

void MainWindow::on_Line7_clicked()
{
    ui->Pname7->clear();
    ui->Length7->clear();
    ui->Width7->clear();
    ui->Height7->clear();
    ui->Weight7->clear();
    ui->Qty7->clear();

    for (int j = 0; j < 6; j++)
        str[6][j].clear();

    ui->Color7->setStyleSheet("background-color: white;");
}

void MainWindow::on_Line8_clicked()
{
    ui->Pname8->clear();
    ui->Length8->clear();
    ui->Width8->clear();
    ui->Height8->clear();
    ui->Weight8->clear();
    ui->Qty8->clear();

    for (int j = 0; j < 6; j++)
        str[7][j].clear();

    ui->Color8->setStyleSheet("background-color: white;");
}


void MainWindow::on_Line9_clicked()
{
    ui->Pname9->clear();
    ui->Length9->clear();
    ui->Width9->clear();
    ui->Height9->clear();
    ui->Weight9->clear();
    ui->Qty9->clear();

    for (int j = 0; j < 6; j++)
        str[8][j].clear();

    ui->Color9->setStyleSheet("background-color: white;");
}


void MainWindow::on_Line10_clicked()
{
    ui->Pname10->clear();
    ui->Length10->clear();
    ui->Width10->clear();
    ui->Height10->clear();
    ui->Weight10->clear();
    ui->Qty10->clear();

    for (int j = 0; j < 6; j++)
        str[9][j].clear();

    ui->Color10->setStyleSheet("background-color: white;");
}


void MainWindow::on_SaveProduct_clicked()
{
    fillStrArrayFromUI();

    if (str[0][0].isEmpty() && str[1][0].isEmpty() &&
        str[2][0].isEmpty() && str[3][0].isEmpty() && str[4][0].isEmpty()) {
        QMessageBox::warning(this, "Missing Field", "Enter at least 1 Product!");
        return;
    }

    for (int i = 0; i < pro_no; i++) {
        QString num = QString::number(i + 1);
        if (!str[i][0].isEmpty()) {
            for (int j = 0; j < 6; j++) {
                if (str[i][j].isEmpty()) {
                    QMessageBox::warning(this, "Missing Field", "Enter Proper Information of " + num + " Product.");
                    return;
                }
            }
            if (str[i][6] == "#000000") {
                QMessageBox::warning(this, "Missing Field", "Choose Unique Color for Product " + num);
                return;
            }
        }
    }

    QFile saveFile("products_data.json");
    QJsonArray productArray;

    if (saveFile.exists()) {
        if (saveFile.open(QIODevice::ReadOnly)) {
            QByteArray data = saveFile.readAll();
            QJsonDocument loadDoc = QJsonDocument::fromJson(data);
            QJsonObject root = loadDoc.object();
            if (root.contains("products") && root["products"].isArray()) {
                productArray = root["products"].toArray();
            }
            saveFile.close();
        }
    }

    QStringList duplicateNames;
    int savedCount = 0;

    for (int i = 0; i < pro_no; ++i) {
        if (!str[i][0].isEmpty()) {
            QJsonObject productObj;
            productObj["name"]     = str[i][0];
            productObj["length"]   = str[i][1].toInt();
            productObj["width"]    = str[i][2].toInt();
            productObj["height"]   = str[i][3].toInt();
            productObj["weight"]   = str[i][4].toInt();
            productObj["quantity"] = str[i][5].toInt();

            bool isDuplicate = false;
            for (const QJsonValue &val : productArray) {
                QJsonObject existing = val.toObject();
                if (existing["name"].toString().compare(productObj["name"].toString(), Qt::CaseInsensitive) == 0) {
                    isDuplicate = true;
                    break;
                }
            }

            if (isDuplicate) {
                duplicateNames.append(productObj["name"].toString());
            } else {
                productArray.append(productObj);
                savedCount++;
            }
        }
    }

    QJsonObject rootObj;
    rootObj["products"] = productArray;
    QJsonDocument saveDoc(rootObj);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Save Error", "Could not open file to write.");
        return;
    }

    saveFile.write(saveDoc.toJson(QJsonDocument::Indented));
    saveFile.close();

    QString message;
    if (savedCount > 0)
        message += QString::number(savedCount) + " product(s) saved successfully.\n";

    if (!duplicateNames.isEmpty())
        message += "\nDuplicate product(s) skipped:\n" + duplicateNames.join(", ");

    if (message.isEmpty())
        message = "No new products were saved.";

    QMessageBox::information(this, "Save Result", message);

    on_DeleteAll_clicked();
}


void MainWindow::fillStrArrayFromUI()
{
    str[0][0] = ui->Pname1->text();
    str[0][1] = ui->Length1->text();
    str[0][2] = ui->Width1->text();
    str[0][3] = ui->Height1->text();
    str[0][4] = ui->Weight1->text();
    str[0][5] = ui->Qty1->text();

    str[1][0] = ui->Pname2->text();
    str[1][1] = ui->Length2->text();
    str[1][2] = ui->Width2->text();
    str[1][3] = ui->Height2->text();
    str[1][4] = ui->Weight2->text();
    str[1][5] = ui->Qty2->text();

    str[2][0] = ui->Pname3->text();
    str[2][1] = ui->Length3->text();
    str[2][2] = ui->Width3->text();
    str[2][3] = ui->Height3->text();
    str[2][4] = ui->Weight3->text();
    str[2][5] = ui->Qty3->text();

    str[3][0] = ui->Pname4->text();
    str[3][1] = ui->Length4->text();
    str[3][2] = ui->Width4->text();
    str[3][3] = ui->Height4->text();
    str[3][4] = ui->Weight4->text();
    str[3][5] = ui->Qty4->text();

    str[4][0] = ui->Pname5->text();
    str[4][1] = ui->Length5->text();
    str[4][2] = ui->Width5->text();
    str[4][3] = ui->Height5->text();
    str[4][4] = ui->Weight5->text();
    str[4][5] = ui->Qty5->text();

    str[5][0] = ui->Pname6->text();
    str[5][1] = ui->Length6->text();
    str[5][2] = ui->Width6->text();
    str[5][3] = ui->Height6->text();
    str[5][4] = ui->Weight6->text();
    str[5][5] = ui->Qty6->text();

    str[6][0] = ui->Pname7->text();
    str[6][1] = ui->Length7->text();
    str[6][2] = ui->Width7->text();
    str[6][3] = ui->Height7->text();
    str[6][4] = ui->Weight7->text();
    str[6][5] = ui->Qty7->text();

    str[7][0] = ui->Pname8->text();
    str[7][1] = ui->Length8->text();
    str[7][2] = ui->Width8->text();
    str[7][3] = ui->Height8->text();
    str[7][4] = ui->Weight8->text();
    str[7][5] = ui->Qty8->text();

    str[8][0] = ui->Pname9->text();
    str[8][1] = ui->Length9->text();
    str[8][2] = ui->Width9->text();
    str[8][3] = ui->Height9->text();
    str[8][4] = ui->Weight9->text();
    str[8][5] = ui->Qty9->text();

    str[9][0] = ui->Pname10->text();
    str[9][1] = ui->Length10->text();
    str[9][2] = ui->Width10->text();
    str[9][3] = ui->Height10->text();
    str[9][4] = ui->Weight10->text();
    str[9][5] = ui->Qty10->text();

}


void MainWindow::on_SelectVP_clicked()
{

    setBoldButton(ui->SelectVP);

    ui->VPTreeWidget->setColumnWidth(0, 250);

    ui->SelectUserContainer->hide();
    ui->container3DPlaceholder->hide();
    ui->ShowContainer->hide();

    ui->SelectAdd->show();
    ui->SelectAdd->setCurrentIndex(3);

    QString path = "C:/Users/vaibh/OneDrive/Documents/LoadingApp/build/Desktop_Qt_6_9_1_MinGW_64_bit-Debug/VP_data.json";
    QFile file(path);

    if (!file.exists()) {
        QMessageBox::warning(this, "Error", "File not found:\n" + path);
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", "Could not open file:\n" + file.errorString());
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        QMessageBox::critical(this, "JSON Parse Error", parseError.errorString());
        return;
    }

    if (!doc.isArray()) {
        QMessageBox::warning(this, "Error", "JSON root is not an array!");
        return;
    }

    QJsonArray vpArray = doc.array();

    ui->VPTreeWidget->clear();
    ui->VPTreeWidget->setColumnCount(5);
    ui->VPTreeWidget->setHeaderLabels({"Name", "Length", "Width", "Height", "Weight"});

    ui->VPTreeWidget->setAlternatingRowColors(true);
    ui->VPTreeWidget->setStyleSheet(R"(
        QTreeWidget {
            border: 1px solid #cccccc;
            border-radius: 8px;
            background-color: #fdfdfd;
            alternate-background-color: #f0f0f0;
            padding: 4px;
            font-size: 14px;
        }

        QTreeWidget::item {
            padding: 6px;
        }

        QTreeWidget::item:hover {
            background-color: #d0eaff;
        }

        QTreeWidget::item:selected {
            background-color: #4ab1c8;
            color: white;
        }

        QHeaderView::section {
            background-color: #3a87ad;
            color: white;
            padding: 6px;
            font-weight: bold;
            border: none;
        }
    )");

    for (const QJsonValue &value : vpArray) {
        QJsonObject obj = value.toObject();
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0, obj["vpname"].toString());
        item->setText(1, QString::number(obj["length"].toDouble(), 'f', 2));
        item->setText(2, QString::number(obj["width"].toDouble(), 'f', 2));
        item->setText(3, QString::number(obj["height"].toDouble(), 'f', 2));
        item->setText(4, QString::number(obj["weight"].toDouble(), 'f', 2));

        ui->VPTreeWidget->addTopLevelItem(item);
    }
}


void MainWindow::on_SelectTruck_clicked()
{
    setBoldButton(ui->SelectTruck);

    ui->TruckTreeWidget->setColumnWidth(0, 250);

    ui->SelectUserContainer->hide();
    ui->container3DPlaceholder->hide();
    ui->ShowContainer->hide();

    ui->SelectAdd->show();
    ui->SelectAdd->setCurrentIndex(0);

    QString path = "C:/Users/vaibh/OneDrive/Documents/LoadingApp/build/Desktop_Qt_6_9_1_MinGW_64_bit-Debug/Truck_data.json";
    QFile file(path);

    if (!file.exists()) {
        QMessageBox::warning(this, "Error", "File not found:\n" + path);
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", "Could not open file:\n" + file.errorString());
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        QMessageBox::critical(this, "JSON Parse Error", parseError.errorString());
        return;
    }

    if (!doc.isArray()) {
        QMessageBox::warning(this, "Error", "JSON root is not an array!");
        return;
    }

    QJsonArray truckArray = doc.array();

    ui->TruckTreeWidget->clear();
    ui->TruckTreeWidget->setColumnCount(5);
    ui->TruckTreeWidget->setHeaderLabels({"Name", "Length", "Width", "Height", "Weight"});

    ui->TruckTreeWidget->setAlternatingRowColors(true);
    ui->TruckTreeWidget->setStyleSheet(R"(
        QTreeWidget {
            border: 1px solid #cccccc;
            border-radius: 8px;
            background-color: #fdfdfd;
            alternate-background-color: #f0f0f0;
            padding: 4px;
            font-size: 14px;
        }

        QTreeWidget::item {
            padding: 6px;
        }

        QTreeWidget::item:hover {
            background-color: #d0eaff;
        }

        QTreeWidget::item:selected {
            background-color: #4ab1c8;
            color: white;
        }

        QHeaderView::section {
            background-color: #3a87ad;
            color: white;
            padding: 6px;
            font-weight: bold;
            border: none;
        }
    )");

    for (const QJsonValue &value : truckArray) {
        QJsonObject obj = value.toObject();
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0, obj["truckname"].toString());
        item->setText(1, QString::number(obj["length"].toDouble(), 'f', 2));
        item->setText(2, QString::number(obj["width"].toDouble(), 'f', 2));
        item->setText(3, QString::number(obj["height"].toDouble(), 'f', 2));
        item->setText(4, QString::number(obj["weight"].toDouble(), 'f', 2));

        ui->TruckTreeWidget->addTopLevelItem(item);
    }
}



void MainWindow::on_SelectContainer_clicked()
{
    setBoldButton(ui->SelectContainer);

    ui->ContainerTreeWidget->setColumnWidth(0, 250);

    ui->SelectUserContainer->hide();
    ui->container3DPlaceholder->hide();
    ui->ShowContainer->hide();

    ui->SelectAdd->show();
    ui->SelectAdd->setCurrentIndex(1);

    QString path = "C:/Users/vaibh/OneDrive/Documents/LoadingApp/build/Desktop_Qt_6_9_1_MinGW_64_bit-Debug/Container_data.json";
    QFile file(path);

    if (!file.exists()) {
        QMessageBox::warning(this, "Error", "File not found:\n" + path);
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", "Could not open file:\n" + file.errorString());
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        QMessageBox::critical(this, "JSON Parse Error", parseError.errorString());
        return;
    }

    if (!doc.isArray()) {
        QMessageBox::warning(this, "Error", "JSON root is not an array!");
        return;
    }

    QJsonArray containerArray = doc.array();

    ui->ContainerTreeWidget->clear();
    ui->ContainerTreeWidget->setColumnCount(5);
    ui->ContainerTreeWidget->setHeaderLabels({"Name", "Length", "Width", "Height", "Weight"});

    ui->ContainerTreeWidget->setAlternatingRowColors(true);
    ui->ContainerTreeWidget->setStyleSheet(R"(
        QTreeWidget {
            border: 1px solid #cccccc;
            border-radius: 8px;
            background-color: #fdfdfd;
            alternate-background-color: #f0f0f0;
            padding: 4px;
            font-size: 14px;
        }

        QTreeWidget::item {
            padding: 6px;
        }

        QTreeWidget::item:hover {
            background-color: #d0eaff;
        }

        QTreeWidget::item:selected {
            background-color: #4ab1c8;
            color: white;
        }

        QHeaderView::section {
            background-color: #3a87ad;
            color: white;
            padding: 6px;
            font-weight: bold;
            border: none;
        }
    )");

    for (const QJsonValue &value : containerArray) {
        QJsonObject obj = value.toObject();
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0, obj["containername"].toString());
        item->setText(1, QString::number(obj["length"].toDouble(), 'f', 2));
        item->setText(2, QString::number(obj["width"].toDouble(), 'f', 2));
        item->setText(3, QString::number(obj["height"].toDouble(), 'f', 2));
        item->setText(4, QString::number(obj["weight"].toDouble(), 'f', 2));

        ui->ContainerTreeWidget->addTopLevelItem(item);
    }
}


void MainWindow::on_SelectWarehouse_clicked()
{
    setBoldButton(ui->SelectWarehouse);

    ui->WarehouseTreeWidget->setColumnWidth(0, 250);

    ui->SelectUserContainer->hide();
    ui->container3DPlaceholder->hide();
    ui->ShowContainer->hide();

    ui->SelectAdd->show();
    ui->SelectAdd->setCurrentIndex(2);

    QString path = "C:/Users/vaibh/OneDrive/Documents/LoadingApp/build/Desktop_Qt_6_9_1_MinGW_64_bit-Debug/Warehouse_data.json";
    QFile file(path);

    if (!file.exists()) {
        QMessageBox::warning(this, "Error", "File not found:\n" + path);
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", "Could not open file:\n" + file.errorString());
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        QMessageBox::critical(this, "JSON Parse Error", parseError.errorString());
        return;
    }

    if (!doc.isArray()) {
        QMessageBox::warning(this, "Error", "JSON root is not an array!");
        return;
    }

    QJsonArray warehouseArray = doc.array();

    ui->WarehouseTreeWidget->clear();
    ui->WarehouseTreeWidget->setColumnCount(5);
    ui->WarehouseTreeWidget->setHeaderLabels({"Name", "Length", "Width", "Height", "Weight"});

    ui->WarehouseTreeWidget->setAlternatingRowColors(true);
    ui->WarehouseTreeWidget->setStyleSheet(R"(
        QTreeWidget {
            border: 1px solid #cccccc;
            border-radius: 8px;
            background-color: #fdfdfd;
            alternate-background-color: #f0f0f0;
            padding: 4px;
            font-size: 14px;
        }

        QTreeWidget::item {
            padding: 6px;
        }

        QTreeWidget::item:hover {
            background-color: #d0eaff;
        }

        QTreeWidget::item:selected {
            background-color: #4ab1c8;
            color: white;
        }

        QHeaderView::section {
            background-color: #3a87ad;
            color: white;
            padding: 6px;
            font-weight: bold;
            border: none;
        }
    )");

    for (const QJsonValue &value : warehouseArray) {
        QJsonObject obj = value.toObject();
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0, obj["warehousename"].toString());
        item->setText(1, QString::number(obj["length"].toDouble(), 'f', 2));
        item->setText(2, QString::number(obj["width"].toDouble(), 'f', 2));
        item->setText(3, QString::number(obj["height"].toDouble(), 'f', 2));
        item->setText(4, QString::number(obj["weight"].toDouble(), 'f', 2));

        ui->WarehouseTreeWidget->addTopLevelItem(item);
    }
}


void MainWindow::on_CancleContainer_clicked()
{
    ui->SelectAdd->hide();

    ui->container3DPlaceholder->show();
    ui->ShowContainer->show();
    ui->SelectUserContainer->show();
}


void MainWindow::on_CancleWarehouse_clicked()
{
    ui->SelectAdd->hide();

    ui->container3DPlaceholder->show();
    ui->ShowContainer->show();
    ui->SelectUserContainer->show();
}


void MainWindow::on_CancleVP_clicked()
{
    ui->SelectAdd->hide();

    ui->container3DPlaceholder->show();
    ui->ShowContainer->show();
    ui->SelectUserContainer->show();
}


void MainWindow::on_CancleTruck_clicked()
{
    ui->SelectAdd->hide();

    ui->container3DPlaceholder->show();
    ui->ShowContainer->show();
    ui->SelectUserContainer->show();
}


void MainWindow::on_VPSave_clicked()
{
    QString vpname = ui->AddVPName->text().trimmed();
    QString length = ui->AddVPLength->text().trimmed();
    QString width  = ui->AddVPWidth->text().trimmed();
    QString height = ui->AddVPHeight->text().trimmed();
    QString weight = ui->AddVPWeight->text().trimmed();

    if (vpname.isEmpty() || length.isEmpty() || width.isEmpty() ||
        height.isEmpty() || weight.isEmpty()) {
        QMessageBox::warning(this, "Missing Input", "Please fill all fields.");
        return;
    }

    QJsonArray vpArray;
    QFile file("VP_data.json");
    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (doc.isArray())
            vpArray = doc.array();
        file.close();
    }

    QString vpnameLower = vpname.toLower();
    for (const QJsonValue &val : vpArray) {
        QJsonObject obj = val.toObject();
        if (obj["vpname"].toString().toLower() == vpnameLower) {
            QMessageBox::warning(this, "Duplicate VP", "This " + vpname + " VP already exists.");

            ui->AddVPName->clear();
            ui->AddVPLength->clear();
            ui->AddVPWidth->clear();
            ui->AddVPHeight->clear();
            ui->AddVPWeight->clear();
            return;
        }
    }

    QJsonObject newVP;
    newVP["vpname"] = vpname;
    newVP["length"] = length.toInt();
    newVP["width"]  = width.toInt();
    newVP["height"] = height.toInt();
    newVP["weight"] = weight.toDouble();

    vpArray.append(newVP);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open VP_data.json for writing.");
        return;
    }

    QJsonDocument saveDoc(vpArray);
    file.write(saveDoc.toJson(QJsonDocument::Indented));
    file.close();

    QMessageBox::information(this, "Success", "VP data saved successfully.");

    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, vpname);
    item->setText(1, length);
    item->setText(2, width);
    item->setText(3, height);
    item->setText(4, weight);
    ui->VPTreeWidget->addTopLevelItem(item);

    ui->AddVPName->clear();
    ui->AddVPLength->clear();
    ui->AddVPWidth->clear();
    ui->AddVPHeight->clear();
    ui->AddVPWeight->clear();
}




void MainWindow::on_TruckSave_clicked()
{
    QString truckname = ui->AddTruckName->text().trimmed();
    QString length = ui->AddTruckLength->text().trimmed();
    QString width  = ui->AddTruckWidth->text().trimmed();
    QString height = ui->AddTruckHeight->text().trimmed();
    QString weight = ui->AddTruckWeight->text().trimmed();

    if (truckname.isEmpty() || length.isEmpty() || width.isEmpty() ||
        height.isEmpty() || weight.isEmpty()) {
        QMessageBox::warning(this, "Missing Input", "Please fill in all truck fields.");
        return;
    }

    QJsonArray truckArray;
    QFile file("Truck_data.json");
    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (doc.isArray())
            truckArray = doc.array();
        file.close();
    }

    QString trucknameLower = truckname.toLower();
    for (const QJsonValue &val : truckArray) {
        QJsonObject obj = val.toObject();
        if (obj["truckname"].toString().toLower() == trucknameLower) {
            QMessageBox::warning(this, "Duplicate Truck", "This " + truckname + " Truck already exists.");

            ui->AddTruckName->clear();
            ui->AddTruckLength->clear();
            ui->AddTruckWidth->clear();
            ui->AddTruckHeight->clear();
            ui->AddTruckWeight->clear();
            return;
        }
    }

    QJsonObject newTruck;
    newTruck["truckname"] = truckname;
    newTruck["length"] = length.toDouble();
    newTruck["width"]  = width.toDouble();
    newTruck["height"] = height.toDouble();
    newTruck["weight"] = weight.toDouble();

    truckArray.append(newTruck);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open Truck_data.json for writing.");
        return;
    }

    QJsonDocument saveDoc(truckArray);
    file.write(saveDoc.toJson(QJsonDocument::Indented));
    file.close();

    QMessageBox::information(this, "Success", "Truck data saved successfully.");

    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, truckname);
    item->setText(1, length);
    item->setText(2, width);
    item->setText(3, height);
    item->setText(4, weight);
    ui->TruckTreeWidget->addTopLevelItem(item);

    ui->AddTruckName->clear();
    ui->AddTruckLength->clear();
    ui->AddTruckWidth->clear();
    ui->AddTruckHeight->clear();
    ui->AddTruckWeight->clear();
}




void MainWindow::on_ContainerSave_clicked()
{
    QString containername = ui->AddContainerName->text().trimmed();
    QString length = ui->AddContainerLength->text().trimmed();
    QString width  = ui->AddContainerWidth->text().trimmed();
    QString height = ui->AddContainerHeight->text().trimmed();
    QString weight = ui->AddContainerWeight->text().trimmed();

    if (containername.isEmpty() || length.isEmpty() || width.isEmpty() ||
        height.isEmpty() || weight.isEmpty()) {
        QMessageBox::warning(this, "Missing Input", "Please fill in all container fields.");
        return;
    }

    QJsonArray containerArray;
    QFile file("Container_data.json");
    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (doc.isArray())
            containerArray = doc.array();
        file.close();
    }

    QString containernameLower = containername.toLower();
    for (const QJsonValue &val : containerArray) {
        QJsonObject obj = val.toObject();
        if (obj["containername"].toString().toLower() == containernameLower) {
            QMessageBox::warning(this, "Duplicate Container",  "This " + containername +  " Container already exists.");

            ui->AddContainerName->clear();
            ui->AddContainerLength->clear();
            ui->AddContainerWidth->clear();
            ui->AddContainerHeight->clear();
            ui->AddContainerWeight->clear();

            return;
        }
    }

    QJsonObject newContainer;
    newContainer["containername"] = containername;
    newContainer["length"] = length.toDouble();
    newContainer["width"]  = width.toDouble();
    newContainer["height"] = height.toDouble();
    newContainer["weight"] = weight.toDouble();

    containerArray.append(newContainer);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open Container_data.json for writing.");
        return;
    }

    QJsonDocument saveDoc(containerArray);
    file.write(saveDoc.toJson(QJsonDocument::Indented));
    file.close();

    QMessageBox::information(this, "Success", "Container data saved successfully.");

    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, containername);
    item->setText(1, length);
    item->setText(2, width);
    item->setText(3, height);
    item->setText(4, weight);
    ui->ContainerTreeWidget->addTopLevelItem(item);

    ui->AddContainerName->clear();
    ui->AddContainerLength->clear();
    ui->AddContainerWidth->clear();
    ui->AddContainerHeight->clear();
    ui->AddContainerWeight->clear();
}



void MainWindow::on_WarehouseSave_clicked()
{
    QString warehousename = ui->AddWarehouseName->text().trimmed();
    QString length = ui->AddWarehouseLength->text().trimmed();
    QString width  = ui->AddWarehouseWidth->text().trimmed();
    QString height = ui->AddWarehouseHeight->text().trimmed();
    QString weight = ui->AddWarehouseWeight->text().trimmed();

    if (warehousename.isEmpty() || length.isEmpty() || width.isEmpty() ||
        height.isEmpty() || weight.isEmpty()) {
        QMessageBox::warning(this, "Missing Input", "Please fill in all warehouse fields.");
        return;
    }

    QJsonArray warehouseArray;
    QFile file("Warehouse_data.json");
    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (doc.isArray())
            warehouseArray = doc.array();
        file.close();
    }

    QString warehousenameLower = warehousename.toLower();
    for (const QJsonValue &val : warehouseArray) {
        QJsonObject obj = val.toObject();
        if (obj["warehousename"].toString().toLower() == warehousenameLower) {
            QMessageBox::warning(this, "Duplicate Warehouse",  "This " + warehousename +  " warehouse already exists.");

            ui->AddWarehouseName->clear();
            ui->AddWarehouseLength->clear();
            ui->AddWarehouseWidth->clear();
            ui->AddWarehouseHeight->clear();
            ui->AddWarehouseWeight->clear();

            return;
        }
    }

    QJsonObject newWarehouse;
    newWarehouse["warehousename"] = warehousename;
    newWarehouse["length"] = length.toDouble();
    newWarehouse["width"]  = width.toDouble();
    newWarehouse["height"] = height.toDouble();
    newWarehouse["weight"] = weight.toDouble();

    warehouseArray.append(newWarehouse);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open Warehouse_data.json for writing.");
        return;
    }

    QJsonDocument saveDoc(warehouseArray);
    file.write(saveDoc.toJson(QJsonDocument::Indented));
    file.close();

    QMessageBox::information(this, "Success", "Warehouse data saved successfully.");

    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, warehousename);
    item->setText(1, length);
    item->setText(2, width);
    item->setText(3, height);
    item->setText(4, weight);
    ui->WarehouseTreeWidget->addTopLevelItem(item);

    ui->AddWarehouseName->clear();
    ui->AddWarehouseLength->clear();
    ui->AddWarehouseWidth->clear();
    ui->AddWarehouseHeight->clear();
    ui->AddWarehouseWeight->clear();
}



void MainWindow::on_ProductInContainer_clicked()
{

    ui->ResultPlaceholder->hide();

    ui->widgetAddProduct->show();

    ui->treeWidget->setColumnWidth(0, 170);

    QString path = "C:/Users/vaibh/OneDrive/Documents/LoadingApp/build/Desktop_Qt_6_9_1_MinGW_64_bit-Debug/products_data.json";
    QFile file(path);

    if (!file.exists()) {
        QMessageBox::warning(this, "Error", "File not found:\n" + path);
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", "Could not open file:\n" + file.errorString());
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        QMessageBox::critical(this, "JSON Parse Error", parseError.errorString());
        return;
    }

    if (!doc.isObject()) {
        QMessageBox::warning(this, "Error", "JSON root is not an object!");
        return;
    }

    QJsonArray products = doc.object()["products"].toArray();

    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(6);
    ui->treeWidget->setHeaderLabels({"Name", "Length", "Width", "Height", "Weight", "Quantity"});

    ui->treeWidget->setAlternatingRowColors(true);
    ui->treeWidget->setStyleSheet(R"(
    QTreeWidget {
        border: 1px solid #cccccc;
        border-radius: 8px;
        background-color: #fdfdfd;
        alternate-background-color: #f0f0f0;
        padding: 4px;
        font-size: 14px;
    }

    QTreeWidget::item {
        padding: 6px;
    }

    QTreeWidget::item:hover {
        background-color: #d0eaff;
    }

    QTreeWidget::item:selected {
        background-color: #4ab1c8;
        color: white;
    }

    QHeaderView::section {
        background-color: #3a87ad;
        color: white;
        padding: 6px;
        font-weight: bold;
        border: none;
    }
)");

    for (const QJsonValue &value : products) {
        QJsonObject obj = value.toObject();
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0, obj["name"].toString());
        item->setText(1, QString::number(obj["length"].toInt()));
        item->setText(2, QString::number(obj["width"].toInt()));
        item->setText(3, QString::number(obj["height"].toInt()));
        item->setText(4, QString::number(obj["weight"].toInt()));
        item->setText(5, QString::number(obj["quantity"].toInt()));
        ui->treeWidget->addTopLevelItem(item);
    }
}


void MainWindow::on_Cancle_clicked()
{
    ui->widgetAddProduct->hide();

    ui->ResultPlaceholder->show();
}


void MainWindow::handleColorPick11()
{
    QColor color = QColorDialog::getColor();
    if (!color.isValid()) return;

    QString colorHex = color.name().toLower();

    if (selectedColorsSet.contains(colorHex)) {
        QMessageBox::warning(this, "Duplicate Color", "This color has already been selected. Please choose a unique color.");
        return;
    }

    selectedColorsSet.remove(selectedColor11.name().toLower());

    selectedColor11 = color;
    selectedColorsSet.insert(colorHex);

    ui->AddProductInContainerColor->setStyleSheet(QString("background-color: %1; color: black;").arg(colorHex));

}

void MainWindow::deleteItemFromTreeAndJson(QTreeWidget* tree, const QString& filePath, const QString& nameKey)
{
    QTreeWidgetItem* selectedItem = tree->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "No Selection", "Please select an item to delete.");
        return;
    }

    QString selectedName = selectedItem->text(0);

    if (QMessageBox::question(this, "Confirm Delete", "Are you sure you want to delete \"" + selectedName + "\"?")
        != QMessageBox::Yes) {
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open " + filePath);
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray array;

    if (doc.isObject() && doc.object().contains("products")) {
        array = doc.object()["products"].toArray();
    } else if (doc.isArray()) {
        array = doc.array();
    } else {
        QMessageBox::critical(this, "Error", "Invalid JSON format in " + filePath);
        return;
    }

    QJsonArray updatedArray;
    for (const QJsonValue& val : array) {
        QJsonObject obj = val.toObject();
        if (obj[nameKey].toString() != selectedName) {
            updatedArray.append(obj);
        }
    }

    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QMessageBox::critical(this, "Error", "Failed to write to " + filePath);
        return;
    }

    if (doc.isObject()) {
        QJsonObject updatedObj = doc.object();
        updatedObj["products"] = updatedArray;
        QJsonDocument newDoc(updatedObj);
        file.write(newDoc.toJson(QJsonDocument::Indented));
    } else {
        QJsonDocument newDoc(updatedArray);
        file.write(newDoc.toJson(QJsonDocument::Indented));
    }

    file.close();

    delete selectedItem;

    QMessageBox::information(this, "Deleted", selectedName + " deleted successfully.");
}


void MainWindow::on_DeleteVP_clicked()
{
    deleteItemFromTreeAndJson(ui->VPTreeWidget, "VP_data.json", "vpname");
}


void MainWindow::on_DeleteTruck_clicked()
{
    deleteItemFromTreeAndJson(ui->TruckTreeWidget, "Truck_data.json", "truckname");
}


void MainWindow::on_DeleteContainer_clicked()
{
    deleteItemFromTreeAndJson(ui->ContainerTreeWidget, "Container_data.json", "containername");
}


void MainWindow::on_DeleteWarehouse_clicked()
{
    deleteItemFromTreeAndJson(ui->WarehouseTreeWidget, "Warehouse_data.json", "warehousename");
}


void MainWindow::on_DeleteProduct_clicked()
{
    deleteItemFromTreeAndJson(ui->treeWidget, "products_data.json", "name");

}


void MainWindow::on_SelectVPforLoading_clicked()
{
    QTreeWidgetItem* selectedItem = ui->VPTreeWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "No Selection", "Please select a VP from the list.");
        return;
    }

    float length = selectedItem->text(1).toFloat();
    float width  = selectedItem->text(2).toFloat();
    float height = selectedItem->text(3).toFloat();
    float maxWeight = selectedItem->text(4).toFloat();

    float volume = length * width * height;

    ui->PerConWeight->setText(QString::number(maxWeight, 'f', 2));
    ui->PerConVolume->setText(QString::number(volume, 'f', 2));
    ui->ProWeight->clear();
    ui->ProVolume->clear();

    drawResultContainer3D(length, width, height);

    ui->stackedWidget->setCurrentIndex(0);

    setBoldButton(ui->LoadingButton);
}


void MainWindow::drawResultContainer3D(float length, float width, float height)
{

    if (viewContainer) {
        delete viewContainer;
        viewContainer = nullptr;
    }

    view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(Qt::white));

    QWidget *containerWidget = QWidget::createWindowContainer(view);
    containerWidget->setMinimumSize(QSize(100, 100));
    containerWidget->setMaximumSize(QSize(10000, 10000));
    containerWidget->setFocusPolicy(Qt::StrongFocus);

    QLayout *layout = ui->ResultPlaceholder->layout();
    if (!layout) {
        layout = new QGridLayout(ui->ResultPlaceholder);
        ui->ResultPlaceholder->setLayout(layout);
    } else {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
    }
    layout->addWidget(containerWidget);

    rootEntity = new Qt3DCore::QEntity();

    Qt3DRender::QCamera *camera = view->camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(length * 1.5f, height * 1.5f, width * 2.0f));
    camera->setViewCenter(QVector3D(length / 2, height / 2, width / 2));

    auto *controller = new Qt3DExtras::QOrbitCameraController(rootEntity);
    controller->setCamera(camera);
    controller->setLinearSpeed(20.0f);
    controller->setLookSpeed(100.0f);


    QVector3D corners[8] = {
        {0, 0, 0},
        {length, 0, 0},
        {length, height, 0},
        {0, height, 0},
        {0, 0, width},
        {length, 0, width},
        {length, height, width},
        {0, height, width}
    };

    auto edge = [&](int i, int j) {
        drawEdgeLine(corners[i], corners[j]);
    };

    edge(0, 1); edge(1, 5); edge(5, 4); edge(4, 0);

    edge(3, 2); edge(2, 6); edge(6, 7); edge(7, 3);

    edge(0, 3); edge(1, 2); edge(5, 6); edge(4, 7);

    view->setRootEntity(rootEntity);
    viewContainer = containerWidget;

    containerRotation = new Qt3DCore::QTransform();
    rootEntity->addComponent(containerRotation);

    rotationAnimation = new QPropertyAnimation(containerRotation, QByteArrayLiteral("rotation"));
    rotationAnimation->setDuration(10000);
    rotationAnimation->setStartValue(QQuaternion::fromEulerAngles(0, 0, 0));
    rotationAnimation->setEndValue(QQuaternion::fromEulerAngles(0, 360, 0));
    rotationAnimation->setLoopCount(-1);
    rotationAnimation->start();


}


void MainWindow::drawEdgeLine(const QVector3D &start, const QVector3D &end)
{
    Qt3DCore::QEntity *lineEntity = new Qt3DCore::QEntity(rootEntity);

    QVector3D diff = end - start;
    float len = diff.length();
    QVector3D center = (start + end) / 2.0f;

    auto *mesh = new Qt3DExtras::QCuboidMesh();
    mesh->setXExtent(0.02f);
    mesh->setYExtent(0.02f);
    mesh->setZExtent(len);

    QMatrix4x4 matrix;
    matrix.translate(center);
    matrix.rotate(QQuaternion::rotationTo(QVector3D(0, 0, 1), diff.normalized()));

    auto *transform = new Qt3DCore::QTransform();
    transform->setMatrix(matrix);

    auto *material = new Qt3DExtras::QPhongMaterial();
    material->setDiffuse(Qt::black);

    lineEntity->addComponent(mesh);
    lineEntity->addComponent(transform);
    lineEntity->addComponent(material);
}



void MainWindow::on_SelectProductforLoading_clicked()
{

}


void MainWindow::on_SelectTruckforLoading_clicked()
{
    QTreeWidgetItem* selectedItem = ui->TruckTreeWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "No Selection", "Please select a Truck.");
        return;
    }

    containerLength = selectedItem->text(1).toFloat();
    containerWidth  = selectedItem->text(2).toFloat();
    containerHeight = selectedItem->text(3).toFloat();
    float maxWeight = selectedItem->text(4).toFloat();

    float volume = containerLength * containerWidth * containerHeight;

    ui->PerConWeight->setText(QString::number(maxWeight, 'f', 2));
    ui->PerConVolume->setText(QString::number(volume, 'f', 2));
    ui->ProWeight->clear();
    ui->ProVolume->clear();

    drawResultContainer3D(containerLength, containerWidth, containerHeight);

    ui->stackedWidget->setCurrentIndex(0);
    setBoldButton(ui->LoadingButton);
}




void MainWindow::on_SelectContainerforLoading_clicked()
{
    QTreeWidgetItem* selectedItem = ui->ContainerTreeWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "No Selection", "Please select a Container.");
        return;
    }

    containerLength = selectedItem->text(1).toFloat();
    containerWidth  = selectedItem->text(2).toFloat();
    containerHeight = selectedItem->text(3).toFloat();
    float maxWeight = selectedItem->text(4).toFloat();

    float volume = containerLength * containerWidth * containerHeight;

    ui->PerConWeight->setText(QString::number(maxWeight, 'f', 2));
    ui->PerConVolume->setText(QString::number(volume, 'f', 2));
    ui->ProWeight->clear();
    ui->ProVolume->clear();

    drawResultContainer3D(containerLength, containerWidth, containerHeight);

    ui->stackedWidget->setCurrentIndex(0);
    setBoldButton(ui->LoadingButton);
}




void MainWindow::on_SelectWarehouseforLoading_clicked()
{
    QTreeWidgetItem* selectedItem = ui->WarehouseTreeWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "No Selection", "Please select a Warehouse.");
        return;
    }

    containerLength = selectedItem->text(1).toFloat();
    containerWidth  = selectedItem->text(2).toFloat();
    containerHeight = selectedItem->text(3).toFloat();
    float maxWeight = selectedItem->text(4).toFloat();

    float volume = containerLength * containerWidth * containerHeight;

    ui->PerConWeight->setText(QString::number(maxWeight, 'f', 2));
    ui->PerConVolume->setText(QString::number(volume, 'f', 2));
    ui->ProWeight->clear();
    ui->ProVolume->clear();

    drawResultContainer3D(containerLength, containerWidth, containerHeight);

    ui->stackedWidget->setCurrentIndex(0);
    setBoldButton(ui->LoadingButton);
}


void MainWindow::on_Clear_clicked()
{
    if (!rootEntity) return;

    const auto children = rootEntity->children();
    for (QObject* child : children) {
        delete child;
    }

    ui->PerConWeight->clear();
    ui->PerConVolume->clear();
    ui->ProWeight->clear();
    ui->ProVolume->clear();

    containerLength = 0.0f;
    containerWidth = 0.0f;
    containerHeight = 0.0f;

    productEntityMap.clear();
    productQueue.clear();
}



void MainWindow::on_ShowContainer_clicked()
{

    float length = ui->ConLen1->text().toFloat();
    float width  = ui->ConWidth1->text().toFloat();
    float height = ui->ConHei1->text().toFloat();
    float weight = ui->ConWei1->text().toFloat();

    if (length <= 0 || width <= 0 || height <= 0 || weight <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter positive values for all dimensions.");
        return;
    }

    float volume = length * width * height;
    ui->PerConWeight->setText(QString::number(weight, 'f', 2));
    ui->PerConVolume->setText(QString::number(volume, 'f', 2));
    ui->ProWeight->clear();
    ui->ProVolume->clear();

    drawContainer3DPlaceholder(length, width, height);
}


void MainWindow::drawContainer3DPlaceholder(float length, float width, float height)
{

    if (viewContainer) {
        delete viewContainer;
        viewContainer = nullptr;
    }

    view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(Qt::white));

    QWidget *containerWidget = QWidget::createWindowContainer(view);
    containerWidget->setMinimumSize(QSize(100, 100));
    containerWidget->setMaximumSize(QSize(10000, 10000));
    containerWidget->setFocusPolicy(Qt::StrongFocus);

    QLayout *layout = ui->container3DPlaceholder->layout();
    if (!layout) {
        layout = new QGridLayout(ui->container3DPlaceholder);
        ui->container3DPlaceholder->setLayout(layout);
    } else {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
    }
    layout->addWidget(containerWidget);

    rootEntity = new Qt3DCore::QEntity();

    Qt3DRender::QCamera *camera = view->camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(length * 1.5f, height * 1.5f, width * 2.0f));
    camera->setViewCenter(QVector3D(length / 2, height / 2, width / 2));

    auto *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    camController->setCamera(camera);
    camController->setLinearSpeed(50.0f);
    camController->setLookSpeed(180.0f);

    QVector3D corners[8] = {
        {0, 0, 0},
        {length, 0, 0},
        {length, height, 0},
        {0, height, 0},
        {0, 0, width},
        {length, 0, width},
        {length, height, width},
        {0, height, width}
    };

    auto edge = [&](int i, int j) {
        drawEdgeLine(corners[i], corners[j]);
    };


    edge(0, 1); edge(1, 5); edge(5, 4); edge(4, 0);

    edge(3, 2); edge(2, 6); edge(6, 7); edge(7, 3);

    edge(0, 3); edge(1, 2); edge(5, 6); edge(4, 7);

    view->setRootEntity(rootEntity);
    viewContainer = containerWidget;
}



void MainWindow::on_SelectUserContainer_clicked()
{

    float length = ui->ConLen1->text().toFloat();
    float width  = ui->ConWidth1->text().toFloat();
    float height = ui->ConHei1->text().toFloat();
    float weight = ui->ConWei1->text().toFloat();

    if (length <= 0 || width <= 0 || height <= 0 || weight <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Enter valid container dimensions.");
        return;
    }

    QLayout *layout = ui->container3DPlaceholder->layout();
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                item->widget()->deleteLater();
            }
            delete item;
        }
    }

    float volume = length * width * height;
    ui->PerConWeight->setText(QString::number(weight, 'f', 2));
    ui->PerConVolume->setText(QString::number(volume, 'f', 2));
    ui->ProWeight->clear();
    ui->ProVolume->clear();

    drawResultContainer3D(length, width, height);

    containerLength = length;
    containerWidth = width;
    containerHeight = height;

    ui->ConLen1->clear();
    ui->ConWidth1->clear();
    ui->ConHei1->clear();
    ui->ConWei1->clear();

    ui->stackedWidget->setCurrentIndex(0);
    setBoldButton(ui->LoadingButton);
}
