#include <stdio.h>
#include <stdlib.h>
#include "cJson/cJSON.h"
#include <string.h>

char *getCorrespondingURL(char webSiteName[]){

  FILE* fop;
  char *jsonWebsites;
  long fileSize; // store file size

  // open file with read
  fop = fopen("/home/kenny/Code/c_files/goweb/json/webSites.json", "r");

  // loo for end of file to get file size
  fseek(fop, 0, SEEK_END);
  fileSize = ftell(fop);  
  fseek(fop, 0, SEEK_SET);

  // allocate memory for json content
  jsonWebsites = (char *)malloc(fileSize + 1);
  fread(jsonWebsites, 1, fileSize, fop);
  jsonWebsites[fileSize] = '\0';

  // close file
  fclose(fop);

// parse JSON content
  cJSON *json = cJSON_Parse(jsonWebsites);
  if (json == NULL) {
        printf("Error parsing JSON: %s\n", cJSON_GetErrorPtr());
        free(jsonWebsites);
        return NULL;
    }

// try to find the website url
  cJSON *siteURL = cJSON_GetObjectItem(json, webSiteName);
      if (siteURL == NULL) {
        printf("Website name '%s' not found in JSON\n", webSiteName);
        cJSON_Delete(json); 
        free(jsonWebsites); 
        return NULL;
    }

// get the url
  const char *url = cJSON_GetStringValue(siteURL);
      if (url == NULL) {
        printf("URL for '%s' is not a string\n", webSiteName);
        cJSON_Delete(json);
        free(jsonWebsites); 
        return NULL;
    }

// make url to string
  char *result = strdup(url);
      if (result == NULL) {
        printf("Memory allocation for result failed\n");
        cJSON_Delete(json);
        free(jsonWebsites);
        return NULL;
    }
  
  cJSON_Delete(json);
  free(jsonWebsites);

  return result;
}
