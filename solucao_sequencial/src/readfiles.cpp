#include "readfiles.h"

Readfiles::Readfiles(string argumento, string arquivoA, string arquivoB) {
	this->argumento = argumento;
	this->fileA.open(arquivoA);
	this->fileB.open(arquivoB);


	this->vetorA = new int[std::stoi(argumento) * std::stoi(argumento)];
	this->vetorB = new int[std::stoi(argumento) * std::stoi(argumento)];
	this->size[0] = std::stoi(argumento);
	this->size[1] = std::stoi(argumento);
}

Readfiles::~Readfiles() 
{
	this->fileA.close();
	this->fileB.close();
	delete [] this->vetorA;
	delete [] this->vetorB;
}

void Readfiles::lerMatrizes() {


	if (!fileA) {
    	cout << "falhou ao abrir\n";
    }

    int size[2];
    for (int i = 0; i < 2; ++i)
    {
    	if (!(fileA >> size[i])) {
    		cout << "falhou ao ler o primeiro valor\n";
    	}
    }

    
    
    for (int i = 0; i < size[0]*size[0]	; ++i) {
        if (!(fileA >> vetorA[i])) {
        	cout << "falhou ao ler um dos valores\n";
        }
    }    



	if (!fileB) {
    	cout << "falhou ao abrir\n";
    }

    
    for (int i = 0; i < 2; ++i)
    {
    	if (!(fileB >> size[i])) {
    		cout << "falhou ao ler o primeiro valor\n";
    	}
    }

    for (int i = 0; i < size[0]*size[0]	; ++i) {
        if (!(fileB >> vetorB[i])) {
        	cout << "falhou ao ler um dos valores\n";
        }
    }    


    
}

void Readfiles::escreverMatriz(std::vector< vector<int> > C)
{
	
	std::ofstream fileC ("../matrizes/resultados da sequencial/C"+argumento+"x"+argumento+".txt");	
	if (fileC.is_open())
	{
		fileC << argumento << " " << argumento <<"\n";

	    for (int i = 0; i < size[0] ; ++i)
	    {
	    	for (int j = 0; j < size[1]; ++j)
	    	{
	    		fileC << C[i][j] << " ";
	    		
	    	}
	    	fileC << "\n";
	    
	    }
	}
  	else
  	{ 
  		cout << "falhou ao gravar\n";
  	}
  	fileC.close();
}

void Readfiles::escreverDadosEstatisticos(long double tempo_medio,double maior_tempo, double menor_tempo, double desvio_padrao)
{
	std::ofstream dados ("../matrizes/dados/dados_sequencial/C"+argumento+"x"+argumento+".txt");	
	if (dados.is_open())
	{
		dados << "Tempo médio em segundos: " << tempo_medio << "\n";
		dados << "Menor tempo: " << menor_tempo << "\n";
		dados << "Maior tempo: " << maior_tempo << "\n";
		dados << "Desvio Padrão: " << desvio_padrao << "\n";
	}
  	else
  	{ 
  		cout << "falhou ao gravar\n";
  	}
  	dados.close();
}