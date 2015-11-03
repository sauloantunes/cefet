#include "termino.h"
#include "ui_termino.h"

Termino::Termino(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Termino)
{
    ui->setupUi(this);
}

Termino::~Termino()
{
    delete ui;
}

void Termino::on_ok_termino_clicked()
{
    close();
}

void Termino::setMsg(QString msg){
    ui->mensagem->setText(msg);
}
