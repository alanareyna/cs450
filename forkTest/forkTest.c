#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main{

  pid_t p;
  
  for(int i = 0; i < 9; i++){
    p = fork();
    if (p == 0){
      
}
