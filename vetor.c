#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MILUSUARIOS 1000
#define CARACTERESNOME 50
#define CARACTERESEMAIL 40
#define CARACTERESEND 100

int ids[MILUSUARIOS];
char names[MILUSUARIOS][CARACTERESNOME];
char emails[MILUSUARIOS][CARACTERESEMAIL];
char genders[MILUSUARIOS][CARACTERESNOME];
char addresses[MILUSUARIOS][CARACTERESEND];
double alturas[MILUSUARIOS];
int vacinado[MILUSUARIOS];

int numCadastros = 0;


int IDnumero() {
    return rand() % 10001 + 5;
}

int VerificarEmail(const char* email) {
    return strchr(email, '@') != NULL;
}

int VerificarGenero(const char* gender) {
    return strcmp(gender, "F") == 0 || strcmp(gender, "M") == 0 || strcmp(gender, "I") == 0;
}


int ValidacaoAltura(double altura) {
    return altura >= 1.0 && altura <= 2.0;

}

int ValidacaoVacina(int vacina) {
    return vacina == 0 || vacina == 1;
}


void adicionarusuario() {
    if (numCadastros >= MILUSUARIOS) {
        printf("Limite máximo de usuários atingido.\n");
        return;
    }

    int IDnova = IDnumero();
    ids[numCadastros] = IDnova;



    printf("Insira seu nome: ");
    fgets(names[numCadastros], sizeof(names[numCadastros]), stdin);
    names[numCadastros][strcspn(names[numCadastros], "\n")] = '\0';

    printf("Insira seu email: ");
    fgets(emails[numCadastros], sizeof(emails[numCadastros]), stdin);
    emails[numCadastros][strcspn(emails[numCadastros], "\n")] = '\0';

    while (!VerificarEmail(emails[numCadastros])) {
        printf("Email inválido. Digite novamente: ");
        fgets(emails[numCadastros], sizeof(emails[numCadastros]), stdin);
        emails[numCadastros][strcspn(emails[numCadastros], "\n")] = '\0';
    }

    printf("Qual seu sexo? (M, F ou I): ");
    fgets(genders[numCadastros], sizeof(genders[numCadastros]), stdin);
    genders[numCadastros][strcspn(genders[numCadastros], "\n")] = '\0';

    while (!VerificarGenero(genders[numCadastros])) {
        printf("Sexo inválido. Digite novamente: ");
        fgets(genders[numCadastros], sizeof(genders[numCadastros]), stdin);
        genders[numCadastros][strcspn(genders[numCadastros], "\n")] = '\0';
    }

    printf("Digite o endereço: ");
    fgets(addresses[numCadastros], sizeof(addresses[numCadastros]), stdin);
    addresses[numCadastros][strcspn(addresses[numCadastros], "\n")] = '\0';

    printf("Digite a altura (entre 1 e 2 metros): ");
    scanf("%lf", &alturas[numCadastros]);

    while (!ValidacaoAltura(alturas[numCadastros])) {
        printf("Apenas valores entre 1 e 2 metros. Digite novamente: ");
        scanf("%lf", &alturas[numCadastros]);
    }

    
    printf("Informe se o usuário está vacinado (0 = não vacinado ou 1 = vacinado): ");
    scanf("%d", &vacinado[numCadastros]);

    
    while (vacinado[numCadastros] != 0 && vacinado[numCadastros] != 1) {
        printf("Apenas 0 ou 1. Insira o valor novamente (0 = não vacinado ou 1 = vacinado): ");
        scanf("%d", &vacinado[numCadastros]);
    }


    printf("O usuário foi cadastrado com sucesso.\n");
    numCadastros++;
        printf("Seu id é: %d", IDnova);

 



 }
  int main() {
   
    char option;

    do {
        printf("Selecione uma opção:\n");
        printf("1. Adicionar usuário\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf(" %c", &option);
        getchar();

        switch (option) {
            case '1':
                adicionarusuario();
                break;
            case '0':
                printf("Fechando.\n");
                break;
            default:
                printf("Apenas 0 ou 1. Insira novamente.\n");
        }

        printf("\n");
    } while (option != '0');
  
   

    return 0;
}

 
    


    
