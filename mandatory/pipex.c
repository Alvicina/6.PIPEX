/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:41:34 by alvicina          #+#    #+#             */
/*   Updated: 2024/01/03 20:22:43 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_close_pipes(t_pipex *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

static char	*ft_get_path(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			break ;
		i++;
	}
	return (envp[i] + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (mesg(ERR_INPUT));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile == -1)
		return (mesg_err(ERR_INFILE));
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.outfile == -1)
		return (mesg_err(ERR_OUTFILE));
	if (pipe(pipex.pipe) == -1)
		return (mesg_err(ERR_PIPE));
	pipex.path = ft_get_path(envp);
	pipex.commd_path = ft_split(pipex.path, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		child_one(&pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		child_two(&pipex, argv, envp);
	ft_close_pipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	ft_free_parent(&pipex);
	return (0);
}
