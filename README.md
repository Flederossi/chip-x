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
- First install https://github.com/libsdl-org/SDL and put the include files in the src/include and the lib file in the src/lib folder.

- Then run in the root folder:
```
make
```

- The binary now should be in the bin/ folder.

## Comands
A simple command looks like this:
```
[hex value of the command] [hex values of the parameters]
```
Example - Set register 1 to 255:
```
00 01 FF
```
### Available commands
|Command|Parameters|Description|Example|Explanation|
|-------|----------|-----------|-------|-----------|
|**Main**|
|`00`|reg, value|- Set a register to a specific value|`00 01 FF`|- Sets the register 1 to 255|
|`01`|reg|- If register equals zero (jump to next EE if not)|`01 01 [Your code if reg equals zero] EE`|- Runs the code if register 1 equals zero|
|`02`|reg|- If register is not zero (jump to next EE if not)|`02 01 [Your code if reg is not zero] EE`|- Runs the code if register 1 is not zero|
|**Screen**|
|`10`|reg x, reg y|- Set a pixel on the screen to the current color|`10 01 02`|- Draws a pixel on the x and y value of register 1 and 2|
|`11`|reg for color|- Set the current color (0: red, 1: green, 2: bluew)|`11 01`|- Sets the current color to the value of register 1|
|`12`|--|- Clear the screen|`12`|- Clears the screen
|**Math**|
|`20`|reg 1, reg 2|- Add the value of the second register to first register|`20 01 02`|- Adds register 2 to register 1|
|`21`|reg 1, reg 2|- Subtract the value of the second register from the first register|`21 01 02`|- Subtracts register 2 from register 1|
|`22`|reg 1, reg 2|- Multiply the value of the second register with the first register|`22 01 02`|- Multiplies register 2 with register 1|
|`23`|reg 1, reg 2|- Divide the first register by the value of the second register|`23 01 02`|- Divide register 1 by register 2|
|**Keyboard**|
|--|--|- The keyboard input is written to register 255 every frame (1: up, 2: right, 3: down, 4: left)|--|--|
|**Indicators**|
|`EE`|--|- End of the if statement|`01 01 [code] EE`|- Jumps to EE when register 1 is not zero
|`FF`|--|- Start of the loop section (code before statement only executed on start, code after executed every frame)|`00 01 00 00 02 01 FF 20 01 02`|- Sets up the registers on start, then adds register 2 to register 1 every frame| 
