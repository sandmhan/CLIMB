//Main program runner. Continuous prompt loop
//Author: Austin Sanders

#include <stdio.h>
#include "files.h"
#include "profile.h"

int main(int argc, char *argv[]) {

    printf("\nThe make file works somehow");
	
	Profile *dude = profile_init("Arashiyama Jurota", 79, 295);

	profile_print(dude);

    return 0;
}

