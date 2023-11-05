// reference counting on filesystem objects
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <fstream>
#include <sys/wait.h>
#include <pthread.h>

using namespace std;


int main () {
    const char* pathname = "test.txt";
 
    int fd[2];

    if (pipe(fd) == -1) {
        perror("pipe");
    }
    

    // forks so fd is availabe to chid
    pid_t process = fork();
    
    // child
    if (process == 0) {
        // read file even if file is deleted 
        ifstream cFile(pathname);
        string lines;
        while (getline(cFile, lines)) {
            std::cout << "Child Lines from '" << pathname << "': " << lines << std::endl;
        }
    }
    else if (process > 0) {
        // parent
        // open existing file for reading
        int status;
        std::fstream file;

        file.open(pathname, ios::in);
        // closes and deletes the file using unlink
        file.close();
        unlink(pathname);

        // verify file is gone by using ls
        std::cout << ">>ls output from parent process: " << std::endl;
        system("ls");

        // send sychonization message to child over pipe
        waitpid(process, &status, 0);
    }



}

/*------WHAT MIGHT BE HAPPENING------
in this program, when the fork occurs, there is a shared object
representation that is created. It refers to the file with the shared
representation and doesn't recreate it until all of it disappears, being unlinked.
*/