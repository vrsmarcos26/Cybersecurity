
/////////////////////////////////
//Brute Force apenas de números//
/////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//Variaveis//

int senha;
int tentativa;
char escolha;


int main (){
    while (1)
    {   
        printf("Digite uma senha de apenas NUMEROS POSITIVOS para eu tentar adivinha-la: ");
        scanf("%d",&senha);

        //MENSAGEM DE ERRO//
        if ( senha < 0)
        {
            printf("Voce nao pode chutar numeros negativos\n");
            continue;
        }
    
        //INICIO DO BRUTE FORCE
        printf("Vou tentar achar sua senha... \n");

        tentativa = 0;
        if(tentativa == senha){
            printf("Senha encontrada: %d\n", tentativa);
            break;
        }

        while (senha != tentativa)
        {
            
            tentativa++; 

            printf("Senha: %d\n", tentativa);
            
            //SE ENCONTRAR SENHA//
            if (tentativa == senha) 
            {
                printf("Senha encontrada: %d\n", tentativa);
                break;
            }
                     
        }

        //Se deseja testar novamente//

        printf ("Deseja jogar novamente? (y/n) R: ");
        scanf(" %c", &escolha);

        if (escolha == 'n' || escolha == 'N')
        {
            printf("Ate a proxima entao.");
            break;
        }
    }
    
}
