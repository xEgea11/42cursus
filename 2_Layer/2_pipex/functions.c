/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:16:48 by regea-go          #+#    #+#             */
/*   Updated: 2023/06/06 19:09:24 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <errno.h>
#include <string.h>

int main (void)
{
    //Funcion access -- solo deja un argumento; 0 es verdadero, -1 falso
    ft_printf("Value of access: %i\n", access("file.txt", F_OK));
    //Funcion perror <errno.h>
    perror("Esto es un error");
    //Funcion strerror <string.h>
    int errnum = errno;
    ft_printf("Imprimiendo una cadena de error: %s\n", strerror(errnum));
    //Funcion "dup" <unistd.h>, duplicates a file descriptor; returns lowest available; maybe not very useful
    //int newfd = dup(fd);
    
    //function "dup2" <unistd.h>, duplicates a file descriptor to a desired and specific new file descriptor 
    //int newfd = dup2(int oldfd, int newfd);
    
    //function "execve" <unistd.h>, executes a program with arguments; argv is mandatory, envp is optional
    //int execve(const char *programPath, char *const argv[], char *const envp[]);

    //function "exit" <stdlib.h>, causes normal process termination
    //void exit(int status);

/*  function "fork" <sys/types.h>, <unistd.h>, create a new process by duplicating the existing one
    int id = pid_t fork(void); // Fork returns an id so the process can know who it is
    
    //With "fork", we "duplicate the code", i.e. the child and the parent execute the code
    //(if there is no condition, they execute almost at the same time, in a chaotic order, 
    //depending of the OS calls and threads)
    int id = fork();
    (if id == 0) //It is the child process 
    {
        do_child_stuff();
    }
    else //Not in the child, its going to execute in the parent process
    {
        do_parent_stuff();
    }
    (no condition)
        execute_at_the_same_time
*/

/*  function "pipe" <unistd.h>, create interprocess communication pipe, returns 0 on success and -1 on failure
    int pipe (int pipefd[2]) 
    pipe(pipefd) --> initializes the pipe, creates two fd (one for each position    )
    read(pipefd[0], buffer, sizeof(buffer)) --> pipefd[0] is used to read data from the pipe 
    write(pipefd[1], message, message length) --> pipefd[1] is used to send data to the pipe
*/

    //function "unlink" <unistd.h>, delete a name 
    //and possibly the file it refers to, if the name deleted was the last link to the file
    //0 if success, -1 if failure
    //int unlink(const char *pathname)
    
/*  //function "wait, waitpid" <sys/types.h>, <sys/wait.h>, parent waits until child process has finished its execution;
    //It prevents from chaotic result and execution at the same time between parent and child process
    pid_t wait(int *wstatus);
    pid_t waitpid(pid_t pid, int *wstatus, int options);
            ***waitpid(pid, NULL, 0);*****  
                pid = waits until process with pid finishes
                        > 0, waitpid waits for the child process with specified pid
                        -1, waits for any child process
                        = 0,  waits for any child process in the same process group
                status = ptr to int where the termination status of child process will be stored
                        macros WIFEXITED, WIFSIGNALED, WEXITSTATUS are defined
                options = additional options:
                        WNOHANG --> returns immediately if there are no terminated child processes
                        WUNTRACED --> returns if a child has stopped, in addition to terminated child processes
                        WCONTINUED --> returns if a stopped child has been resumed by a sigcont signal
*/
    
/*  //********CARE, MAYBE NOT ALLOWED IN ThE PROJECT********* //instead, execve is allowed
    //function "execlp(command)" , allows to execute CLI. Problem is, it replaces the process for its own, 
    // so we have to fork() a process to create a child, then execute the command into the child process

*/

/*  ******SIMULATING "|" in C***********
    //create a pipe
    //fork a process
    //execute "dup2(fd[1], STDOUT_FILENO)" --> set the "write" end of the pipe to STDOUT_FILE NO, to send the info over there
    //close both fd[0] (we dont use it in the child) and fd[1] (it's no longer the original value)
    //execute command (execve) on child to the "write" end; if the parent does, he will be replaced
    //fork another process (it will execute "grep command")
    //set dup2(fd[0], STDIN_FILENO) to read from STDIN
    //close fd[0] (since its no longer needed), and fd[1] since we dont use it
    //execute the command (execve)
    
    //already on the main process (after child finishes), close both fd[0], fd[1], since they are still
    //open on parent process, and if not done, will cause "grep" to read indefinitely
    //set a wait to let the child finish
    //
    

*/

}   