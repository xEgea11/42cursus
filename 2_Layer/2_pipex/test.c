/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:38:42 by regea-go          #+#    #+#             */
/*   Updated: 2023/06/07 00:10:32 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{
	int		id;
	int		fd;
	int		fd2;
	int		pipefd[2];
	char	**args;
	char	**args2;

	if (argc != 5)
	{
		ft_printf("Arguments are not valid");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	if (pipe(pipefd) < 0)
		return (1);
	id = fork();
	if (id < 0)
		return (1);
	if (id == 0)
	{
		if (dup2(fd, STDIN_FILENO) < 0)
			return (1);
		close(fd);
		if (dup2(pipefd[1], STDOUT_FILENO) < 0)
			return (1);
		close(pipefd[0]);
		close(pipefd[1]);
		args = ft_split(argv[2], ' ');
		//FIND A WAY TO GET PATH VARIABLE..do we have to do another fork?
		//change intialization too
		char *envp[] = {"/usr/local/bin/", "/usr/bin/", "/bin/", "/usr/sbin/", "/sbin", NULL};
        // Error handling (Watch signal error from CodeVault)
		//Another fork??
		execve("/bin/ls", args, envp);
	}
	waitpid(0, NULL, 0);
	if (dup2(pipefd[0], STDIN_FILENO))
		return (1);
	close(pipefd[0]);
	close(pipefd[1]);
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0755);
	if (fd2 < 0)
		return (1);
	if (dup2(fd2, STDOUT_FILENO) < 0)
		return (1);
	close(fd2);
	args2 = ft_split(argv[3], ' ');
    //We have to find a way of getting the PATH...do we have to do another fork?
	//change the initialization too
	char	*envp2[] = {"/usr/local/bin/", "/usr/bin/", "/bin/", "/usr/sbin/", "/sbin", NULL};
    // Error handling (Watch signal error from CodeVault)
	//Another fork?
	execve("/usr/bin/grep", args2, envp2);
	ft_printf("Execute failed");
}
