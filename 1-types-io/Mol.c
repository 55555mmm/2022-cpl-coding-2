#include <stdio.h>

//
// Created by En on 2022/10/1.
//
int main(){
    const double MOL =6.02e23;
    const int GRAM_PER_MOL =32;
    int mass =6;

    double quantity =mass*1.0/GRAM_PER_MOL*MOL;

    printf("quantity=%.3e\nquantity=%.5g\n",
           quantity,quantity);

    return  0;
}