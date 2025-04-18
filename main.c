#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jsonHandlerFuncs.h"
#include <ctype.h>

int main(int argc, char *argv[]){

//check if not empty
if (argc < 2) {
    printf("Some worng, type the site!");
    return 1;
}

  char command[256];
  //go thru every char and make lowercase
  for (int i = 0; argv[1][i] != '\0'; i++) {
    argv[1][i] = tolower(argv[1][i]);
  }
  printf("%s", argv[1]);

  if(strcmp(argv[1], "-n") == 0){
    addUrlToJSON(argv[2], argv[3]);
  }
  else{

    char *siteURL = getCorrespondingURL(argv[1]);
    if(siteURL == NULL){
      printf("Some wrong!");
      return 1;
    }

    printf("%s\n", siteURL);

    //check if user input is not empty
    if(argc > 1){
      char *webSite = argv[1];
      printf("%s\n", webSite);
    }
    snprintf(command, sizeof(command), "firefox %s &", siteURL);
    int firefoxStartStatus = system(command);

    if(firefoxStartStatus >= 0){
      printf("Firefox running...\n");
    }else if (firefoxStartStatus == -1){
      printf("WTF some wrong\n");
    }
  }

  return 0;

}
