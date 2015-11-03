#ifndef SOBRE_H
#define SOBRE_H

#include <QDialog>

namespace Ui {
class Sobre;
}

class Sobre : public QDialog
{
    Q_OBJECT

public:
    explicit Sobre(QWidget *parent = 0);
    ~Sobre();

private slots:
    void on_pushButton_clicked();

    void on_sobre_ok_clicked();

private:
    Ui::Sobre *ui;
};

#endif // SOBRE_H
