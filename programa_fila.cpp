#include <iostream>
#include <clocale>
#include <windows.h>
using namespace std;

const int fim = 9;
int matriz[fim];
int inicio = 0;

//move cursor na posicao indicada
void posicaoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// limpa tela e volta o cursor a posição original
void limpa(void) {
    HANDLE TELA;
    DWORD ESCRITA = 0;
    COORD POS;
    TELA = GetStdHandle(STD_OUTPUT_HANDLE);
    POS.X = 0;
    POS.Y = 0;
    FillConsoleOutputCharacter(TELA, 32, 100 * 100, POS, &ESCRITA);
    posicaoXY(0, 0);
}

//limpa o buffer do teclado
void limpabf(void) {
    cin.ignore(100, '\n');
    cout << "\n";
}

//faz a pausa do programa
void pausa(void) {
    cout << "TECLE <ENTER> PARA CONTINUAR. . ." << endl;
    cin.get();
}

bool vazia(void) {
    if(inicio == 0)
        return true;
    else
        return false;
}

bool cheia(void) {
    if(inicio == fim)
        return true;
    else
        return false;
}

bool adicionar(int elemento) {
    if(cheia())
        return false;
    else {
        matriz[inicio] = elemento;
        inicio++;
        return true;
    }
}

bool retirar(int &elemento) {
    int i;
    if (vazia())
        return false;
    else {
        elemento = matriz[0];
        for(i=0; i <= inicio - 1; i++)
            matriz[i] = matriz[i + 1];
        inicio--;
        return true;
    }
    return elemento;
}

void criar(void) {
    int i;
    inicio = 0;
    for(i = 0; i <= fim; i++)
        matriz[i] = 0;
    limpa();
}

void entrada(void) {
    int x;
    cout << "Rotina de entrada de dados" << endl;
    cout << "Entre valor: ";
    cin >> x;
    limpabf();
    if(adicionar(x))
        cout << "Elemento " << x << " foi inserido na posição " << inicio << " da fila" << endl;
    else
        cout << "Impossível inserir o elemento " << x << " -fila lotada" << endl;
    pausa();
    limpa();
}

void saida(void) {
    int x;
    if(retirar(x))
        cout << "O Elemento " << x << " foi retirado do início da fila";
    else
        cout << "Impossível retirar elementos - fila vazia.";
    limpabf();
    pausa();
    limpa();
}

void atual(void) {
    if(vazia())
        cout << "Impossível apresentar - fila vazia.";
    else
        cout << matriz[0] << " primeiro elemento da fila nesse momento";
    limpabf();
    pausa();
    limpa();
}

void exibicao(void) {
    int i;
    cout << "Rotina de exibição" << endl;
    if(vazia())
        cout << "Impossível apresentar - fila vazia.";
    else
        for(i = 0; i <= inicio - 1; i++)
            cout << "Posição " << i +1 << " possui o elemento " << matriz[i] << endl;
    limpabf();
    pausa();
    limpa();
}

void instrucoes(void) {
    limpabf();
    cout << "O programa cria uma fila de numeros inteiros," << endl;
    cout << "o primeiro numero a entrar e o primeiro a sair." << endl;
    cout << "Entre apenas valores numericos inteiros" << endl;
    pausa();
    limpa();
}

void menu(void) {
    cout << ">> PROGRAMA FILA <<" << endl;
    cout << "[1] - Entrada" << endl;
    cout << "[2] - Saída" << endl;
    cout << "[3] - Apresenta o 1° da fila" << endl;
    cout << "[4] - Apresentar a fila" << endl;
    cout << "[5] - Nova Fila" << endl;
    cout << "[6] - Instruções" << endl;
    cout << "[7] - Sair" << endl;
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    criar();
    int opcao;
    do {
        menu( );
        do {
            cin >> opcao;
            if (cin.fail()) {
                cout << "Entre apenas valores numericos...";
                cin.clear( );
                cout << endl;
                opcao = 0;
            }
            if (opcao <= 0 or opcao >= 8) {
                cout << "Entre valores entre 1 e 7..." << endl;
                pausa( );
                limpabf( );
                limpa( );
                menu( );
            }
        } while(opcao <= 0 or opcao >= 8 );
        switch(opcao) {
        case 1 :
            entrada();
            break;
        case 2 :
            saida();
            break;
        case 3 :
            atual();
            break;
        case 4 :
            exibicao();
            break;
        case 5 :
            criar();
            break;
        case 6 :
            instrucoes();
            break;
        }
    } while (opcao != 7);
    return 0;
}
