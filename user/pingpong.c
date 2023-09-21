#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int p[2];

  char buf[4];
  pipe(p);
  int pid = fork();
  if (pid == 0) { //child
  read(p[0],buf,sizeof(buf));
  close(p[0]);

  printf("%d: received %s\n", getpid(), buf);

  write(p[1], "pong", 4);
  close(p[1]);

  exit(0);

  } else {
    //parent
  write(p[1], "ping", 4);
  close(p[1]);

  read(p[0], buf, sizeof(buf));
  close(p[0]);

  printf("%d: received %s\n", getpid(), buf);

  exit(0);
  }





}


