#include <iostream>
#include "unistd.h"

void cout_pid() {
    std::cout << "my pid:" << getpid() << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc == 1) { // 1 means no arg except itself
        char *arglist[] = {"./course", "min", "111", "222", "333", NULL};
        char *env[] = {NULL};
        execve(arglist[0], arglist, env);
    } else {
        if (!strcmp(argv[1], "max")) {
            int t1, t2, t;
            sscanf(argv[2], "%d", &t1);
            sscanf(argv[3], "%d", &t2);
            t = t1 > t2 ? t1 : t2;
            std::cout << "max(" << t1 << "," << t2 << ")=" << t << std::endl;
        } else if (!strcmp(argv[1], "min")) {
            int t1, t2, t;
            sscanf(argv[2], "%d", &t1);
            sscanf(argv[3], "%d", &t2);
            t = t1 < t2 ? t1 : t2;
            std::cout << "min(" << t1 << "," << t2 << ")=" << t << std::endl;
        } else if (!strcmp(argv[1], "average")) {
            float t1, t2, t3, t;
            sscanf(argv[2], "%f", &t1);
            sscanf(argv[3], "%f", &t2);
            sscanf(argv[4], "%f", &t3);
            t = (t1 + t2 + t3) / 3.0;
            std::cout << "average(" << t1 << "," << t2 << "," << t3 << ")=" << t << std::endl;
        } else {
            std::cout << argv[1] << "not valid params" << std::endl;
        }
    }
    return 0;
}
