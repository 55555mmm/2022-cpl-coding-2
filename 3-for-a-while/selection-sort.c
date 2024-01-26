//
// Created by En on 2022/10/14.
//
#include <stdio.h>

#define LEN 20
int numbers[LEN] = {0};

int main() {
    /*
     * Input the array
     * Note: fails to run this program in "Run" (Ctrl + D)
     * See: https://youtrack.jetbrains.com/issue/CPP-5704
     * Use "Terminal" instead.
     */
    //EOF：end of file
    int len = -1;
    //若是ctrl Z不起作用（windows下clion）
    //input indirection(输入重定向)
    //本来输入数据是从 标准输入（命令行控制台）输入进去的
    //输入重定向（input indirection）：不从标准输入输入数据，而是从文件
    while (scanf("%d", &numbers[++len]) != EOF);
    //输入重定向：命令行：.\selection-sort < numbers.md
    //原因：因为numbers.md是一个文件，文件末尾天然有一个EOF标识，因此解决了ctrl Z不能工作的问题
    //但windows下clion不支持,只能用外面的命令行(命令提示符)
    //若想把输出也放在一个文件里，可使用输出重定向
    //selection-sort < numbers.md > numbers-sorted.md

    for(int i=0;i<len-1;i++){
        int min=numbers[i];
        int min_index=0;
        for(int j=i+1;j<=len-1;j++){
            if(numbers[j]<min){
                min=numbers[j];
                min_index=j;
            }
        }
        int temp=numbers[min_index];
        numbers[min_index]=numbers[i];
        numbers[i]=temp;
    }
    for (int i = 0; i < len; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    // add code below

    return 0;
}