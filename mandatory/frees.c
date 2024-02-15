/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:26:31 by alvicina          #+#    #+#             */
/*   Updated: 2023/12/29 10:53:33 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_parent(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	while (pipex->commd_path[i])
	{
		free(pipex->commd_path[i]);
		i++;
	}
	free(pipex->commd_path);
}

void	ft_free_child(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	while (pipex->commd_args[i])
	{
		free(pipex->commd_args[i]);
		i++;
	}
	free(pipex->commd_args);
}
