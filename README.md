# Simple Shell in C

This repository contains a simple shell implementation in C, allowing users to enter and execute basic commands.

## Features
- Tokenizes user input
- Forks a child process to execute commands
- Supports built-in `exit` command to terminate the shell
- Handles basic command execution using `execvp`

## Installation & Compilation
### Prerequisites
Ensure you have a C compiler (e.g., `gcc`) installed on your system.

### Compilation
```sh
gcc -o shell Shell.c
```

### Running the Shell
```sh
./shell
```

## Usage
1. Run the compiled executable.
2. Enter commands as you would in a standard shell.
3. Type `exit` to quit the shell.

## Example
```
Enter command: ls -l
(total output of ls -l)
Enter command: exit
```

## Limitations
- Does not support command chaining (`&&`, `||`, `;`).
- Limited to single-line commands.
- Lacks advanced shell features like piping and environment variable expansion.

