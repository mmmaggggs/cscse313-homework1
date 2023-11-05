#include <iostream>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int openr(const char* pathname) {
    int file_fd = open(pathname, O_RDONLY);
	if (file_fd == -1) {
        perror("file does not exist");
        exit(1);
    }
    return file_fd;
}
int main (int argc, char* argv[]) {
    if (argc != 2) {
        cerr << argv[0] << endl;
        return 1;
    }
    
    const char* file = argv[1];
    int fd;
    fd = openr(file);
    if (fd != -1) {
        std::cout << "successful: " << fd << std::endl;
        close(fd);
    }
    return 0;
}
// sets up arguments for the unix open system call
// with 0_read flag and returns the syetm call result

// in main:
// - program takes pathname argument
// - call openr
// - output stdout

// write a stub in x86-64 assembly for openr()