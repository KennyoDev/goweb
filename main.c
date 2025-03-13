#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  int firefoxStartStatus = system("firefox github.com &");

  if(firefoxStartStatus >= 0){
    printf("Firefox running...\n");
  }else if (firefoxStartStatus == -1){
    printf("WTF some wrong\n");
  }

  return 0;

}
