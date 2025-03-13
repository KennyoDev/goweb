#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){


  //check if user input is not empty
  if(argc > 1){
    char *webSite = argv[1];
    printf("%s\n", webSite);
  }

  //start firefox *github.com just a place holder BETA*
  int firefoxStartStatus = system("firefox github.com &");

  if(firefoxStartStatus >= 0){
    printf("Firefox running...\n");
  }else if (firefoxStartStatus == -1){
    printf("WTF some wrong\n");
  }

  return 0;

}
