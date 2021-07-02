#Declaracion de bibliotecas
import threading
import time
from pynput.mouse import Button, Controller
from pynput.keyboard import Listener, KeyCode

#Declaracion de Variables Globales
DELAY = 0.001
BUTTON = Button.left
START_STOP_KEY = KeyCode(char='s')
EXIT_KEY = KeyCode(char='e')

#Imprime instrucciones de usos
print("S para iniciar\nS para detener\nE para salir\nCon un DELAY de "+str(DELAY)+"s\n")

class ClickMouse(threading.Thread):
    """In this class is defined all the functions to use"""
    def __init__(self, DELAY, BUTTON):
        super(ClickMouse, self).__init__()
        self.delay = DELAY
        self.button = BUTTON
        self.running = False
        self.program_running = True

    def start_clicking(self):
        """This function starts the program"""
        self.running = True
        print("Empezaste a clikear")

    def stop_clicking(self):
        """This function stops the program"""
        self.running = False
        print("Dejaste de clikear")

    def exit(self):
        """This function end the script"""
        self.stop_clicking()
        self.program_running = False
        print("Saliste...")

    def run(self):
        """This function run the script"""
        while self.program_running:
            while self.running:
                mouse.click(self.button)
                time.sleep(self.delay)
            time.sleep(0.1)

#Inicializo las bibliotecas exportadas
mouse = Controller()
click_thread = ClickMouse(DELAY, BUTTON)
click_thread.start()

def on_press(key):
    """This function recive the key pressed"""
    if key == START_STOP_KEY:
        if click_thread.running:
            click_thread.stop_clicking()
        else:
            click_thread.start_clicking()
    elif key == EXIT_KEY:
        click_thread.exit()
        listener.stop()

with Listener(on_press=on_press) as listener:
    listener.join()