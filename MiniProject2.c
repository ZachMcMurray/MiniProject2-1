#include <stdio.h>
#include<string.h>
#include <math.h>

struct user_t
{
    double latitude;
    double longtitude;
    double altitude;
    int time;
    char name[20];
};


void fileReader(FILE *readFile, struct user_t user_o[], struct user_t* use_1){

    int x; fscanf(readFile,"%i", &x);
    char name[20];
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

void otherUsers(struct user_t user_o[],int size){
    
    for(int x=0;x<size;x++){
        printf("enter %i user lat: ", x+1);
        scanf("%lf",&user_o[x].latitude);
        printf("enter %i user long: ", x+1);
        scanf("%lf",&user_o[x].longtitude);
        printf("enter %i user alt: ", x+1);
        scanf("%lf",&user_o[x].altitude);
        printf("enter %i user time: ", x+1);
        scanf("%i",&user_o[x].time);
        printf("enter %i user name: ", x+1);
        scanf("%s",&user_o[x].name);
    }
}

void difference(struct user_t user_o[], struct user_t use_1, double array[],int size){

    for(int y=0;y<size;y++){
        array[y]=sqrt(((use_1.altitude-user_o[y].altitude)*(use_1.altitude-user_o[y].altitude))+
        ((use_1.latitude-user_o[y].latitude)*(use_1.latitude-user_o[y].latitude))+
        ((use_1.longtitude-user_o[y].longtitude)*(use_1.longtitude-user_o[y].longtitude)));
    }

}

int nearUser(double array[],int size){

    double small = array[0];
    int countSave=0;

    printf("%lf\n",array[0]);

    for(int x=1;x<size;x++){
        if(array[x]<small){
            small = array[x];
            countSave = x;
        }

        printf("%lf\n",array[x]);

    }
    return countSave;
}

int main(void){

    char txt; //user input for text or manual input
    int othernum; //user input for otheruser count
    struct user_t our_user; //defining our user
    int smallSpot;

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
        double arrdis[size];
        fileReader(fopen(fileName, "r"),arr,&our_user);
        difference(arr,our_user,arrdis,size);
        smallSpot = nearUser(arrdis,size);
        printf("%s is the closest to %s at %.2lfm",arr[smallSpot].name,our_user.name,arrdis[smallSpot]);
    }
    else if (txt == 'n' || txt == 'N')
    {
        printf("What is your users data? (lat long alt time name)");
        scanf("%lf %lf %lf %i %s", &our_user.latitude, &our_user.longtitude, &our_user.altitude, &our_user.time, &our_user.name);
        printf("How many other users are you inputting?");
        scanf(" %d", &othernum);
        struct user_t other_users[othernum];
        double arrdis[othernum];
        otherUsers(other_users,othernum);
        difference(other_users,our_user,arrdis,othernum);
        smallSpot = nearUser(arrdis,othernum);
        printf("%s is the closest to %s at %.2lfm",other_users[smallSpot].name,our_user.name,arrdis[smallSpot]);
    }
    
}


