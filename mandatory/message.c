/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:00:19 by alvicina          #+#    #+#             */
/*   Updated: 2023/12/29 10:53:28 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	mesg(char *err)
{
	return (write(2, err, ft_strlen(err)));
}

int	mesg_err(char *err)
{
	perror(err);
	return (-1);
}
