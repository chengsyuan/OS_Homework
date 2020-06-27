//
// Created by yingchengxuan on 2020/6/27.
//

#include <iostream>
#include "unistd.h"

void cout_pid(){
    std::cout << "my pid:" << getpid() << std::endl;
}
void cout_son_pid(pid_t t){
    std::cout << "my son's pid:" << t << std::endl;
}

int main() {
    std::cout << "Experiment1" << std::endl;

    pid_t t1 = fork();
    if (t1 == 0){
        // inside son process
        pid_t t2 = fork();
        if (t2 == 0){
            std::cout << "子2" << std::endl; cout_pid();
        } else {
            std::cout << "子1" << std::endl; cout_pid(); cout_son_pid(t2);
        }
    } else {
        std::cout << "父" << std::endl; cout_pid(); cout_son_pid(t1);
    }
    return 0;
}
