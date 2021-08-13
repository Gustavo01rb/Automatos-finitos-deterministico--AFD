#include "Matriz.h"
#include "AFD.h"

int menu();
int info();

int main(){
    AFD automato;
    char titulo[15];
    int escolha = 0;
    char aux;
    char *predefinido = "automato.txt";
    char *palavra = CharArray(30);

    while(escolha != 3){
        escolha = info();
        switch(escolha){
            case 1:
                NovoAutomato(&automato);
                escolha = 3;
            break;
            case 2:
                printf("\nDeseja ler o arquivo predefinido [s/n]: ");
                scanf("%c", &aux);
                scanf("%c", &aux);

                if(aux != 's' && aux != 'S'){
                    printf("Informe o nome do arquivo: ");
                    scanf("%s",titulo);
                    if(LeituraDeDados(&automato, titulo) == 0) escolha = 3;
                }else
                    if(LeituraDeDados(&automato, predefinido) == 0) escolha = 3;
                
            break;
            case 3:
                printf("\n\n");
            break;
            default: printf("\n\tOpcao invalida\n");
        }
    }
    system("clear");
    escolha = 0;

    while(escolha != 6){
        escolha = menu();
        switch(escolha){
            case 1:
                printf("Informe o nome do arquivo: ");
                scanf("%s",titulo);
                SalvaDados(&automato, titulo);
            break;
            case 2:
                Informacoes(&automato);
            break;
            case 3:
                printf("\nInforme a palvra: ");
                scanf("%s", palavra);
                VerificaPalavra(&automato, palavra, 30)
                ? printf("\n A palavra informada pode ser gerada pelo automato.\n")
                : printf("\n A palavra informada nao pode ser gerada pelo automato.\n");
                
                printf("\nDeseja ver o relatorio gerado [s/n]: ");
                scanf("%c", &aux);
                scanf("%c", &aux);

                if(aux == 's' || aux == 'S'){
                   ImprimeRlatorio(&automato.relatorio); 
                }
            break;
            case 4:
                ImprimeRlatorio(&automato.relatorio);
            break;
            case 5:
                system("clear");
            break;
            default: printf("\n\tOpcao invalida\n");
        }

    }


    
   

    return 0;
}

int menu(){
    int resposta;
    printf("\n\n-----------------------------------------------------------------------------------------------------");
    printf("\n\tMenu de opcoes :");
    printf("\n\n[1] -> Salvar automato em um arquivo.");
    printf("\n[2] -> Informacoes do automato.");
    printf("\n[3] -> Inserir uma palavra.");
    printf("\n[4] -> Ultimo relatorio gerado pela analise da palavra.");
    printf("\n[5] -> Limpar tela.");
    printf("\n[6] -> Sair.");



    printf("\n\nInforme sua escolha: ");
    scanf("%d", &resposta);
    printf("-----------------------------------------------------------------------------------------------------\n\n");


    return resposta;
}
int info(){
    int resposta;
    printf("\n\n\tAutomatos finitos deterministicos:\n");
    printf("\n[1] -> Para inserir um novo automato.");
    printf("\n[2] -> Para ler um automato existente.");
    printf("\n[3] -> Sair");
    printf("\n\nInforme sua escolha: ");
    scanf("%d", &resposta);
    printf("\n\n");
    return resposta;
}
