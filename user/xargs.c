#include "kernel/types.h"
#include "user/user.h"
#include "kernel/param.h"

int main(int args, char *argv[]){
  char *nargv[MAXARG];
  char buf[512], c, *p = buf;
  for(int i = 1; i < args; i++)
    nargv[i - 1] = argv[i];
  nargv[args - 1] = buf;
  nargv[args] = 0;
  while(read(0, &c, 1) > 0){
    if(c != '\n') *p++ = c;
    else{
      *p = 0;
      if(fork() == 0){
        exec(nargv[0], nargv);
        fprintf(2, "exec failed\n");
        exit(1);
      }
      p = buf;
    }
  }
  if(p > buf){
    *p = 0;
    if(fork() == 0){
      exec(nargv[0], nargv);
      fprintf(2, "exec failed\n");
      exit(1);
    }
  }
  exit(0);
}