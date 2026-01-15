# Simple Shell – Control Flow Diagram

This diagram shows the control flow and decision-making process of the simple shell,
from reading user input to executing built-in or external commands.

The diagram is written using Mermaid and is rendered automatically on GitHub.

---

```mermaid
flowchart TD
    A[Start main()] --> B[read_input]
    B -->|EOF| Z[Exit shell]
    B -->|Input read| C[execute_input]

    C --> D[handle_input]
    D -->|Empty or spaces only| B

    D --> E[build_argv]
    E -->|No command| B

    E --> F[handle_builtins]
    F -->|exit builtin| Z
    F -->|env builtin| G[print_env] --> B
    F -->|not a builtin| H[launch_command]

    H --> I[resolve_command_path]
    I -->|Command not found| J[print_error] --> K[Return 127]
    I -->|Command found| L[fork]

    L -->|Child process| M[execve]
    M -->|execve fails| J --> K

    L -->|Parent process| N[wait]
    N --> O[Return child exit status]
    O --> B
