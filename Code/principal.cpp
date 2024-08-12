#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cores.h"
#include "pacote.h"
#include "rede.h"
using namespace std;

void desenhar(int, int);
void espacos(int);

int main()
{
	
	srand(unsigned(time(NULL))); // semente usada para gerar vaores pseudoaleat�rios


	// - Inicializa posi��es
	unsigned int posicao_1 = 0;
	unsigned int posicao_2 = 0;

	// - Declara vari�veis de velociade (a atribui��o de valor ocorrer� depois, mas ainda antes das vari�veis serem utilizadas)
	unsigned int velocidade_1;
	unsigned int velocidade_2;
	
	// - Inicializa cores
	unsigned int cor_1 = LILAS;
	unsigned int cor_2 = VERDE_AGUA;

	// - Declara vari�veis de estado da pista (a atribui��o de valor ocorrer� depois, mas ainda antes das vari�veis serem utilizadas)
	unsigned int pista_1;
	unsigned int pista_2;

	// Inicializa vari�vel que representa os passos
	int passos = 0;

	do
	{
		system("cls"); // Limpa tela
		
		// Cria uma barra de duas cores com o "t�tulo" do jogo
		ajustar_cor(BRANCO, LILAS);
		cout.width(60); cout << "NEED FOR SPEED ";
		ajustar_cor(BRANCO, VERDE_AGUA);
		cout << left; cout.width(60); cout << " DELUXE VERSION";
		cout << right;

		resetar_cor(); 

		// Desenha caminh�es 
		desenhar(posicao_1, cor_1);
		desenhar(posicao_2, cor_2);
		
		resetar_cor();
		cout << endl << endl;


		// Atualiza velocidade com valores pseudoaleat�rios
		velocidade_1 = (rand() % 10) + 1; // "rand() % 10" gera valores na faixa de 0 a 9. com "+ 1", a vari�vel recebe valores na faixa de 1 a 10
		velocidade_2 = (rand() % 10) + 1; // "rand() % 10" gera valores na faixa de 0 a 9. com "+ 1", a vari�vel recebe valores na faixa de 1 a 10

		// Atualiza estado da pista com valores pseudoaleat�rios
		pista_1 = rand() % 2; // a vari�vel recebe 0 ou 1
		pista_2 = rand() % 2; // a vari�vel recebe 0 ou 1
		

		// Transmite, recebe e processa dados do caminh�o 1
		transmitir(passos, cor_1, posicao_1, velocidade_1, pista_1);
		posicao_1 = processar(receber()); // A vari�vel de posi��o recebe o novo valor calculado e retornado pela fun��o processar(). A fun��o receber() exibe os daodos

		// Exibe a pr�xima posi��o do caminh�o 1
		cout << "Processando dados...\n";
		ajustar_cor(cor_1, PRETO);
		cout << "Pr�xima posi��o: " << posicao_1 << endl << endl;
		resetar_cor();


		// Transmite, recebe e processa dados do caminh�o 2
		transmitir(passos, cor_2, posicao_2, velocidade_2, pista_2);
		posicao_2 = processar(receber()); // A vari�vel de posi��o recebe o novo valor calculado e retornado pela fun��o processar(). A fun��o receber() exibe os daodos

		// Exibe a pr�xima posi��o do caminh�o 2
		cout << "Processando dados...\n";
		ajustar_cor(cor_2, PRETO);
		cout << "Pr�xima posi��o: " << posicao_2 << endl << endl;
		resetar_cor();
		

		// Exibe uma barra de duas cores com a mensagem de pressionar ENTER para o pr�ximo passo
		ajustar_cor(BRANCO, VERDE_AGUA);
		cout.width(60); cout << " ";
		ajustar_cor(BRANCO, LILAS);
		cout.width(60); cout << "[ENTER] Executar Passo >";
		
		
		system("pause > nul"); // Aguarda pressionamento de tecla, sem exibir mensagem no terminal
		
		resetar_cor();

		passos = passos + 1; // Incrementa mais uma unidade aos passos

	} while (posicao_1 <= 100 && posicao_2 <= 100);
	
	system("cls");// Limpa tela

	// Cria uma barra de duas cores com o "t�tulo" do jogo
	ajustar_cor(BRANCO, LILAS);
	cout.width(60); cout << "NEED FOR SPEED ";
	ajustar_cor(BRANCO, VERDE_AGUA);
	cout << left; cout.width(60); cout << " DELUXE VERSION";
	cout << right;

	resetar_cor();

	// Desenha caminh�es 
	desenhar(posicao_1, cor_1);
	desenhar(posicao_2, cor_2);

	// Exibe faixa com mensagem de corrida conclu�da
	cout << endl;
	ajustar_cor(AZUL, BRANCO);
	cout.width(60); cout << ">>> CORRIDA ";
	cout << left; cout.width(60); cout << " CONCLU�DA <<<";
	cout << right;
	cout << endl << endl;

	resetar_cor();


	// Calcula as velocidades m�dias de cada caminh�o
	float vel_media_1 = float(posicao_1) / float(passos);
	float vel_media_2 = float(posicao_2) / float(passos);

	// Exibi��o dos resultados abaixo

	// Exibe os passos totais
	ajustar_cor(BRANCO, AZUL);
	cout << left; cout.width(9); cout << " Passos ";
	cout << right;
	resetar_cor();
	cout.width(4); cout << passos << endl << endl;

	// Exibe a posi��o final do caminh�o 1
	ajustar_cor(BRANCO, cor_1);
	cout << " Posi��o ";
	ajustar_cor(cor_1, PRETO);
	cout.width(4); cout << posicao_1 << " ";

	// Exibe a velocidade m�dia do caminh�o 1
	ajustar_cor(BRANCO, cor_1);
	cout << " Velocidade m�dia ";
	ajustar_cor(cor_1, PRETO);
	cout.width(6); cout << fixed; cout.precision(2); cout << vel_media_1 << endl << endl;

	// Exibe a posi��o final do caminh�o 2
	ajustar_cor(BRANCO, cor_2);
	cout << " Posi��o ";
	ajustar_cor(cor_2, PRETO);
	cout.width(4); cout << posicao_2 << " ";

	// Exibe a velocidade m�dia do caminh�o 2
	ajustar_cor(BRANCO, cor_2);
	cout << " Velocidade m�dia ";
	ajustar_cor(cor_2, PRETO);
	cout.width(6); cout << fixed; cout.precision(2); cout << vel_media_2 << endl;

	resetar_cor();

	return 0;
}

void desenhar(int posicao, int cor) // Desenha os caminh�es e a pista
{
	ajustar_cor(cor, PRETO);
	cout << "\n\n";

	// Caminh�o
	espacos(posicao);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB \xDB\xDC\xDC\n";
	espacos(posicao);
	cout << "\xDFOO\xDF\xDF\xDF\xDF\xDFO\xDF\n";

	// Pista
	cout << "----------------------------------------------------------------------------------------------------|-------------------" << endl;
	cout.width(102);
	cout << "100";
	cout << endl;

	resetar_cor();
}

void espacos(int qtd) { while (qtd-- > 0) cout << ' '; } // Fun��o que acrescenta espa�os e faz os caminh�es "andarem"
