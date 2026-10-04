# First Project 
## Building an LED chaser
 One LED should turn on and all remaining led should turn off, and the led that is on should keep on switching in the line, making it seem like the LED is chasing along the line

## LED USED
- GPIO1 - 28, 29 and 31
- GPIO2 - 2,3,4,5 and 6
- As you see they were not a continuous sequence and that was my biggest issues with using LED_MASk directly
- So i had to create my own small mask, which is not as big as it sounds to do

## Things I learnt 
- `FIODIR` - sets pins as output or input
- `FIOSET` - sets a pin value
- `FIOCLR` - Clears a pin value
- `some bit & some bit` - basically works as a bit check, like are they same or not 
- I learnt how to create a bit mask using `#define` 
- How to group several bits to be manipulated together using `|`, see the `FIODIR` usage 
- How to call a function use it and send parameters, although making complex functions is still a bit wonky