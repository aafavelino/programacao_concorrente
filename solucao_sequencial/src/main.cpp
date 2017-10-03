#include <iostream>
#include "readfiles.h"
#include "math.h"
#include "alg_mult_mat.h"

using namespace std;




int main(int argc, char const *argv[])
{
	// Argumento em linha de comando...
    if (argc != 4)
    {
        cout << "Parâmetro incorreto!!!" << endl << endl;
        cout << "tente $ ./multimat_concorrente 2 caminhoA caminhoB" << endl << endl;
        exit(1);
    }
    // Passando o Tamanho das matrizes
    int size[2];
    for (int i = 0; i < 2; ++i)
    {
    	size[i]= std::stoi(argv[1]);	
    }

    //Variáveis e objeto 
    std::vector< vector<int> > A(size[0], vector<int>(size[0])); // Matriz A
    std::vector< vector<int> > B(size[0], vector<int>(size[0])); // Matriz B
    std::vector< vector<int> > C(size[0], vector<int>(size[0])); // Matriz C
    double desvio_padrao; // Desvio Padrão
    double somatorio = 0; // Somatório
    long double media = 0; // Valor médio dos tempos
	std::chrono::time_point<std::chrono::system_clock> inicio, fim; // Clock
	unsigned long long int nanosegundos_decorridos; // Fim - Inicio do clock
	double maior_tempo; // Maior tempo de clock
	double menor_tempo; // Menor tempo de clock
	unsigned long long int nanosegundos_decorridos_vetor[21]; // Vetor de clocks
    
    //Definindo leitura de arquivos...
    Readfiles *files = new Readfiles(argv[1], argv[2], argv[3]);
    //Lendo os arquivos de matrizes e armazenando num vetor
    files->lerMatrizes();



    //Passar os vetores para Matrizes de vector(A e B) colhidos na leitura dos arquivos
    int aux = 0;
	for (int i = 0; i < size[0]; ++i)
	{
		for (int j = 0; j < size[1]; ++j)
		{
			A[i][j] = files->vetorA[j+aux];
		}
		aux+=size[0];
		
	}

	aux = 0;
	for (int i = 0; i < size[0]; ++i)
	{
		for (int j = 0; j < size[1]; ++j)
		{
			B[i][j] = files->vetorB[j+aux];
		}
		aux+=size[0];
		
	}



	//FAZENDO ANALISE EMPIRICA


	//TESTES DE TEMPO
	for (int i = 1; i <= 20; ++i)
    {   std::cout << i << std::endl;
		inicio = std::chrono::system_clock::now();
			C = multiplicaMatrizes(A, B, C, size[0]);
	 	fim = std::chrono::system_clock::now();

	 	nanosegundos_decorridos = std::chrono::duration_cast<std::chrono::nanoseconds> (fim-inicio).count();
	 	nanosegundos_decorridos_vetor[i] = nanosegundos_decorridos;

	 	//Média de tempos...
	 	media = media + ((nanosegundos_decorridos - media)/i);
	}


	//Calculando menor tempo e maior tempo
	maior_tempo = nanosegundos_decorridos_vetor[1];
	menor_tempo = nanosegundos_decorridos_vetor[1];
	for (int i = 1; i <= 20; ++i)
	{
		if (maior_tempo < nanosegundos_decorridos_vetor[i])
		{
			maior_tempo = nanosegundos_decorridos_vetor[i];
		}
		if (menor_tempo > nanosegundos_decorridos_vetor[i])
		{
			menor_tempo = nanosegundos_decorridos_vetor[i];
		}
	}

	//Convertendo para segundos...
	for (int i = 1; i <= 20; ++i)
		nanosegundos_decorridos_vetor[i] = nanosegundos_decorridos_vetor[i]/1000000000;
	media = media/1000000000;
	menor_tempo = menor_tempo/1000000000;
	maior_tempo = maior_tempo/1000000000;




	//CALCULO DO DESVIO PADRAO
	for (int i = 1; i <= 20; ++i)
	{
		somatorio+= pow((media-nanosegundos_decorridos_vetor[i]),2);
	}
	somatorio = somatorio;
	desvio_padrao = sqrt(somatorio)*0.05;
	


	//ESCREVENDO NA MATRIZ DE ARQUIVO
 	files->escreverMatriz(C);
 	//ESCREVENDO DADOS ESTATISTICOS
 	files->escreverDadosEstatisticos(media,maior_tempo,menor_tempo,desvio_padrao);
 	A.clear();
 	B.clear();
 	C.clear();
	return 0;
}
