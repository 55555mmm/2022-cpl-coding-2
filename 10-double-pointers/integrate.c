//
// Created by En on 2022/12/18.
//
//函数指针：声明定义一个函数，这个函数接受的参数还能是一个函数

#include <math.h>
#include <stdio.h>

#define NUM_OF_PARTITION 100000

double Integrate(double low, double high, double (*fp)(double));//fp:该函数接受一个double，返回一个double
//double (*fp)(double):解读为：fp是一个指针，该指针指向一个函数，这个函数接受一个double，返回一个double

//别忘了工具：https://www.wolframalpha.com

int main(){
    double low=0.0;
    double high=1.0;
    double integration=0.0;

    integration = Integrate(low,high,sin);//同理，取不取地址都一样，会自动转化为指针
    printf("sin : %f\n",integration);

    integration = Integrate(low,high,cos);//同理，取不取地址都一样，会自动转化为指针
    printf("cos : %f\n",integration);

    //函数指针也可以放在数组里（可当成普通指针来用）
    double (*fps[2])(double) = {sin,cos};
    //[]优先级高于*，先读。
    //fps是一个数组，这个数组里有两个元素，每个元素是一个指针，这个指针指向一个函数，这个函数接受一个double，返回一个double
    for(int i=0;i<2;i++){
        printf("%f\n", Integrate(low,high,fps[i]));
    }


    return 0;
}
double Integrate(double low, double high, double (*fp)(double)){
    double interval = (high-low)/NUM_OF_PARTITION;

    double sum=0.0;
    for(int i=0;i<NUM_OF_PARTITION;i++){
        double xi=low+interval*i;
        double yi=fp(xi);//直接调用被传进来的函数指针
        //调用fp函数时，(*fp)(xi)与fp(xi)解引用与不解引用都是一样的
        //就如同调用math.h中的sin()函数时直接写函数名（其实已经是一个函数指针了），背后会将函数名转化为函数指针在用
        //在C语言里，当函数名放在一个表达式里的时候，会自动转化为函数指针，因此解不解引用都是一样的
        sum+=yi*interval;
    }
    return sum;

}