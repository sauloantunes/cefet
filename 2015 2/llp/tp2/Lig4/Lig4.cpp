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
    jogadorDaVez(0)/*,
    bolas  {{ui->bola11, ui->bola12, ui->bola13, ui->bola14, ui->bola15, ui->bola16, ui->bola17},
            {ui->bola21, ui->bola22, ui->bola23, ui->bola24, ui->bola25, ui->bola26, ui->bola27},
            {ui->bola31, ui->bola32, ui->bola33, ui->bola34, ui->bola35, ui->bola36, ui->bola37},
            {ui->bola41, ui->bola42, ui->bola43, ui->bola44, ui->bola45, ui->bola46, ui->bola47},
            {ui->bola51, ui->bola52, ui->bola53, ui->bola54, ui->bola55, ui->bola56, ui->bola57},
            {ui->bola61, ui->bola62, ui->bola63, ui->bola64, ui->bola65, ui->bola66, ui->bola67}}*/
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

void Lig4::botaoClica(int coluna){
    int linha = qtdBolasNaColuna[coluna]++;

    qDebug() << "Linha: " << linha;
    qDebug() << "Coluna: " << coluna;

    // Cor do jogador da vez
    QPixmap pixmapBlue(":/blue");
    QPixmap pixmapRed(":/red");

    QPixmap pixmap = jogadorDaVez ? pixmapBlue : pixmapRed;

    // Alterna a vez
    jogadorDaVez = !jogadorDaVez;

    // Faz Jogada
    bolas[linha][coluna]->setPixmap(pixmap);

    // Verifica se coluna encheu
    if(linha == 5)
        botoes[coluna]->setEnabled(false);

    // Verifica se há vencedor

    // Verifica se há empate


    Termino termino;
    if(bolas[1][1]->pixmap() != NULL){
        if(bolas[1][1]->pixmap()->toImage() == pixmapBlue.toImage())
            termino.setMsg("Azul ganhou!");
        else
            termino.setMsg("Vermelho ganhou!");

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
