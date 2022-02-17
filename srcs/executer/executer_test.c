/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:31:08 by tsekiguc          #+#    #+#             */
/*   Updated: 2022/02/17 14:28:56 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status;

void	print_list(t_list *list, char *kind)
{
	t_list	*current;

	printf("%-10s: ", kind);
	current = list;
	while (current != NULL)
	{
		printf("[%s] ", (char *)current->content);
		current = current->next;
	}
	printf("\n");
}

void	print_cmd(t_cmd *cmd)
{
	printf("\n");
	print_list(cmd->cmd, "cmd");
	print_list(cmd->infile, "infile");
	print_list(cmd->outfile, "outfile");
	printf("\n\n");
}

void	print_cmds(t_list *cmds)
{
	t_list	*current;

	current = cmds;
	while (current != NULL)
	{
		print_cmd(current->content);
		current = current->next;
	}
}

void	test(char *str)
{
	t_list	*tokens;
	t_list	*cmds;

	printf("***********test************\n");
	printf("[command] : %s\n", str);
	tokens = NULL;
	lexer(&tokens, str);
	cmds = NULL;
	parser(&cmds, tokens);
	expander(cmds);
	print_cmds(cmds);
	printf("***********test************\n\n");
	executer(cmds);
}

int main(void)
{
//	test("/bin/cat << LOVE");
//	test("/bin/ls -a -l | /usr/bin/grep git | /usr/bin/wc ");
//	test("echo This is echo test");
//	test("cat << END");
//	test("cat < Makefile < .gitignore << END");
//	test("cat < Makefile < .gitignore << END | grep a < Makefile | wc -l");
	test("cat < Makefile | wc > outfile");
	//test("/bin/cat Makefile | /usr/bin/wc -l");
	//test("/bin/cat < .gitmodules < Makefile < .gitignore");
	//test("/bin/cat << END < Makefile < .gitignore");
	//test("/bin/cat << END < Makefile < .gitignore | /usr/bin/wc -l | wc -l");
	//test("/bin/cat < Makefile < .gitignore | /usr/bin/wc -l");
	//test("env");
	//test("export TEST=taiyou");
//	test("env");
//	test("cd ..");
	return (0);
}
