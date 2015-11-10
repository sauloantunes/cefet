#include "Lig4.h"
#include "ui_Lig4.h"

#include <string>
#include <QDebug>
#include <QSignalMapper>

#include "sobre.h"
#include "termino.h"

Lig4::Lig4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Lig4),
    restart(false),
    jogadorDaVez(0),
    numLinhas(6),
    numColunas(7),
    pixmapBlue(":/blue"),
    pixmapRed(":/red")
{
    ui->setupUi(this);

    // Criar o mapeador de sinais
    QSignalMapper* mapper = new QSignalMapper(this);

    botoes << ui->botao1 << ui->botao2 << ui->botao3 << ui->botao4 << ui->botao5 << ui->botao6 << ui->botao7;

    int c = 0;
    foreach (QPushButton* botao, botoes) {
        // Criar o mapeamento botao coluna e conectar o botao no mapa
        mapper->setMapping(botao, c++); // botao1 na coluna 1
        QObject::connect(botao, SIGNAL(clicked()), mapper, SLOT(map()));
    }

    // Conectar o mapeamento no seu slot que deve receber um número inteiro
    // Por exemplo, o slot: void jogar(int coluna);
    QObject::connect(mapper, SIGNAL(mapped(int)), this, SLOT(botaoClica(int)));

    QLabel* balls[6][7]  = {{ui->bola11, ui->bola12, ui->bola13, ui->bola14, ui->bola15, ui->bola16, ui->bola17},
                            {ui->bola21, ui->bola22, ui->bola23, ui->bola24, ui->bola25, ui->bola26, ui->bola27},
                            {ui->bola31, ui->bola32, ui->bola33, ui->bola34, ui->bola35, ui->bola36, ui->bola37},
                            {ui->bola41, ui->bola42, ui->bola43, ui->bola44, ui->bola45, ui->bola46, ui->bola47},
                            {ui->bola51, ui->bola52, ui->bola53, ui->bola54, ui->bola55, ui->bola56, ui->bola57},
                            {ui->bola61, ui->bola62, ui->bola63, ui->bola64, ui->bola65, ui->bola66, ui->bola67}};

    memcpy(bolas, balls, sizeof balls);
    memset(qtdBolasNaColuna, 0, sizeof qtdBolasNaColuna);
}

Lig4::~Lig4()
{
    delete ui;
}

// Verifica se jogador venceu na linha
bool Lig4::vencedorLinha(QPixmap jogador){
    for (int l = 0; l < numLinhas; ++l) {
        for (int c = 0; c < numColunas - 3; ++c) {
            for (int k = 0; k < 4; ++k) {
                if(bolas[l][c+k]->pixmap() == NULL)
                    break;
                if(bolas[l][c+k]->pixmap()->toImage() != jogador.toImage())
                    break;
                if(k == 3)
                    return true;
            }
        }
    }

    return false;
}

// Verifica se jogador venceu na coluna
bool Lig4::vencedorColuna(QPixmap jogador){
    for (int l = 0; l < numLinhas - 3; ++l) {
        for (int c = 0; c < numColunas; ++c) {
            for (int k = 0; k < 4; ++k) {
                if(bolas[l+k][c]->pixmap() == NULL)
                    break;
                if(bolas[l+k][c]->pixmap()->toImage() != jogador.toImage())
                    break;
                if(k == 3)
                    return true;
            }
        }
    }

    return false;
}

// Verifica diagonal principal
bool Lig4::vencedorDiagonal(QPixmap jogador){
    for (int l = 0; l < numLinhas - 3; ++l) {
        for (int c = 0; c < numColunas - 3; ++c) {
            for (int k = 0; k < 4; ++k) {
                if(bolas[l+k][c+k]->pixmap() == NULL)
                    break;
                if(bolas[l+k][c+k]->pixmap()->toImage() != jogador.toImage())
                    break;
                if(k == 3)
                    return true;
            }
        }
    }

    return false;
}

// Verifica diagonal secundária
bool Lig4::vencedorDiagonalSecundaria(QPixmap jogador){
    for (int l = numLinhas-1; l > 2; l--) {
        for (int c = 0; c < numColunas - 3; ++c) {
            for (int k = 0; k < 4; ++k) {
                if(bolas[l-k][c+k]->pixmap() == NULL)
                    break;
                if(bolas[l-k][c+k]->pixmap()->toImage() != jogador.toImage())
                    break;
                if(k == 3)
                    return true;
            }
        }
    }

    return false;
}

// Verifica se jogador venceu
int Lig4::vencedor(QPixmap jogador){
    if(vencedorLinha(jogador))
        return LINHA;
    if(vencedorColuna(jogador))
        return COLUNA;
    if(vencedorDiagonal(jogador))
        return DIAGONAL;
    if(vencedorDiagonalSecundaria(jogador))
        return DIAGONAL_SECUNDARIA;
    return SEM_VENCEDOR;
}

void Lig4::botaoClica(int coluna){
    int linha = qtdBolasNaColuna[coluna]++;

    // Cor do jogador da vez
    QPixmap pixmap= jogadorDaVez ? pixmapBlue : pixmapRed;

    // Faz Jogada
    bolas[linha][coluna]->setPixmap(pixmap);

    // Alterna a vez
    jogadorDaVez = !jogadorDaVez;

    // Verifica se bolas na coluna atingiu limite
    if(linha == numLinhas - 1)
        botoes[coluna]->setEnabled(false);

    // Verifica se jogador da vez venceu o jogo
    int teveVencedor = vencedor(pixmap);
    QString msg = jogadorDaVez ? "Jogador Vermelho venceu na " : "Jogador Azul venceu na ";
    switch(teveVencedor){
        case LINHA: msg += "Linha"; break;
        case COLUNA: msg += "Coluna"; break;
        case DIAGONAL: msg += "Diagonal"; break;
        case DIAGONAL_SECUNDARIA: msg += "Diagonal Secundaria"; break;
    }

    // Verifica fim de jogo
    bool fimDeJogo = false;
    for (int i = 0; i < numColunas; ++i) {
        if(qtdBolasNaColuna[i] < numLinhas)
            break;
        if(i+1 == numColunas){
            msg = "O Jogo Empatou";
            fimDeJogo = true;
        }
    }

    // Desativa botões se houver vencedor
    if(teveVencedor){
        for (int i = 0; i < numColunas; ++i)
            botoes[i]->setEnabled(false);
    }

    // Exibe mensagem de fim de jogo
    if(teveVencedor || fimDeJogo){
        Termino termino;
        termino.setMsg(msg);
        termino.setModal(true);
        termino.exec();
    }
}


void Lig4::on_actionSobre_triggered()
{
    qDebug() << "Sobre";
    Sobre sobre;
    sobre.setModal(true);
    sobre.exec();
}

void Lig4::on_actionNovo_triggered()
{
    restart = true;
    close();
}

void Lig4::on_actionSair_triggered()
{
    close();
}
