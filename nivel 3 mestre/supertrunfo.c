#include <stdio.h>
#include <string.h>
#include <locale.h>

/*----------DADOS--------
Carta 1:
Estado: A
Código: A01
Nome da Cidade: São Paulo
População: 12325000
Área: 1521.11 km²
PIB: 699.28 bilhões de reais
Número de Pontos Turísticos: 50
-----------------
Carta 2:
Estado: B
Código: B02
Nome da Cidade: Rio de Janeiro
População: 6748000
Área: 1200.25 km²
PIB: 300.50 bilhões de reais
Número de Pontos Turísticos: 30    
*/
/*---------------desafio 4---------------------------------------
treinar estruturas condicionais (if-else por enquanto)
vou mudar o codigo para cartas já cadastradas, ao inves do usuario colocar as informações (para economizar tempo hehe)
*/
/* -------------desafio 5-----------------------
criando um menu interativo
para o usuario escolher o atributo a ser comparado entre as cartas
atributos serao nome, pop, area, pib, turisticos, densidade

*/

int main() {
    setlocale(LC_ALL, "");
    char estado1[50] = "A", estado2[50] = "B",nome_cidade1[50] = "Sao Paulo", nome_cidade2[50] = "Rio de Janeiro", codigo1[50] = "SP", codigo2[50] = "RJ";
   
    unsigned long int pop1 = 12325000, pop2 = 6748000;
    int pontos_tur1 = 50, pontos_tur2 = 30;
    float area_km1 = 1521.11, area_km2 = 1200.25, pib1 = 699.28, pib2 = 300.50;

    // ---------------dados da primeira carta---------------------
 
    float densidade_pop1 = pop1 / area_km1;
    float pib_per_capita1 = (pib1 * 1e9f) / pop1;
    float inverso_densidade1 = 1.0f / densidade_pop1;
    float super_poder1 = pop1 + area_km1 + pib1 + pontos_tur1 + pib_per_capita1 + inverso_densidade1;

    //--------------------dados da segunda carta----------------------


    float densidade_pop2 = pop2 / area_km2;
    float pib_per_capita2 = (pib2 * 1e9f) / pop2;
    float inverso_densidade2 = 1.0f / densidade_pop2;
    float super_poder2 = pop2 + area_km2 + pib2 + pontos_tur2 + pib_per_capita2 + inverso_densidade2;
    //menu
    int opcao;

    printf("bem vindo ao super trunfo!\n");
    printf("escolha o atributo a ser comparado entre as cartas:\n");    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turisticos\n");
    printf("5 - Densidade populacional\n");
    printf("6 - regras do jogo\n");
    printf("7 - sair\n");
    scanf("%d", &opcao);

    switch (opcao)
    { 
      case 1:
        printf("-------COMPARANDO AS CARTAS (atributo: populacao)-------\n");
        printf("Carta 1 - %s (%s): %.1f milhoes\n", nome_cidade1, codigo1, pop1 / 1000000.0);
        printf("Carta 2 - %s (%s): %.1f milhoes\n", nome_cidade2, codigo2, pop2 / 1000000.0);
        
        if (pop1 > pop2) {
            printf("Populacao: Carta 1 (%s) venceu\n",nome_cidade1);
        } else if (pop1 == pop2) {
            printf("Populacao: Empate\n");
        } else {
            printf("Populacao: Carta 2 (%s) venceu\n",nome_cidade2);
        }
        break;
      case 2:
        printf("-------COMPARANDO AS CARTAS (atributo: area)-------\n");
        printf("Carta 1 - %s (%s): %.2f km²\n", nome_cidade1, codigo1, area_km1);
        printf("Carta 2 - %s (%s): %.2f km²\n", nome_cidade2, codigo2, area_km2);
        
        if (area_km1 > area_km2) {
            printf("Area: Carta 1 (%s) venceu\n",nome_cidade1);
        } else if (area_km1 == area_km2) {
            printf("Area: Empate\n");
        } else {
            printf("Area: Carta 2 (%s) venceu\n",nome_cidade2);
        }
        break;
      case 3:
        printf("-------COMPARANDO AS CARTAS (atributo: pib)-------\n");
        printf("Carta 1 - %s (%s): %.2f bilhoes de reais\n", nome_cidade1, codigo1, pib1);
        printf("Carta 2 - %s (%s): %.2f bilhoes de reais\n", nome_cidade2, codigo2, pib2);
        
        if (pib1 > pib2) {
            printf("PIB: Carta 1 (%s) venceu\n",nome_cidade1);
        } else if(pib1 == pib2){
            printf("PIB: Empate\n");
        } else {
            printf("PIB: Carta 2 (%s) venceu\n",nome_cidade2);}
        break;
      case 4:
        printf("-------COMPARANDO AS CARTAS (atributo: pontos turisticos)-------\n");
        printf("Carta 1 - %s (%s): %d pontos turisticos\n", nome_cidade1, codigo1, pontos_tur1);
        printf("Carta 2 - %s (%s): %d pontos turisticos\n", nome_cidade2, codigo2, pontos_tur2);
        
        if (pontos_tur1 > pontos_tur2) {
            printf("Pontos turisticos: Carta 1 (%s) venceu\n",nome_cidade1);
        } else if (pontos_tur1 == pontos_tur2) {
            printf("Pontos turisticos: Empate\n");
        } else {
            printf("Pontos turisticos: Carta 2 (%s) venceu\n",nome_cidade2);
        }
        break;
      case 5:
        printf("-------COMPARANDO AS CARTAS (atributo: densidade populacional)-------\n");
        printf("Carta 1 - %s (%s): %.2f hab/km²\n", nome_cidade1, codigo1, densidade_pop1);
        printf("Carta 2 - %s (%s): %.2f hab/km²\n", nome_cidade2, codigo2, densidade_pop2);
        
        if (densidade_pop1 < densidade_pop2) {
            printf("Densidade populacional: Carta 1 (%s) venceu\n",nome_cidade1);
        } else if (densidade_pop1 == densidade_pop2) {
            printf("Densidade populacional: Empate\n");
        } else {
            printf("Densidade populacional: Carta 2 (%s) venceu\n",nome_cidade2);
        } 
        break;
        case 6:
        printf("-------REGRAS DO JOGO-------\n");
        printf("O jogo Super Trunfo é um jogo de cartas onde cada jogador tem um baralho com cartas que representam cidades.\n");
        printf("Cada carta possui atributos como população, área, PIB, pontos turísticos e densidade populacional.\n");
        printf("Os jogadores escolhem um atributo para comparar as cartas, e a carta com o maior valor nesse atributo vence a rodada.\n");
        printf("O jogo continua até que um dos jogadores fique sem cartas ou até que um jogador vença todas as cartas do outro.\n");
        printf("O jogador que vencer mais rodadas é o vencedor do jogo.\n");
        printf("Boa sorte!\n");
        break;
        case 7:
        printf("Saindo do jogo...\n");
        return 0;
        break;

        default:
        printf("Opcao invalida! Tente novamente.\n");
    }
    return 0;
}
