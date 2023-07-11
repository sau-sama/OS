#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 512

struct my_msg {
    long int msg_type;
    char some_text[MAX_TEXT];
};

int main() {
    int running = 1;
    int msgid;
    struct my_msg some_data;
    char buffer[50];

    msgid = msgget((key_t)14534, 0666 | IPC_CREAT);
    if (msgid == -1) {
        printf("Error in creating queue\n");
        exit(0);
    }

    while (running) {
        printf("Enter some text:\n");
        fgets(buffer, 50, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';  // Remove trailing newline character

        some_data.msg_type = 1;
        strncpy(some_data.some_text, buffer, MAX_TEXT);

        if (msgsnd(msgid, (void *)&some_data, sizeof(struct my_msg) - sizeof(long int), 0) == -1) {
            printf("Failed to send message\n");
        }

        if (strncmp(buffer, "end", 3) == 0) {
            running = 0;
        }
    }

    return 0;
}
