#ifndef TASK_H 
#define TASK_H 
#include <QString> 
#include "treap.h" 
#include "task.cpp" 
#include "explenetion.h" 
#include <QVector> 
#include <QFile> 

template <class T>
bool addFirstElement(treap<T>*&, QString, QString);

template <class T>
QString addOrDelIntTreapElLine(treap<T>*&, QString, bool);

#endif // TASK_H 