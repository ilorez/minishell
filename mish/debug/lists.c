
#include "./debug.h"


// [x] - 
t_ast *example_list_0()
{
	t_ast *ast;
  _print_list_cmd("echo hello world");
	ast = ex_exec("echo hello world");
	return ast;
}

// [x] - 
t_ast *example_list_1() 
{
	t_ast *ast = calloc(1, sizeof(t_ast));
	if (!ast) return NULL;

  _print_list_cmd("(sleep 2 | echo hi1) && (sleep 2 && echo hi2)");
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

// [x] - hard test for quotes with wild card
t_ast *example_list_4()
{
	t_ast *ast;
  _print_list_cmd("echo *'ai'*.c *'*'* *\"*\"* *\"$wild\"* Ma$wild'file'");
	ast = ex_exec("echo *'ai'*.c *'*'* *\"*\"* *\"$wild\"* Ma$wild'file'");
	return ast;
}

// [x]
t_ast *example_list_5()
{
	t_ast *ast;
  _print_list_cmd("echo $? $1b  $~ $$ $HOME $PWD $-");
	ast = ex_exec("echo $? $1b  $~ $$ $HOME $PWD $-");
	return ast;
}

// [ ]
t_ast *example_list_6()
{
	t_ast *ast;
  _print_list_cmd("cd libft | pwd");
	ast = ex_bi(T_PIPE, ex_exec("cd libft"), ex_exec("pwd"));
	return ast;
}


t_ast *example_list_7()
{
	t_ast *ast;
	_print_list_cmd("false || echo fallback");
	ast = ex_bi(T_OR, ex_exec("false"), ex_exec("echo fallback"));
	return ast;
}

t_ast *example_list_8()
{
	t_ast *ast;
	_print_list_cmd("true && false || echo recovered");
	ast = ex_bi(T_OR, ex_bi(T_AND, ex_exec("true"), ex_exec("false")), ex_exec("echo recovered"));
	return ast;
}

t_ast *example_list_9()
{
	t_ast *ast;
	_print_list_cmd("echo hi > out.txt");
	ast = ex_redir("out.txt", 1, O_CREAT | O_WRONLY | O_TRUNC, ex_exec("echo hi"));
	return ast;
}

t_ast *example_list_10()
{
	t_ast *ast;
	_print_list_cmd("echo hi >> out.txt");
	ast = ex_redir("out.txt", 1, O_CREAT | O_WRONLY | O_APPEND, ex_exec("echo hi"));
	return ast;
}

t_ast *example_list_11()
{
	t_ast *ast;
	_print_list_cmd("cat < infile | grep hi");
	ast = ex_bi(T_PIPE, ex_redir("infile", 0, O_RDONLY, ex_exec("cat")), ex_exec("grep hi"));
	return ast;
}

t_ast *example_list_12()
{
	t_ast *ast;
	_print_list_cmd("(echo hello) > file.txt");
	ast = ex_redir("file.txt", 1, O_CREAT | O_WRONLY | O_TRUNC, ex_subshell(ex_exec("echo hello")));
	return ast;
}


t_ast *example_list_13()
{
    t_ast *ast;
    _print_list_cmd("(cd /tmp && (mkdir test_dir || echo \"Failed to create directory\")) && echo \"Success\" > result.txt");

    // Inner subshell: (mkdir test_dir || echo "Failed to create directory")
    t_ast *inner_subshell = ex_subshell(
        ex_bi(T_OR,
              ex_exec("mkdir test_dir"),
              ex_exec("echo Failed to create directory")));

    // Outer subshell: (cd /tmp && inner_subshell)
    t_ast *outer_subshell = ex_subshell(
        ex_bi(T_AND,
              ex_exec("cd /tmp"),
              inner_subshell));

    // echo "Success"
    t_ast *echo_success = ex_exec("echo Success");

    // Redirect echo_success to result.txt
    t_ast *redir = ex_redir("result.txt", 1, O_CREAT | O_WRONLY | O_TRUNC, echo_success);

    // Combine outer_subshell && redir
    ast = ex_bi(T_AND, outer_subshell, redir);
    return ast;
}

t_ast *example_list_14()
{
    t_ast *ast;
    _print_list_cmd("cat << EOF | grep \"pattern\"");

    // Here-document content
    const char *heredoc_content = "line 1\npattern line\nline 3\n";

    // Create a temporary file to simulate the here-document
    const char *tmp_filename = "/tmp/heredoc_example.txt";
    FILE *tmp_file = fopen(tmp_filename, "w");
    if (tmp_file) {
        fputs(heredoc_content, tmp_file);
        fclose(tmp_file);
    }

    // cat < /tmp/heredoc_example.txt
    t_ast *cat_cmd = ex_redir((char *)tmp_filename, 0, O_RDONLY, ex_exec("cat"));

    // grep "pattern"
    t_ast *grep_cmd = ex_exec("grep pattern");

    // Combine cat_cmd | grep_cmd
    ast = ex_bi(T_PIPE, cat_cmd, grep_cmd);
    return ast;
}


t_ast *example_list_15()
{
    t_ast *ast;
    char **argv;


    argv = ft_calloc(3, sizeof(char *));
    argv[2] = NULL;
    argv[0] = ft_strdup("awk");
    argv[1] = ft_strdup("'{print $2}'");
    _print_list_cmd("ps aux | grep \"bash\" | awk '{print $2}' > bash_pids.txt");

    // ps aux
    t_ast *ps_cmd = ex_exec("ps aux");

    // grep "bash"
    t_ast *grep_cmd = ex_exec("grep bash");

    // awk '{print $2}'
    t_ast *awk_cmd = ex_exec_2(argv);

    // Combine ps_cmd | grep_cmd
    t_ast *pipe1 = ex_bi(T_PIPE, ps_cmd, grep_cmd);

    // Combine pipe1 | awk_cmd
    t_ast *pipe2 = ex_bi(T_PIPE, pipe1, awk_cmd);

    // Redirect output to bash_pids.txt
    ast = ex_redir("bash_pids.txt", 1, O_CREAT | O_WRONLY | O_TRUNC, pipe2);
    return ast;
}

t_ast *example_list_16()
{
    t_ast *ast;
    _print_list_cmd("ls -l | tee filelist.txt | grep \"^d\" > directories.txt");

    // Step 1: Create the 'ls -l' command node
    t_ast *ls_cmd = ex_exec("ls -l");

    // Step 2: Create the 'tee filelist.txt' command node
    t_ast *tee_cmd = ex_exec("tee filelist.txt");

    // Combine 'ls -l' and 'tee filelist.txt' using a pipe
    t_ast *pipe1 = ex_bi(T_PIPE, ls_cmd, tee_cmd);

    // Step 3: Create the 'grep "^d"' command node
    t_ast *grep_cmd = ex_exec("grep ^d");

    // Redirect the output of 'grep "^d"' to 'directories.txt'
    t_ast *redir = ex_redir("directories.txt", 1, O_CREAT | O_WRONLY | O_TRUNC, grep_cmd);

    // Combine the previous pipe with the redirection
    ast = ex_bi(T_PIPE, pipe1, redir);

    return ast;
}
