/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 13:53:48 by alejandro         #+#    #+#             */
/*   Updated: 2024/01/02 16:00:19 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static char	*ft_get_commd(char **commd_path, char *commd_args)
{
	size_t	i;
	char	*temp;
	char	*command;

	i = 0;
	while (commd_path[i])
	{
		temp = ft_strjoin(commd_path[i], "/");
		command = ft_strjoin(temp, commd_args);
		free(temp);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

static void	ft_sub_dup2(int st_in, int st_out)
{
	dup2(st_in, STDIN_FILENO);
	dup2(st_out, STDOUT_FILENO);
}

void	ft_child(t_pipex *p, char **argv, char **envp)
{
	p->pid = fork();
	if (p->pid == 0)
	{
		if (p->id == 0)
			ft_sub_dup2(p->infile, p->pipe[1]);
		else if (p->id == p->cmd_nmbs - 1)
			ft_sub_dup2(p->pipe[2 * p->id - 2], p->outfile);
		else
			ft_sub_dup2(p->pipe[2 * p->id -2], p->pipe[2 * p->id + 1]);
		ft_close(p);
		p->commd_args = ft_split(argv[2 + p->here_doc + p->id], ' ');
		p->commd = ft_get_commd(p->commd_path, p->commd_args[0]);
		if (p->commd == NULL)
		{
			ft_msg_pipe(p->commd_args[0]);
			ft_child_free(p);
			exit(1);
		}
		execve(p->commd, p->commd_args, envp);
	}
}
