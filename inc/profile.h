//Header File for Profiles
#ifndef PROFILES_H__
#define  PROFILES_H__

#include <stdio.h>

typedef struct{
    char name[30];
    double weight;//in lbs
    double height;//in inches
}Profile;

int profile_set_name(Profile *a, char *name);

int profile_get_name(Profile *a, char *name);

int profile_set_weight(Profile *a, double weight);

double profile_get_weight(Profile *a);

int profile_set_height(Profile *a, double height);

double profile_get_height(Profile *a);

#endif
