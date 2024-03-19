#include <stdio.h>
#include <string.h>

int main() {
    
    char senha[5];
    char tentativa[5];
    char ctrs[50];
    char alternativa = 'N'; // Inicializando com 'N'

    // Senha do usuário

    printf("Digite sua senha de 4 digitos: ");
    scanf("%s", senha);

    if(strlen(senha) != 4 ){
        printf("Digite uma senha de 4 digitos, por favor.");
        return 0;
    }

    // Adicionando características

    printf("Digite caracteristicas para quebra de senha: ");
    scanf("%s", ctrs);

    while (alternativa == 'N' || alternativa == 'n') {
        printf("Apenas essas caracteristicas? (Y/N) ");
        scanf(" %c", &alternativa);

        if (alternativa == 'Y' || alternativa == 'y') {
            break;
        }

        printf("Digite mais caracteristicas: ");
        char novas_caracteristicas[50];
        scanf("%s", novas_caracteristicas);
        strcat(ctrs, novas_caracteristicas);
    }

    // Iniciando Brute force
    printf("Vou tentar adivinhar sua senha...\n");


    for(int c1 = 0; c1 < strlen(ctrs); c1++){
        for(int c2 = 0; c2 < strlen(ctrs); c2++){
            for(int c3 = 0; c3 < strlen(ctrs); c3++){
                for(int c4 = 0; c4 < strlen(ctrs); c4++){
                    tentativa[0] = ctrs[c1];
                    tentativa[1] = ctrs[c2];
                    tentativa[2] = ctrs[c3];
                    tentativa[3] = ctrs[c4];
                    tentativa[4] = '\0';
                    printf("Tentativa: %s\n", tentativa);
                    if (strcmp(tentativa, senha) == 0) {
                        printf("Sua senha = %s\n", tentativa);
                        return 0;
                    }
                }
            }
        }
    }

    printf("Nao consegui encontrar sua senha.");
    return 0;
}