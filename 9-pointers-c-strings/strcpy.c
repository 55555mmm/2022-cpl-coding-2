//
// Created by En on 2022/12/7.
//
#include <string.h>
#include <stdio.h>

/**
 * @brief We assume that there is enough room for storing src(inside dest).
 *  Otherwise, it is an undefined behavior.
 *
 *  If copying takes place between objects that overlap,(src和dest在内存上有交叠（有重叠空间）)
 *  then behavior is undefined.
 *
 * @param dest
 * @param src
 */
void StrCpy(char *dest, const char *src);
void StrCpy1(char *dest, const char *src);
void StrCpy2(char *dest, const char *src);
void StrCpy3(char *dest, const char *src);
void StrCpy4(char *dest, const char *src);
void StrCpy5(char *dest, const char *src);
char *StrCpyStd(char *dest, const char *src);

int main() {
    const char *src = "Hello World";
    //需要动态分配内存时，才用malloc
    char dest[strlen(src) + 1];
    //strlen()函数求出来的长度不包括'\0'这个字符，因此要+1

    StrCpy(dest, src);
    //传进来的值是dest的拷贝，在函数内部对dest进行++，函数外部的dest的值并未发生改变
    strlen(dest);
    printf("dest = %s\n", dest);

    strlen(StrCpyStd(dest, src));
    //C标准库里返回的是dest指针：可以直接使用

    return 0;
}

void StrCpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void StrCpy1(char *dest, const char *src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') {
        //左边是赋值表达式有返回值，返回值是赋完值之后左边的值（由于是赋值表达式左右相等）
        i++;
    }
}

void StrCpy2(char *dest, const char *src) {
    int i = 0;
    // dest[i] : *(dest + i)//语法糖缩写(该版本只是剥开糖皮)
    while ((*(dest + i) = *(src + i)) != '\0') {
        i++;
    }
}

void StrCpy3(char *dest, const char *src) {
    while ((*dest = *src) != '\0') {
        src++;
        dest++;
        //指针自己可以++
    }
}

void StrCpy4(char *dest, const char *src) {
    // dest++: dest(返回值为dest，然后再进行dest+1), dest = dest + 1
    // dest[0]
    // *dest++: *dest, not *(dest + 1)
    while ((*dest++ = *src++) != '\0');
    //Suffix/Postfix(后缀)++/--运算优先级(最高)高于Prefix(前缀)++/--
    //同样也高于*(Indirection(dereference))解引用运算符
}

// NOT recommended!
void StrCpy5(char *dest, const char *src) {
    // '\0': null character, 0 空字符
    //0:False
    //非0:True
    while ((*dest++ = *src++));
}

char *StrCpyStd(char *dest, const char *src) {
    for (char *s = dest; (*s++ = *src++) != '\0';);
    return dest;
}