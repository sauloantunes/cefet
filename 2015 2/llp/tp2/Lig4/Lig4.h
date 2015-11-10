#ifndef LIG4_H
#define LIG4_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

enum {SEM_VENCEDOR, LINHA, DIAGONAL, COLUNA, DIAGONAL_SECUNDARIA};

namespace Ui {
class Lig4;
}

class Lig4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Lig4(QWidget *parent = 0);
    ~Lig4();
    bool restart;

private:
    Ui::Lig4 *ui;
    int tabuleiro[6][7];
    int jogadorDaVez;
    int numLinhas;
    int numColunas;
    int qtdBolasNaColuna[7];
    QLabel* bolas[6][7];
    QList<QPushButton*> botoes;

    int vencedor(QPixmap jogador);
    bool vencedorLinha(QPixmap jogador);
    bool vencedorColuna(QPixmap jogador);
    bool vencedorDiagonal(QPixmap jogador);
    bool vencedorDiagonalSecundaria(QPixmap jogador);
    QPixmap pixmapBlue;
    QPixmap pixmapRed;

private slots:
    void botaoClica(int coluna);

    void on_actionSobre_triggered();
    void on_actionNovo_triggered();
    void on_actionSair_triggered();
};

#endif // LIG4_H
