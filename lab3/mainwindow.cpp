#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setupScene();
	facade = std::make_shared<Facade>(Facade());
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::checkCameraExist()
{
	auto camera_count = std::make_shared<size_t>(0);
	CameraCount camera_command(camera_count);
	facade->execute(camera_command);

	if (!*camera_count) {
		std::string message = "No camera found.";
		throw CameraError(message);
	}
}

void MainWindow::canDeleteCamera()
{
	auto model_count = std::make_shared<size_t>(0);
	ModelCount model_command(model_count);
	facade->execute(model_command);

	auto camera_count = std::make_shared<size_t>(0);
	CameraCount camera_command(camera_count);
	facade->execute(camera_command);

	if (*camera_count <= 1 && *model_count) {
		std::string message = "Can not delete the last camera with the loaded models";
		throw CameraError(message);
	}
}

void MainWindow::checkModelsExist()
{
	auto count = std::make_shared<size_t>(0);
	ModelCount model_command(count);
	facade->execute(model_command);

	if (!*count) {
		std::string message = "No models found.";
		throw ModelError(message);
	}
}

void MainWindow::setupScene()
{
	scene = new QGraphicsScene(this);
	ui->graphicsView->setScene(scene);
	ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

	auto rcontent = ui->graphicsView->contentsRect();
	scene->setSceneRect(0, 0, rcontent.width(), rcontent.height());

	std::shared_ptr<AbstractDrawerFactory> factory(new QtDrawerFactory(scene));
	drawer = factory->createGraphics();
}

void MainWindow::updateScene()
{
	DrawScene draw_command(drawer);
	facade->execute(draw_command);
}

void MainWindow::clearScene()
{
	try {
		checkModelsExist();
	} catch (const ModelError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять модели, добавьте хотя бы одну.");
		return;
	}

	for (int i = ui->comboBox->count() - 1; i >= 0; --i) {
		size_t j = (size_t) i;
		RemoveModel remove_command(j);
		facade->execute(remove_command);

		ui->comboBox->removeItem(i);
	}

	updateScene();
}

//загрузка модели
void MainWindow::on_pushButton_clicked()
{
	try {
		checkCameraExist();
	} catch (const CameraError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Прежде чем добавлять модель, добавьте хотя бы одну камеру.");
		return;
	}

	auto t = QFileDialog::getOpenFileName();

	if (t.isNull())
		return;

	LoadModel load_command(t.toUtf8().data());

	try {
		facade->execute(load_command);
	} catch (const SourceError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Что-то пошло не так при загрузке файла...");
		return;
	}

	updateScene();
	ui->comboBox->addItem(QFileInfo(t.toUtf8().data()).fileName());
	ui->comboBox->setCurrentIndex(ui->comboBox->count() - 1);
}


//удаление одной модели
void MainWindow::on_pushButton_2_clicked()
{
	try {
		checkModelsExist();
	} catch (const ModelError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять модель, добавьте хотя бы одну.");
		return;
	}

	size_t i = (size_t) ui->comboBox->currentIndex();
	RemoveModel remove_command(i);
	facade->execute(remove_command);

	ui->comboBox->removeItem(ui->comboBox->currentIndex());

	updateScene();
}


//удаление всех моделей
void MainWindow::on_pushButton_3_clicked()
{
	try {
		checkModelsExist();
	} catch (const ModelError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять модель, добавьте хотя бы одну.");
		return;
	}

	for (int i = 0; i < ui->comboBox->count()+1 ; ++i)
	{
		RemoveModel remove_command(ui->comboBox->currentIndex());
		facade->execute(remove_command);

		ui->comboBox->removeItem(ui->comboBox->currentIndex());
	}

	updateScene();
}


//поворот одной модели
void MainWindow::on_pushButton_9_clicked()
{
	try {
		checkCameraExist();
		checkModelsExist();
	} catch (const CameraError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
		return;
	} catch (const ModelError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
		return;
	}

	RotateModel rotate_command(
			ui->lineEdit->text().toDouble(),
			ui->lineEdit_2->text().toDouble(),
			ui->lineEdit_3->text().toDouble(),
			ui->comboBox->currentIndex());
	facade->execute(rotate_command);
	updateScene();
}


//поворот всех моделей
void MainWindow::on_pushButton_10_clicked()
{
	try {
		checkCameraExist();
		checkModelsExist();
	} catch (const CameraError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
		return;
	} catch (const ModelError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
		return;
	}

	for (int i = 0; i < ui->comboBox->count(); ++i)
	{
		RotateModel rotate_command(
				ui->lineEdit->text().toDouble(),
				ui->lineEdit_2->text().toDouble(),
				ui->lineEdit_3->text().toDouble(),
				i);
		facade->execute(rotate_command);
	}
	updateScene();
}


//масштабирование одной модели
void MainWindow::on_pushButton_11_clicked()
{
	try {
		checkCameraExist();
		checkModelsExist();
	} catch (const CameraError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
		return;
	} catch (const ModelError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
		return;
	}

	ScaleModel scale_command(
			ui->lineEdit_4->text().toDouble(),
			ui->lineEdit_5->text().toDouble(),
			ui->lineEdit_6->text().toDouble(),
			ui->comboBox->currentIndex());
	facade->execute(scale_command);
	updateScene();
}


//масштабирование всех моделей
void MainWindow::on_pushButton_12_clicked()
{
	try {
		checkCameraExist();
		checkModelsExist();
	} catch (const CameraError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
		return;
	} catch (const ModelError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
		return;
	}

	for (int i = 0; i < ui->comboBox->count(); ++i)
	{
		ScaleModel scale_command(
				ui->lineEdit_4->text().toDouble(),
				ui->lineEdit_5->text().toDouble(),
				ui->lineEdit_6->text().toDouble(),
				i);
		facade->execute(scale_command);
	}
	updateScene();
}


//перемещение одной модели
void MainWindow::on_pushButton_13_clicked()
{
	try {
		checkCameraExist();
		checkModelsExist();
	} catch (const CameraError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
		return;
	} catch (const ModelError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
		return;
	}

	MoveModel move_command(
			ui->lineEdit_7->text().toDouble(),
			ui->lineEdit_8->text().toDouble(),
			ui->lineEdit_9->text().toDouble(),
			ui->comboBox->currentIndex());
	facade->execute(move_command);
	updateScene();
}


//перемещение всех моделей
void MainWindow::on_pushButton_14_clicked()
{
	try {
		checkCameraExist();
		checkModelsExist();
	} catch (const CameraError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
		return;
	} catch (const ModelError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
		return;
	}

	for (int i = 0; i < ui->comboBox->count(); ++i)
	{
		MoveModel move_command(
				ui->lineEdit_7->text().toDouble(),
				ui->lineEdit_8->text().toDouble(),
				ui->lineEdit_9->text().toDouble(),
				i);
		facade->execute(move_command);
	}
	updateScene();
}


//добавить камеру
void MainWindow::on_pushButton_4_clicked()
{
	auto rcontent = ui->graphicsView->contentsRect();
	AddCamera camera_command(rcontent.width() / 2.0, rcontent.height() / 2.0, 0.0);
	facade->execute(camera_command);

	updateScene();

	auto cam = ui->comboBox_2;
	if (0 == cam->count())
		cam->addItem(QString::number(1));
	else
		cam->addItem(QString::number(
				cam->itemText(cam->count() - 1).toInt() + 1));

	ui->comboBox_2->setCurrentIndex(ui->comboBox_2->count() - 1);
}


//удалить камеру
void MainWindow::on_pushButton_15_clicked()
{
	try {
		checkCameraExist();
	} catch (const CameraError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять камеру, добавьте хотя бы одну.");
		return;
	}

	try {
		canDeleteCamera();
	} catch (const CameraError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять камеру, необходимо удалить оставшиеся модели.");
		return;
	}

	RemoveCamera remove_command(ui->comboBox_2->currentIndex());
	facade->execute(remove_command);

	ui->comboBox_2->removeItem(ui->comboBox_2->currentIndex());

	try {
		checkCameraExist();
	} catch (const CameraError &error) {
		return;
	}

	updateScene();
}


void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
	try {
		checkCameraExist();
	} catch (const CameraError &error) {
		return;
	}

	SetCamera camera_command(ui->comboBox_2->currentIndex());
	facade->execute(camera_command);
	updateScene();
}


void MainWindow::on_pushButton_5_clicked()
{
	try {
		checkCameraExist();
		checkModelsExist();
	} catch (const CameraError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
		return;
	} catch (const ModelError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
		return;
	}

	MoveCamera camera_command(ui->comboBox_2->currentIndex(), 0, -10);
	facade->execute(camera_command);
	updateScene();
}


void MainWindow::on_pushButton_6_clicked()
{
	try {
		checkCameraExist();
		checkModelsExist();
	} catch (const CameraError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
		return;
	} catch (const ModelError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
		return;
	}

	MoveCamera camera_command(ui->comboBox_2->currentIndex(), 0, 10);
	facade->execute(camera_command);
	updateScene();
}


void MainWindow::on_pushButton_7_clicked()
{
	try {
		checkCameraExist();
		checkModelsExist();
	} catch (const CameraError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
		return;
	} catch (const ModelError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
		return;
	}

	MoveCamera camera_command(ui->comboBox_2->currentIndex(), 10, 0);
	facade->execute(camera_command);
	updateScene();
}

void MainWindow::on_pushButton_8_clicked()
{
	try {
		checkCameraExist();
		checkModelsExist();
	} catch (const CameraError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
		return;
	} catch (const ModelError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
		return;
	}

	MoveCamera camera_command(ui->comboBox_2->currentIndex(), -10, 0);
	facade->execute(camera_command);
	updateScene();
}


void MainWindow::on_pushButton_16_clicked()
{
	try {
		checkCameraExist();
		checkModelsExist();
	} catch (const CameraError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
		return;
	} catch (const ModelError &error) {
		QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
		return;
	}

	RotateCamera camera_command(ui->comboBox_2->currentIndex(), 10);
	facade->execute(camera_command);
	updateScene();
}

