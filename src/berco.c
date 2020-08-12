

typedef struct berco
{
	/*
		id = numero identificação
		na = numero navios atentidos
		ha = hora abertura
		hd = hora fechamento
		v1 = violação janela de tempo berço
		v2 = violação janela de tempo navios
		fo = função objetivo
	*/
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
		bercos[i]->id = i;
		bercos[i]->na = 0;
		bercos[i]->ha = 0;
		bercos[i]->hd = 0;
		bercos[i]->v1 = 0;
		bercos[i]->v2 = 0;
		bercos[i]->fo = 0;
		bercos[i]->naviosAtendidos = criaMatriz(1, N);
	}
	return bercos;
}

/*Retorna uma matriz com a ordem dos navios atendidos em cada berço*/
int **criarMatrizOrdemNaviosAtendidosBerco(int berco, int N, int **Tki, int **navios)
{

    int **linha = criaMatriz(1, N);
    int **ordem = criaMatriz(1, N);

    copiarLinha(Tki, linha, berco, N);
    copiarLinha(Tki, ordem, berco, N);

    int i, j;
    for (i = 0; i < N; i++)
    {
        if (navios[berco][i] == 0)
        {
            ordem[0][i] = MAX;
            linha[0][i] = MAX;
        }
    }
    ordernarMatriz(ordem, 1, N);

    for (i = 0; i < N; i++)
    {
        if (ordem[0][i] == MAX)
        {
            break;
        }
        for (j = 0; j < N; j++)
        {
            if (ordem[0][i] != MAX && (ordem[0][i] == linha[0][j]))
            {
                ordem[0][i] = j;
                linha[0][j] = MAX;
            }
        }
    }
    //imprimirMatriz(ordem, 1, N);
    return ordem;
}

/*Preenche os berços com cada informação específica*/
int povoarBercos(int K, int N, Berco **bercos, int **k, int **Tki, int **tki, int **ai, int **bi, int **navios)
{
	printf("Povoando lista de berços...\n");
	int i, na = 0;

	for (i = 0; i < K; i++)
	{
		bercos[i]->id = i;
		na = naviosAtendidosPorBerco(bercos[i]->id, N, navios);
		bercos[i]->na = na;
		bercos[i]->ha = k[i][0];
		bercos[i]->hd = k[i][1];
		bercos[i]->v1 = violacoesJanelaTempoBerco(i, N, navios, Tki, k, tki);
		bercos[i]->v2 = violacoesJanelaTempoNavios(i, N, navios, Tki, tki, bi);
		bercos[i]->fo = calcularFOBerco(i, N, Tki, tki, ai, navios);
		int **naviosAtendidos = criaMatriz(1, N);
		naviosAtendidos = criarMatrizOrdemNaviosAtendidosBerco(i, N, Tki, navios);
		bercos[i]->naviosAtendidos = naviosAtendidos;
	}
	return 0;
}

int addNavio(int berco, int navio, Berco **bercos){
	
	bercos[berco]->naviosAtendidos[0][bercos[berco]->na] = navio;
	bercos[berco]->na++;
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
		printf("    Berço %d\n", bercos[i]->id + 1);
		printf("\t  H. abertura: %d\n", bercos[i]->ha);
		
		navio = bercos[i]->naviosAtendidos[0][0];
	
		//printf("navio = %d\n", navio);
		for (j = 1; navio != MAX; j++)
		{

			if(navio != MAX){	
				
				bercoProgramacaoToString(bercos[i]->id, navio, Tki, tki);
			}
			
			navio = bercos[i]->naviosAtendidos[0][j];
			
		}
		

		printf("\t  H. fechamento: %d\n\n", bercos[i]->hd);
		//printf("na = %d\t last = %d\n", na, last);
	}

	return 0;
}

