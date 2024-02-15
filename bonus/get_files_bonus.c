/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:20:56 by alvicina          #+#    #+#             */
/*   Updated: 2024/01/02 16:02:31 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	ft_get_outfile(char *argv, t_pipex *pipex)
{
	if (pipex->here_doc)
	{
		pipex->outfile = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0000644);
		if (pipex->outfile < 0)
			return (ft_msg_error(ERR_OUTFILE), 1);
	}
	else
	{
		pipex->outfile = open(argv, O_CREAT | O_RDWR | O_TRUNC, 0000644);
		if (pipex->outfile < 0)
			return (ft_msg_error(ERR_OUTFILE), 1);
	}
	return (0);
}

int	ft_get_infile(char **argv, t_pipex *pipex)
{
	if (pipex->here_doc)
	{
		if (ft_here_doc(argv[2], pipex))
			return (ft_msg_error(ERR_HEREDOC), 1);
	}
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile < 0)
			return (ft_msg_error(ERR_INFILE), 1);
	}
	return (0);
}
