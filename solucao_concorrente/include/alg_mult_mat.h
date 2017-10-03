void multiplicaMatrizes (std::vector< vector<int> > A, std::vector< vector<int> > B, std::vector< vector<int> > &C, int n, int inicio_r, int fim_r) 
{	
	int soma = 0;
	for (int i = inicio_r; i < fim_r; ++i)
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


void multiplicacao_threads (std::vector< vector<int> > A, std::vector< vector<int> > B,std::vector< vector<int> > &C, int n, int quantidade_de_threads)
{ 
	thread threads[quantidade_de_threads];
	int inicio_r = 0;
	int fim_r = 0;
	int quant_quebras = n/quantidade_de_threads;


	if (quantidade_de_threads >= 1 && quantidade_de_threads <= n) {
	
		for (int i = 0; i < quantidade_de_threads; ++i)
		{
			fim_r = inicio_r+quant_quebras;

			threads[i] = thread(multiplicaMatrizes, A, B, ref(C), n, inicio_r, fim_r);

			inicio_r = fim_r ;
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


























