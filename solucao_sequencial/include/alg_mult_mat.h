/**
 * @brief multiplicaMatrizes
 * Algoritmo padrão para realizar a multiplicação das matrizes
 * Um exemplo deste algoritmo foi dado em pseudo-código na descrição do projeto
 * @param A MatrizA 
 * @param B MatrizB
 * @param C MatrizC
 * @param n Dimensão das Matrizes
 * @return std::vector< vector<int> >
 */	
std::vector< vector<int> > multiplicaMatrizes (std::vector< vector<int> > A, std::vector< vector<int> > B, std::vector< vector<int> > C, int n) 
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int soma = 0;
			for (int k = 0; k < n; ++k)
			{
				soma += A[i][k]*B[k][j];
			}
			C[i][j] = soma;
		}
	}
	return C;
}