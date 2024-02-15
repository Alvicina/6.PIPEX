/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:56:39 by alejandro         #+#    #+#             */
/*   Updated: 2024/01/02 16:02:14 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	ft_parent_free(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->here_doc)
		unlink(".heredoc_temp");
	while (pipex->commd_path[i])
	{
		free(pipex->commd_path[i]);
		i++;
	}
	free(pipex->commd_path);
	free(pipex->pipe);
	return (1);
}

int	ft_free_pipe(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->here_doc)
		unlink(".heredoc_temp");
	free(pipex->pipe);
	return (ft_msg_error(ERR_ENVP), -1);
}

void	ft_child_free(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	while (pipex->commd_args[i])
	{
		free(pipex->commd_args[i]);
		i++;
	}
	free(pipex->commd_args);
	free(pipex->commd);
}
