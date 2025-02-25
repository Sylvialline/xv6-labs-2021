#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int p1[2];
  pipe(p1);
  if(fork() > 0){ // main process: generate 2~35 and pass to p1
    close(p1[0]);
    for(uint8 i=2; i<=35; i++){
      write(p1[1], &i, 1);
    }
    close(p1[1]);
    wait(0);
    exit(0);
  }
  while(1){
    char *c = 0;
    close(p1[1]);
    int p0 = p1[0]; // last proc -> p0 -> this proc
    if(read(p0, c, 1) == 0){
      close(p0);
      exit(0);
    }
    uint8 p = *c, q;
    fprintf(1, "prime %d\n", (int)p);

    pipe(p1); // this proc <-> p1 <-> next proc
    if(fork() > 0){ // this proc
      close(p1[0]);
      while(read(p0, c, 1) != 0){
        q = *c;
        if(q % p != 0){
          write(p1[1], &q, 1);
        }
      }
      close(p0);
      close(p1[1]);
      wait(0);
      exit(0);
    }
    close(p0); // next proc, no need for p0
  }
}