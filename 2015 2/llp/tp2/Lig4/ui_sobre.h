/********************************************************************************
** Form generated from reading UI file 'sobre.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOBRE_H
#define UI_SOBRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Sobre
{
public:
    QPushButton *sobre_ok;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Sobre)
    {
        if (Sobre->objectName().isEmpty())
            Sobre->setObjectName(QStringLiteral("Sobre"));
        Sobre->resize(396, 155);
        sobre_ok = new QPushButton(Sobre);
        sobre_ok->setObjectName(QStringLiteral("sobre_ok"));
        sobre_ok->setGeometry(QRect(300, 20, 80, 23));
        label = new QLabel(Sobre);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 40, 231, 91));
        label_2 = new QLabel(Sobre);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 20, 59, 15));
        label_2->setLineWidth(1);
        label_2->setTextFormat(Qt::PlainText);

        retranslateUi(Sobre);

        QMetaObject::connectSlotsByName(Sobre);
    } // setupUi

    void retranslateUi(QDialog *Sobre)
    {
        Sobre->setWindowTitle(QApplication::translate("Sobre", "Dialog", 0));
        sobre_ok->setText(QApplication::translate("Sobre", "OK", 0));
        label->setText(QApplication::translate("Sobre", "Saulo Antunes Silva\n"
"      sauloantuness@gmail.com\n"
"\n"
"Thayana Pessoa Duarte\n"
"      thayanepessoaduarte@gmail.com", 0));
        label_2->setText(QApplication::translate("Sobre", "TP2 - LP", 0));
    } // retranslateUi

};

namespace Ui {
    class Sobre: public Ui_Sobre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOBRE_H
