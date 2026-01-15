# Simple Shell

## Description

This project is a simple UNIX command line interpreter written in C as part of the
Holberton School curriculum.

The shell replicates basic behavior of `/bin/sh`. It reads user input, parses it,
executes commands found in the system `PATH`, and supports a small set of built-in
commands.

This project focuses on understanding:
- Process creation
- System calls
- Environment handling
- Memory management
- Basic shell architecture

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
($) pwd
/home/user/simple_shell
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
- Executes commands found in the `PATH` (e.g. `ls`)
- Handles command arguments (e.g. `ls -l /tmp`)
- Works in interactive and non-interactive modes

### Built-ins

- `exit` — exits the shell
- `env` — prints the current environment

### Error Handling

- Prints errors similar to `/bin/sh`
- Returns correct exit status codes
- Handles end-of-file (Ctrl + D)

---

## Project Structure

| File | Description |
|------|-------------|
| `main.c` | Entry point and main shell loop |
| `execute_input.c` | Processes and dispatches user input |
| `launch_command.c` | Forks and executes external commands |
| `handle_builtins.c` | Handles built-in commands |
| `build_argv.c` | Tokenizes command input |
| `handle_input.c` | Cleans and trims user input |
| `path.c` | PATH resolution utilities |
| `print_error.c` | Error message handling |
| `print_env.c` | env built-in implementation |
| `main.h` | Header file |

---

## Allowed Functions

The project uses only allowed system calls and functions, including:

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

This shell does **not** support:

- Pipes (`|`)
- Redirections (`>`, `<`)
- Command chaining (`;`)
- Wildcards (`*`)
- Built-ins with arguments (e.g. `exit 2`)

---

## Learning Objectives

Through this project, the following concepts were practiced:

- How a shell works internally
- Process lifecycle management
- Environment variable handling
- Memory ownership and cleanup
- Modular C programming

---

## Author

**Patrick Macabulos**  
Holberton School

---

## License

This project is for educational purposes only.
