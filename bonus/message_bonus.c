/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:23:26 by alvicina          #+#    #+#             */
/*   Updated: 2024/01/02 16:03:05 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_wait(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_nmbs)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
}

void	ft_msg_pipe(char *string)
{
	write(2, ERR_CMD, ft_strlen(ERR_CMD));
	write(2, string, ft_strlen(string));
	write(2, "\n", 1);
}

int	ft_msg(char *string)
{
	return (write(2, string, ft_strlen(string)));
}

int	ft_msg_error(char *string)
{
	perror(string);
	return (-1);
}
