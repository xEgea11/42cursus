/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:38:45 by regea-go          #+#    #+#             */
/*   Updated: 2023/06/04 17:12:41 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[])
{   
    int id = fork();
    int status;
    if (id == 0) //child process
    {
        char *args[] = {"ls", "-la", "/etc/", NULL};
        execvp("ls", args);
        ft_printf("It didnt execute\n");
    }
    else
    {
        wait(&status);
        ft_printf("hi im the parent\n");
    }
}