import sys
import pygame
import numpy as np
import time

pygame.init()

size = width, height = 800, 800

bg = [25, 25, 25]

nxC = 40
nyC = 40

dimCW = (width - 1) / nxC

dimCH = (height - 1) / nyC

screen = pygame.display.set_mode(size)
screen.fill(bg)
gameState = np.zeros((nxC, nyC))

gameState[1, 1] = 1
gameState[2, 2] = 1
gameState[2, 3] = 1
gameState[1, 3] = 1
gameState[0, 3] = 1

# Control de la ejecuacion
pauseExect = False

while True:
    new_gameState = np.copy(gameState)
    screen.fill(bg)
    # time.sleep(0.5)

    # Eventos de teclado y raton
    ev = pygame.event.get()

    for event in ev:
        if event.type == pygame.KEYDOWN:
            pauseExect = not pauseExect

        # Detecata si se presiona el raton
        mouseClick = pygame.mouse.get_pressed()

        if sum(mouseClick) != 0:
            posX, posY = pygame.mouse.get_pos()
            celX, celY = int(np.floor(posX / dimCW)
                             ), int(np.floor(posY / dimCH))
            new_gameState[celX, celY] = not mouseClick[2]

    # Iniciar el juego
    for y in range(0, nyC):
        for x in range(0, nxC):
            if not pauseExect:
                # Numero de vecinos
                n_neigh = gameState[(x - 1) % nxC, (y - 1) % nyC] +\
                    gameState[(x) % nxC, (y - 1) % nyC] +\
                    gameState[(x + 1) % nxC, (y - 1) % nyC] +\
                    gameState[(x - 1) % nxC, (y) % nyC] +\
                    gameState[(x + 1) % nxC, (y) % nyC] +\
                    gameState[(x - 1) % nxC, (y + 1) % nyC] +\
                    gameState[(x) % nxC, (y + 1) % nyC] +\
                    gameState[(x + 1) % nxC, (y + 1) % nyC]

                # regla 1
                if gameState[x, y] == 0 and n_neigh == 3:
                    new_gameState[x, y] = 1
                # regla 2
                elif gameState[x, y] == 1 and (n_neigh < 2 or n_neigh > 3):
                    new_gameState[x, y] = 0

            poly = [(round((x) * dimCW), round(y * dimCH)),
                    (round((x + 1) * dimCW), round(y * dimCH)),
                    (round((x + 1) * dimCW), round((y + 1) * dimCH)),
                    (round((x) * dimCW), round((y + 1) * dimCH))]

            if new_gameState[x, y] == 0:
                pygame.draw.polygon(screen, (128, 128, 128), poly, 1)
            else:
                pygame.draw.polygon(screen, (255, 255, 255), poly, 0)

    gameState = np.copy(new_gameState)
    time.sleep(0.1)
    pygame.display.flip()
