#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <locale.h>
#include <langinfo.h>
#include <unistd.h>

// ASCII art for the Tux logo
const char* tux_logo = 
"       .--.\n"
"      |o_o |\n"
"      |:_/ |\n"
"     //   \\ \\\n"
"    (|     | )\n"
"   /'\\_   _/`\\\n"
"   \\___)=(___/\n";

int main() {
    // Retrieve system information
    struct utsname system_info;
    if (uname(&system_info) != 0) {
        perror("uname");
        return 1;
    }

    // Get the username
    char* username = getlogin();

    // Get system locale
    char* system_locale = setlocale(LC_ALL, NULL);

    printf("kernel: %s\n", system_info.release);
    printf("hostname: %s\n", system_info.nodename);
    printf("architecture: %s\n", system_info.machine);
    printf("user: %s\n", (username != NULL) ? username : "Unknown");
    
    printf("%s\n", tux_logo);

    return 0;
}

