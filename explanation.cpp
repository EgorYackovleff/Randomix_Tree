#include "explenetion.h"
#include "ui_explenetion.h"

Explenetion::Explenetion(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::Explenetion)

{
	ui->setupUi(this);
}

Explenetion::~Explenetion()

{
	delete ui;
}