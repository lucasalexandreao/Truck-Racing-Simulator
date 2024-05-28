// Definições das funções da bibloteca cores
#include <iostream>
#include "cores.h"
using namespace std;

void ajustar_cor(unsigned int cor_texto, unsigned int cor_fundo)
{
	cout << "\033[38;5;" << cor_texto << "m"; // altera a cor dos caracteres do texto 
	cout << "\033[48;5;" << cor_fundo << "m"; // altera a cor do fundo do texto
}

void resetar_cor()
{
	cout << "\033[m"; // altera cor e fundo para o padrão
}