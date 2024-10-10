Task 2: 
- Requirement: For this task we were asked to declare a counter and write code to print the value of the counter, then increment inside of our while loop. 
- My solution: I initialized a counter of type uint32_t to 0. Within the while loop, I printed the value of counter using uart_println and then incremented by 1 each time the while loop executed. This displayed the current count and toggled LED as well. 

Task 3: 
- Requirement: We are given a complete program that doesn't ever exit our while loop and our task is to figure out why. 
- My solution: When I initially ran the program without changes it never completed its task nor exited the while loop. After looking more closely I changed the value of "volatile uint16_t i;" to "volatile uint32_t i;" this resolved the issue which I can only assume by giving a bigger range of delay iterations when we run the for loop.

Task 4: 
- Requirement: For this task we are asked to implement a print_and_increment function and run it using both pass-by-reference and pass-by-value. 
- My solution: I completed the function and tested both ways of calling it. When calling as (*value) the counter was assigned a value of 536936448 and it never incremented. When calling as (value) the counter was assigned a value of 1 and incremented as expected. 

Task 5: 
- Requirement: For this task we are asked to take control of the RGB light on the MSP432 board and make it output different colors. 
- My solution:  I implemented a loop that cycles through different LED colors based on the value of a counter.The activeLED variable is set based on the current value of the counter using a modulo operation. I also included delays between toggling the LEDs to create a blinking effect.