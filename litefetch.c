#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

#define ANSI_BOLD "\x1b[1m"
#define ANSI_RESET "\x1b[0m"

void printSystemInfo() {
    struct utsname system_info;
    if (uname(&system_info) != 0) {
        fprintf(stderr, "Error retrieving system information\n");
        return;
    }

    char *username = getenv("USER");

    printf("%sKERNEL%s %s\n", ANSI_BOLD, ANSI_RESET, system_info.release);
    printf("%sHOST%s %s\n", ANSI_BOLD, ANSI_RESET, system_info.nodename);
    printf("%sLOCALE%s %s\n", ANSI_BOLD, ANSI_RESET, getenv("LANG"));
    printf("%sUSER%s %s\n", ANSI_BOLD, ANSI_RESET, (username != NULL) ? username : "Unknown");
}

int main() {
    printSystemInfo();

    return 0;
}

