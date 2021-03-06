﻿# C语言基础复习补漏

标签（空格分隔）： 未分类

---

- **scanf("%lf",a)  printf("%f",a)**
scanf在输入浮点数要用lf
出现在scanf字符串里的东西是一定要输入的
例如：
scanf("hello %d %d",&a,&b) 一定要输入 hello 3 4 这样的字符串才会读到
- **单目运算符**
只有一个算子 比如+a 表示正a
- **嵌入式赋值 a=b+(c=d)**
可以编译执行但不利于阅读 应避免
函数声明可以不写参数名字，编译器不会检查
- **行内注释**
注释可以写在行内  aaaa/\*bb\*/cccc
- **c语言编译器不管空格回车这些符号**
- **函数的`原型声明` 函数的`定义`**
函数的声明中可以不带参数，编译器不会检查出错误会默认参数类型不确定，而运行的时候有课能就出错，因为编译器会猜测，一旦猜错了如int变double 后果很严重
**int 和 double 在内存中是完全不同的表示 即使值是一样的**
- **c语言函数传参只有`值`传递**
- **逗号运算符 a =b,c 最后的结果取c的值**
- **c语言的编译器不会检查数组下标越界**
- **数组的传递只能通过数组遍历的方式，没有办法把一个数组赋给另一个数组**
  **数组作为参数传递的时候，要另外一个变量专门传递数组的长度**
- **二维数组的列数一定要定义 如int arr[][5] 行数可以由编译器算出来**
- **sizeof(a++)是静态的 编译器在编译的时候就把括号的值替换掉了**
```c
int a = 1;
sizeof(a++);
最后输出的a还是1
sizeof(a+2.0) 是8 只管a+2.0之后的类型 并不会真的去算
```

---
## 指针和字符串
- **指针使用的场景**
函数需要返回多个值，就可以通过指针带入，指针指向的变量就改变了
函数返回特殊的状态，而值用指针返回
在别的语言中c++ java 采用异常机制来返回状态
- **使用指针常见的错误**

 1.在没给指针明确赋值的情况下使用
 2.传递到函数的数组实际是指针
 3.数组不能赋给另一个数组
 4.int b[] 可以看成 int const b
```c
int *p;
*p = 12;
这样写意思是先声明了一个指针变量p 但是没有赋地址值，其中的地址可能是乱七八糟的数
然后让p指向了12，意思就是这个乱七八糟的数代表的地址内存中存放12这个值
int *p = 0  //这样意思是指针的地址是0
*p = a  //把a赋给地址是0的内存
```
```c
int arr[10];
void fun(int arr[]){
/*
这里arr其实是指针
函数中 int arr[] 也可以写成 int *a 因为函数中这两个都是指针

*/
}
```

```c
    int arr1[] = {1,2,3};
    int arr2[] = {4,5,6};
    arr1 = arr2 //这样是错误的，因为这两个都是地址都作为常量指针存在，无法赋值
    要想赋值只能一个一个的copy
```

- **老师说数组变量可以被看作是const的指针变量，到底是“可以被看作”，还是“就是”指针呢**
`答 只能被看做指针`
```c
#include <stdio.h>

void fun(int arr[]);

int main(){
	int a = 1;
	int b = 2;
	//常量指针
	const int *p;
	p = &a;
	printf("p的地址：%p",p);
	printf("p所指向的值：%d\n",*p); //输出  p的地址：0061FF24  p所指向的值：1
	
	//改变p的地址
	p = &b;
	printf("p的地址：%p",p);
	printf("p所指向的值：%d\n",*p); //输出 p的地址：0061FF24 p所指向的值：2
	
	//改变p所指向的值
	//*p = a;  // 会报错  assignment of read-only location '*p' 说明常量指针指向的值不能改变
	//printf("p的地址：%p",p);
	//printf("p所指向的值：%d\n",*p);
	
	
	//数组
	int arr1[] = {1,2,3};
	int arr2[] = {4,5,6};
	//改变arr1的地址
	//arr1 = arr2; //会报错  assignment to expression with array type 说明数组地址不能改变
	//改变arr1的值
	arr1[0] = 1000;
	printf("arr1[0]:%d\n",arr1[0]); //输出 arr1[0]:1000
	printf("arr1[0]:%d\n",*arr1); //输出 arr1[0]:1000
	fun(arr1);
}

void fun(int arr[]){
	printf("arr[0]:%d",*arr); //输出 arr[0]:1000
}
```
- 加上`const`之后的区别
const int\* p
int const\* p
int \*const p
他们三个有什么区别？
const在\*前面表示不能通过 \*p = i 这样赋值 但是i的值本身是可变的
const在\*后面表示p不能变，也就是p中保存的地址不能变 如：p = &i不对
- 在数组上加`const`
const int a[]
因为a本身可以看做不可改变地址的指针，在加上const表示数组中的每个值都是不可改变的
注意和const指针不一样，const指针指向的值可以改变
- *p++
通常*P++ 都有对应的机器指令 可以执行的更快
- NULL
操作系统会为每个进程分配连续的虚拟内存，其中有0地址的内存通常不能动，
我们利用这个为指针赋初值0 或 NULL，通常为NULL
- 动态内存分配 `malloc`
```c
//使用malloc 必须引入
#include <stdlib.h>
int* a;
//malloc返回的是void* 必须转换
a = (int*)malloc(n*sizeof(int));
//用完之后必须释放
free(a);
```
- getchar()和putchar()
每次只读取和写入一个字节
在shell环境中，可以连续输入一串字符串，按回车键会写入shell的缓冲区中，然后才由c程序读取
`ctrl+d`或`ctrl+z`:这个指令是shell接收，会把程序执行完
`ctrl+c`:强行中断
- 字符串数组
`char** a`表示a是一个指向指针的指针
`char a[][]` a[0]-->char[10]
`char* a[]` a[0]-->char*
```c
    main(int argc,char const *argv[]){
    }
```
- 字符串操作函数
\#include <string.h>
strlen(char const* s)
strcmp(const char* s1,const char* s2)
char* strcpy(char* restrict dst,char const*restrict src)
char* strchr(const char* s,int c)
char* strrchr(const char* s,int c)
char* strstr(const char* s1,const char* s2)
char* strcasestr(const char* s1,const char* s2)
- 枚举
```c
    //colors是枚举的类型
    //常量符号只能是int类型，依次从0到n
    enum colors {red,green,yellow,numcolors};
    //枚举类型常量也可以指定值
    enum colors {red=2,green,yellow=5};
```
- 结构类型
```c
struct date {
            int day;
            int month;
            int year;
            };
struct date date1 = {1,2,3};
struct date date2 = {.day=1,.year=3};//没有赋值的默认0
```
结构类型和数组不一样 数组名字是指针，结构类型不是，
结构类型可以用另一个结构类型赋值，数组不行，并且赋值以后两个是独立的个体
结构类型作为参数的时候是复制过去的，和数组不一样
`p->month`:p是结构体指针
`scanf("%d",&p->x)`先计算p->x 再取地址&

- 结构数组
`struct date dates[] = {{},{}}`
- 类型定义
`typedef int alias`
- 联合
`union{}`里面的成员占据同样的空间
小端法：低位在前
- ACLLIB图形库

