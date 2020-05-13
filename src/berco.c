
typedef struct berco
{
	int id, na, ha, hd, v1, v2, fo;
	int **naviosAtendidos;
} Berco;

/*Cria lista de berços*/
Berco **criarBercos(int K, int N)
{
	printf("Criando lista de berços...\n");
	Berco **bercos = (Berco **)malloc(K * sizeof(Berco *));
	int i;
	for (i = 0; i < K; i++)
	{
		bercos[i] = (Berco *)malloc(sizeof(Berco));
		bercos[i]->naviosAtendidos = criaMatriz(1, N);
	}
	return bercos;
}
/*Preenche os berços com cada informação específica*/
int povoarBercos(int K, int N, Berco **bercos, int **k, int **Tki, int **tki, int **ai, int **bi, int **navios)
{
	printf("Povoando lista de berços...\n");
	int i, na = 0;

	for (i = 0; i < K; i++)
	{
		bercos[i]->id = i + 1;
		na = naviosAtendidos(bercos[i]->id, N, navios);
		bercos[i]->na = na;
		bercos[i]->ha = k[i][0];
		bercos[i]->hd = k[i][1];
		bercos[i]->v1 = totalViolacoesJanelaTempoBercos(i + 1, N, navios, Tki, k, tki);
		bercos[i]->v2 = totalViolacoesJanelaTempoNavios(i, N, navios, Tki, tki, bi);
		bercos[i]->fo = calcularFOBerco(i, N, Tki, tki, ai, navios);
		int **naviosAtendidos = criaMatriz(1, N);
		naviosAtendidos = criarMatrizOrdemNaviosAtendidosBerco(i, N, Tki, navios);
		bercos[i]->naviosAtendidos = naviosAtendidos;
	}
	return 0;
}
/*Imprime o contéudo da lista*/
int imprimirListaBercos(int K, int N, Berco **bercos)
{
	int i;

	for (i = 0; i < K; i++)
	{
		bercoToString(i, N, bercos[i]->na, bercos[i]->ha, bercos[i]->hd, bercos[i]->v1, bercos[i]->v2, bercos[i]->fo, bercos[i]->naviosAtendidos);
	}
	return 0;
}

int imprimirProgramacaoBercos(int K, int N, Berco **bercos, int **Tki, int **tki)
{
	int i, j, navio;
	printf("Programação:\n\n");
	for (i = 0; i < K; i++)
	{
		printf("    Berço %d\n", bercos[i]->id);
		printf("\t  H. abertura: %d\n", bercos[i]->ha);
		
		navio = bercos[i]->naviosAtendidos[0][0];
	
		//printf("navio = %d\n", navio);
		for (j = 1; navio != MAX; j++)
		{

			if(navio != MAX){	
				
				bercoProgramacaoToString(bercos[i]->id - 1, navio, Tki, tki);
			}
			
			navio = bercos[i]->naviosAtendidos[0][j];
			
		}
		

		printf("\t  H. fechamento: %d\n\n", bercos[i]->hd);
		//printf("na = %d\t last = %d\n", na, last);
	}

	return 0;
}
