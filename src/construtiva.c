#define MAX 10000

/*Tem o objetivo de corrigir a matriz de navios atendidos, caso um navio ocupe dois berços é feito um novo sorteio*/
int corrigirMatrizNavios(int K, int N, int **navios, int **tki)
{
    int i, j, k, sorteio, cont = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < K; j++)
        {
            cont = cont + navios[j][i];
        }
        if (cont == 0)
        {
            sorteio = rand() % K;
            navios[sorteio][i] = 1;
        }
        if (cont > 1)
        {
            for (k = 0; k < K; k++)
            {
                if (navios[k][i] == 1)
                {
                    navios[k][i] = 0;
                }
            }
            sorteio = rand() % K;
            navios[sorteio][i] = 1;
        }
        cont = 0;
    }
    return 0;
}

int **povoarPrimeirosNavios(int K, int N, int **Tki, int **navios, Berco **bercos)
{
    int i, j, navio, peso = MAX;
    int **controle = criaMatriz(1, N);
    padronizarMatriz(controle, 1, N, 0);

    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (peso > Tki[i][j] && controle[0][j] == 0)
            {
                peso = Tki[i][j];
                navio = j;
                //printf("peso = %d\t navio = %d\n", peso, navio);
            }
        }
        navios[i][navio] = 1;
        controle[0][navio] = 1;
        addNavio(i, navio, bercos);
        peso = MAX;
    }
    return controle;
}

int **euristicaGulosa(int K, int N, int **Tki, int **tki, int **ai, Berco **bercos)
{

    int i, j, peso = 0, berco, fo = 0;
    int **navios = criaMatriz(K, N);
    int **controle = criaMatriz(1, N);

    padronizarMatriz(navios, K, N, 0);
    controle = povoarPrimeirosNavios(K, N, Tki, navios, bercos);

    for (j = 0; j < N; j++)
    {
        if (controle[0][j] == 1)
        {
            continue;
        }
        else
        {
            peso = MAX;
            berco = -1;
            for (i = 0; i < K; i++)
            {
                if (tki[i][j] != 0)
                {
                    fo = Tki[i][j] - ai[0][j] + tki[i][j];
                    if (peso > fo && fo > 0)
                    {
                        peso = fo;
                        berco = i;
                    }
                }
            }
            if (peso != MAX && berco > -1)
            {
                navios[berco][j] = 1;
                addNavio(berco, j, bercos);
                controle[0][j] = 1;
            }
        }
    }

    return navios;
}

/*Tem o objetivo de sortear os N navios para os K berços*/
int **sortearNaviosCandidatos(int K, int N, int **tki)
{
    int i, j, sorteio;
    int **navios = criaMatriz(K, N);
    padronizarMatriz(navios, K, N, 0);

    for (i = 0; i < K; i++)
    {
        for (j = 0; j < (N / K); j++)
        {
            sorteio = rand() % N;
            navios[i][sorteio] = 1;
        }
    }
    //corrigirMatrizNavios(K, N, navios, Tki);
    return navios;
}

/*Essa função faz o cálculo da matriz Tki apartir da entrada*/
int calcularMatrizHoraAtracacao(int K, int N, int **Tki, int **ai, int **k, int **tki)
{
    int i, j, navio = 0, soma = 0, peso = 0;
    int **ak = criaMatriz(1, N);
    int **aj = criaMatriz(1, N);

    copiarMatriz(ai, ak, 1, N);
    copiarMatriz(ai, aj, 1, N);
    ordernarMatriz(aj, 1, N);

    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            peso = aj[0][j];
            navio = getColuna(ak, 0, N, peso);
            ak[0][navio] = MAX;
            // printf("navio = %d\n", valor);

            if (j == 0) //Se for o primeiro navio, a soma (referente ao horário em que o berço está ocupado)
            {
                if (ai[0][navio] < k[i][0])
                {
                    soma = soma + k[i][0]; //com o pesode abertura do berço, se o navio chegar antes que o berço abrir
                }
                if (ai[0][navio] > k[i][0])
                {
                    soma = soma + ai[0][navio]; //com o pesode chegada do navio, se ele chegar depois que o berço abrir
                }
                Tki[i][navio] = soma; //automaticamente o primeiro navío recebe esse o pesoda soma
                soma = soma + tki[i][navio];
            }
            else //automaticamente o primeiro navío recebe esse o pesoda soma
            {

                if (ai[0][navio] > soma)
                {
                    Tki[i][navio] = ai[0][navio];
                    soma = soma + tki[i][navio];
                }
                else
                {
                    Tki[i][navio] = soma;
                    soma = soma + tki[i][navio];
                }
            }

            //printf("soma = %d, navio = %d, tki = %d\n", soma, navio, tki[i][navio]);
        }
        //k[i][1] = soma;
        copiarMatriz(ai, ak, 1, N);
        soma = 0;
    }
    limparMatriz(ak, 1);
    return 0;
}

/*Tem o objetivo de criar um vetor com a ordem de atendimento de todos os navios
int **criarMatrizOrdemNavios(int K, int N, int **Tki, int **navios)
{
    int **ordemNavios = criaMatriz(1, N);
    padronizarMatriz(ordemNavios, 1, N, MAX);
    int **ordem = criaMatriz(1, N);

    int i, j, l = 0, na, last = 0;
    for (i = 0; i < K; i++)
    {
        ordem = criarMatrizOrdemNaviosAtendidosBerco(i, N, Tki, navios);
        na = naviosAtendidosPorBerco(i, N, navios);
        while (ordemNavios[0][last] != MAX)
        {
            last++;
        }
        for (j = last; j < last + na; j++)
        {
            ordemNavios[0][j] = ordem[0][l];
            l++;
        }
        l = 0;
    }

    // imprimirMatriz(ordemNavios, 1, N);
    return ordemNavios;
}



Tem o objetivo de povoar a matriz Tki com números aleatórios de 1 a 200
int sortearTempoEspera(int K, int N, int **Tki)
{
    int i = 0, j = 0, sorteio = 0;

    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            sorteio = rand() % 200;
            Tki[i][j] = sorteio;
        }
    }
    return 0;
}

Tem o objetivo de mudar 2 bits aleatórios na linha da 
matriz navios de N colunas passados por parâmetros
int mudarDoisBits(int **navios, int linha, int N)
{
    int i = 0, j = 0, sorteio1 = 0, sorteio2 = 0;

    sorteio1 = rand() % N;
    sorteio2 = rand() % N;
    while (sorteio1 == sorteio2)
    {
        sorteio2 = rand() % N;
    }
    //printf("sorteio= %d\n", sorteio);
    if (navios[linha][sorteio1] == 0)
    {
        navios[linha][sorteio1] = 1;
    }
    else
    {
        navios[linha][sorteio1] = 0;
    }

    if (navios[linha][sorteio2] == 0)
    {
        navios[linha][sorteio2] = 1;
    }
    else
    {
        navios[linha][sorteio2] = 0;
    }
    return 0;
}*/