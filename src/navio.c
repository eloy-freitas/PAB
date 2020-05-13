
typedef struct navio
{
    int id, ai, ha, hd, bi;
    struct navio *prox;
} Navio;

typedef struct navio Navio;

Navio *criarListaNavios()
{
    Navio *lista; 
    lista = (Navio *)malloc(sizeof(Navio));
    lista->prox = NULL;

    return lista;
}

int addNavio(Navio *lista, int id, int ai, int ha, int hd, int bi)
{
    Navio *novo;
    novo = (Navio *)malloc(sizeof(Navio));
    if (novo != NULL)
    {
        novo->id = id;
        novo->ai = ai;
        novo->ha = ha;
        novo->hd = hd;
        novo->bi = bi;
        novo->prox = NULL;
        if (lista->prox == NULL)
        {
            lista->prox = novo;
        }
        else
        {
            Navio *aux;
            aux = lista->prox;
            while (aux->prox != NULL)
            {
             
                aux = aux->prox;
            }
            aux->prox = novo;
        }
        return 0;
    }
    else
    {
        return 1;
    }
    
}

int imprimirOrdemNavios(Navio *lista)
{
    Navio *aux;
    aux = lista->prox;
    printf("Sequência de navios...: I --> ");

    do
    {
        printf("%d --> ", aux->id);
        aux = aux->prox;
    } while (aux->prox != NULL);

    return 0;
}

int povoarListaNavios(Navio* lista, int berco, int N, int na, int** navios, int** Tki, int** tki, int** ai, int** bi, int** ordem){

    int i;

    for(i = 0; i < na; i++){
        
        Navio* novo = (Navio*)malloc(sizeof(Navio));
        if(novo != NULL){
            int id = ordem[0][i];
            addNavio(novo, id, ai[0][id], Tki[berco][id], Tki[berco][id] + tki[berco][id], bi[0][id]);
        }else
        {
            return 1;
        } 
    }
    return 0;
}

/*int dropNavio(int *navios, int id)
{
    Navio *anterior = navios->prox;

    if (anterior->id == id && anterior->prox == NULL)
    {
        free(anterior);
        return 0;
    }
    else
    {
        Navio *aux = anterior->prox;
        while (aux->id != id)
        {
            anterior = aux;
            aux = aux->prox;
        }
        if (aux->prox == NULL)
        {
            free(aux);
        }

        anterior->prox = aux->prox;
        free(aux);

        return 0;
    }
}*/