# IA - Reolver puzzle Jogo dos 8 
Jogo dos 8: http://www.professeurs.polymtl.ca/michel.gagnon/Disciplinas/Bac/IA/ResolProb/arv_busca_queb8a.gif

Algoritmo usa basicamente a busca em largura;

No main.c é colocado a matriz inicial, que representa o tabuleiro no estado inicial;

No skynet.c, existe uma variavel chamada codFinal, esse código é referente ao estado final, ou estado alvo, por exemplo, a matriz resulado é a seguinte:
|1 2 3|<br/>
|4 5 6|<br/>
|7 8 0|<br/>

Então o código vai ser 123456780, ou seja, os valores da matriz em ordem.

Para copilar: gcc -o skynet lista.c skynet.c main.c
