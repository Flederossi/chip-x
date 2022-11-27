# chip-x
A tiny fantasy console written in C using SDL2.

*It uses a minimal hex based language which let's you create small graphical applications and games.
It also includes a small keyboard engine to receive user input.*

![Alt Text](https://github.com/Flederossi/chip-x/blob/main/img/logo.png)

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

*Other platforms are added in the future.*

## Instructions
A simple instruction looks like this:
```
[hex value of the instruction] [hex values of the parameters]
```
Example - Set register 1 to 255:
```
00 01 FF
```
You can seperate each instruction and parameter as you wish but don't seperate the two hex values of the instruction or parameter itself.
### Available instructions
|Instruction|Parameters|Description|Example|Explanation|
|-----------|----------|-----------|-------|-----------|
|**Main**|
|`00`|reg, value|Set a register to a specific value|`00 01 FF`|*Sets the register 1 to 255*|
|`01`|reg|If register equals zero (jump to next EE if not)|`01 01 [Your code if reg equals zero] EE`|*Runs the code if register 1 equals zero*|
|`02`|reg|If register is not zero (jump to next EE if not)|`02 01 [Your code if reg is not zero] EE`|*Runs the code if register 1 is not zero*|
|**Screen**|
|`10`|reg x, reg y|Set a pixel on the screen to the current color|`10 01 02`|*Draws a pixel on the x and y value of register 1 and 2*|
|`11`|reg for color|Set the current color (0: red, 1: green, 2: blue)|`11 01`|*Sets the current color to the value of register 1*|
|`12`|--|Clear the screen|`12`|*Clears the screen*|
|**Math**|
|`20`|reg 1, reg 2|Add the value of the second register to first register|`20 01 02`|*Adds register 2 to register 1*|
|`21`|reg 1, reg 2|Subtract the value of the second register from the first register|`21 01 02`|*Subtracts register 2 from register 1*|
|`22`|reg 1, reg 2|Multiply the value of the second register with the first register|`22 01 02`|*Multiplies register 2 with register 1*|
|`23`|reg 1, reg 2|Divide the first register by the value of the second register|`23 01 02`|*Divide register 1 by register 2*|
|**Keyboard**|
|--|--|The keyboard input is written to register 255 every frame (1: up, 2: right, 3: down, 4: left)|--|--|
|**Indicators**|
|`EE`|--|End of the if statement|`01 01 [code] EE`|*Jumps to EE when register 1 is not zero*|
|`FF`|--|Start of the loop section (code before statement only executed on start, code after executed every frame)|`00 01 00 00 02 01 FF 20 01 02`|*Sets up the registers on start, then adds register 2 to register 1 every frame*|

## Example
*Note: The commands are only for explainatory purpose. If you want to use the program don't copy it from here, use the one without commands in example/example.cx. There is the chance that the commands distract the interpreter of the fantasy console. (This should be fixed in the future ^^)*
### Code
```
00 00 01            // Set reg 0 to 1
11 00               // Set color to reg 0 (value 1 -> green)

00 01 00            // Set reg 1 to 0
00 02 20            // Set reg 2 to 32
00 0A 01            // Set reg 10 to 1

FF                  // Start the loop section (the next part is called every frame)

12                  // Clear the screen

10 01 02            // Render pixel on posision (x: reg 1, y: reg 2)

00 03 02            // Set reg 3 to 2
21 03 FF            // Subtract the keyboard value reg from the reg 3

01 03               // If reg 3 == 0 (-> arrow right clicked)
20 01 0A            // Add reg 10 (value 1) to reg 1 (x value of the drawn pixel)
EE                  // End of the if statement
```
### Run
Run the script:
```
chip-x example.cx
```
### Result
Now a window should show up and the now rendered pixel should move to the right every time the right arrow key is pressed:

![Alt Text](https://github.com/Flederossi/chip-x/blob/main/example/result.gif)
