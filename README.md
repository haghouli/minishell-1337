# minishell-1337
![Alt text](/images/prompt.jpg)
minishell is about creating a mini bash like.

## team members
- haghouli(me)
- mohcin tadlaoui [GitHub Pages](https://github.com/motadlaoui).

## Description
42 Minishell is a simple Unix shell implementation, created as part of the 42 network curriculum. It aims to mimic basic shell functionalities (such as `echo`, `pwd`, `cd`, `exit`, etc.) while offering a learning experience in the areas of system calls, process management, and file descriptors.

## Features
- **Basic Shell Commands**: Supports built-in commands like `echo`, `cd`, `pwd`, `exit`.
- **Command Execution**: Execute external programs using `fork`, `execve`, and manage processes.
- **Pipes**: Supports piping between commands (`|`).
- **Redirection**: Implements input/output redirection (`>`, `>>`, `<`).
- **Environment Variables**: Handle environment variables and `export`.
- **Custom Prompts**: Customizable command prompt with support for different colors.
- **Signals Handling**: Properly manages signals like `Ctrl+C`.

## Installation

To run minishell, follow these steps:

### Prerequisites:
- A Linux or macOS system.
- Make sure you have **GCC** or **Clang** installed.
- **Make** should be available to build the project.

### Clone the repository:
```bash
git clone https://github.com/haghouli/minishell-1337.git
cd minishell-1337
make
./minishell
