/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:51:03 by tsekiguc          #+#    #+#             */
/*   Updated: 2022/02/15 21:26:49 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void
infile_part(char *token)
{
	int	fd;

	fd = open(&token[2], O_RDONLY);
	if (fd < 0)
		ms_error("open");
	close(0);
	dup2(fd, 0);
	close(fd);
}

char
*rl_gets_heredoc(void)
{
	char	*line_read;

	line_read = readline("heredoc > ");
	return (line_read);
}

void
heredoc_loop(int fd, char *token)
{
	char	*line;
	//int		result;

	while(1)
	{
		//write(STDOUT, "heredoc > ", 10);
		//result = get_next_line(STDIN, &line);
		line = rl_gets_heredoc();
		if (ms_strcmp(line, &token[3]) == 0)
			break ;
		write(fd, line, ms_strlen(line));
		write(fd, "\n", 1);
		free(line);
		if (result == ERROR)
		{
			close(fd);
			ms_error("gnl failed");
		}
		else if (result == END)
			break ;
		else
		{
			if (ms_strcmp(line, &token[3]) == 0)
				break ;
			write(fd, line, ms_strlen(line));
			write(fd, "\n", 1);
		}
	}
}

void	heredoc_part(char *token)
{
	int	fd;

	//make tmp file for input heredoc
	fd = open("./tmp", O_WRONLY | O_CREAT | O_EXCL | O_TRUNC, 0600);
	if (fd < 0)
		ms_error("open");

	//exec heredoc
	heredoc_loop(fd, token);
	close(fd);

	fd = open("./tmp", O_RDONLY);
	if (fd < 0)
		ms_error("open failed");

	unlink("./tmp");

	close(0);
	dup2(fd, 0);
	close(fd);
}

void	do_redirect(char *token, t_kind kind)
{
	if (kind == INFILE)
		infile_part(token);
	else if (kind == HEREDOC)
		heredoc_part(token);
}*/
