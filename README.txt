-> Descrição
 Este projeto tem o objetivo de solucionar o problema alocação de berços proposto no arquivo trabalho1.pdf
 
 -> Informações
 Até o momento o que foi desenvolvido:
   1- matriz.c e matri.h -> arquivo que serve para criar e manipular as estruturas de dados do programa;
   2- construtiva.c e cosntrutiva.h -> oferece heuristicas que servem para construir
      uma solução inicial para a matriz Tki;
   3- refinamento.c e refinamento.h -> oferece heuristicas que servem para refinar a solução inicial (não finalinzado);
   4- o arquivo restricoes.c não está sendo utilizado;
-> Como executar
gcc src/main.c -o main && ./main < instancias/i0X.txt 
(X = número de algum arquivo de instância)

-> Obs
O arquivo i06.txt possui um cenário com 5 navios e 2 berços
