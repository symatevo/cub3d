## Summary

In this project, you are required to create a 3D maze game using the raycasting technique. The game should render a first-person perspective of a maze-like world and allow the player to navigate through it. You'll need to implement collision detection, texturing, and other graphics-related functionalities.

## Skills to Learn

- Graphics Programming
- Raycasting Technique
- 2D and 3D Rendering
- Game Development Concepts
- Maze Generation

## The "Cub3D" Program

### Usage

```bash
./cub3D path_to_map.cub
```

### Description

The "Cub3D" program reads a configuration file (map.cub) that describes the maze and various settings for the game. The program then generates a window with a first-person view of the maze and allows the player to navigate through it.

The configuration file (map.cub) should contain information about the maze layout, textures, colors, and other settings related to the game.

## Project Constraints

- The game should render a first-person view using the raycasting technique.
- The maze and other textures should be read from a configuration file.
- The player should be able to move through the maze using keyboard inputs.
- The game should implement collision detection with walls and other obstacles.
- The game should include texturing for walls and sprites.
- The program should support basic graphics functionalities like floor and ceiling coloring.
- The game window should have smooth movement and be responsive to user inputs.

## Example Usage

```bash
$> ./cub3D map.cub
```

# How to run it

Using make will build the executable "./cub3D". To run it enter a map from "maps" folder.
For example you can simply run ./cub3d maps/1.cub
Use W A S D to move in maze and left right keys for rotation.

# How it looks like

![map2.cub](https://media.discordapp.net/attachments/937622316433686548/1026168431831171193/Screen_Shot_2022-10-02_at_8.10.34_PM.png?width=1486&height=1177)


# Useful links

https://lodev.org/cgtutor/raycasting.html
