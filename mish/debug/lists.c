
#include "./debug.h"

static void _print_list_cmd(char *cmd)
{
  printf("================================================\n");
  printf("%s\n", cmd);
  printf("================================================\n");
}
// [x] - (ls | echo hi) && (sleep 2 && echo hi2)
t_ast *example_list_1() 
{
	t_ast *ast = calloc(1, sizeof(t_ast));
	if (!ast) return NULL;

  _print_list_cmd("(ls | echo hi) && (sleep 2 && echo hi2)");
	ast->type = T_AND;
	ast->left = ex_subshell(ex_bi(T_PIPE, ex_exec("sleep 2"), ex_exec("echo hi1")));
	ast->right = ex_subshell(ex_bi(T_AND, ex_exec("sleep 2"), ex_exec("echo hi2")));
	return ast;
}

// export a=".md libf"
// [x] - echo *$a'*' && echo ------------------ && echo *$a* 
t_ast *example_list_2()
{
	t_ast *ast;
  _print_list_cmd("echo *$a'*' && echo ------------------ && echo *$a*");
	ast = ex_bi(T_AND, ex_bi(T_AND, ex_exec("echo *$a'*'"), ex_exec("echo -----------------")), ex_exec("echo *$a*"));
	return ast;
}

// [x]
t_ast *example_list_3()
{
	t_ast *ast;
  _print_list_cmd("echo \"*\"\"$a\"* && echo \"*$a'*'\"");
	ast = ex_bi(T_AND, ex_exec("echo \"*\"\"$a\"*"), ex_exec("echo \"*$a'*'\""));
	return ast;
}

// [ ] - hard test for quotes with wild card
t_ast *example_list_4()
{
	t_ast *ast;
  _print_list_cmd("echo *'ai'*.c *'*'* *\"*\"* *\"$wild\"* Ma$wild'file'");
	ast = ex_exec("echo *'ai'*.c *'*'* *\"*\"* *\"$wild\"* Ma$wild'file'");
	return ast;
}

