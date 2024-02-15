/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:17:48 by alvicina          #+#    #+#             */
/*   Updated: 2024/01/02 16:04:06 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* proper defs ex. pid*/
# include <sys/types.h>
/* to open, unlink */
# include <fcntl.h>
/* to use perror, strerror */
# include <stdio.h>
/* to use write, read, close  */
# include <unistd.h>
/* to use malloc, free, exit, access, pipe, dup, dup2, execve, fork */
# include <stdlib.h>
/* to use my libft */
# include "../libft/libft.h"

# define ERR_INPUT "Incorrect number of arguments"
# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_PIPE "Pipe"
# define ERR_CMD "command not found"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipe[2];
	char	*path;
	char	**commd_path;
	char	**commd_args;
	char	*commd;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

int		mesg(char *err);
int		mesg_err(char *err);
void	child_one(t_pipex *pipex, char **argv, char **envp);
void	child_two(t_pipex *pipex, char **argv, char **envp);
void	ft_free_parent(t_pipex *pipex);
void	ft_free_child(t_pipex *pipex);

#endif