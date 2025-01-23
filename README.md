# get_next_line - 42 Project

`get_next_line` is a project that requires creating a function capable of reading a line from a file descriptor, including handling multiple file descriptors simultaneously.

---

## Table of Contents

- [About the Project](#about-the-project)
- [Function Prototype](#function-prototype)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Key Concepts](#key-concepts)
- [Project Highlights](#project-highlights)

---

## About the Project

The goal of `get_next_line` is to create a function that reads a line from a file descriptor, returning it one line at a time. The function can handle files, standard input, or any valid file descriptor, and it ensures proper memory management.

---

## Function Prototype

```c
char *get_next_line(int fd);
```
---

## Getting Started

### Prerequisites
A GCC-compatible C compiler.
make utility.

### Installation
```bash
git clone https://github.com/stefan620/get_next_line.git
cd get_next_line
```
---

## Usage

1. Include get_next_line in your source code:
```c
#include "get_next_line.h"
```
2. Use the function to read lines from a file:
```c
int fd = open("example.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL) {
    printf("%s", line);
    free(line);
}
close(fd);
```
---

## Key Concepts

- Buffer Management: The function reads data in chunks defined by the BUFFER_SIZE macro.
- Static Variables: Maintains the state of unfinished reads across function calls.
- Memory Management: Allocates and frees memory dynamically for each line.

---

## Project Highlights

- Efficient I/O: Optimized to minimize the number of read system calls.
- Dynamic Memory: Supports lines of any length, limited only by available memory.
- Error Handling: Properly detects and handles read errors and memory allocation failures.

