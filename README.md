# Simple Shell

## Description

This project is a simple UNIX command line interpreter written in C as part of the
Holberton School curriculum.

The shell reproduces basic behavior of `/bin/sh`. It reads commands from standard
input, parses them, resolves executable paths using the `PATH` environment variable,
and executes programs in child processes.

This project focuses on understanding:
- How a shell works internally
- Process creation and execution
- Environment variables
- Exit status handling
- Modular C programming

---

## Requirements

- Ubuntu 20.04 LTS
- GCC compiler
- GNU C89 standard

### Compilation

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## Usage

### Interactive Mode

```sh
$ ./hsh
($) ls
file1 file2
($) env
PATH=/usr/bin:/bin
($) exit
```

### Non-Interactive Mode

```sh
$ echo "/bin/ls" | ./hsh
file1 file2
```

---

## Features

### Supported Commands
- Executes commands using absolute paths (e.g. `/bin/ls`)
- Executes commands found using the `PATH` environment variable
- Supports command arguments (e.g. `ls -l /tmp`)
- Works in both interactive and non-interactive modes

### Built-in Commands
- `exit` — exits the shell
- `env` — prints the current environment

### Error Handling
- Prints errors similar to `/bin/sh`
- Returns correct exit status codes
- Handles end-of-file (Ctrl + D)

---

## Project Structure

| File | Description |
|------|------------|
| `main.c` | Entry point and main shell loop |
| `read_input.c` | Reads input from standard input |
| `execute_input.c` | Dispatches and processes commands |
| `handle_input.c` | Cleans and trims user input |
| `build_argv.c` | Tokenizes input into argument vectors |
| `handle_builtins.c` | Handles built-in commands |
| `print_env.c` | Implements the `env` built-in |
| `launch_command.c` | Forks and executes external commands |
| `resolve_command_path.c` | Determines how to resolve command paths |
| `get_path_value.c` | Retrieves the PATH environment variable |
| `find_command_in_path.c` | Searches PATH directories for commands |
| `build_and_check_path.c` | Builds and validates executable paths |
| `print_error.c` | Prints formatted error messages |
| `main.h` | Header file with function prototypes and macros |

---

## Allowed Functions

Only allowed system calls and functions are used, including:

- `fork`
- `execve`
- `wait`
- `getline`
- `write`
- `malloc`
- `free`

No prohibited functions such as `system()` are used.

---

## Limitations

This shell does not support:
- Pipes (`|`)
- Redirections (`>`, `<`)
- Command chaining (`;`)
- Wildcards (`*`)
- Variable expansion (e.g. `$?`)
- Built-in arguments (e.g. `exit 2`)

---

## Learning Objectives

Through this project, the following concepts were practiced:

- Process lifecycle management
- PATH resolution
- Exit status propagation
- Environment handling
- Memory ownership and cleanup
- Code modularization

---

## Author

**Patrick Macabulos**  
Holberton School

---

## License

This project is for educational purposes only.
