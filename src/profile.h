//Header File for Profiles
#include <stdio.h>

typedef struct Profile{
    char name[30];
    double weight;//in lbs
    double height;//in inches
}Profile;

int profile_set_name(Profile *a, char name[30]);

int profile_get_name(Profile *a);

int profile_set_weight(Profile *a, double weight);

int profile_get_weight(Profile *a);



