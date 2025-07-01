#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Qt3DCore/QEntity>
#include <Qt3DExtras/Qt3DWindow>
#include <QPushButton>
#include <QTreeWidget>

#include <Qt3DCore/QTransform>
#include <QPropertyAnimation>

struct ProductBox {
    QString name;
    float length, width, height, weight;
    int quantity;
    QColor color;
};

namespace Qt3DCore {
class QTransform;
}
class QPropertyAnimation;


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_ProductButton_clicked();
    void on_ContainerButton_clicked();
    void on_LoadingButton_clicked();
    void on_AddInContainer_clicked();

    void handleColorPick1();
    void handleColorPick2();
    void handleColorPick3();
    void handleColorPick4();
    void handleColorPick5();
    void handleColorPick6();
    void handleColorPick7();
    void handleColorPick8();
    void handleColorPick9();
    void handleColorPick10();
    void handleColorPick11();

    void on_Add_clicked();
    void on_DeleteAll_clicked();

    void on_Line1_clicked();
    void on_Line2_clicked();
    void on_Line3_clicked();
    void on_Line4_clicked();
    void on_Line5_clicked();
    void on_Line6_clicked();
    void on_Line7_clicked();
    void on_Line8_clicked();
    void on_Line9_clicked();
    void on_Line10_clicked();

    void on_ShowContainer_clicked();

    void on_SaveProduct_clicked();

    void on_ProductInContainer_clicked();

    void fillStrArrayFromUI();

    void on_SelectVP_clicked();

    void on_SelectTruck_clicked();

    void on_SelectContainer_clicked();

    void on_SelectWarehouse_clicked();

    void on_CancleContainer_clicked();

    void on_CancleWarehouse_clicked();

    void on_CancleVP_clicked();

    void on_CancleTruck_clicked();

    void on_VPSave_clicked();

    void on_TruckSave_clicked();

    void on_ContainerSave_clicked();

    void on_WarehouseSave_clicked();

    void on_Cancle_clicked();

    void setBoldButton(QPushButton *active);

    void on_DeleteVP_clicked();

    void on_DeleteTruck_clicked();

    void on_DeleteContainer_clicked();

    void on_DeleteWarehouse_clicked();

    void on_DeleteProduct_clicked();

    void on_SelectVPforLoading_clicked();

    void on_SelectProductforLoading_clicked();

    void on_SelectTruckforLoading_clicked();

    void on_SelectContainerforLoading_clicked();

    void on_SelectWarehouseforLoading_clicked();

    void on_Clear_clicked();

    void on_SelectUserContainer_clicked();

private:
    Ui::MainWindow *ui;

    Qt3DExtras::Qt3DWindow *view;
    Qt3DCore::QEntity *rootEntity;
    Qt3DCore::QEntity *containerEntity;
    QWidget *viewContainer;

    void drawContainer(float l, float w, float h);

    void setup3DView();

    void createEdgeBox(const QVector3D &start, const QVector3D &end);

    void deleteItemFromTreeAndJson(QTreeWidget* tree, const QString& filePath, const QString& nameKey);

    void drawResultContainer3D(float length, float width, float height);

    void drawEdgeLine(const QVector3D &start, const QVector3D &end);

    float containerLength = 0.0f;
    float containerWidth = 0.0f;
    float containerHeight = 0.0f;

    QList<ProductBox> productQueue;
    QMap<QString, QList<Qt3DCore::QEntity*>> productEntityMap;

    void drawContainer3DPlaceholder(float length, float width, float height);

    Qt3DCore::QTransform *containerRotation = nullptr;
    QPropertyAnimation *rotationAnimation = nullptr;

};

#endif // MAINWINDOW_H
