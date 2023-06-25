# Cub3D

Welcome to Cub3D! This project aims to create a 3D maze game using the raycasting technique. In this game, players navigate through a maze-like environment and interact with various elements.

## Features

- **Raycasting Engine**: Utilize a raycasting technique to create a 3D rendering of the game world.
- **Interactive Maze**: Navigate through a maze-like environment filled with walls, doors, collectibles, and enemies.
- **Textured Walls**: Render textured walls to enhance the visual experience.
- **Sprites**: Implement sprites to represent collectibles, enemies, and other interactive elements.
- **Player Controls**: Allow players to move within the game world and interact with objects.
- **Minimap**: Display a minimap for players to navigate and track their progress.
- **Game Elements**: Incorporate additional game elements such as bonuses, power-ups, and traps.

## Installation

1. Clone this GitHub repository to your local machine:

  git clone https://github.com/Cavallucci/cub3d.git

2. Navigate to the project directory:

  cd cub3d

3. Build the project using the provided Makefile:

  make

4. Run the game:

  ./cub3D map.cub

## Usage

Once the game is running, you can use the following controls:

- **W**: Move forward
- **S**: Move backward
- **A**: Move left
- **D**: Move right
- **Left Arrow**: Rotate left
- **Right Arrow**: Rotate right
- **Esc**: Exit the game

Explore the maze, collect items, and interact with the environment to progress in the game.

## Map Configuration

To create custom game maps, you can modify the `map.cub` file following the provided format. The file consists of various parameters such as resolution, textures, colors, and the map layout. Refer to the project documentation or provided samples for more details on map configuration.

## Credits

Cub3D is brought to you by the following contributors:

- Paul Guignier
- Laura Cavallucci

We would like to express our gratitude to the open-source community for their valuable libraries, resources, and inspiration.

For more information on how to play the game and further technical details, please refer to the [project's wiki](https://github.com/Cavallucci/cub3d/wiki).
