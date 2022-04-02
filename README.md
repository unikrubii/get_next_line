<h1 align="center">42 Cursus: get_next_line</br></br>
  <sup><sup><sup><sup>Reading a line from a fd is way too tedious.</sup></sup></sup></sup></h1>

:dart: Goal of this project
> This project is aim to achieve how to read file from file discriptor with size of BUFFER_SIZE, then return one line read from the file.

:thinking: What need to know about this project
> - Reading file with read().</br>
> - Memory allocation and free memory.</br>
> - Implementing `define` macro to use in function.</br>
> - How to append characters into another strings.</br>
> - Linked list (if you want to do completely dynamic (hard mode) in for bonus)

### 	:computer: To compile ###
- Compile the code with: `-gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c` (in case of a buffer size of 42 is used)
- To change the buffer size of the ***get_next_line*** function you will have to add `-D BUFFER_SIZE=n` (where ***n*** is number of size you desire)
</br>

### **Mandatory Part**
- The function should read the text file pointed to by the file descriptor, one line at a time.
- Your function should return the line that was read.
- Your function works as expected both when reading a file and when reading from the standard input.</br>

|**Function name**|**get_next_line**|
|:---         |:---           |
|Prototypes|char \*get_next_line(int fd)|
|Turn in files|*get_next_line.c </br>get_next_line_utils.c </br>get_next_line.h*|
|Parameters|Read line: correct behavior </br>NULL: there is nothing else to read, or an error occured|
|External Functions|read, malloc, free|
|Forbidden Functions|lseek() </br>Global variables|

This is the example when you are able to read through the file from the file discriptor.
![image](https://user-images.githubusercontent.com/83582645/161393271-374e55eb-5737-44c2-9ad1-2c56a974491e.png)
</br></br>

## For anyone who think ***Mandatory Part*** is not enough
There you are! ***BONUS PART***
- Your get_next_line() is using only one static variable
- It also can manage multiple file discriptors at the same time without losing the reading thread of each fd or returning a line from another fd.
- The bonus part will only be assessed if the mandatory part is ***PERFECT***.
- The files needed to turn in are as follow:
  - get_next_line_bonus.c
  - get_next_line_utils_bonus.c
  - get_next_line_bonus.h

This is the example when you are able to make the bonus part out.
![image](https://user-images.githubusercontent.com/83582645/161394116-2a53fb53-000a-4a90-8e74-f49acd09acab.png)
