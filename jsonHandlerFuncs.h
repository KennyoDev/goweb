#include <stdio.h>
#include <stdlib.h>
#include "cJson/cJSON.h"
#include <string.h>

char *getCorrespondingURL(char webSiteName[]){

  FILE* fop;
  char *jsonWebsites;
  long fileSize; // store file size

  // open file with read
  //fop = fopen("/home/user/Docs/goweb/webSites.json", "r");
  fop = fopen("/home/kenny/Code/c/goweb_changes/goweb/goweb/json/webSites.json", "r");

  // look for end of file to get file size
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






void addUrlToJSON(char webSiteName[], char websiteUrl[]){

  FILE* jsonFile;
  //enter you complete file path to the json here
  //char filePath[256] = "/home/user/Docs/goweb/webSites.json";
  char filePath[256] = "/home/kenny/Code/c/goweb_changes/goweb/goweb/json/webSites.json";
  
  //open json file to read it
  jsonFile = fopen(filePath, "r");
  if(jsonFile == NULL){
    printf("Error opening file!");
  }

  //look for end of file to get size
  fseek(jsonFile, 0, SEEK_END);
  long length = ftell(jsonFile);
  rewind(jsonFile);

  // Allocate space for the JSON string (+1 for null terminator)
  char *data = malloc(length + 1);
  if (data == NULL) {
      printf("Memory allocation failed\n");
      fclose(jsonFile);
      return;
  }

  // Read file into string
  fread(data, 1, length, jsonFile);
  data[length] = '\0';  // Null-terminate the string
  fclose(jsonFile);

  // Parse the data into json
  cJSON *root = cJSON_Parse(data);
  free(data);

  // Add the site to the json root
  cJSON_AddStringToObject(root, webSiteName, websiteUrl);

  // Write json to file
  char *finalJson = cJSON_Print(root);
  jsonFile = fopen(filePath, "w");
  fprintf(jsonFile, "%s", finalJson);

  //Clean up
  fclose(jsonFile);
  cJSON_Delete(root);
  free(finalJson);

}





