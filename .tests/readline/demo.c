#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

void handle_sigint(int sig) {
    printf("signal: %d\n", sig);
    rl_on_new_line();
    rl_replace_line("", 0);  // Clear input buffer
    rl_redisplay();
}

void init_history() {
    rl_clear_history();
    add_history("sample history entry 1");
    add_history("sample history entry 2");
}

int main() {
    char *input;
    
    signal(SIGINT, handle_sigint);
    init_history();

    while (1) {
        input = readline("custom> ");
        
        if (!input) break;
        
        if (*input) {
            add_history(input);
            
            if (strcmp(input, "replace") == 0) {
                printf("replace\n");
                rl_replace_line("Replaced text!", 10);
                rl_redisplay();
            }
        }
        
        printf("Processed: %s\n", input);
        free(input);
    }
    
    return 0;
}
