*This project has been created as part of the 42 curriculum by agalvan-*

---

# libft

## Table of Contents

- [Description](#description)
  - [What is libft?](#what-is-libft)
  - [Character classification functions](#character-classification-functions)
  - [Memory functions](#memory-functions)
  - [String functions](#string-functions)
  - [Conversion functions](#conversion-functions)
  - [Output functions](#output-functions)
  - [Linked list functions](#linked-list-functions)
- [Instructions](#instructions)
- [Resources](#resources)

---

## Description

### What is libft?

`libft` is the first project in the 42 school curriculum. The goal is to re-implement a set of standard C library functions from scratch, without using the originals. The result is a static library (`libft.a`) that can be linked into future 42 projects as a personal utility belt.

Building libft forces a deep understanding of how foundational C functions work under the hood — memory layout, pointer arithmetic, null-termination, and safe iteration — before any higher-level project relies on them.

---

### Character classification functions

These functions mirror the standard `<ctype.h>` predicates. Each takes a single `int` and returns non-zero (true) or zero (false).

| Function | Description |
|---|---|
| `ft_isalpha` | Returns true if the character is alphabetic (a–z, A–Z) |
| `ft_isdigit` | Returns true if the character is a decimal digit (0–9) |
| `ft_isalnum` | Returns true if the character is alphanumeric (combines the two above) |
| `ft_isascii` | Returns true if the value falls within the 7-bit ASCII range (0–127) |
| `ft_isprint` | Returns true if the character is printable (includes space, excludes control codes) |
| `ft_toupper` | Converts a lowercase letter to uppercase; returns other characters unchanged |
| `ft_tolower` | Converts an uppercase letter to lowercase; returns other characters unchanged |

**Example**
```c
ft_isalpha('A');   // → 1
ft_isdigit('9');   // → 1
ft_isalnum('!');   // → 0
ft_toupper('g');   // → 'G'
```

---

### Memory functions

These functions operate on raw bytes rather than C strings, so they work on any data type and do **not** stop at a null byte.

| Function | Description |
|---|---|
| `ft_memset` | Fills `n` bytes of a memory area with a constant byte value |
| `ft_bzero` | Sets `n` bytes of a memory area to zero (equivalent to `memset(s, 0, n)`) |
| `ft_memcpy` | Copies `n` bytes from source to destination; regions must not overlap |
| `ft_memmove` | Copies `n` bytes handling overlapping regions safely |
| `ft_memchr` | Scans `n` bytes for the first occurrence of a byte value |
| `ft_memcmp` | Compares `n` bytes of two memory areas lexicographically |
| `ft_calloc` | Allocates memory for `count` elements of `size` bytes each, zeroed out |

**Example**
```c
char buf[5];
ft_memset(buf, 'A', 4);
buf[4] = '\0';
// buf → "AAAA"

char src[] = "hello";
char dst[6];
ft_memcpy(dst, src, 6);
// dst → "hello"
```

---

### String functions

The bulk of libft lives here. These mirror the `<string.h>` functions and add several extras not found in the standard library.

| Function | Description |
|---|---|
| `ft_strlen` | Returns the number of characters before the terminating null byte |
| `ft_strlcpy` | Copies up to `dstsize - 1` characters and null-terminates; returns source length |
| `ft_strlcat` | Appends src to dst up to `dstsize`; returns combined length |
| `ft_strchr` | Finds the first occurrence of a character in a string |
| `ft_strrchr` | Finds the last occurrence of a character in a string |
| `ft_strncmp` | Compares up to `n` characters of two strings |
| `ft_strnstr` | Finds the first occurrence of `needle` within the first `len` bytes of `haystack` |
| `ft_strdup` | Allocates and returns a duplicate of the given string |
| `ft_substr` | Allocates and returns a substring starting at index `start` with length `len` |
| `ft_strjoin` | Allocates and returns a new string that is the concatenation of `s1` and `s2` |
| `ft_strtrim` | Allocates and returns a copy of `s1` with leading/trailing characters from `set` removed |
| `ft_split` | Splits a string by a delimiter character and returns a null-terminated array of strings |
| `ft_strmapi` | Creates a new string by applying a function `f(index, char)` to each character |
| `ft_striteri` | Applies a function `f(index, &char)` to each character of a string in place |

**Example**
```c
char *joined = ft_strjoin("Hello, ", "world!");
// joined → "Hello, world!"

char **words = ft_split("the quick brown fox", ' ');
// words[0] → "the"
// words[1] → "quick"
// words[2] → "brown"
// words[3] → "fox"
// words[4] → NULL

char *trimmed = ft_strtrim("  hello  ", " ");
// trimmed → "hello"
```

---

### Conversion functions

| Function | Description |
|---|---|
| `ft_atoi` | Converts the initial portion of a string to an `int`, skipping leading whitespace and handling an optional sign |
| `ft_itoa` | Allocates and returns a string representation of an integer (handles negative numbers) |

**Example**
```c
ft_atoi("  -42abc");  // → -42
ft_atoi("2147483647"); // → 2147483647

char *s = ft_itoa(-1234);
// s → "-1234"
```

---

### Output functions

These write directly to a given file descriptor, making them useful for writing to `stdout` (fd 1), `stderr` (fd 2), or any open file.

| Function | Description |
|---|---|
| `ft_putchar_fd` | Writes a single character to `fd` |
| `ft_putstr_fd` | Writes a string to `fd` |
| `ft_putendl_fd` | Writes a string followed by a newline to `fd` |
| `ft_putnbr_fd` | Writes the decimal representation of an integer to `fd` |

**Example**
```c
ft_putstr_fd("Error: invalid input\n", 2);  // writes to stderr
ft_putnbr_fd(42, 1);                        // writes "42" to stdout
```

---

### Linked list functions

libft implements a singly-linked list using the following struct, defined in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

Each node holds a `void *content` pointer, so it can store any data type, and a `next` pointer to the following node (or `NULL` for the tail).

| Function | Description |
|---|---|
| `ft_lstnew` | Allocates and returns a new node with the given content; `next` is set to `NULL` |
| `ft_lstadd_front` | Inserts a node at the beginning of the list (O(1)) |
| `ft_lstadd_back` | Appends a node to the end of the list |
| `ft_lstsize` | Counts and returns the number of nodes in the list |
| `ft_lstlast` | Returns a pointer to the last node |
| `ft_lstdelone` | Frees a single node using a provided delete function; does **not** free `next` |
| `ft_lstclear` | Frees all nodes in the list and sets the pointer to `NULL` |
| `ft_lstiter` | Applies a function to the content of each node |
| `ft_lstmap` | Creates a new list by applying a function to each node's content; frees on failure |

**Example**
```c
t_list *list = ft_lstnew("first");
ft_lstadd_back(&list, ft_lstnew("second"));
ft_lstadd_back(&list, ft_lstnew("third"));

// list → ["first"] → ["second"] → ["third"] → NULL

ft_lstiter(list, &print_content);  // prints each content

ft_lstclear(&list, &free);
// list → NULL
```

---

## Instructions

### Requirements

- A C compiler (`cc`) with the flags `-Wall -Wextra -Werror`
- `make` (GNU Make)
- Unix-like environment (Linux or macOS)

### Build

Clone or copy the project directory, then run:

```bash
# Compile the library
make

# This produces libft.a in the project root
```

### Use in your project

```bash
# Compile your project and link against libft
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

Include the header in your source files:

```c
#include "libft.h"
```

### Makefile targets

| Target | Action |
|---|---|
| `make` / `make all` | Compiles all `.c` files and archives them into `libft.a` |
| `make clean` | Removes all `.o` object files |
| `make fclean` | Removes object files and `libft.a` |
| `make re` | Runs `fclean` then `all` (full rebuild) |

---

## Resources

- [The C Standard Library — cppreference.com](https://en.cppreference.com/w/c) — authoritative reference for every function libft reimplements
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/) — beginner-friendly walkthrough of C, memory, and pointers
- [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html) — full documentation for writing and understanding Makefiles
- [42 Docs / Norm](https://github.com/42School/norminette) — the `norminette` tool that enforces 42's coding style; your code must pass it
- [Valgrind](https://valgrind.org/) — memory error detector; run your tests through it to catch leaks in `malloc`-using functions like `ft_strdup`, `ft_split`, and the list functions
