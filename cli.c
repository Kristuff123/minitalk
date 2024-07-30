#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_printf.h"

volatile sig_atomic_t g_ack_received = 0;

void ack_handler(int sig) {
    (void)sig;  // Unused parameter
    g_ack_received = 1;
}

void send_char(pid_t server_pid, char c) {
    int i = 0;
    while (i < 8) {
        g_ack_received = 0;
        if (c & (1 << i)) {
            kill(server_pid, SIGUSR2);
        } else {
            kill(server_pid, SIGUSR1);
        }
        while (!g_ack_received) {
            pause();  // Wait for acknowledgment
        }
        i++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t server_pid = ft_atoi(argv[1]);
    char *message = argv[2];

    signal(SIGUSR1, ack_handler);  // Set up acknowledgment handler

    size_t i = 0;
    while (message[i] != '\0') {
        send_char(server_pid, message[i]);
        i++;
    }

    // Send newline character at the end
    send_char(server_pid, '\n');

    return 0;
}

