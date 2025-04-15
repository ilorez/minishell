#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>


void show_progress() {
    static const char progress[] = {'-', '\\', '|', '/'};
    static int counter = 0;
    
    // Save current input
    char *original = rl_copy_text(0, rl_end);
    
    // Create progress display
    char display[3] = {progress[counter++ % 4], ' ', '\0'};
    
    // Replace line content
    rl_replace_line(display, 0);
    rl_redisplay();
    
    // Restore original input
    usleep(200000);  // 200ms delay
    rl_replace_line(original, 0);
    rl_redisplay();
    
    free(original);
}

int main() {
    rl_bind_keyseq("\\C-p", (Function *)show_progress);
    
    while(1) {
        char *input = readline("ProgressDemo> ");
        if (!input) break;
        free(input);
    }
    return 0;
}
