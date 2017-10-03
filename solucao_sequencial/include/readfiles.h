/*!
 *  @file readfiles.h
 *  @brief Corpo da Classe Readfiles
 *
 *  Arquivo com a classe Readfiles responsável
 *	pela leitura dos arquivos do projeto...
 */
#ifndef _READFILES_H_
#define _READFILES_H_ 
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>


using namespace std;

/**
 * @brief Classe Readfiles
 *
 * Assinaturas das funções e definição da classe Readfiles
 */
class Readfiles
{
public:
	int size[2]; //Dimensões das matrizes
	std::ifstream fileA; // Arquivo A
	std::ifstream fileB; // Arquivo B
	string argumento; // Argumento do tamanho passado das matrizes
	string arquivoA; // Caminho do arquivo A
	string arquivoB; // Caminho do arquivo B

	int* vetorA;
	int* vetorB;
	/**
     * @brief Construtor da classe Readflies
     * Instancia os arquivos
     */
	Readfiles(string argumento, string arquivoA, string arquivoB);
	~Readfiles();
	/**
     * @brief lerMatrizes
     * Ler as matrizes
     */
	void lerMatrizes();
	/**
     * @brief escreverMatriz
     * Escreve o resultado da Matriz C em arquivo
     */	
	void escreverMatriz(std::vector< vector<int> > C);	
	/**
     * @brief escreverDadosEstatisticos
     * Escreve o resultado dos dados em arquivo
     */	
	void escreverDadosEstatisticos(long double tempo_medio,double maior_tempo, double menor_tempo, double desvio_padrao);
};

#endif