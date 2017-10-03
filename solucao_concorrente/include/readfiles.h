#ifndef _READFILES_H_
#define _READFILES_H_ 
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>


using namespace std;
class Readfiles
{
public:
	int size[2];
	std::ifstream fileA;
	std::ifstream fileB;
	string argumento;
	string arquivoA;
	string arquivoB;

	int* vetorA;
	int* vetorB;

	Readfiles(string argumento, string arquivoA, string arquivoB);
	~Readfiles();

	void lerMatrizes();
	void escreverMatriz(std::vector< vector<int> > C);	
	void escreverDadosEstatisticos(long double tempo_medio,double maior_tempo, double menor_tempo, double desvio_padrao);
};

#endif