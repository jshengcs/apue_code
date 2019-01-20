#include "apue.h"
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirent;

    if (argc != 2) {
        err_quit("usage: ls directory_name");
    }

    if ((dp = opendir(argv[1])) == NULL) {
        err_sys("can't open %s", argv[1]);
    }

    while ((dirent = readdir(dp)) != NULL) {
        printf("%s\n", dirent->d_name);
    }

    closedir(dp);
    exit(0);

}