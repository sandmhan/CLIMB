//Main program runner. Continuous prompt loop
//Author: Austin Sanders

#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include "profile.h"

void menu_prompt(char *buff);
void menu_welcome();

int main(int argc, char *argv[]) {
    menu_welcome();
    menu_prompt(NULL); 
	//Profile *dude = profile_init("Arashiyama Jurota", 79, 295);
	//profile_print(dude);

    return 0;
}

//Initial menu prompt 
//if the buffer is empty, then there was no cli input
//The menu prompt will appear, input will be retrieved from 
//user if buff is empty. Otherwise, the input comes from argv[1].
//Then the appropriate action is taken based on the char given.
void menu_prompt(char *buff){
    
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
                printf("\n DOODOODOO A profile is being created");
                valid = 0;
                break;

            case 'P':
            case 'p':
                printf("\nSCHLAMI PROCLAMI A Profile is being printed for mami");
                valid = 0;
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

void menu_welcome(){
    printf("\n Welcome to CLIMB! The Command Line Interface Muscle Builder!");
    printf("\n Catalog workouts, journal, and track your progress in various parameters.");
    printf("\n More features are soon to come! \n\n Please hit enter to start the program");

    getchar();//waits for enter to proceed

    return;

}
