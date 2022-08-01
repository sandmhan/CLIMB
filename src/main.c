//Main program runner. Continuous prompt loop
//Author: Austin Sanders

#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include "profile.h"

void menu_prompt(char *buff, Profile *a);
FILE *menu_profile_create(Profile *a);
void menu_welcome();

int main(int argc, char *argv[]) {
    menu_welcome();
    Profile *dude = malloc(sizeof(Profile));
    menu_prompt(NULL,dude); 
	profile_print(dude);

    return 0;
}

//Initial menu prompt 
//if the buffer is empty, then there was no cli input
//The menu prompt will appear, input will be retrieved from 
//user if buff is empty. Otherwise, the input comes from argv[1].
//Then the appropriate action is taken based on the char given.
void menu_prompt(char *buff, Profile *a){
    
    printf("\nMenu Options:\n(C)reate profile\n(P)rint profile\n(Q)uit\n\nARABE>");//arabe means choose in jap
    char preinput = 0;//flag for cl args
    char valid = 1;
    while(valid){
        if(buff == NULL){
            buff = malloc(sizeof(char));
            *buff = getchar();
            preinput = 1;
        }

        switch(*buff){
            case 'C':
            case 'c':
                menu_profile_create(a);
                valid = 0;
                break;

            case 'P':
            case 'p':
                profile_print(a);
                break;

            case 'Q':
            case 'q':
                printf("\nWow ok I see how it is. Leave then, you soy boy that will not be blessed with the mooscles");
                valid = 0;
                break;
            
            default:
                printf("\nInvalid input. Please try again:");
                free(buff);
                buff = NULL;
                break;
        }
    }

    //if memory was allocated, free it you goob
    if(preinput){
        free(buff);
    }

    return; 
}

//Populates the fields for the profile, creates the file, and returns the pointer for use
FILE *menu_profile_create(Profile *a){

    char buff[100];
    double weight,height;
   
    //error handle invalid inputs later
    printf("\nPlease input the name for this profile: ");
    profile_set_name(a, fgets(buff, 100,stdin));

    printf("\nPlease input the weight for this profile: ");
    scanf("%lf", &weight); 
    profile_set_weight(a,weight);

    printf("\nPlease input the height for this profile: ");
    scanf("%lf", &height); 
    profile_set_height(a,height);

    return NULL;
}

void menu_welcome(){
    printf("\n Welcome to CLIMB! The Command Line Interface Muscle Builder!");
    printf("\n Catalog workouts, journal, and track your progress in various parameters.");
    printf("\n More features are soon to come! \n\n Please hit enter to start the program");

    getchar();//waits for enter to proceed

    return;

}
