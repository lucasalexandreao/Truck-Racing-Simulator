// Definições das funções da biblioteca pacote
unsigned int empacotar(unsigned int passo, unsigned int cor, unsigned int posicao, unsigned int velocidade, unsigned int pista)
{
	unsigned int numero; // Variável que receberá o número empacotado

	// As linhas seguintes deslocam os bits de cada atributo de forma que os bits relevantes fiquem posicionados como se já estivessem empacotados
	passo = passo << 24; 
	cor = cor << 16; 
	posicao = posicao << 9; 
	velocidade = velocidade << 5; 
	pista = pista << 4; 

	numero = passo | cor | posicao | velocidade | pista; // O operador "|" faz uma união entre os bits dos 5 números, assim efetivando o empacotamento

	return numero;
}

unsigned int passo(unsigned int numero)
{
	return numero >> 24; // Desloca 24 bits do número empacotado para a direita, assim sobrando os 8 bits mais baixos, que representam o passo (os outros ficam zerados)
}

unsigned int cor(unsigned int numero)
{
	return (numero << 8) >> 24;  // Desloca 8 bits do número empacotado para a esquerda. Os 8 bits mais altos passam a representar a cor. Depois desloca 24 bits a direita, os 8 bits da cor passam a ser os mais baixos (os outros ficam zerados)
}

unsigned int posicao(unsigned int numero)
{
	return (numero << 16) >> 25;  // Desloca 16 bits do número empacotado para a esquerda. Os 7 bits mais altos passam a representar a posição. Depois desloca 25 bits a direita, os 7 bits da posição passam a ser os mais baixos (os outros ficam zerados)
}

unsigned int velocidade(unsigned int numero)
{
	return (numero << 23) >> 28; // Desloca 23 bits do número empacotado para a esquerda. Os 4 bits mais altos passam a representar a velocidade. Depois desloca 28 bits a direita, os 4 bits da velocidade passam a ser os mais baixos (os outros ficam zerados)
}

unsigned int pista(unsigned int numero)
{
	return (numero << 27) >> 31; // Desloca 27 bits do número empacotado para a esquerda. O bit mais alto passa a representar o estado da pista. Depois desloca 31 bits a direita, restando o único bit do estado da pista (os outros ficam zerados)
}