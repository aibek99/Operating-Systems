#include <stdio.h>
#include <linux/input.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

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
        if (event.value == event.code && event.code == 0) continue;
        if (event.value == 0) {
            printf ("RELEASED %d %#06x %d\n", event.value, (int)event.code, (int)event.code);
            fflush(stdout);
        }
        else if (event.value == 1) {
            printf ("PRESSED %d %#06x %d\n", event.value, (int)event.code, (int)event.code);
            fflush(stdout);
        }
        else if (event.value == 2) {
            printf ("REPEATED %d %#06x %d\n", event.value, (int)event.code, (int)event.code);
            fflush(stdout);
        }
    }
    return EXIT_SUCCESS;
}



