# Current Task
- fix appending '/' to delimiter.  
- set up profile struct deletion (free names)

# Recently Fixed
- SegFault when trying to write to profile name.
    - trying to find best way to write dynamic string to struct
        -that's the trick, there is no best way
    - Not sure why the seg fault is occuring with the given input. the temp string is being read properly so possibly an issue with the des
        - **it was a destination problem. Didn't malloc for struct......**

# Immediate To-do
1. Set up menu options to request input/files
2. Write initial file/directory management functions (profile read and write,profile directory creation)
3. Fix double prompt when incorrect input is given

# Broad Scope Functionality
-Profile creation
    -tracking weigh-ins chronologically
    -compiling multiple documents into one profile report
-workout journaling
    -takes input form exercise library to create workout
-exercise log
    -individual exercises with recommended rep ranges/weight, targted muscles, general target area / difficulty
-calorie tracker
