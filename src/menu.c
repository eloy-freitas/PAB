
int painel(int K, int N, int **Tki, int **tki, int **ai, int **bi, int **k, int t)
{

    int option = 0;
    int **navios = criaMatriz(K, N); 
    Berco** bercos = criarBercos(K, N);
    do
    {
        imprimirMenu();
        scanf("%d", &option);
        while(option > 2 || option < 0){
            printf("\n\n\n\tOpção inválida!\n\n\n");
            imprimirMenu();
            scanf("%d", &option);
        }
        switch (option)
        {
        case 1:
            
            navios = sortearNaviosCandidatos(K, N, tki);
            
            break;
        case 2:
            navios = euristicaGulosa(K, N, tki, ai);

            break;
        default:
            break;
        }

        povoarBercos(K, N, bercos, k, Tki, tki, ai, bi, navios);

        Solucao so = criarSolucao(1, K, N, t, navios, Tki, tki, k, ai, bi, bercos);

        imprimirSolucao(so);


        //imprimirListaBercos(K, N, bercos);
        //imprimirProgramacaoBercos(K, N, bercos, Tki, tki);

        //benchmark result = 228

    
    } while (option != 0);
    return 0;
}