#include "BotaoJogar.h"

BotaoJogar::BotaoJogar(QWidget* parent) : QPushButton(parent) {
    this->setStyleSheet("QPushButton { " \
                        "    border: none; " \
                        "    outline: none; " \
                        "    image: url(':/arrow'); " \
                        "}" \
                        "QPushButton:disabled { " \
                        "    image: url(':/disabled');" \
                        "}" \
                        "QPushButton:hover { "\
                        "    image: url(':/hover'); " \
                        "}");

    QSize defaultSize(48, 48);
    this->setMinimumSize(defaultSize);
    this->setMaximumSize(defaultSize);
    this->setIconSize(defaultSize);
    this->setFlat(true);
}

BotaoJogar::~BotaoJogar() {
}

