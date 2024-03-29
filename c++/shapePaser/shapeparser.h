#ifndef SHAPEPARSER_H
#define SHAPEPARSER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class shapeParser; }
QT_END_NAMESPACE

class shapeParser : public QMainWindow
{
    Q_OBJECT

public:
    shapeParser(QWidget *parent = nullptr);
    ~shapeParser();

private:
    Ui::shapeParser *ui;
};
#endif // SHAPEPARSER_H
