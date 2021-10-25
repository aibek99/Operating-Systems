#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <linux/limits.h>
#include <dirent.h>

typedef struct Node {
    int inode;
    char *name;
} node;

int cmp (const void *n1, const void *n2) {
    node a = *((node*)n1);
    node b = *((node*)n2);
    if (a.inode > b.inode) return 1;
    if (a.inode < b.inode) return -1;
    return 0;
}

int main(void) {
    FILE *fp;
    fp = freopen("ex4.txt", "w", stdout);

    int num_files = 0;
    node *files;

    chdir("tmp");

    DIR *folder = opendir(".");
    struct dirent *info;
    struct stat check;

    while ((info = readdir(folder)) != NULL) {
        num_files ++;
        files = (node *)realloc(files, num_files * sizeof(node));
        files[num_files - 1].inode = info -> d_ino;
        files[num_files - 1].name = info -> d_name;
    }

    closedir(folder);

    chdir ("..");

    qsort(files, num_files, sizeof(node), cmp);

    printf ("File    -   Hard Links\n");
    for (int i = 0; i < num_files; i ++) {
        int inode = files[i].inode, j = 0;
        while (files[i].inode == files[i + j].inode) j ++;
        if (j > 1) {
            printf ("inode : %d  -  ", inode);
            while (i < num_files && files[i].inode == inode) {
                printf ("%s ", files[i].name);
                i ++;
            }
            printf ("\n");
        }
    }

    fclose(fp);
    return EXIT_SUCCESS;
}






