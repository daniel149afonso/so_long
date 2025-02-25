so_long

so_long is a small 2D game project developed using MiniLibX. The game involves navigating through a map filled with walls, collectibles, and an exit. You control the player and must collect all items to unlock the exit and finish the level.
Table of Contents

    Features
    Requirements
    Installation
    Usage
    Controls
    Allowed Functions
    Project Structure
    Credits

Features

    Navigate a 2D grid-based map.
    Collect all collectibles to open the exit.
    Collision detection with walls.
    Dynamic map display and movement animation.
    Error handling for invalid maps (empty maps, invalid characters, duplicate entities, etc.).

Requirements

    Operating System: Linux or macOS (with X11 support on Linux).
    Compiler: GCC.
    Libraries:
        MiniLibX
        Standard C library functions (open, close, read, write, malloc, free, perror, strerror, exit)
        Math library (compile with -lm)
        Your custom ft_printf (or equivalent)
    Make: A valid Makefile is provided.

Installation

    Clone the repository:

git clone <repository_url>
cd so_long

Build the project:

Simply run:

make

This command compiles the project and builds the executable (so_long).

Clean build files (optional):

To remove object files:

make clean

To remove the executable as well:

make fclean

To recompile everything from scratch:

    make re

Usage

Once compiled, run the game by passing a map file (with the .ber extension) as an argument:

./so_long path/to/your_map.ber

If the map is invalid (e.g., missing, empty, or containing errors), the game will output an error message and exit.
Controls

    Move Up: W or Arrow Up
    Move Left: A or Arrow Left
    Move Right: D or Arrow Right
    Move Down: S or Arrow Down
    Exit Game: ESC

Allowed Functions

For this project, you are permitted to use:

    System calls: open, close, read, write
    Memory management: malloc, free
    Error handling: perror, strerror, exit
    Math library functions: (link with -lm)
    MiniLibX functions: (all available functions to create windows, handle images, events, etc.)
    Custom functions: ft_printf and any equivalent functions that you have implemented

Ensure you do not use any non-authorized functions.
Project Structure

    srcs/ – Contains all the source files.
    maps/ – Contains test map files (valid and invalid).
    Libft/ – Your custom libft library.
    minilibx-linux/ (or minilibx_mac/) – The MiniLibX library.
