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
	
	srand(unsigned(time(NULL))); // semente usada para gerar vaores pseudoaleatórios


	// - Inicializa posições
	unsigned int posicao_1 = 0;
	unsigned int posicao_2 = 0;

	// - Declara variáveis de velociade (a atribuição de valor ocorrerá depois, mas ainda antes das variáveis serem utilizadas)
	unsigned int velocidade_1;
	unsigned int velocidade_2;
	
	// - Inicializa cores
	unsigned int cor_1 = LILAS;
	unsigned int cor_2 = VERDE_AGUA;

	// - Declara variáveis de estado da pista (a atribuição de valor ocorrerá depois, mas ainda antes das variáveis serem utilizadas)
	unsigned int pista_1;
	unsigned int pista_2;

	// Inicializa variável que representa os passos
	int passos = 0;

	do
	{
		system("cls"); // Limpa tela
		
		// Cria uma barra de duas cores com o "título" do jogo
		ajustar_cor(BRANCO, LILAS);
		cout.width(60); cout << "NEED FOR SPEED ";
		ajustar_cor(BRANCO, VERDE_AGUA);
		cout << left; cout.width(60); cout << " DELUXE VERSION";
		cout << right;

		resetar_cor(); 

		// Desenha caminhões 
		desenhar(posicao_1, cor_1);
		desenhar(posicao_2, cor_2);
		
		resetar_cor();
		cout << endl << endl;


		// Atualiza velocidade com valores pseudoaleatórios
		velocidade_1 = (rand() % 10) + 1; // "rand() % 10" gera valores na faixa de 0 a 9. com "+ 1", a variável recebe valores na faixa de 1 a 10
		velocidade_2 = (rand() % 10) + 1; // "rand() % 10" gera valores na faixa de 0 a 9. com "+ 1", a variável recebe valores na faixa de 1 a 10

		// Atualiza estado da pista com valores pseudoaleatórios
		pista_1 = rand() % 2; // a variável recebe 0 ou 1
		pista_2 = rand() % 2; // a variável recebe 0 ou 1
		

		// Transmite, recebe e processa dados do caminhão 1
		transmitir(passos, cor_1, posicao_1, velocidade_1, pista_1);
		posicao_1 = processar(receber()); // A variável de posição recebe o novo valor calculado e retornado pela função processar(). A função receber() exibe os daodos

		// Exibe a próxima posição do caminhão 1
		cout << "Processando dados...\n";
		ajustar_cor(cor_1, PRETO);
		cout << "Próxima posição: " << posicao_1 << endl << endl;
		resetar_cor();


		// Transmite, recebe e processa dados do caminhão 2
		transmitir(passos, cor_2, posicao_2, velocidade_2, pista_2);
		posicao_2 = processar(receber()); // A variável de posição recebe o novo valor calculado e retornado pela função processar(). A função receber() exibe os daodos

		// Exibe a próxima posição do caminhão 2
		cout << "Processando dados...\n";
		ajustar_cor(cor_2, PRETO);
		cout << "Próxima posição: " << posicao_2 << endl << endl;
		resetar_cor();
		

		// Exibe uma barra de duas cores com a mensagem de pressionar ENTER para o próximo passo
		ajustar_cor(BRANCO, VERDE_AGUA);
		cout.width(60); cout << " ";
		ajustar_cor(BRANCO, LILAS);
		cout.width(60); cout << "[ENTER] Executar Passo >";
		
		
		system("pause > nul"); // Aguarda pressionamento de tecla, sem exibir mensagem no terminal
		
		resetar_cor();

		passos = passos + 1; // Incrementa mais uma unidade aos passos

	} while (posicao_1 <= 100 && posicao_2 <= 100);
	
	system("cls");// Limpa tela

	// Cria uma barra de duas cores com o "título" do jogo
	ajustar_cor(BRANCO, LILAS);
	cout.width(60); cout << "NEED FOR SPEED ";
	ajustar_cor(BRANCO, VERDE_AGUA);
	cout << left; cout.width(60); cout << " DELUXE VERSION";
	cout << right;

	resetar_cor();

	// Desenha caminhões 
	desenhar(posicao_1, cor_1);
	desenhar(posicao_2, cor_2);

	// Exibe faixa com mensagem de corrida concluída
	cout << endl;
	ajustar_cor(AZUL, BRANCO);
	cout.width(60); cout << ">>> CORRIDA ";
	cout << left; cout.width(60); cout << " CONCLUÍDA <<<";
	cout << right;
	cout << endl << endl;

	resetar_cor();


	// Calcula as velocidades médias de cada caminhão
	float vel_media_1 = float(posicao_1) / float(passos);
	float vel_media_2 = float(posicao_2) / float(passos);

	// Exibição dos resultados abaixo

	// Exibe os passos totais
	ajustar_cor(BRANCO, AZUL);
	cout << left; cout.width(9); cout << " Passos ";
	cout << right;
	resetar_cor();
	cout.width(4); cout << passos << endl << endl;

	// Exibe a posição final do caminhão 1
	ajustar_cor(BRANCO, cor_1);
	cout << " Posição ";
	ajustar_cor(cor_1, PRETO);
	cout.width(4); cout << posicao_1 << " ";

	// Exibe a velocidade média do caminhão 1
	ajustar_cor(BRANCO, cor_1);
	cout << " Velocidade média ";
	ajustar_cor(cor_1, PRETO);
	cout.width(6); cout << fixed; cout.precision(2); cout << vel_media_1 << endl << endl;

	// Exibe a posição final do caminhão 2
	ajustar_cor(BRANCO, cor_2);
	cout << " Posição ";
	ajustar_cor(cor_2, PRETO);
	cout.width(4); cout << posicao_2 << " ";

	// Exibe a velocidade média do caminhão 2
	ajustar_cor(BRANCO, cor_2);
	cout << " Velocidade média ";
	ajustar_cor(cor_2, PRETO);
	cout.width(6); cout << fixed; cout.precision(2); cout << vel_media_2 << endl;

	resetar_cor();

	return 0;
}

void desenhar(int posicao, int cor) // Desenha os caminhões e a pista
{
	ajustar_cor(cor, PRETO);
	cout << "\n\n";

	// Caminhão
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

void espacos(int qtd) { while (qtd-- > 0) cout << ' '; } // Função que acrescenta espaços e faz os caminhões "andarem"
