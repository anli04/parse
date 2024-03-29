#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char ** parse_args(char * line);

int main(){
  char * line = strdup("ls -a -l");
  printf("Line to be tested: \"ls -a -l\"\n");
  char ** args = parse_args(line);
  execvp(args[0], args);
  printf("Error with execvp\n");
  return 0;
}

char ** parse_args(char * line){
  char ** args = malloc(256);
  int i = 0;
  while (line){
    args[i] = strsep(&line, " ");
    i++;
  }
  return args;
}
