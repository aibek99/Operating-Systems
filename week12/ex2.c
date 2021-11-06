#include <stdio.h>
#include <linux/input.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

void pressed() {
    printf ("PRESSED ");
}

void released() {
    printf ("RELEASED ");
}

void repeated() {
    printf ("REPEATED ");
}

int main(void) {
    /// %x - hexadecimal
    int check = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    if (check == -1) {
        puts("FAILED TO OPEN THE FILE!");
        return check;
    }
    while (1) {
        struct input_event event;
        read(check, &event, sizeof(event));
        if (event.type == 0) released();
        else if (event.type == 1) pressed();
        else if (event.type == 2) repeated();
        printf ("%d %x %d\n", event.value, event.code, event.code);
        fflush(stdout);
    }
    return EXIT_SUCCESS;
}


///linux/input-event-code.h
