#include <stdio.h>
#include<string.h>
struct user_t
{
    double latitude;
    double longtitude;
    double altitude;
    double time;
    char name[20];
};


void fileReader(FILE *readFile, struct user_t user_o[], struct user_t* use_1){
    int x; fscanf(readFile,"%i", &x);
    char name[10];
    int time;
    double lng, lat, alt;
    fscanf(readFile,"%s", &name);
    fscanf(readFile,"%i", &time);
    fscanf(readFile,"%lf", &lng);
    fscanf(readFile,"%lf", &lat);
    fscanf(readFile,"%lf", &alt);
    strcpy((*use_1).name, name);
    (*use_1).time=time;
    (*use_1).longtitude = lng;
    (*use_1).latitude = lat;
    (*use_1).altitude = alt;

    for(int y=0;y<x;y++){
        fscanf(readFile,"%s", &name);
        fscanf(readFile,"%i", &time);
        fscanf(readFile,"%lf", &lng);
        fscanf(readFile,"%lf", &lat);
        fscanf(readFile,"%lf", &alt);
        strcpy(user_o[y].name, name);
        user_o[y].time=time;
        user_o[y].longtitude = lng;
        user_o[y].latitude = lat;
        user_o[y].altitude = alt; 
    }

}

int main(void){
    char txt; //user input for text or manual input
    int othernum; //user input for otheruser count
    struct user_t our_user; //defining our user
    do{ //do while to ensure user gives valid input
    printf("Are you using a text file? (y/n)");
    scanf(" %c", &txt);
    if(txt == 'y' || txt == 'Y' || txt == 'n' || txt == 'N'){  //checks that user gave valid input
        break;
    }
    else{
        printf("Please enter a valid input, (y or n)");
    }
    }while(1==1);

    if (txt == 'y' || txt == 'Y')
    {
        char fileName[30];
        printf("Please enter name of file\n");
        scanf("%s", &fileName);
        FILE *std=fopen(fileName,"r");
        int size; fscanf(std,"%i",&size);
        fclose(std);
        struct user_t arr[size];
        fileReader(fopen(fileName, "r"),arr,&our_user);
        
        printf("%s %s %s %s", our_user.name,arr[0].name, arr[1].name,arr[2].name);
    }
    else if (txt == 'n' || txt == 'N')
    {
        printf("What is your users data? (lat long alt time name)");
        scanf("%ld %ld %ld %ld %s", &our_user.latitude, &our_user.longtitude, &our_user.altitude, &our_user.time, &our_user.name);
        printf("How many other users are you inputting?");
        scanf(" %d", &othernum);
        struct user_t other_users[othernum];
    }
    
    
}


