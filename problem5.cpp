#include <iostream>
#include <sys/resource.h>
#include <signal.h>
#include <sys/stat.h>

int main () {
    // program that determines the max num of open files permitted by a process in OS
    struct stat max_fd;
    // find max file descriptors
    // open as manu files i can
    // when reach max files
    // throw emfile == nerror 

    // use sysconf? or unlimit -n?
    
};
