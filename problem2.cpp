#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <iostream>


void intro() {
    int x = 2;
    int y = 4;
    for (int i = 0; i < x * y; i++) {
        std::cout << "Hello world! ";
    }
    //std::endl;
}



int main() {
    struct timespec start, end;
    long long elapsed_ns;
    
    // Get the start time
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    // Perform some computation or code
    intro();
    // Get the end time
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

    // Calculate the elapsed time in nanoseconds
    elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000 +
    (end.tv_nsec - start.tv_nsec);

    // Print the elapsed time
    printf("Elapsed Time: %lld nanoseconds\n", elapsed_ns);



    return 0;
}