// Defini��es das fun��es da biblioteca rede
#include <iostream>
#include "pacote.h"
#include "cores.h"
using namespace std;

unsigned int rede;

void transmitir(unsigned int passo, unsigned int cor, unsigned int posicao, unsigned int velocidade, unsigned int pista)
{
	rede = empacotar(passo, cor, posicao, velocidade, pista); // atribui o valor empacotado � vari�vel global rede

	// Exibe mensagem com o n�mero empacotado
	cout << "Transmitindo dados...\n";
	ajustar_cor(BRANCO, cor);
	cout << rede << endl;

	resetar_cor();
}

unsigned int receber()
{
	// Exibe dados (passo, posi��o, velocidade e estado da pista)
	cout << "Recebendo dados...\n";

	// Exibe o passo
	ajustar_cor(cor(rede), PRETO);
	cout << "Frame ";
	ajustar_cor(BRANCO, cor(rede));
	cout << " " << passo(rede) << " ";

	// Exibe a posi��o
	ajustar_cor(cor(rede), PRETO);
	cout.width(6); cout << "Pos ";
	ajustar_cor(BRANCO, cor(rede));
	cout << " " << posicao(rede) << " ";

	// Exibe a velocidade
	ajustar_cor(cor(rede), PRETO);
	cout.width(6); cout << "Vel ";
	ajustar_cor(BRANCO, cor(rede));
	cout << " " << velocidade(rede) << " ";
	
	// Exibe o estado da pista
	ajustar_cor(cor(rede), PRETO);
	cout.width(6); cout << "Oil ";
	ajustar_cor(BRANCO, cor(rede));
	if (pista(rede))
		cout << " true \n";
	else
		cout << " false \n";


	resetar_cor();

	return rede; // retorna o valor da var�avel global rede
}

unsigned int processar(unsigned int numero_rede)
{
	unsigned int nova_posicao;

	// calcula e retorna o valor da pr�xima posi��o do caminh�o
	nova_posicao = posicao(numero_rede) + velocidade(numero_rede) - pista(numero_rede);

	return nova_posicao;
}