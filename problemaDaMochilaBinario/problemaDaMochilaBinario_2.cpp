#include <iostream>
#include <vector>

#define SUCCESS 0
#define value 1
#define weigth 0
using namespace std;

int achaPrimeiroDentroDoPeso(int** matriz, vector<float> media, int pesoDisponivel) {
    int tamanho = media.size();
    for(int i = 0; i < tamanho; i++) {
        if(matriz[i][weigth] <= pesoDisponivel && media[i] != 0) {
            return i;
        }
    }
    return -1;
}

int achaMelhorMedia(vector<float> media, int** matriz, int peso, int pesoAtual) {
    float maiorI = achaPrimeiroDentroDoPeso(matriz, media, (peso - pesoAtual));
    
    if(maiorI == -1)
        return maiorI;
        
    float maior = media[maiorI];
    
    for(int i = 1; i < media.size(); i++) {
        if(maior < media[i] && (pesoAtual + matriz[i][weigth]) <= peso) {
            maiorI = i;
            maior = media[i];
        }
    }
    return maiorI;
}

vector<int> achaMelhorSolucao(int** matriz, int numDeItens, int peso) {
    vector<float> valorPorPeso;
    vector<int> index;
    int pesoAtual = 0, maiorI;
    float media;

    for(int i = 0; i < numDeItens; i++) {
        media = (float) matriz[i][value] / matriz[i][weigth];
        valorPorPeso.push_back(media);
    }
    for(int i = pesoAtual; i < peso;) {
        maiorI = achaMelhorMedia(valorPorPeso, matriz, peso, pesoAtual);
        if(maiorI == -1)
            return index;
        index.push_back(maiorI);
        pesoAtual += matriz[maiorI][weigth];
        valorPorPeso[maiorI] = 0;
    }
    return index;
}

float retornaValor(int** matriz, vector<int> index, int peso) {
    float valor = 0, pesoAtual = 0;
    for(int i = 0; i < index.size(); i++) {
        int x = index[i];
        valor += matriz[x][value];
        pesoAtual += matriz[x][weigth];
    }
    if(pesoAtual > peso)
        return 0;
        
    return valor;
}

void verificaValor(int** matriz, vector<int> index, vector<int> melhorSolucao,int  numDeItens, int peso) {
    float valorIndex, melhorValor;
    
    valorIndex = retornaValor(matriz, index, peso);
    melhorValor = retornaValor(matriz, melhorSolucao, peso);
    
    if(valorIndex == melhorValor) {
        printf("Solucao otima.\n");
    }else if(valorIndex == 0) {
        printf("Solucao inviavel.\n");
    }else {
        printf("Solucao viavel mas nao otima.\n");
    } 
}


int main() {
    int peso, numDeItens, entraOuNao;
    vector<int> index, melhorSolucao;
    cin >> peso;
    cin >> numDeItens;
    int **catalago = criaNovaMatriz(numDeItens, numDeItens);
    for(int i = 0; i < numDeItens; i++) {
        cin >> catalago[i][0];
        cin >> catalago[i][1];
    }
    for(int i = 0; i < numDeItens; i++) {
        cin >> entraOuNao;
        if(entraOuNao)
            index.push_back(i);
    }

    melhorSolucao = achaMelhorSolucao(catalago, numDeItens, peso);
    verificaValor(catalago, index, melhorSolucao, numDeItens, peso);

    return SUCCESS;
}