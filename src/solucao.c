typedef struct solucao
{
    /*
        id = numero identificação
		na = numero navios atentidos
		bu = numero de bercos usados
		tst = tempo de serviço total
		tv1 = total violação janela de tempo berço
		tv2 = total violação janela de tempo navios
		fo = função objetivo
	*/

    int id, na, bu, tv1, tv2, fo;

    int **navios;
    Berco **bercos;
} Solucao;

Solucao **criarSolucoes(int qtd, int K, int N)
{
    printf("criando estrutura de dados das soluções...\n");
    int i;
    Solucao **solucoes = (Solucao **)malloc(qtd * sizeof(Solucao *));

    for (i = 0; i < qtd; i++)
    {
        solucoes[i] = (Solucao *)malloc(sizeof(Solucao));
        solucoes[i]->id = i;
        solucoes[i]->na = 0;
        solucoes[i]->bu = 0;
        solucoes[i]->tv1 = 0;
        solucoes[i]->tv2 = 0;
        solucoes[i]->fo = 0;
        solucoes[i]->navios = criaMatriz(1, N);
        solucoes[i]->bercos = criarBercos(K, N);
    }
    return solucoes;
}

int totalBercosUtilizados(int K, Berco **bercos)
{
    int i, bu = 0;
    for (i = 0; i < K; i++)
    {
        if (bercos[i]->na > 0)
        {
            bu++;
        }
    }
    return bu;
}

int totalNaviosAtendidos(int K, Berco **bercos)
{
    int i, na = 0;
    for (i = 0; i < K; i++)
    {
        na = na + bercos[i]->na;
    }
    return na;
}

int totalViolacoesTempoNavios(int K, Berco **bercos)
{
    int i, v1 = 0;
    for (i = 0; i < K; i++)
    {
        v1 = v1 + bercos[i]->v1;
    }
    return v1;
}

int totalViolacoesTempoBercos(int K, Berco **bercos)
{
    int i, v2 = 0;
    for (i = 0; i < K; i++)
    {
        v2 = v2 + bercos[i]->v2;
    }
    return v2;
}

int totalFO(int K, Berco **bercos)
{
    int i, fo = 0;
    for (i = 0; i < K; i++)
    {
        fo = fo + bercos[i]->fo;
    }
    return fo;
}

int povoarSolucoes(int id, Solucao **solucoes, int K, int N, int **Tki, int **tki, int **ai, int **bi, int **k)
{

    int **navios = criaMatriz(K, N);
    Berco **bercos = criarBercos(K, N);

    //navios = euristicaGulosa(K, N, Tki, tki, ai, bercos);
    navios = sortearNaviosCandidatos(K, N, tki);
    corrigirMatrizNavios(K, N, navios, tki);
    povoarBercos(K, N, bercos, k, Tki, tki, ai, bi, navios);
    solucoes[id]->na = totalNaviosAtendidos(K, bercos);
    solucoes[id]->bu = totalBercosUtilizados(K, bercos);
    solucoes[id]->tv1 = totalViolacoesTempoBercos(K, bercos);
    solucoes[id]->tv2 = totalViolacoesTempoNavios(K, bercos);
    solucoes[id]->fo = totalFO(K, bercos);
    solucoes[id]->bercos = bercos;
    solucoes[id]->navios = navios;
    return 0;
}

int imprimirSolucao(int id, int K, int N, int **tki, int **Tki, Solucao **solucoes)
{
    imprimirDadosSolucao(solucoes[id]->id, solucoes[id]->bu, solucoes[id]->na, 0, solucoes[id]->tv1, solucoes[id]->tv2, solucoes[id]->fo);
    imprimirListaBercos(K, N, solucoes[id]->bercos);
    imprimirProgramacaoBercos(K, N, solucoes[id]->bercos, Tki, tki);
    return 0;
}