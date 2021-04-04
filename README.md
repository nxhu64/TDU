# Teardown Unleashed
TDU is an open source internal "tool" for testing / developing Teardown stuff, it should be a decent enough reference if you want to make your own lua functions to access internal functions, APIs, or just your own mod in general.
There's gonna be a lot of spaghetti code in here, as it's my first "big" project with reverse engineering and C++.

###### (basically just random code I've written while reversing Teardown)

## Features
* Lua executor, to run scripts while playing
* Hooks placed so that you can register your own functions
* Ability to load and spawn voxels through scripts
* A loadbuffer hook, if you want to replace the game's scripts with your own, without the need of replacing the actual files, or if you want to prevent them from loading altogether.
* Noclip, for messing around and exploring maps.
* A couple debug features that were in the original debug menu (render targets, draw bounds, draw bodies).
* Reversed entity classes, although, i suggest you get those [here](https://github.com/SK83RJOSH/Teardown).
* A "cheat" menu, for debugging purposes, with features like god, no recoil, etc

## Installation
Grab the opengl32 dll from releases, and paste it on your game's root directory (where Teardown.exe is located)

## Key binds
* Insert to open the menu
* N to toggle noclip
* (While noclipping) Shift to go fast, Ctrl to go slow

## Build requirements
* [MS Detours](https://github.com/microsoft/Detours)
* [GLEW](http://glew.sourceforge.net/)

## Building:
1. Clone the repository **`git clone --recurse-submodules https://github.com/nxhu64/TDU`**
2. Open TDU.sln on Visual Studio (TDU was coded on VS 2019, there's no guarantee it'll work on any older versions without changing some stuff)
3. On project properties->Debugging set the Command argument to your version of Teardown (SteamStub has anti-debugging, you'll have to figure how to circumvent that on your own) and set the working directory to Teardown's root directory (where the exe is located)
4. On VC++ Directories set your include/library directories for GLEW and MS Detours
5. Everything should be ready to build.

## Special thanks to
* [SK83RJOSH](https://github.com/SK83RJOSH) | Seriously, [this](https://github.com/SK83RJOSH/Teardown) helped me so much, thank you
* [Xorberax](https://github.com/ss-gnalvesteffer)
* [Nymda](https://github.com/nymda)

Thank you so much for your help, knowledge, ideas and inspiration
