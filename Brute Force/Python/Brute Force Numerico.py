"""
=================================
==Brute Force apenas de números==
=================================
"""

while True:
    senha = int(input("Digite uma senha de apenas NUMEROS POSITIVOS para eu tentar adivinha-la: "))

    # MENSAGEM DE ERRO
    if senha < 0:
        print("Você não pode digitar números negativos")
        continue

    # INICIO DO BRUTE FORCE
    print("Vou tentar achar sua senha...")

    tentativa = 0

    while senha != tentativa or senha == 0:

        if senha == 0:
            print("Senha encontrada:", 0)
            break

        tentativa += 1

        print("Senha:", tentativa)

        # SE ENCONTRAR SENHA
        if tentativa == senha:
            print("Senha encontrada:", tentativa)
            break

    # Se deseja testar novamente
    escolha = input("Deseja jogar novamente? (y/n) R: ")

    if escolha.lower() == 'n':
        print("Até a próxima então.")
        break
