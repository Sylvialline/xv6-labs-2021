#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int p[2], readfd, writefd;
  pipe(p);
  if(fork() == 0) {
    readfd = p[0];
    writefd = 0;
    close(p[1]);
    uchar x, pr = 0;
    while(read(readfd, &x, 1)) {
      if(pr == 0) {
        pr = x;
        fprintf(1, "prime %d\n", x);
      }
      else if(x % pr) {
        int isp = 1;
        if(!writefd) {
          pipe(p);
          isp = fork() != 0;
          if(isp == 0) {
            readfd = p[0];
            writefd = 0;
            close(p[1]);
            pr = 0;
          } else {
            writefd = p[1];
            close(p[0]);
          }
        }
        if(isp) {
          write(writefd, &x, 1);
        }
      }
    }
    close(readfd);
    if(writefd)close(writefd);
    wait(0);
    exit(0);
  }
  writefd = p[1];
  readfd = 0;
  close(p[0]);
  for(uchar i=2; i<=35; i++){
    write(writefd, &i, 1);
  }
  close(writefd);
  wait(0);
  exit(0);
}