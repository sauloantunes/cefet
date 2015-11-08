/********************************************************************************
** Form generated from reading UI file 'termino.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TERMINO_H
#define UI_TERMINO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Termino
{
public:
    QLabel *mensagem;
    QPushButton *ok_termino;

    void setupUi(QDialog *Termino)
    {
        if (Termino->objectName().isEmpty())
            Termino->setObjectName(QStringLiteral("Termino"));
        Termino->resize(408, 155);
        mensagem = new QLabel(Termino);
        mensagem->setObjectName(QStringLiteral("mensagem"));
        mensagem->setGeometry(QRect(10, 10, 381, 81));
        mensagem->setLayoutDirection(Qt::LeftToRight);
        mensagem->setAlignment(Qt::AlignCenter);
        ok_termino = new QPushButton(Termino);
        ok_termino->setObjectName(QStringLiteral("ok_termino"));
        ok_termino->setGeometry(QRect(320, 120, 80, 23));

        retranslateUi(Termino);

        QMetaObject::connectSlotsByName(Termino);
    } // setupUi

    void retranslateUi(QDialog *Termino)
    {
        Termino->setWindowTitle(QApplication::translate("Termino", "Dialog", 0));
        mensagem->setText(QApplication::translate("Termino", "Jogador X venceu na ", 0));
        ok_termino->setText(QApplication::translate("Termino", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class Termino: public Ui_Termino {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERMINO_H
