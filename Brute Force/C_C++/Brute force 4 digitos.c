////////////////////////////////
//Brute Force de ate 4 digitos//
////////////////////////////////

#include <stdio.h>
#include <string.h>

int main() {
    //Variaveris/arrays/vetores//

    char senha[5]; 
    char tentativa[5]; 
    char crts[] = "\0 0123456789";

    //PERGUNTA A SENHA
    
    printf("Digite uma senha, com apenas NUMEROS, de ate 4 digitos: ");
    scanf("%s", senha);

    if(strlen(senha) > 5){
        printf("Escreva uma senha de so ate 4 digitos, por favor.");
        return 0;
    }
    
    printf("Vou tentar adivinhar sua senha ...\n");

    //BRUTE FORCE//

    for(int c1 = 0; c1 < 13; c1++) {
        for(int c2 = 0; c2 < 13; c2++) {
            for(int c3 = 0; c3 < 13; c3++) {
                for(int c4 = 0; c4 < 13; c4++) {
                    tentativa[0] = crts[c1];
                    tentativa[1] = crts[c2];
                    tentativa[2] = crts[c3];
                    tentativa[3] = crts[c4];
                    tentativa[4] = '\0'; // Nulo é obrigado para dizer que acabou a array de strings
                    printf("Tentativa: %s\n", tentativa);

                    // usamos "strcmp" para comparar duas strings
                    // "==0" diz que são exatamente iguais.
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
