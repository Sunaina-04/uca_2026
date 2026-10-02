#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Global variable to count signal triggers
volatile sig_atomic_t signal_count = 0;

// Signal handler function for SIGINT
void handle_sigint(int sig) {
    signal_count++;
    printf("\n[Signal Caught] Received SIGINT (Signal %d) | Total Ctrl+C pressed: %d\n", sig, signal_count);
    
    // Optional: Exit program after pressing Ctrl+C 3 times
    if (signal_count >= 3) {
        printf("Exiting program after 3 signals...\n");
        exit(0);
    }
}

int main() {
    // Register the signal handler for SIGINT using the signal() function
    if (signal(SIGINT, handle_sigint) == SIG_ERR) {
        perror("Failed to register SIGINT handler");
        return 1;
    }

    printf("Program running (PID: %d). Try pressing Ctrl+C...\n", getpid());

    while (1) {
        sleep(1);
    }

    return 0;
} 
