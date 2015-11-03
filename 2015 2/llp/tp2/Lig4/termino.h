#ifndef TERMINO_H
#define TERMINO_H

#include <QDialog>
#include <QString>

namespace Ui {
class Termino;
}

class Termino : public QDialog
{
    Q_OBJECT

public:
    explicit Termino(QWidget *parent = 0);
    ~Termino();
    void setMsg(QString);

private slots:
    void on_ok_termino_clicked();

private:
    Ui::Termino *ui;
};

#endif // TERMINO_H
