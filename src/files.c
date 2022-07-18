//Source file for file header
//Responsible for the creation, reading, and editing of 
//profiles,exercise files, nutrition, etc.

#include <stdio.h>
#include "files.h"
#include "profile.h"


//A file will be created that contains all the profile parameters 
//and stores them for later access when running program for first time
int profile_create(Profile *a){
    
    if(a == NULL){//verify profile exists
        printf("\nERROR: NULL PROFILE\n");
        return -1;
    }
    
    return 0;
}
