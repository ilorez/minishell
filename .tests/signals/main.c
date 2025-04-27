#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Simple signal handler for SIGINT
void handle_sigint(int sig) {
    printf("Caught SIGINT (Ctrl+C). Doing important work safely...\n");
    sleep(20);  // Simulate important work
    printf("Finished work after SIGINT.\n");
}

int main() {
    struct sigaction sa;

    // Set the handler function
    sa.sa_handler = handle_sigint;

    // Initialize the mask to empty
    sigemptyset(&sa.sa_mask);

    // Add SIGTERM to the mask (block it while handle_sigint is running)
    sigaddset(&sa.sa_mask, SIGTERM);

    // No special flags
    sa.sa_flags = 0;

    // Install the handler for SIGINT
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Running... Press Ctrl+C to trigger SIGINT handler.\n");
    printf("Send SIGTERM while SIGINT is being handled to see it blocked.\n");

    // Infinite loop
    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}

