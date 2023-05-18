import random

class Tamagotchi:
    def __init__(self):
        self.name = ""
        self.age = 0
        self.hunger = 0
        self.happiness = 0
        self.health = 100

    def __str__(self):
        '''
        return: status del animalito
        '''

        if self.hunger > 50:
            print(f"{self.name} tiene hambre")

        if self.happiness > 40 and self.happiness < 70:
            print(f"{self.name} esta molesto")

        return f"\n{self.name} is {self.age} years old. Hunger: {self.hunger}, Happiness: {self.happiness}, Health: {self.health}"

    def feed(self):
        '''
        Alimenta al animalito
        hunger: decrementa entre 5 y 10pts
        health: incrementa entre 1 y 10pts
        '''
        self.hunger -= random.randint(5, 10)
        self.health += random.randint(10, 20)

    def play(self):
        '''
        Juegas con el animalito
        happiness: incrementa entre 6 y 9pts
        hunger: decrementa entre 4 y 8pts
        '''
        self.happiness += random.randint(6, 9)
        self.hunger -= random.randint(4, 8)

    def sleep(self):
        '''
        Duerme al animalito
        hunger: incrementa entre 5 y 8pts
        happiness: incrementa entre 4 y 9
        hralth: decrementa entre 5 y 10
        '''
        self.hunger += random.randint(5, 8)
        self.happiness += random.randint(4, 9)
        self.health -= random.randint(5, 10)

    def tick(self):
        '''
        Marca el tiempo por cada decision
        hunger: aumenta entre 1 y 10
        happiness: decrementa entre 1 y 5
        health: decrementa entre 1 y 7
        '''
        self.hunger += random.randint(1, 10)
        self.happiness -= random.randint(1, 5)
        self.health -= random.randint(5, 10)

        # Si la salud es mayor a 100 esta no aumentara mas.
        if self.health > 100:
            self.health = 100

    def is_alive(self):
        return self.health > 0

def main():
    # Create a new Tamagotchi
    tamagotchi = Tamagotchi()

    # Give the Tamagotchi a name
    tamagotchi.name = input("What is your Tamagotchi's name? ")

    # Play with the Tamagotchi
    while tamagotchi.is_alive():
        print(tamagotchi)
        action = input("What do you want to do? (feed, play, sleep, or quit): ")

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

    if tamagotchi.is_alive():
        print("Your Tamagotchi is alive!")
    else:
        print("Your Tamagotchi died.")

if __name__ == "__main__":
    main()
