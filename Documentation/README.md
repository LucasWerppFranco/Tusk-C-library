# Documentation

## Documentation in other languages

- [PT - BR](Documentation_in_Portuguese)

---

## Keyboard Input Library Project

This project contains a C library called `tusk`, which allows non-blocking keyboard input reading on Unix/Linux systems. The library is useful for applications that need to react immediately to user input without waiting for the Enter key.

## Project Structure

/project  
│  
├── conio_lib.h # Library header  
├── conio_lib.c # Library implementation  
└── main.c # Main program that uses the library  

## Library Features

### 1. `set_conio_terminal_mode()`

This function configures the terminal to non-blocking mode. It disables the canonical mode, allowing keyboard input to be read immediately, and disables echo, so typed characters are not displayed on the screen.

### 2. `reset_terminal_mode()`

This function restores the terminal's default settings, re-enabling canonical mode and echo. It should be called before exiting the program to ensure the terminal returns to its normal state.

### 3. `kbhit()`

This function checks if a character is available to be read from the input buffer. If a character is available, it is read and placed back into the buffer, allowing the program to process it. The function returns 1 if a character is available and 0 otherwise.

## Usage Example

The `main.c` file demonstrates how to use the `conio_lib` library to detect user input. Below is a detailed explanation of the code:

```c
#include <stdio.h>
#include "conio_lib.h"

int main() {
    set_conio_terminal_mode(); // Configures the terminal in non-blocking mode
    printf("Press 'n' to see the message or 'q' to quit.\n");

    while (1) {
        if (kbhit()) { // Checks if a character is available
            char ch = getchar(); // Reads the character
            if (ch == 'n') {
                printf("You pressed the 'n' key!\n");
            } else if (ch == 'q') {
                break; // Exits the loop if 'q' is pressed
            }
        }
        usleep(100000); // Waits briefly to prevent excessive CPU usage
    }

    reset_terminal_mode(); // Restores terminal settings
    return 0; // Returns 0 to indicate the program finished successfully
}
```

## Code Explanation

  - **1** Header Inclusion: The program includes the conio_lib.h header, which contains the function declarations.

  - **2** Terminal Configuration: The set_conio_terminal_mode() function is called to configure the terminal in non-blocking mode.

  - **3** Main Loop: The program enters an infinite loop where it continuously checks if a key has been pressed using the kbhit() function.

  - **4** Key Reading: If a key is available, it is read with getchar(). If the key is 'n', a message is displayed. If the key is 'q', the loop is exited.

  - **5** Terminal Restoration: Before exiting, the reset_terminal_mode() function is called to restore the terminal's settings.

## Compilation

To compile the library and the main program, use the following commands in the terminal:

```bash
gcc -c conio_lib.c -o conio_lib.o  # Compiles the library
gcc main.c conio_lib.o -o main      # Compiles the main program
```

## Execution

After compilation, you can run the program with the following command:

```bash
./main
```

Press 'n' to see the message or 'q' to quit the program.

## Final Notes

There are still sections to be added as the project progresses, such as: "Installation", "Usage", "Examples", etc...
