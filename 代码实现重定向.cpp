#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>

using namespace std;

int main(int argc, char *argv[])
{
        int id = fork();
        if(id < 0){
                cerr << "fork failed" << endl;
                exit(1);
        }
        else if(id == 0){
                close(STDOUT_FILENO);
                open("./test.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

                // now exec "wc"...
                char* s[3];
                s[0] = strdup("wc");
                s[1] = strdup("test");
                s[2] = NULL;
                execvp(s[0], s);
        }
        else{
                int wt = wait(NULL);
        }
        return 0;

}
