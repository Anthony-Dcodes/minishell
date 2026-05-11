# minishell
Small version of bash-like shell written in C.

## External functions allowed:
	- All the external functions allowed as per Minishell subject
### Headers
	- <stdio.h> - standard input/output
	- <readline/readline.h>
	- <readline/history.h>
	- <stdlib.h> - standard lib
	- <unistd.h> - unix standard
	- <fcntl.h> - file control
	- <errno.h> - error number (defines global errno variable and error code amcros)
	- <signal.h> - signal
	- <dirent.h> - directory entry
	- <sys/wait.h> - process waiting
	- <sys/stat.h> - file status/ statistics
### GNU Readline Library
	- utility which aids in the consistency of user interface across discrete programs which provide a command line interface
	- basically utilities that are used in different implementations of shell
	- [GNU_readline_lib_man_pages](https://tiswww.case.edu/php/chet/readline/readline.html)
### GNU History Library
	- programming tool that provides a consistent user interface for recalling lines of previously typed input
	- history expansions introduce words from the history list into the input stream
	- easy to repeat commands, insert arguments to a previous command
	- fix errors in previous commands quickly
	- [GNU_history_lib_man_pages](https://tiswww.case.edu/php/chet/readline/history.html)
1. `char* readline(const char *prompt)`
	- Get a line from a user with editing
	- #include <stdio.h>, <readline/readline.h>, <readline/history.h>
	- [linux_man_pages](https://man7.org/linux/man-pages/man3/readline.3.html)
1. `void rl_clear_history(void)`
	- clear the history list by deleting all of the entries
	- in the same manner as clear_history()
	- frees private data readline() saves in the history list
1. `int rl_on_new_line(void)`
	- tell the update functions that we have moved onto a new(empty) line\
	- usually after outputting a newline
1. `void rl_replace_line(const char *text, int clear_undo)`
	- replace contexts of rl_line_buffer with text
	- preserves poin and mark if possible
	- if clear_undo is non-zero, this clears the undo list associated with the current line
1. `void rl_redisplay`
	- change what's displayed on the screen to reflect the current contents of rl_line_buffer
1. `void add_history(const char *string)`
	- add string to the end of the history list
	- set associated data field to NULL
	- if the maximum number of history entries has been set using stifle_history() -> removes oldest history entry


1. `int printf(const char *restrict format, ...)`
	- <stdio.h>
	- [man_page](https://man7.org/linux/man-pages/man3/printf.3.html)
1. `void* malloc(size_t size)`
	- <stdlib.h>
	- [man_page](https://man7.org/linux/man-pages/man3/malloc.3.html)
1. `void free(void* _Nullable p)`
	- <stdlib.h>
	- [man_page](https://man7.org/linux/man-pages/man3/malloc.3.html)
1. `ssize_t write(int fd, const void buf[count], size_t count)`
	- writes up to count bytes from th ebuffer starting at buf to the file refferenced to by the file descriptor fd
	- <unistd.h>
	- [man_page](https://man7.org/linux/man-pages/man2/write.2.html)
1. `int access(const char *path, int mode)`
	- check users permissions for a file
	- mode:
		- specifies the accessibility check(s) to be performeds
		- F_OK - tests existence of the file
		- R_OK - if exists and grants read permissions
		- W_OK - if exists and grants write permissions
		- X_OK - if exists and grants execute permissions
	- <unistd.h>
	- [man_page](https://man7.org/linux/man-pages/man2/access.2.html)
1. `int open(const char *pathname, int flags, ... /* mode_t mode*/)`
	- open and possibly create a file
	- opens file specified by path
	- if file does not exist it my be optionally created (if O_CREAT is specified in flags)
	- return value:
		- file descriptor - a small nonnegative integer that is an index to an entry in the process's table of open file descriptors
		- fd is used in subsequent system calls (read(2), write(2), lseek(2), fcntl(2))
	- <fcntl.h>
1. `ssize_t read(int fd, void buf[.count], size_t count)`
	- read from file descriptor
	- attempts to read up to count bytes from fd into buf
	- on success the number of bytes read is returned and file possition is advanced by this number
	- on error -1 returned and errno is set to indicate error
	- <unistd.h>
1. `int close(int fd)`
	- close a file descriptor
	- <unistd.h>
	- returns 0 on success, -1 on error and errno is set
