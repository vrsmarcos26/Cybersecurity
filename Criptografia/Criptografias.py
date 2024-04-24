#CRIAÇÃO DE PROGRAMA DE DESCRIPTOGRAFIA/CRIPTOGRAFIA

import base64
import base58

def CR_Cifra_De_Cesar(mensagem, chave):
    resultado = ""
    chave = int(chave)
    for char in mensagem:
        if char.isalpha():
            shift = chave % 26
            if char.islower():
                resultado += chr((ord(char) - ord('a') + shift) % 26 + ord('a'))
            else:
                resultado += chr((ord(char) - ord('A') + shift) % 26 + ord('A'))
        else:
            resultado += char
    return resultado

def CR_ASCII_Bin_Dec_Hex_Oct(mensagem):
    ascii_values = [ord(char) for char in mensagem]
    binary = ' '.join(format(val, 'b') for val in ascii_values)
    hexadecimal = ' '.join(format(val, 'x') for val in ascii_values)
    octal = ' '.join(format(val, 'o') for val in ascii_values)
    decimal = ' '.join(str(val) for val in ascii_values)    
    return f"Binary: {binary}\nDecimal: {decimal}\nHexadecimal: {hexadecimal}\nOctal: {octal}"

def CR_Atbash(mensagem):
    resultado = ""
    for char in mensagem:
        if char.isalpha():
            if char.islower():
                resultado += chr(ord('z') - (ord(char) - ord('a')))
            else:
                resultado += chr(ord('Z') - (ord(char) - ord('A')))
        else:
            resultado += char
    return resultado

def CR_Base_32_58_64_85(mensagem):
    enc_base64 = base64.b64encode(mensagem.encode()).decode()
    enc_base32 = base64.b32encode(mensagem.encode()).decode()
    enc_base85 = base64.b85encode(mensagem.encode()).decode()
    enc_base58 = base58.b58encode(mensagem.encode()).decode()
    return f"Base32: {enc_base32}\nBase58: {enc_base58}\nBase64: {enc_base64}\nBase85: {enc_base85}"

def DesCR_Cifra_De_Cesar(mensagem, chave):
    return CR_Cifra_De_Cesar(mensagem, -int(chave))

def DesCR_ASCII_Bin_Dec_Hex_Oct(mensagem, formato):
    
    chars = mensagem.split()
    if formato == 'binary':
        dec = ''.join([chr(int(c, 2)) for c in chars])
    elif formato == 'decimal':
        dec = ''.join([chr(int(c)) for c in chars])
    elif formato == 'hexadecimal':
        dec = ''.join([chr(int(c, 16)) for c in chars])
    elif formato == 'octal':
        dec = ''.join([chr(int(c, 8)) for c in chars])
    else:
        return "Formato desconhecido"
    
    return dec

def DesCR_Base_32_58_64_85(mensagem):
    try:
        dec_base64 = base64.b64decode(mensagem).decode()
    except:
        dec_base64 = "Invalid Base64 string"
    try:
        dec_base32 = base64.b32decode(mensagem).decode()
    except:
        dec_base32 = "Invalid Base32 string"
    try:
        dec_base85 = base64.b85decode(mensagem).decode()
    except:
        dec_base85 = "Invalid Base85 string"
    try:
        dec_base58 = base58.b58decode(mensagem).decode()
    except:
        dec_base58 = "Invalid Base58 string"
    return f"Base32: {dec_base32}\nBase58: {dec_base58}\nBase64: {dec_base64}\nBase85: {dec_base85}"


print("Esse é um programa de criptografias.")
while True:
    crip_decoder = int(input("\nCaso queira criptografar (1) ou descriptografar (2): "))
    opções = int(input("\nEscolha o tipo de criptografia:\n1. Cifra de César\n2. ASCII/Bin/Dec/Hex/Oct\n3. Atbash\n4. Base32/58/64/85\n\nR: "))
    x = input("\nDigite sua mensagem:\n")

    if crip_decoder == 1:
        if opções == 1:
            chave = input("Quantas letras você quer que desloque?: ")
            print("\nSua mensagem criptografada fica: \n" + CR_Cifra_De_Cesar(x, chave))
        elif opções == 2:
            print("\nSua mensagem criptografada fica: \n" + CR_ASCII_Bin_Dec_Hex_Oct(x))
        elif opções == 3:
            print("\nSua mensagem criptografada fica: \n" + CR_Atbash(x))
        elif opções == 4:
            print("\nSua mensagem criptografada fica: \n" + CR_Base_32_58_64_85(x))
    elif crip_decoder == 2:
        if opções == 1:
            chave = input("Quantas letras foram deslocadas na criptografia?: ")
            print("\nSua mensagem descriptografada fica: \n" + DesCR_Cifra_De_Cesar(x, chave))
        elif opções == 2:
            formato = input("Informe o formato (binary, decimal, hexadecimal, octal): ")
            print("\nSua mensagem descriptografada fica: \n" + DesCR_ASCII_Bin_Dec_Hex_Oct(x, formato))
        elif opções == 3:
            print("\nSua mensagem descriptografada fica: \n" + CR_Atbash(x))
        elif opções == 4:
            print("\nSua mensagem descriptografada fica: \n" + DesCR_Base_32_58_64_85(x))

    reboot = input("\nDeseja fazer outra operação? (y/n): ")
    if reboot.lower() == 'n':
        break
        