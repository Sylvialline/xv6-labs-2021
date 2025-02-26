#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

char path[512];
const char *name;
void find(char *p, const char *nm){
  int fd;
  struct dirent de;
  struct stat st;
  if((fd = open(path, O_RDONLY)) < 0){
    fprintf(2, "find: cannot open %s\n", path);
    return;
  }
  if(fstat(fd, &st) < 0){
    fprintf(2, "find: cannot stat %s\n", path);
    close(fd);
    return;
  }
  switch(st.type){
    case T_FILE:
      if(nm == 0){ // find the name if the given dir is a file
        for( ; p >= path && *p != '/'; p--);
        nm = p + 1;
      }
      if(strcmp(nm, name) == 0) fprintf(1, "%s\n", path);
      break;
    case T_DIR:
      *p++ = '/';
      while(read(fd, &de, sizeof(de)) == sizeof(de)){
        if(de.inum == 0) continue;
        if(strcmp(de.name, ".") == 0 || strcmp(de.name, "..") == 0) continue;
        // avoid recursing into "." or ".."
        strcpy(p, de.name);
        find(p + strlen(p), de.name);
      }
      break;
  }
  close(fd);
}
int main(int argc, char *argv[]){
  if(argc != 3){
    fprintf(2, "Usage: find directory name\n");
    exit(1);
  }
  strcpy(path, argv[1]);
  name = argv[2];
  char *p = path + strlen(path);
  if(p[-1] == '/') *--p = '\0'; // delete if the last ch is '/'
  find(p, 0);
  exit(0);
}