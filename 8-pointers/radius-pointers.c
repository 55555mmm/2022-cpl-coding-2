//
// Created by En on 2022/11/19.
//
//数组、指针是一种数据类型，但不是基本数据类型，从基本数据类型派生出来的数据类型。
//A variable has its type, value, and address.
//一个变量有类型，有值，有地址。
//A variable can be used as a lvalue or a rvalue.
//一个变量可以作左值用，也可以作右值用。
//A pointer is a variable that contains the address of a variable.
//一个指针就是一个变量，并且是另一个变量的地址。
//只要是变量，就有以上属性。
#include <stdio.h>

int main() {
    /********** On radius **********/
    //type:int; value:100; address:&radius (&: address-of operator(取地址符))
    int radius = 100;

    printf("radius = %d\n", radius);
    printf("The address of radius is %p\n",&radius);
    //取地址：%p

    //radius as a lvalue(space, memory, storage, address)
    radius = 200;
    //radius as a rvalue(value: 值本身)
    double circumference = 2 * 3.14 * radius;
    printf("radius = %d; circumference = %f\n", radius, circumference);
    /********** On radius **********/

    /********** On ptr_radius1 **********/

    //type: int *; value: &radius; address: &ptr_radius1
    int *ptr_radius1 = &radius;
    printf("The address of ptr_radius1 is %p\n",&ptr_radius1);

    /********** On ptr_radius1 **********/

    /********** On *ptr_radius1 **********/

    //*ptr_radius1 behaves like radius.
    //*: indirection/dereference(间接寻址、解引用 运算符)
    //*ptr_radius1相当于radius，完全等价
    //*ptr_radius1类型是：int
    //*ptr_radius1 as a lvalue
    *ptr_radius1=100;
    printf("The value of radius is %d\n",radius);
    //*ptr_radius1 as a rvalue
    circumference=2*3.14*(*ptr_radius1);
    printf("circumference = %f\n",circumference);

    /********** On *ptr_radius1 **********/

    /********** On ptr_radius1 again **********/

    int radius_1=1000;
    int *ptr_radius_1=&radius_1;
    ptr_radius1=ptr_radius_1;
    *ptr_radius1=2000;
    printf("The value of radius1 is %d\n",*ptr_radius_1);

    /********** On ptr_radius1 again **********/

    /********** On array names **********/
    int arr[]={1,2,3};
    //arr++;
    int *ptr_arr=arr;
    //可以定义指针变量遍历数组
    /********** On array names **********/

    /********** On malloc/free **********/
    int array[5]={0};
    //free(array);
    //malloc申请的空间必须free
    //也只能free通过malloc申请的空间（栈上的空间不能free）
    //如果free（UB）

    /********** On malloc/free **********/

    /********** On const **********/

    const int *const_radius=&radius;//仅仅指不可以通过该指针间接寻址（解引用）来修改
    //不代表该变量不能被修改
    radius=20;//不会报错
    //*const_radius=20;(会报错)
    int *radius_4=const_radius;
    *radius_4=20;

    int const *const_radius1 = &radius;//相当于const int *

    int *const const_radius2 = &radius;//含义：它是一个const的指针，该指针指向int
    //含义：该指针是const的，不再允许指向其他地方
    const int *const const_radius3 = &radius;

    /********** On const **********/
}


