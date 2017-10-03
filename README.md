# Trabalho de Programação Concorrente 2017.2 UFRN

## Objetivo

O objetivo deste trabalho é verificar se é válido ou não o senso comum de que programas concorrentes apresentam um melhor desempenho com relação a tempo de execução quando comparados a suas respectivas versões sequenciais. Para tal, serão implementadas as versões sequencial e concorrente de um algoritmo e realizados testes para diferentes cargas (workloads). Através da análise dos resultados em termos de tempo de execução registrado em cada um dos testes,será possível concluir acerca da hipó́tese inicialmente dada.


**"Não furtarás."**
(Êxodo 20:15)

**Compilação**

Para Ambas as soluções compila-se da mesma forma...

```shell
	g++ -std=c++11 src/main.cpp src/readfiles.cpp -I include -o bin/exe
```

**Execução**

Sequencial:

```shell
	./bin/exe DIMENSAO /CAMINHO/matrizes/ARQUIVOA.txt /CAMINHO/matrizes/ARQUIVOB.txt
```

Concorrente:

Para Meus testes realizei somente com quantidade threads em potências de base 2 como nas dimensões das matrizes...

```shell
./bin/exe DIMENSAO NUMERO_DE_THREADS /CAMINHO/matrizes/ARQUIVOA.txt /CAMINHO/matrizes/ARQUIVOB.txt
```


### Grupo (Até duas pessoas)

|  Aluno                        | Adelino Afonso Fernandes Avelino  |
|-------------------------------|-----------------------------------|
|  GitHub                       |  github.com/aafavelino            |
|  Email               			|  aafavelino@icloud.com            |
|  Email acadêmico 				|  adelino18fernandes@gmail.com     |
|  Telefone						|  (84) 98634-8534					|

### Disponível em:

[Análise empírica de Threads](https://github.com/aafavelino/programacao_concorrente)
