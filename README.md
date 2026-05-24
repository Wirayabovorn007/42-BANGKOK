# 42 BANGKOK Projects

*This repository contains the projects I have completed as part of the 42 School curriculum.*

## 📚 About
This collection tracks my progress through the 42 "Common Core." Each folder represents a specific project, designed to explore different aspects of computer science, from low-level C programming and algorithm design to system administration and virtualization.

All C projects in this repository are written in accordance with the **42 Norm** (Norminette).

## 📂 Projects Overview

### Rank 00
| Project | Description |
| :--- | :--- |
| **[Libft](./libft)** | My very first C library. It reimplements a set of standard C library functions (like `libc`) and additional utility functions that are used throughout the curriculum. |

### Rank 01
| Project | Description |
| :--- | :--- |
| **[ft_printf](./ft_printf)** | A reimplementation of the famous `printf` function. It handles variable numbers of arguments and formats specific types (like `%s`, `%d`, `%x`). |
| **[get_next_line](./get_next_line)** | A function that reads a file descriptor line by line. This project teaches static variables and file manipulation in C. |
| **[Born2beroot](./born2beroot)** | An introduction to virtualization and system administration. This project involves setting up a strict Debian server environment, including LVM, SSH configuration, and firewall rules. |

### Rank 02
| Project | Description |
| :--- | :--- |
| **[push_swap](./push_swap)** | An algorithmic project where I sort data on a stack using a limited set of instructions and the lowest possible number of actions. Implements a **Greedy/Turk Algorithm** for efficiency. |
| **[minitalk](./minitalk)** | Create a communication program in the form of a client and a server. The catch? The only method of communication allowed is **UNIX signals**. |
| **[so_long](./so_long)** | **so_long** is a small 2D game developed in C using the MiniLibX (MLX) graphical library. |

### Extras
| Folder | Description |
| :--- | :--- |
| **[exam_practice](./exam_practice)** | A collection of practice problems and solutions for the 42 exams (e.g., Exam Rank 02), covering string manipulation, bits, and algorithm basics. |

## 🛠️ Usage
Most C projects in this repository include a `Makefile`. To test or run a specific project:

1.  Navigate to the project directory:
    ```bash
    cd <project_name>
    ```
2.  Compile the project:
    ```bash
    make
    ```
3.  Execute the program or link the library (refer to the specific README in each folder for detailed instructions).

## ⚠️ Disclaimer
These projects are part of my personal learning journey at 42. If you are a 42 student, please use this code for reference and learning purposes only. Copying code (cheating) does not help you learn and violates the school's principles.
