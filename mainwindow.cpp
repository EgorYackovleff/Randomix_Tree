#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "treap.h"
#include "task.h"


MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->lineEdit->setEnabled(false);
	ui->lineEdit_2->setEnabled(false);
}

MainWindow::~MainWindow()
{
	delete ui;
}
treap<int>* newTreapElement = new treap<int>;

void MainWindow::on_pushButton_4_clicked()
{
	QString resultPlainTextTwo = "";
	QString resultPlainText = "";
	QString dataString = ui->lineEdit->text();
	if (ui->lineEdit_3->isEnabled()) {
		ui->plainTextEdit_2->clear();
		if (addFirstElement(newTreapElement, ui->lineEdit_3->text(), ui->lineEdit_4->text())) {
			ui->lineEdit_3->setEnabled(false);
			ui->lineEdit_4->setEnabled(false);
			ui->lineEdit->setEnabled(true);
			ui->lineEdit_2->setEnabled(true);
		}
		else {
			ui->plainTextEdit_2->insertPlainText("Incorrect Data, Bro");
		}
	}
	else {
		resultPlainTextTwo = addOrDelIntTreapElLine(newTreapElement, dataString, true);
		QPrintTreap(newTreapElement, 0, true, resultPlainText);
		ui->plainTextEdit->clear();
		ui->plainTextEdit->insertPlainText(resultPlainText);
		ui->plainTextEdit_2->clear();
		ui->plainTextEdit_2->insertPlainText(resultPlainTextTwo);
	}
}

void MainWindow::on_pushButton_16_clicked()
{
	if (ui->lineEdit->isEnabled())
		ui->lineEdit->insert("(A,B)");
}

void MainWindow::on_pushButton_17_clicked()
{
	ui->lineEdit->clear();
}

void MainWindow::on_pushButton_clicked()
{
	if (ui->lineEdit->isEnabled())
		ui->lineEdit->insert("1");
}

void MainWindow::on_pushButton_2_clicked()
{
	if (ui->lineEdit->isEnabled())
		ui->lineEdit->insert("2");
}

void MainWindow::on_pushButton_3_clicked()
{
	if (ui->lineEdit->isEnabled())
		ui->lineEdit->insert("3");
}

void MainWindow::on_pushButton_5_clicked()
{
	if (ui->lineEdit->isEnabled())
		ui->lineEdit->insert("4");
}

void MainWindow::on_pushButton_7_clicked()
{
	if (ui->lineEdit->isEnabled())
		ui->lineEdit->insert("5");
}

void MainWindow::on_pushButton_8_clicked()
{
	if (ui->lineEdit->isEnabled())
		ui->lineEdit->insert("6");
}

void MainWindow::on_pushButton_9_clicked()
{
	if (ui->lineEdit->isEnabled())
		ui->lineEdit->insert("7");
}

void MainWindow::on_pushButton_10_clicked()
{
	ui->lineEdit->insert("8");
}

void MainWindow::on_pushButton_11_clicked()
{
	if (ui->lineEdit->isEnabled())
		ui->lineEdit->insert("9");
}

void MainWindow::on_pushButton_12_clicked()
{
	if (ui->lineEdit->isEnabled())
		ui->lineEdit->insert("0");
}

void MainWindow::on_pushButton_13_clicked()
{
	if (ui->lineEdit->isEnabled())
		ui->lineEdit->insert("(");
}

void MainWindow::on_pushButton_14_clicked()
{
	if (ui->lineEdit->isEnabled())
		ui->lineEdit->insert(",");
}

void MainWindow::on_pushButton_15_clicked()
{
	if (ui->lineEdit->isEnabled())
		ui->lineEdit->insert(")");
}

void MainWindow::on_pushButton_18_clicked()
{
	if (ui->lineEdit_3->isEnabled()) {
		ui->plainTextEdit->clear();
		ui->plainTextEdit_2->clear();
		ui->plainTextEdit_2->insertPlainText("Tree is empty/");
	}
	else {
		QString resultPlainTextTwo;
		QString resultPlainText;
		QString dataString;
		dataString = ui->lineEdit->text();
		resultPlainTextTwo = addOrDelIntTreapElLine(newTreapElement, dataString, false);
		QPrintTreap(newTreapElement, 0, true, resultPlainText);
		ui->plainTextEdit->clear();
		ui->plainTextEdit->insertPlainText(resultPlainText);
		ui->plainTextEdit_2->clear();
		ui->plainTextEdit_2->insertPlainText(resultPlainTextTwo);
	}
}

void MainWindow::on_pushButton_6_clicked()
{
	QFile read(ui->lineEdit_2->text());
	if (read.open(QIODevice::ReadOnly | QIODevice::Text))
		ui->lineEdit->setText(read.readLine());
	else ui->lineEdit_2->setText("incorrect dir");
}

void MainWindow::on_pushButton_19_clicked()
{
	Explenetion lol;
	lol.exec();
}