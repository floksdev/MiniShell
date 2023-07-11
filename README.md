# MiniShell
💻 | A nice command interpreter in C

This is the readme file for the MiniShell project, which combines the functionalities of minishell1 and minishell2. The project was completed as part of the B1 and B2 levels of the Unix System Programming and Shell Programming courses at 42. The goal of MiniShell is to create a command interpreter similar to the reference shell, TCSH, with added features and functionalities.

# Project Details :
- Binary Name : mysh
- Language : C
- Compilation : Makefile with re, clean, and fclean rules.
- Error messages is written on the error output, and the program exit with error code 84 (or 0 if there is no error).
  
# Project Description

MiniShell is a command interpreter that emulates a shell environment. It provides a prompt ($> by default) and waits for the user to enter the command line, which is then validated when a new line is received. Once the command has been executed, the prompt is displayed again.

The MiniShell project combines all basic command lines as well as more advanced features such as semicolons (;) and pipes (|). Priority management is crucial in handling these features.

Built-in Commands

The following built-in commands are supported in MiniShell:

    cd: Change the current directory.
    setenv: Set an environment variable.
    unsetenv: Unset an environment variable.
    env: Display the current environment variables.
    exit: Terminate the MiniShell program.

The env built-in element takes no arguments, and the unsetenv built-in element does not support the * wildcard character.

# Ctrl + D

In UNIX systems, pressing Ctrl + D is used to indicate the end of file (EOF) or to send an EOF signal. In the context of MiniShell, pressing Ctrl + D can be used to exit or terminate the shell.

# Authorized Functions

I've set myself the constraint of using only the following functions :

    malloc, free, exit, opendir, readdir, closedir, getcwd, chdir
    fork, stat, lstat, fstat, open, close, getline, strtok, strtok_r
    read, write, execve, access, isatty, wait, waitpid
    wait3, wait4, signal, kill, getpid, strerror, perror, strsignal
    pipe, dup, dup2


# Examples

Below are some examples of commands that can be executed using MiniShell:

**./mysh**

```
$> ./my_ls .
dir my_ls ‘#test#’ test~
```

```
$> pwd
/tmp
$> cd test
$> pwd
/tmp/test
```
```
∼/B-PSU-101> echo “ls” | ./mysh
tata
∼/B-PSU-101> echo $?
0
∼/B-PSU-101> echo “ls nofile” | ./mysh
∼/B-PSU-101> echo $?
2
```

```
$> ./mysh
> ls -l; ls -l | wc -l
total 4
drwxr-xr-x 2 johan johan 4096 Mar 17 16:28 tata
-rw-r–r– 1 johan johan 0 Mar 17 16:28 toto
```

```
$> ls -l /usr /var
/usr:
total 72
drwxr-xr-x 2 root root 36864 Jan 6 17:24 bin
drwxr-xr-x 2 root root 4096 May 13 2019 games
drwxr-xr-x 36 root root 4096 Dec 14 11:15 include
drwxr-xr-x 54 root root 4096 Dec 14 11:15 lib
drwxr-xr-x 3 root root 4096 Apr 2 2020 libexec
drwxr-xr-x 10 root root 4096 Aug 3 2019 local
drwxr-xr-x 2 root root 4096 Jan 6 17:24 sbin
drwxr-xr-x 108 root root 4096 Jan 6 17:24 share
drwxr-xr-x 5 root root 4096 Apr 2 2020 src
/var:
total 40
drwxr-xr-x 2 root root 4096 May 13 2019 backups
drwxr-xr-x 11 root root 4096 Jan 6 17:24 cache
drwxr-xr-x 29 root root 4096 Jan 6 17:24 lib
drwxrwsr-x 2 root staff 4096 May 13 2019 local
lrwxrwxrwx 1 root root 9 Aug 3 2019 lock -> /run/lock
drwxr-xr-x 6 root root 4096 Apr 2 2020 log
drwxrwsr-x 2 root mail 4096 May 11 2020 mail
drwxr-xr-x 2 root root 4096 Aug 3 2019 opt
lrwxrwxrwx 1 root root 4 Aug 3 2019 run -> /run
drwxr-xr-x 5 root root 4096 Jan 13 2020 spool
drwxrwxrwt 2 root root 4096 Apr 2 2020 tmp
drwxr-xr-x 3 root root 4096 Jan 31 2020 www
```

```
$> ./mysh
> mkdir test ; cd test ; ls -a ; ls | cat | wc -c > tutu ; cat tutu
. ..
```
Note: The examples above are for illustrative purposes and may not cover all possible scenarios.
