#ifndef EXPLENETION_H 
#define EXPLENETION_H 

#include <QDialog> 

namespace Ui {
	class Explenetion;
}

class Explenetion : public QDialog
{
	Q_OBJECT

public:
	explicit Explenetion(QWidget* parent = 0);
	~Explenetion();

private:
	Ui::Explenetion* ui;
};

#endif // EXPLENETION_H 