#include <stdio.h>
struct user_t
{
    double latitude;
    double longtitude;
    double altitude;
    double time;
    char name[20];
};

int main(){
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
        printf("placeholder");  //this is on you dawg
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
struct user_t scan_user(struct user_t settinguser){
printf("are you scanning your user or another user?"){

}
}

