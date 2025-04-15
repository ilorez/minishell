#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <ctype.h>
#include <signal.h>


int uppercase_transform(int count, int key) {
    // Get current line
   // char *current_line = rl_copy_text(0, rl_end);
    
    // Convert to uppercase
    //for(char *p = current_line; *p; p++)
     //   *p = toupper(*p);
    
    // Replace line content
    // rl_replace_line(current_line, 0);
    
    // Move cursor to end
    rl_point = rl_end;
    
    // Update display
    //rl_redisplay();
    //free(current_line);
    return 0;
}

int main() {
    // Bind to Ctrl-U
    //rl_bind_keyseq("\\C-u", uppercase_transform);
    
    while(1) {
        char *input = readline("UppercaseDemo> ");
        if (!input) break;
        printf("Final input: %s\n", input);
        free(input);
    }
    return 0;
}
