#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jsonHandlerFuncs.h"
#include <ctype.h>
#include <stdbool.h>

//check if browser was specified
bool getBrowserSpecified(const char flag[3]){

  bool browserSpecified = 0;

  if(strcmp(flag, "-f") == 0 || strcmp(flag, "-c") == 0){
    browserSpecified = 1;
    return browserSpecified;
  }else{
    return browserSpecified;
  }

}

int main(int argc, char *argv[]){

//check if not empty
if (argc < 2) {
    printf("Some worng, type the site!");
    return 1;
}

  char command[256];
  //go thru every char and make lowercase

  for(int i = 1; i < argc; i++){
    for (int j = 0; argv[i][j] != '\0'; j++) {
        argv[i][j] = tolower(argv[i][j]);
      }
  }
  
  if(strcmp(argv[1], "-n") == 0){

    if(getBrowserSpecified(argv[1])){
      addUrlToJSON(argv[3], argv[4]);
    }else{
      addUrlToJSON(argv[2], argv[3]);
    }

  }
  else{

    char *siteURL;

    if(getBrowserSpecified(argv[1])){
      siteURL = getCorrespondingURL(argv[2]);
    }else{
      siteURL = getCorrespondingURL(argv[1]);
    }
//char *siteURL = getCorrespondingURL(argv[1]);
    if(siteURL == NULL){
      printf("Some wrong!");
      return 1;
    }

    printf("%s\n", siteURL);

    //check if user input is not empty
    if(argc > 1){
      char *webSite = argv[1];
    }

    if(strcmp(argv[1], "-c") == 0){
      snprintf(command, sizeof(command), "chromium %s &", siteURL);
    }else if(strcmp(argv[1], "-f") == 0){
      snprintf(command, sizeof(command), "firefox %s &", siteURL);
    }else{
      snprintf(command, sizeof(command), "firefox %s &", siteURL);
    }

    int browserStartStatus = system(command);

    if(browserStartStatus >= 0){
      if(strcmp(argv[1], "-c") == 0){
        printf("Chromium running...\n");
      }else if(strcmp(argv[1], "-f") == 0){
        printf("Firefox running...\n");
      }else{
        printf("Firefox running...\n");
      }
      
    }else if (browserStartStatus == -1){
      printf("WTF some wrong\n");
    }
  }

  return 0;

}
