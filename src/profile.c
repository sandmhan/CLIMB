//Basic profile manager. Contains functions to populate profiles 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "profile.h"

const int NAME_MAXSIZE = 1000;

Profile *profile_init(char *name, double weight, double height){
	Profile *person = malloc(sizeof(Profile));
	if(person == NULL){
		printf("\nMalloc Failed");
		return NULL;
	}

	profile_set_name(person, name);
	profile_set_height(person, height);
	profile_set_weight(person,weight);
	return person;
}

void profile_print(Profile *a){
	if(a == NULL){
        fprintf(stderr, "\nERROR: PROFILE DOES NOT EXIST\n");
		return;
	}

	char name[100]; 
	double height, weight;

	profile_get_name(a, name);
	height = profile_get_height(a);
	weight = profile_get_weight(a);

	printf("\nProfile Overview \n Name: %s \n DIRNAME: %s \n Height: %f \n Weight: %f\n",
			name, a->dirname, height, weight);
	return;
}

//Writes profile data to file. Creates profile directory if one does not exist as well.
//Files should be formatted in Markdown for better viewing experience.

FILE *profile_make_file(Profile *a){
    
    if(a == NULL){
        fprintf(stderr, "\nERROR: PROFILE DOES NOT EXIST\n");
        return NULL;
    }
    
    return NULL;
}

//Dynamically allocate memory for names. NAME_MAXSIZE upper limit.
int profile_set_name(Profile *a, char *name){
    
    if(a == NULL){
        fprintf(stderr, "\nERROR: PROFILE DOES NOT EXIST\n");
        return -1;
    }
    
    char *temp = NULL;
    int ch = EOF;
    size_t size = 0, index = 0;
    

    //takes in name char by char and DyAllocs memory for string
    while(ch){
        printf("\nName input loop %ld",index);
        ch = getc(stdin);//retrieve one char
        if(ch == EOF || ch == '\n'){//check if end of line/file is reached
            ch = 0;
        }

        if(size <= index){
           size += sizeof(char);
           temp = realloc(name, size);//increase size by one char. Just enough memory for name will be allocated
           if(!temp){//if realloc fails
               free(temp);
               temp = NULL;
               return -1;
           }
           name = temp;

        }

        name[index++] = ch;
    }

    //allocating memory for name to get copy of name out of scope
    size++;//add one for NTC
    a->name = malloc(sizeof(char) * size);
    memcpy(a->name, name, size);

    //Tokenizing string to make into directory name for files pertaining to profile
    char d[2] = " ";
    char pathSym[2] = {'.','/'};
    char *tok = strtok(name,d);//initial token
    a->dirname = malloc(sizeof(char)*size + 3);//+3 for ./*/
    a->dirname[0] = pathSym[0];
    a->dirname[1] = pathSym[1];
    
    while(tok != NULL){//loop through appending name to elim spaces
        strcat(a->dirname,tok);
        size--;//space character being removed from name
        tok = strtok(NULL,d);
    }
    a->dirname[size+2] = pathSym[1];
    
    free(name);
    printf("\nSUCCESS: PROFILE NAME SET\n");
    return 0;
}

//Returns profile name
//2.return a char[] copy of the name for reference but doesn't allow access to 
//pointer. This approach will be chosen to create file names using profile name w/o direct reference
int profile_get_name(Profile *a, char *name){
    if(a == NULL){//check if struct exists
        fprintf(stderr, "\nERROR: PROFILE DOES NOT EXIST\n");
        return -1;
        }

    if(a->name == NULL){//check if name has been set
        printf("\nERROR: NAME HAS NOT BEEN SET\n");
        return -1;
    }

    sprintf(name, "%s",a->name);

    return 0;
}

int profile_set_weight(Profile *a, double weight){
    
    if(a == NULL){//check if struct exists
        fprintf(stderr, "\nERROR: PROFILE DOES NOT EXIST\n");
        return -1;
    }

    //set weight
    a->weight = weight;
    return 0;
}


double profile_get_weight(Profile *a){

    if(a == NULL){//check if struct exists
        fprintf(stderr, "\nERROR: PROFILE DOES NOT EXIST\n");
        return -1;
    }

    if(!(a->weight)){//check if weight is set
        printf("\nERROR: WEIGHT NOT SET\n");
    }

    return a->weight;
}

int profile_set_height(Profile *a, double height){
    
    if(a == NULL){//check if struct exists
        fprintf(stderr, "\nERROR: PROFILE DOES NOT EXIST\n");
        return -1;
    }

    //set height
    a->height = height;
    return 0;
}


double profile_get_height(Profile *a){

    if(a == NULL){//check if struct exists
        fprintf(stderr, "\nERROR: PROFILE DOES NOT EXIST\n");
        return -1;
    }

    if(!(a->height)){//check if weight is set
        printf("\nERROR: HEIGHT NOT SET\n");
    }

    return a->height;
}

//Main Tester for Profile Managing
//int main(){
//
//    struct Profile *a = malloc(sizeof(Profile));
//    char name[30] = "Adam Dudley";
//    char cpyname[30];
//
//   profile_set_name(a, name);
//    profile_get_name(a,cpyname);
//    printf("\n%s\n", cpyname);
//
//    profile_set_weight(a, 240.43);
//    printf("\nWeight (lbs):%.2f\n",profile_get_weight(a));
//
//    profile_set_height(a,76.4);
//    printf("\nHeight (inches):%.2f\n",profile_get_height(a));
//
//    return 0;
//
//}



