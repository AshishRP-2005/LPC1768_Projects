# Button Debouncing
- From our perspective we might be clicking the button once but from the perspective of the microcontroller which is taking thousands of samples in a second the button might have been clicked multiple times
- Removing this Confusion from the microcontroller so that it can only take one input when a button is presses is callled Debouncing
    - There are 2 types of Debouncing
        - Hardware - adding pull up/ pull down resistor'
        - Software - using a timing window for the input
- I am using the joystick present on the board to illustrate button debouncing. Each joystick press will turn on a LED.
    - Ex. Pressing up turns on led 2

### I am doing this in two parts
- In the 1st part 
    - I am setting up the code where when i press a button a particular led lights up
    - The code specifics i will comment at the end of the code block
- In the 2nd part 
    - The code will be implemented with the debouncing mechanism

## Things i leart through this experiment
### Summarized in a sentence
- Pull-up resistor keeps the pin at high when no input signal is given to the pin preventing a floating pin situation
- Pull-down resistor keeps the pin at low when no input signal is given to prevent floating pin
- `FIOPIN` is used in LPC to get the info if the pin is high or low
- `typedef` is used to give an alias, Instead of using `enum system_state STATE;` i can just use `system_state STATE;`
- `enum` -> Enumeration, It gives integer values to specified words. Here i can say IDLE instead of 0, UP instead of 1 and vice-versa
- `switch(condition)` is used when we just have to compare the value and bring an output
- How to call a function and pass arguments to it
- I also learnt about Impedance and how it is the resistance to the flow of current in an AC circuit, and that it is the sum of DC resistance and Reactance