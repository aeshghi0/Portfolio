#include "shapeparser.h"
#include "ui_shapeparser.h"

shapeParser::shapeParser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::shapeParser)
{
    ui->setupUi(this);
}

shapeParser::~shapeParser()
{
    delete ui;
}

