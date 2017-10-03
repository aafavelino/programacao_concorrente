/**
 * @brief multiplicaMatrizes
 * Algoritmo padrão para realizar a multiplicação das matrizes
 * Um exemplo deste algoritmo foi dado em pseudo-código na descrição do projeto
 * @param A MatrizA 
 * @param B MatrizB
 * @param &C Referência para MatrizC
 * @param n Dimensão das Matrizes
 * @param inicio Onde começa a contagem
 * @param fim Onde termina a contagem
 * @return void
 */	
void multiplicaMatrizes (std::vector< vector<int> > A, std::vector< vector<int> > B, std::vector< vector<int> > &C, int n, int inicio, int fim) 
{	
	int soma = 0;
	for (int i = inicio; i < fim; ++i)
	{	
		for (int j = 0; j < n; ++j)
		{
			soma = 0;
			for (int k = 0; k < n; ++k)
			{
				soma += A[i][k]*B[k][j];
			}
			C[i][j] = soma;		
		}
	}
}

/**
 * @brief multiplicacao_threads
 * Nesta função são criadas as threads para auxiliar na multiplicação
 * achei justo trabalhar somente com quantidade de threads das potencias de base 2
 * como nas dimensões das matrizes dadas.
 * Os problemas foram divididos em quantidades de threads passadas, onde N/NºThreads
 * @param A MatrizA 
 * @param B MatrizB
 * @param &C Referência para MatrizC
 * @param n Dimensão das Matrizes
 * @param quantidade_de_threads Quantidade de Threads
 * @return void
 */	

void multiplicacao_threads (std::vector< vector<int> > A, std::vector< vector<int> > B,std::vector< vector<int> > &C, int n, int quantidade_de_threads)
{ 
	thread threads[quantidade_de_threads];
	int inicio = 0;
	int fim = 0;
	int quant_quebras = n/quantidade_de_threads;

	if (quantidade_de_threads >= 1 && quantidade_de_threads <= n) {
	
		for (int i = 0; i < quantidade_de_threads; ++i)
		{
			fim = inicio+quant_quebras;

			threads[i] = thread(multiplicaMatrizes, A, B, ref(C), n, inicio, fim);

			inicio = fim;
		}
		for (int i = 0; i < quantidade_de_threads; ++i)
		{
			threads[i].join();
		}
	} else {
		cout << "Informe uma quantidade de threads <= a dimensão da matriz" << endl;
		exit(1);
	}
}


























