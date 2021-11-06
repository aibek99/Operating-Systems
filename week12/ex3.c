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

    int map[1000];

    while (1) {
        struct input_event event;
        read(check, &event, sizeof(event));
        if (event.value == 0) {
            map[event.code] = 0;
        }
        else if (event.value == 1) {
            map[event.code] = 1;
            if (map[25] == 1 && map[18] == 1) {
                printf ("I passed the Exam!\n");
            }
            if (map[46] == 1 && map[30] == 1 && map[25] == 1) {
                printf ("Get some cappuccino!\n");
            }
        }
        else if (event.value == 2) {
            map[event.code] = 1;
            if (map[25] == 1 && map[18] == 1) {
                printf ("I passed the Exam!\n");
            }
            if (map[46] == 1 && map[30] == 1 && map[25] == 1) {
                printf ("Get some cappuccino!\n");
            }
        }
    }
    return EXIT_SUCCESS;
}


