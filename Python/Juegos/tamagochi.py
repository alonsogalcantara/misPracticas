import random
import time
import os


class Tamagotchi:
    def __init__(self):
        self.name = ""
        self.age = 0
        self.hunger = 0
        self.happiness = 0
        self.health = 100
        self.normal_frame = '''
        (__)
        (oo)
   /------\/    
 * / |    ||
    ~~   ~~
    ~~   ~~
    ~~   ~~'''
        self.eating_frame = '''
        (__)
        (oo)
/------\/    
* / |    ||
    ~~   ~~    @@@@
    ~~   ~~   ()()
    ~~   ~~   VVVV'''
        self.sleep_frame = '''
        (__)
        (oo)
/------\/    
* / |    ||
    ~~   ~~   ZzZz
    ~~   ~~
    ~~   ~~
    ~~   ~~'''

        self.play_frame = '''
        (__)
        (oo)
/------\/    
* / |    ||
    ~~   ~~   /|'\'\
    ~~   ~~  / '\
    ~~   ~~
    ~~   ~~'''

    def __str__(self):
        '''
        return: status del animalito
        '''
        if self.hunger > 50:
            print(f"- {self.name} tiene hambre")

        if self.happiness > 45:
            print(f"- {self.name} esta molesto")

        return f"{self.name} is {self.age} years old. Hunger: {self.hunger}, Happiness: {self.happiness}, Health: {self.health}"

    def feed(self):
        '''
        Alimenta al animalito
        hunger: decrementa entre 5 y 10pts
        health: incrementa entre 1 y 10pts
        '''
        self.hunger -= random.randint(5, 10)
        self.health += random.randint(10, 20)
        print(self.eating_frame)

    def play(self):
        '''
        Juegas con el animalito
        happiness: incrementa entre 6 y 9pts
        hunger: decrementa entre 4 y 8pts
        '''
        self.happiness += random.randint(6, 9)
        self.hunger -= random.randint(4, 8)
        print(self.play_frame)

    def sleep(self):
        '''
        Duerme al animalito
        hunger: incrementa entre 5 y 8pts
        happiness: incrementa entre 4 y 6
        hralth: decrementa entre 5 y 10
        '''
        self.hunger += random.randint(5, 8)
        self.happiness += random.randint(4, 6)
        self.health -= random.randint(5, 10)
        print(self.sleep_frame)

    def tick(self):
        '''
        Marca el tiempo por cada decision
        hunger: aumenta entre 1 y 10
        happiness: decrementa entre 1 y 5
        health: decrementa entre 1 y 4, sin embargo si los stats de hunger o happiness estan altos su valor incrementa de entre 5 y 9pts
        '''
        self.hunger += random.randint(1, 10)
        self.happiness -= random.randint(1, 5)

        if self.hunger > 80 or self.happiness > 78:
            self.health -= random.randint(5, 9)
        else:
            self.health -= random.randint(1, 4)

        # Si la salud es mayor a 100 esta no aumentara mas.
        if self.health > 100:
            self.health = 100

    def is_alive(self):
        return self.health > 0


def main():
    while True:
        # Create a new Tamagotchi
        tamagotchi = Tamagotchi()

        # Give the Tamagotchi a name
        tamagotchi.name = input("What is your Tamagotchi's name? ")

        # Play with the Tamagotchi
        while tamagotchi.is_alive():
            print(tamagotchi)

            list_options = ['feed', 'play', 'sleep']

            action = random.choice(list_options)

            print(f'\nElegiste: {action}')
            if action == "feed":
                tamagotchi.feed()
            elif action == "play":
                tamagotchi.play()
            elif action == "sleep":
                tamagotchi.sleep()
            elif action == "quit":
                break

            # Let the Tamagotchi age
            tamagotchi.age += 1
            tamagotchi.tick()

            time.sleep(1)
            os.system("cls")

        if ~tamagotchi.is_alive():
            print(f"{tamagotchi.name} dies at the age of {tamagotchi.age} years")
        
        if ('n' in input('Volver a intentar?: S/n\n').lower()):
            break
        



if __name__ == "__main__":
    main()
