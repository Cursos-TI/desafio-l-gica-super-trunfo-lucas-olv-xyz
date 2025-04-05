#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

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

/*----------DESAFIO FINAL------------------
vamos permitir a comparacao de 2 atributos
vamos colocar menus dinamicos
vamos deixar o codigo mais clean com operador ternario
1. o sistema deve permitir que o usuário escolha entre dois atributos para comparar as cartas.
2. msm tipo de logica, maior atributo vence, menos densidade, esse continua sendo o menor
3. depois de comparar individualmente o sistema deve somar os valores, a carta com maior soma vence
4. tratamento de empate
5. menu dinamico, tipo, apos o usuario escolher o primeiro atributo, o mesmo nao deve aparecer novamente
6. exibicao clara dos resultados
-nome dos paises
-atributos escolhidos
-valores de cada atbributo
-soma dos atributos
-qual carta venceu ou empate
*/


int main() {
    setlocale(LC_ALL, "");
    system("chcp 65001 > nul");//pra nao ter bug na hora de imprimir os acentos


    char estado1[50] = "A", estado2[50] = "B",nome_cidade1[50] = "Sao Paulo", nome_cidade2[50] = "Rio de Janeiro", codigo1[50] = "SP", codigo2[50] = "RJ";
   
    unsigned long int pop1 = 12325000, pop2 = 6748000;
    int pontos_tur1 = 50, pontos_tur2 = 30;
    float area_km1 = 1521.11, area_km2 = 1200.25;
    float pib1 = 699.28, pib2 = 300.50;

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
    printf("escolha uma opcao:\n"); 
    printf("1 - jogar\n");   
    printf("2 - regras do jogo\n");
    printf("3 - sair\n");
    scanf("%d", &opcao);
    int atributo1, atributo2;

    switch (opcao){
        case 1:
            //printando o menu do primeiro atributo
            printf("Escolha o primeiro atributo:\n");
            printf("1 - Populacao\n");
            printf("2 - Area\n");
            printf("3 - PIB\n");
            printf("4 - Pontos turisticos\n");
            printf("5 - Densidade populacional\n");
            scanf("%d", &atributo1);

            //printando o menu do segundo, usando uma verificacao para nao repetir o atributo
            printf("Escolha o segundo atributo (diferente do primeiro):\n");
            if (atributo1 != 1) printf("1 - Populacao\n");
            if (atributo1 != 2) printf("2 - Area\n");
            if (atributo1 != 3) printf("3 - PIB\n");
            if (atributo1 != 4) printf("4 - Pontos turisticos\n");
            if (atributo1 != 5) printf("5 - Densidade populacional\n");
            scanf("%d", &atributo2);

            if (atributo1 == atributo2) {
                printf("Voce nao pode escolher o mesmo atributo duas vezes.\n");
                return 0;
            }

            // Coletando valores para cada atributo usando uma veficicação ==
            float valor1_c1 = (atributo1 == 1) ? pop1 :
                            (atributo1 == 2) ? area_km1 :
                            (atributo1 == 3) ? pib1 :
                            (atributo1 == 4) ? pontos_tur1 :
                            1.0 / (pop1 / area_km1);

            float valor1_c2 = (atributo1 == 1) ? pop2 :
                            (atributo1 == 2) ? area_km2 :
                            (atributo1 == 3) ? pib2 :
                            (atributo1 == 4) ? pontos_tur2 :
                            1.0 / (pop2 / area_km2);

            float valor2_c1 = (atributo2 == 1) ? pop1 :
                            (atributo2 == 2) ? area_km1 :
                            (atributo2 == 3) ? pib1 :
                            (atributo2 == 4) ? pontos_tur1 :
                            1.0 / (pop1 / area_km1);

            float valor2_c2 = (atributo2 == 1) ? pop2 :
                            (atributo2 == 2) ? area_km2 :
                            (atributo2 == 3) ? pib2 :
                            (atributo2 == 4) ? pontos_tur2 :
                            1.0 / (pop2 / area_km2);

            // definindo a soma dos atributos
            float soma1 = valor1_c1 + valor2_c1;
            float soma2 = valor1_c2 + valor2_c2;

            // Imprimindo nomes dos atributos diretamente
            printf("\n======= RESULTADO FINAL =======\n\n");

            printf("CARTA 1 - %s (SP)\n", nome_cidade1);
            printf("%s: %.2f\n", (atributo1 == 1) ? "População" :
                                (atributo1 == 2) ? "Área" :
                                (atributo1 == 3) ? "PIB" :
                                (atributo1 == 4) ? "Pontos Turísticos" :
                                "Densidade Populacional",
                                (atributo1 == 5) ? (pop1 / area_km1) : valor1_c1);
                                /*para densidade a gente salva o valor inverso, exemplo de pq isso funciona: suponha que pop1 = 1000000 e area1 = 500,
                                100000 / 500 = 2000, na hora de calcular a densidade, a gente faz 1.0 / (pop / area) (ali no float logo acima), o que da 0.0005, ou seja, o menor valor de densidade
                                vai ser o maior valor de densidade populacional, e o maior valor de densidade populacional vai ser o menor valor de densidade populacional
                                */

            printf("%s: %.2f\n", (atributo2 == 1) ? "População" :
                                (atributo2 == 2) ? "Área" :
                                (atributo2 == 3) ? "PIB" :
                                (atributo2 == 4) ? "Pontos Turísticos" :
                                "Densidade Populacional",
                                (atributo2 == 5) ? (pop1 / area_km1) : valor2_c1);

            printf("SOMA DOS ATRIBUTOS: %.5f\n\n", soma1);

            printf("CARTA 2 - %s (RJ)\n", nome_cidade2);
            printf("%s: %.2f\n", (atributo1 == 1) ? "População" :
                                (atributo1 == 2) ? "Área" :
                                (atributo1 == 3) ? "PIB" :
                                (atributo1 == 4) ? "Pontos Turísticos" :
                                "Densidade Populacional",
                                (atributo1 == 5) ? (pop2 / area_km2) : valor1_c2);

            printf("%s: %.2f\n", (atributo2 == 1) ? "População" :
                                (atributo2 == 2) ? "Área" :
                                (atributo2 == 3) ? "PIB" :
                                (atributo2 == 4) ? "Pontos Turísticos" :
                                "Densidade Populacional",
                                (atributo2 == 5) ? (pop2 / area_km2) : valor2_c2);

            printf("SOMA DOS ATRIBUTOS: %.5f\n\n", soma2);

            printf("RESULTADO: ");
            (soma1 > soma2) ? printf("CARTA 1 - %s venceu!\n", nome_cidade1) :
            (soma2 > soma1) ? printf("CARTA 2 - %s venceu!\n", nome_cidade2) :
                            printf("Empate!\n");

            break;


        case 2:
            printf("regras do jogo:\n");
            printf("1. cada jogador tem 2 cartas\n");
            printf("2. o jogador escolhe um atributo para comparar as cartas\n");
            printf("3. o jogador com o maior valor no atributo escolhido vence a rodada\n");
            printf("4. se houver empate, o jogador que escolheu o atributo vence\n");
            break;
        case 3:
            printf("saindo...\n");
            return 0;
    }

  return 0;
}
