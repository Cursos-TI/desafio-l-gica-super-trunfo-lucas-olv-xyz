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
    
    //------------------PRINTANDO AS CARTAS----------------------
    //CARTA 1
    printf("---------------------------CARTAS------------------------\n");
    printf("Carta 1:");
    printf("Estado: %s\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da cidade: %s\n", nome_cidade1);
    printf("Populacao: %u\n", pop1);
    printf("Area: %.2f km\n", area_km1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Pontos turisticos: %d\n", pontos_tur1);
    printf("Densidade populacional: %.2f hab/km\n", densidade_pop1);
    printf("PIB per capita: %.2f reais\n", pib_per_capita1);
    //CARTA 2
    printf("---------------------------------------------------------\n");
    printf("Carta 2:");
    printf("Estado: %s\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da cidade: %s\n", nome_cidade2);
    printf("Populacao: %u\n", pop2);
    printf("Area: %.2f km\n", area_km2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Pontos turisticos: %d\n", pontos_tur2);
    printf("Densidade populacional: %.2f hab/km\n", densidade_pop2);
    printf("PIB per capita: %.2f reais\n", pib_per_capita2);

    //------------------COMPARANDO AS CARTAS----------------------
    //vou escolher populacao como o atributo a ser comparado
    printf("-------COMPARANDO AS CARTAS (atributo: populacao)-------\n");
    printf("Carta 1 - %s (%s): %.1f milhoes\n", nome_cidade1, codigo1, pop1 / 1000000.0);
    printf("Carta 2 - %s (%s): %.1f milhoes\n", nome_cidade2, codigo2, pop2 / 1000000.0);
    
    if (pop1 > pop2) {
        printf("Populacao: Carta 1 (%s) venceu\n",nome_cidade1);
    } else {
        printf("Populacao: Carta 2 (%s) venceu\n",nome_cidade2);
    }
    return 0;
}
