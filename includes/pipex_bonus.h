/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:17:37 by alvicina          #+#    #+#             */
/*   Updated: 2024/01/02 16:04:37 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
# define ERR_ENVP "Environment"
# define ERR_HEREDOC "here_doc"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		*pipe;
	char	*path;
	char	**commd_path;
	char	**commd_args;
	char	*commd;
	pid_t	pid;
	int		cmd_nmbs;
	int		pipe_nmbs;
	int		here_doc;
	int		id;
}	t_pipex;

int		ft_msg(char *string);
int		ft_msg_error(char *string);
int		ft_here_doc(char *argv, t_pipex *pipex);
int		ft_get_infile(char **argv, t_pipex *pipex);
int		ft_get_outfile(char *argv, t_pipex *pipex);
int		ft_free_pipe(t_pipex *pipex);
int		ft_parent_free(t_pipex *pipex);
void	ft_close(t_pipex *pipex);
void	ft_child(t_pipex *p, char **argv, char **envp);
void	ft_msg_pipe(char *string);
void	ft_child_free(t_pipex *pipex);
void	ft_wait(t_pipex *pipex);

#endif