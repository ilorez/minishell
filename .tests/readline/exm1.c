#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

void handle_sigint(int sig) {
    // 1. Move to new line
    rl_on_new_line();
    
    // 2. Clear current input buffer
    rl_replace_line("", 0);
    
    // 3. Reset cursor position
    rl_point = rl_end;
    
    // 4. Redraw the display
    rl_redisplay();
}

int main() {
    signal(SIGINT, handle_sigint);  // Register Ctrl+C handler
    
    while(1) {
        char *input = readline("SignalDemo> ");
        if (!input) break;
        printf("You entered: %s\n", input);
        free(input);
    }
    return 0;
}
