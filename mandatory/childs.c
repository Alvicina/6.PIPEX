/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:23:20 by alvicina          #+#    #+#             */
/*   Updated: 2023/12/29 10:53:44 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*ft_get_commd(t_pipex *pipex)
{
	size_t	i;
	char	*temp;
	char	*command;

	i = 0;
	while (pipex->commd_path[i])
	{
		temp = ft_strjoin(pipex->commd_path[i], "/");
		command = ft_strjoin(temp, pipex->commd_args[0]);
		free(temp);
		if (access(command, F_OK | X_OK) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

void	child_one(t_pipex *pipex, char **argv, char **envp)
{
	dup2(pipex->pipe[1], STDOUT_FILENO);
	close(pipex->pipe[0]);
	dup2(pipex->infile, STDIN_FILENO);
	pipex->commd_args = ft_split(argv[2], ' ');
	pipex->commd = ft_get_commd(pipex);
	if (pipex->commd == 0)
	{
		ft_free_child(pipex);
		mesg(ERR_CMD);
		exit(-1);
	}
	execve(pipex->commd, pipex->commd_args, envp);
}

void	child_two(t_pipex *pipex, char **argv, char **envp)
{
	dup2(pipex->pipe[0], STDIN_FILENO);
	close(pipex->pipe[1]);
	dup2(pipex->outfile, STDOUT_FILENO);
	pipex->commd_args = ft_split(argv[3], ' ');
	pipex->commd = ft_get_commd(pipex);
	if (pipex->commd == 0)
	{
		ft_free_child(pipex);
		mesg(ERR_CMD);
		exit(-1);
	}
	execve(pipex->commd, pipex->commd_args, envp);
}
