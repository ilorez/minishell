
#include "./debug.h"

t_ast *example_builtin_list_0()
{
    t_ast *ast;
    char **argv;


    argv = ft_calloc(4, sizeof(char *));
    argv[3] = NULL;
    argv[0] = ft_strdup("echo");
    argv[1] = ft_strdup("-n");
    argv[2] = ft_strdup("'Hello, Wrold!'");
    _print_list_cmd("echo -n 'Hello, World!' && cd /tmp && pwd && export TEST_VAR=42 && env && unset TEST_VAR && exit");

    // Constructing the AST for the command sequence
    ast = ex_bi(T_AND,
                ex_exec_2(argv),
                ex_bi(T_AND,
                      ex_exec("cd /tmp"),
                      ex_bi(T_AND,
                            ex_exec("pwd"),
                            ex_bi(T_AND,
                                  ex_exec("export TEST_VAR=42"),
                                  ex_bi(T_AND,
                                        ex_exec("env"),
                                        ex_bi(T_AND,
                                              ex_exec("unset TEST_VAR"),
                                              ex_exec("exit")
                                        )
                                  )
                            )
                      )
                )
    );

    return ast;
}
