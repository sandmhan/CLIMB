//Basic profile manager. Contains functions to populate profiles 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "profile.h"

int profile_set_name(Profile *a, char name[30]){
    if(a == NULL){
        printf("\nERROR: PROFILE DOES NOT EXIST\n");
        return -1;
    }
    strncpy(a->name,name,30);
    printf("\nSUCCESS: PROFILE NAME SET\n");
    return 0;
}

//Returns profile name
//Design choices: 
//1.return the address of the name in the struct (allows for easy access of 
//pointer while enabling easy safety checking. Though it makes more sense to do this
//if you have private access to the struct members(Should the struct be private?)
//(will probably make the code easier to maintain to establish concrete methods of access
//for any variables needed as opposed to hard coding the logic at each instance which could
//lead to inconsistent code writing knowing me.)
//2.return a char[] copy of the name for reference but doesn't allow access to 
//pointer. Not entirely evident why this would be preferred but is an option nonetheless
//3.printing the name if it exists, and throwing an error otherwise. Lazy option but could
//be made into its own separate functions akin to a toString method in Java
int profile_get_name(Profile *a){
    if(a == NULL){
        printf("\nERROR: NAME COULD NOT BE RETRIEVED\n");
        return -1;
    }

    printf("\nThis Profile is:%s\n", a->name);
    return 0;
}


//Main Tester for Profile Managing
int main(){

    struct Profile *a = malloc(sizeof(Profile));
    char name[30] = "Adam Dudley";
    profile_set_name(a, name);

    profile_get_name(a);
    return 0;

}



