//
// Created by En on 2022/10/9.
//
#include <stdio.h>
int main(){
    int year=0;
    scanf("%d",&year);
    int leap =
            ((year % 4==0 && year % 100 !=0)||
                    (year % 400==0));
//    if (year % 4 != 0) {
//        leap = 0;
//    } else if (year % 100 != 0) {
//        leap = 1;
//    } else if (year % 400 != 0) {
//        leap = 0;
//    } else {
//        leap = 1;
//    }



    if(leap==0){
        printf("The year %d is a common year.\n",year);
    } else{
        printf("The year %d is a leap year.\n",year);
    }


    return 0;
}