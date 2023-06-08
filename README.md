# BlockBreacker (C edition)
A very simple and crude clone of Breakout game written in C using SDL2

# Controls
## Game
`Arrow keys` to move, `spacebar` to launch the ball
## Editor
To launch editor run the game with `--ed` flag. Once you close the editor window map key value will be printed to the standart output(so preferably run this in the terminal if editor is important)
`Left click` places a block, `Right click` removes a block

# Building
This project requires installation of [SDL2](https://www.libsdl.org/) and [SDL_Mixer](https://github.com/libsdl-org/SDL_mixer).

If you wish to change configuration edit constants in `CMakeLists.txt`.
## Limitations
Total block size must be smaller then 64 as the type that holds map info can only hold 64 bits. This __can__ be disabled by using CMake option feature(off by default)

# Details
## Memory
This project avoids use of `malloc` and `calloc` in favour of using compile time constants defined via CMake configuration file
## Physics
The physics are not well done and ball can behave quite weirdly, my goal was not to make an accurate recreation of the original arcade game so i chose to left it as it is

![2023-06-08_22-40](https://github.com/MetalPizzaCat/BlockBreacker_C/assets/36876492/0f7c9d53-bb32-4150-b139-92142a321b15)
