#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QFileDialog>

#include "BaseCommand.h"
#include "cameracommand.h"
#include "modelcommand.h"
#include "scenecommand.h"
#include "abstractdrawer.h"
#include "myerror.h"
#include "facade.h"
#include "abstractdrawerfactory.h"
#include "qtdrawerfactory.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

protected:
	void setupScene();
	void updateScene();
	void clearScene();
	void checkCameraExist();
	void canDeleteCamera();
	void checkModelsExist();

private slots:
	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_9_clicked();

	void on_pushButton_10_clicked();

	void on_pushButton_11_clicked();

	void on_pushButton_12_clicked();

	void on_pushButton_13_clicked();

	void on_pushButton_14_clicked();

	void on_pushButton_4_clicked();

	void on_pushButton_15_clicked();

	void on_comboBox_2_currentIndexChanged(int index);

	void on_pushButton_5_clicked();

	void on_pushButton_6_clicked();

	void on_pushButton_7_clicked();

	void on_pushButton_8_clicked();

	void on_pushButton_16_clicked();

private:
	Ui::MainWindow *ui;
	QGraphicsScene *scene;
	std::shared_ptr<Facade> facade;
	std::shared_ptr<AbstractDrawer> drawer;
};
#endif // MAINWINDOW_H
