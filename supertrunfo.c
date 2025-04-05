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
            printf("escolha o primeiro atributo:\n");
            printf("1 - Populacao\n");
            printf("2 - Area\n");
            printf("3 - PIB\n");
            printf("4 - pontos turisticos\n");
            printf("5 - Densidade populacional\n");
            scanf("%d", &atributo1);

            printf("escolha o segundo atributo:\n");
            
            if (atributo1 != 1) printf("1 - Populacao\n");
            if (atributo1 != 2) printf("2 - Area\n");
            if (atributo1 != 3) printf("3 - PIB\n");
            if (atributo1 != 4) printf("4 - pontos turisticos\n");
            if (atributo1 != 5) printf("5 - Densidade populacional\n");

            scanf("%d", &atributo2);

            //vamos começar a comparar os atributos
            printf("-------COMPARANDO AS CARTAS (atributo: %d)-------\n", atributo1);
            printf("Carta 1 - %s (%s): ", nome_cidade1, codigo1);
            printf("atributo1: ");
            switch (atributo1) {
                case 1:
                    printf("%.1f milhoes\n", pop1 / 1000000.0);
                    break;
                case 2:
                    printf("%.2f km²\n", area_km1);
                    break;
                case 3:
                    printf("%.2f bilhoes de reais\n", pib1);
                    break;
                case 4:
                    printf("%d pontos turisticos\n", pontos_tur1);
                    break;
                case 5:
                    printf("%.2f hab/km²\n", densidade_pop1);
                    break;
            }
            printf("Carta 2 - %s (%s): ", nome_cidade2, codigo2);
            printf("atributo1: "); 
            switch (atri)
            {
            case constant expression:
                /* code */
                break;
            
            default:
                break;
            }

            if (atributo1 == atributo2) {
                printf("voce nao pode escolher o mesmo atributo duas vezes\n");
                return 0;
            }
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
