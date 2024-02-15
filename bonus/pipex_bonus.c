/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:15:36 by alvicina          #+#    #+#             */
/*   Updated: 2024/01/02 16:03:50 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_close(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->pipe_nmbs)
	{
		close(pipex->pipe[i]);
		i++;
	}
}

static int	ft_create_pipe(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_nmbs -1)
	{
		if (pipe(pipex->pipe + 2 * i) < 0)
			return (ft_parent_free(pipex), 1);
		i++;
	}
	return (0);
}

static char	*ft_get_path(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PATH", envp[i], 4))
			return (envp[i] + 5);
		i++;
	}
	return (0);
}

static int	ft_check_input(char *argv, t_pipex *pipex)
{
	if (!ft_strncmp("here_doc", argv, 9))
		return (pipex->here_doc = 1, 6);
	else
		return (pipex->here_doc = 0, 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < ft_check_input(argv[1], &pipex))
		return (ft_msg(ERR_INPUT));
	if (ft_get_infile(argv, &pipex))
		return (-1);
	if (ft_get_outfile(argv[argc - 1], &pipex))
		return (-1);
	pipex.cmd_nmbs = argc - 3 - pipex.here_doc;
	pipex.pipe_nmbs = 2 * (pipex.cmd_nmbs - 1);
	pipex.pipe = malloc(sizeof(int) * pipex.pipe_nmbs);
	if (pipex.pipe == NULL)
		return (ft_msg_error(ERR_PIPE), -1);
	pipex.path = ft_get_path(envp);
	pipex.commd_path = ft_split(pipex.path, ':');
	if (!pipex.commd_path)
		return (ft_free_pipe(&pipex));
	if (ft_create_pipe(&pipex))
		return (ft_msg_error(ERR_PIPE), -1);
	pipex.id = -1;
	while (++pipex.id < pipex.cmd_nmbs)
		ft_child(&pipex, argv, envp);
	ft_close(&pipex);
	ft_wait(&pipex);
	return (ft_parent_free(&pipex), 0);
}
