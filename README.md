# chip-x
A tiny fantasy console written in C using SDL2.

It uses a minimal hex based language which let's you create small graphical applications and games.
It also includes a small keyboard engine to receive user input.

## Usage
```
chip-x [hex-file]
```

## Compile
### Windows
First install https://github.com/libsdl-org/SDL and put the include files in the src/include and the lib file in the src/lib folder.
Then run
```
make
```
in the root folder.
The binary now should be in the bin/ folder.

## Comands
A simple command looks like this:
```
[hex value of the command] [hex values of the parameters]
```
Example - Set register 1 to 255:
```
00 01 FF
```
