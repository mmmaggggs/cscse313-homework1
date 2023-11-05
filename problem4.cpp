#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    string file_path;

    // user file path
    std::cout << "Enter pathname: ";
    std::cin >> file_path;
    
    struct stat deets;

    // lstat 
    if (lstat(file_path.c_str(), &deets) == 0) {
        // displays metadata
        // if corresponds to a file/pipe/symlink
        if (S_ISREG(deets.st_mode)) {
            std::cout << "File" << std::endl;
        }
        if (S_ISFIFO(deets.st_mode)) {
            std::cout << "Pipe" << std::endl;
        }
        if (S_ISLNK(deets.st_mode)) {
            std::cout << "Symbolic Link" << std::endl;
        }

        // permissions of the owner of the file 
        std::cout << "Permissions of the Owner: " << (deets.st_mode & 0777) << std::endl;
    }
}