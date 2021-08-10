#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

using namespace std;

int main(int argc, char *argv[])
{
        cout << "hello world, My id = " << getpid() << endl;
        int id = fork(); // 创建子进程
        if(id < 0){
                cerr << "fork failed" << endl;
                exit(1);
        }
        else if(id == 0){
                cout << "I am child process, id = " << getpid() << endl;
                char* s[3];
                s[0] = strdup("wc");
                s[1] = strdup("test");
                s[2] = NULL;
                execvp(s[0], s); // 程序替换
                cout << "This shouldn't print out." << endl;
        }
        else{
                int wt = wait(NULL); // 进程等待
                cout << "I am parent process, id = " << getpid() << ". My child id = " << id << ". wt: " << wt << endl;
        }
        return 0;

}
