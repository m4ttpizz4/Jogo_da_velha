//bibliotecas:
#include <iostream>
#include <vector>

using namespace std;

const char VAZIO = ' ';
const char JOGADOR_X = 'X';
const char JOGADOR_O = 'O';

class JogoDaVelha {
private:
    vector<vector<char>> tabuleiro;
    char jogadorAtual;

public:
    JogoDaVelha() {
        tabuleiro = vector<vector<char>>(3, vector<char>(3, VAZIO));
        jogadorAtual = JOGADOR_X;
    }

    void exibirTabuleiro() {
        cout << "  0 1 2\n";
        for (int i = 0; i < 3; ++i) {
            cout << i << " ";
            for (int j = 0; j < 3; ++j) {
                cout << tabuleiro[i][j];
                if (j < 2) cout << '|';
            }
            cout << endl;
            if (i < 2) cout << "  -----\n";
        }
    }

    bool realizarJogada(int linha, int coluna) {
        if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == VAZIO) {
            tabuleiro[linha][coluna] = jogadorAtual;
            return true;
        }
        return false;
    }

    bool verificarVitoria() {
        // Checar linhas, colunas e diagonais
        for (int i = 0; i < 3; ++i) {
            if ((tabuleiro[i][0] == jogadorAtual && tabuleiro[i][1] == jogadorAtual && tabuleiro[i][2] == jogadorAtual) ||
                (tabuleiro[0][i] == jogadorAtual && tabuleiro[1][i] == jogadorAtual && tabuleiro[2][i] == jogadorAtual)) {
                return true;
            }
        }
        if ((tabuleiro[0][0] == jogadorAtual && tabuleiro[1][1] == jogadorAtual && tabuleiro[2][2] == jogadorAtual) ||
            (tabuleiro[0][2] == jogadorAtual && tabuleiro[1][1] == jogadorAtual && tabuleiro[2][0] == jogadorAtual)) {
            return true;
        }
        return false;
    }

    void trocarJogador() {
        jogadorAtual = (jogadorAtual == JOGADOR_X) ? JOGADOR_O : JOGADOR_X;
    }

    bool verificarEmpate() {
        for (const auto& linha : tabuleiro) {
            for (const auto& celula : linha) {
                if (celula == VAZIO) {
                    return false;
                }
            }
        }
        return true;
    }

    void jogar() {
        while (true) {
            exibirTabuleiro();
            int linha, coluna;
            cout << "Jogador " << jogadorAtual << ", digite sua jogada (linha e coluna): ";
            cin >> linha >> coluna;

            if (realizarJogada(linha, coluna)) {
                if (verificarVitoria()) {
                    exibirTabuleiro();
                    cout << "Jogador " << jogadorAtual << " venceu!" << endl;
                    break;
                } else if (verificarEmpate()) {
                    exibirTabuleiro();
                    cout << "Empate!" << endl;
                    break;
                }
                trocarJogador();
            } else {
                cout << "Jogada inválida. Tente novamente." << endl;
            }
        }
    }
};

int main() {
    JogoDaVelha jogo;
    jogo.jogar();
    return 0;
}
