# Raycasting in C

So I'm an aspiring game developer and enjoy programming things from scratch to learn the underlying concepts and patterns that are at work in higher level tools. Also C is a language I learned for a while and then dropped, so I wanted to go back to it.

My idea is to learn by doing, I really like wofenstein and doom, so I'm going to try and implement a raycasting rendering engine with C and maybe move it to C++ at a later stage if this becomes an actual engine for a game (which is an objective but not a main one), and learn C and low level game programming in the way.

## Features

For now I'm working on getting to understand the SDL 2 library, it has software rendering for 2D with hardware accelerated graphics too, but It's my goal to eventually move everything to OpenGL when I can.

As of the creation of this document, I have implemented a simple system to render a map saved as an array of strings, with a method to get variable framerate with a deltaTime variable to calculate physics or general game logic to be tied to the FPS you are getting thanks to SDL's step system.

There is also a simple input system which needs to be refactored into it's own files, but for now, it gets the user input, and sets flags in an Input struct, to check if direction keys are pressed. That goes into a Player struct, which holds data for the player position on screen and how to draw it.

### To Do

There is a lot to do, but in the meantime, my goal is to implement a 2D version of the engine, that can cast rays of a certain lenght, and for the rays to be blocked by walls to not draw anything not visible for the player. I have to change the movement of the player to allow rotation, and "DOOM" like movement.

That's all, if you are interested in trying it out, you just need to have the SDL2 library installed, or link it to the compiler. If you are using MSYS2 UCRT, you can compile using the Makefile.

If you are interested in how I set this up to develop on windows since I'm kinda stuck on it thanks to my institute, you can check out a gist I made with how I set it up [here](https://gist.github.com/Dani-0TB/5e35d3ba8a54616398f87ecc6d677bed)


