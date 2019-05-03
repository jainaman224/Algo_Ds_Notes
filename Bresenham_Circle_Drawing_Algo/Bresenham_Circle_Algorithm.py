# Install pygame library
from pygame import gfxdraw
import sys, pygame

# Plotting the Circle of given radius
def circle(radius, offset):
    x, y = 0, radius
    plotCircle(x, y, radius, offset)

# Plotting Symmetrical points or pixels
def symmetry_points(x, y, offset, screen):
    gfxdraw.pixel(
        screen, x + offset, y + offset, (255, 255, 255)
    )
    gfxdraw.pixel(
        screen, -x + offset, y + offset, (255, 255, 255)
    )
    gfxdraw.pixel(
        screen, x + offset, -y + offset, (255, 255, 255)
    )
    gfxdraw.pixel(
        screen, -x + offset, -y + offset, (255, 255, 255)
    )
    gfxdraw.pixel(
        screen, y + offset, x + offset, (255, 255, 255)
    )
    gfxdraw.pixel(
        screen, -y + offset, x + offset, (255, 255, 255)
    )
    gfxdraw.pixel(
        screen, y + offset, -x + offset, (255, 255, 255)
    )
    gfxdraw.pixel(
        screen, -y + offset, -x + offset, (255, 255, 255)
    )
    pygame.display.flip()

# Drawing that circle with symmetrical pixels
def plotCircle(x, y, radius, offset):
    d = 5 / 4.0 - radius
    # setting screen size
    screen = pygame.display.set_mode((400, 400))
    screen.fill((0, 0, 0))
    pygame.display.flip()
    symmetry_points(x, y, radius + offset, screen)
    while x < y:
        if d < 0:
            x += 1
            d += 2 * x + 1
        else:
            x += 1
            y -= 1
            d += 2 * (x - y) + 1
        symmetry_points(x, y, radius + offset, screen)

def main():
    # Initializing pygame window
    pygame.init()

    # Taking entries from User
    radius = int(input("Enter radius: "))
    offset = int(input("Enter offset: "))

    # Calling Out The function
    circle(
        radius, offset
    )  # circle(radius,<offset from edge>)
    pygame.display.flip()

    while 1:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()

# Driver Function
if __name__ == "__main__":
    main()
'''
   OUTPUT :- https://imgur.com/96w3MPE

'''
