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
    long int msg_to_rec = 0;

    msgid = msgget((key_t)14534, 0666 | IPC_CREAT);
    if (msgid == -1) {
        printf("Error in creating queue\n");
        exit(0);
    }

    while (running) {
        if (msgrcv(msgid, (void *)&some_data, sizeof(struct my_msg) - sizeof(long int), msg_to_rec, 0) == -1) {
            printf("Failed to receive message\n");
        }

        printf("Data received: %s\n", some_data.some_text);

        if (strncmp(some_data.some_text, "end", 3) == 0) {
            running = 0;
        }
    }

    if (msgctl(msgid, IPC_RMID, 0) == -1) {
        printf("Failed to delete message queue\n");
    }

    return 0;
}
