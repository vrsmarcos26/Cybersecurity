////////////////////////////////
//Brute Force de ate 4 digitos//
////////////////////////////////

#include <stdio.h>
#include <string.h>

int main() {
    char senha[5]; // 4 caracteres + terminador nulo
    char tentativa[5]; // 4 caracteres + terminador nulo
    char charset[] = "\0 0123456789";
    
    printf("Digite uma senha, com apenas NUMEROS, de ate 4 digitos: ");
    scanf("%s", senha);

    if(strlen(senha) > 5){
        printf("Escreva uma senha de so ate 4 digitos, por favor.");
        return 0;
    }
    
    printf("Vou tentar adivinhar sua senha ...\n");

    for(int c1 = 0; c1 < 13; c1++) {
        for(int c2 = 0; c2 < 13; c2++) {
            for(int c3 = 0; c3 < 13; c3++) {
                for(int c4 = 0; c4 < 13; c4++) {
                    tentativa[0] = charset[c1];
                    tentativa[1] = charset[c2];
                    tentativa[2] = charset[c3];
                    tentativa[3] = charset[c4];
                    tentativa[4] = '\0'; // Adiciona o terminador nulo
                    printf("Tentativa: %s\n", tentativa);
                    if (strcmp(tentativa, senha) == 0) {
                        printf("Sua senha = %s\n", tentativa);
                        return 0;
                    }
                }
            }
        }
    }

    printf("Não consegui adivinhar sua senha.\n");
    return 0;
}
