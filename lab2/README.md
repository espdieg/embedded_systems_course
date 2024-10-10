Within this lab assignment there were four different tasks we were asked to complete. If you'd like to skip ahead and try any of these programs yourself you'll need to download the [*lab2.h*](https://github.com/espdieg/embedded_systems_course/blob/main/lab2/lab2.h) header file, the [*main.c*](https://github.com/espdieg/embedded_systems_course/blob/main/lab2/main.c) main file and whichever other task file you'd like, along with the Code Composer studio IDE and connecting to a MSP432. Within the [*main.c*](https://github.com/espdieg/embedded_systems_course/blob/main/lab2/main.c) file the only change you'd need to make is to either comment out or uncomment whichever task you are running. Below I've outlined the requirement for each task and a brief explanation on what I did to complete the task. 

### [Task 2](https://github.com/espdieg/embedded_systems_course/blob/main/lab2/task_2.c): 
- **Requirement**: For this task we were asked to declare a counter and write code to print the value of the counter, then increment inside of our while loop. 
- **My solution**: I initialized a counter of type uint32_t to 0. Within the while loop, I printed the value of counter using uart_println and then incremented by 1 each time the while loop executed. This displayed the current count and toggled LED as well.
- **My output**:
-  ![](https://github.com/espdieg/embedded_systems_course/blob/main/lab2/lab2_task_2_output.PNG)

### [Task 3](https://github.com/espdieg/embedded_systems_course/blob/main/lab2/task_3.c): 
- **Requirement**: We are given a complete program that doesn't ever exit our while loop and our task is to figure out why. 
- **My solution**: When I initially ran the program without changes it never completed its task nor exited the while loop. After looking more closely I changed the value of "volatile uint16_t i;" to "volatile uint32_t i;" this resolved the issue which I can only assume by giving a bigger range of delay iterations when we run the for loop.
- **My output**:
- ![](https://github.com/espdieg/embedded_systems_course/blob/main/lab2/lab2_task_3_output.PNG)

### [Task 4](https://github.com/espdieg/embedded_systems_course/blob/main/lab2/task_4.c): 
- **Requirement**: For this task we are asked to implement a print_and_increment function and run it using both pass-by-reference and pass-by-value. 
- **My solution**: I completed the function and tested both ways of calling it. When calling as (*value) the counter was assigned a value of 536936448 and it never incremented. When calling as (value) the counter was assigned a value of 1 and incremented as expected.
- **My output**:
- ![](https://github.com/espdieg/embedded_systems_course/blob/main/lab2/lab2_task_4_output.PNG)

### [Task 5](https://github.com/espdieg/embedded_systems_course/blob/main/lab2/task_5.c): 
- **Requirement**: For this task we are asked to take control of the RGB light on the MSP432 board and make it output different colors. 
- **My solution**:  I implemented a loop that cycles through different LED colors based on the value of a counter.The activeLED variable is set based on the current value of the counter using a modulo operation. I also included delays between toggling the LEDs to create a blinking effect.
