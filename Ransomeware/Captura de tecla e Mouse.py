#Captura de tecla e Mouse

from pynput import keyboard, mouse
import time

def on_press(key):
    print(f'{key} pressed')

def on_release(key):
    print(f'{key} released')

def on_click(x, y, button, pressed):
    print(f'Mouse click at {x},{y} with button {button}')

with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    with mouse.Listener(on_click=on_click) as mouse_listener:
        listener.join()
        mouse_listener.join()