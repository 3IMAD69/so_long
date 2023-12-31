
# So_long | 1337 Bengurir | 125/125 

This project is a small 2D game designed to help you work with textures, sprites, and basic gameplay elements. 
The goal is to create a 2D game using the MiniLibX library, focusing on window management, event handling, colors, textures and animations . 

![Logo](https://github.com/3IMAD69/so_long/assets/83024321/54dfadb7-273d-426f-bd30-02caf847e926)

**And Thanks for All The Dolphins :trollface::**


## Norms
The code in this repository may appear unconventional or different from typical coding practices. This is intentional and follows the coding standards and norms set by my school.

## The Goal of The Game
You play as a brave samurai facing off against dolphins. Your mission: defeat the dolphins in combat, collect all the coins scattered across the battleground, and make a daring escape before a giant wave hits.

## Map Rules
Map components: walls, collectibles, free space, exit, starting position.\
Map composed of `0`, `1`, `C`, `E` , `P` characters.\
Rectangular map enclosed by walls.\
Validate map for duplicates, valid path, and completeness.\
Other characters will be added in bonus to represent the enemy and traps .

## Controls:

| Key | Action |
|---|---|
| <kbd>W</kbd>, | Move up |
| <kbd>S</kbd>, | Move down |
| <kbd>A</kbd>, | Move left |
| <kbd>D</kbd>, | Move right |
| <kbd>↑</kbd>, | Attack up |
| <kbd>↓</kbd>, | Attack down |
| <kbd>←</kbd> | Attack left |
| <kbd>→</kbd>, | Attack right |
| <kbd>ESC</kbd>, | Leave The Game |



## Installation

This project was done on macOS Catalina (Version 10.15.7), OpenGL and AppKit is required .

```bash
  git clone https://github.com/3IMAD69/so_long.git
  cd so_long
  make
  ./so_long mandatory/maps/map1337.ber
```
For Bonus 

```bash
  make bonus
  ./so_long_bonus bonus/maps/map1337.ber
```


    
