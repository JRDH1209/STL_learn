#include<stdio.h>
#include<iostream>
// #include <string>
using std::cin;
using std::cout;
using std::string;
using std::endl;
long get_a_target_lone()
{
    long target = 0;
    cout << "target (0~" << RAND_MAX <<");";
    cin >> target;
    cout<<"the cin is:"<<target<<std::endl;
    return target;
}

string get_a_target_string()
{
    long target = 0;
    char buf[10];

    cout << "target (0~" <<RAND_MAX <<");";
    cin >> target;
    snprintf(buf,10,"%ld",target);   /*snprintf()实际上是将target存放在buf里面，10为字符串数组的长度*/
    return string(buf);
}

int compareLonges(const void* a,const void* b)
{
/*
const void* a 解析：
1.void*代表a为一个无类型指针，a仅存放一个地址，地址指向的空间的类型暂定
2.这里只是暂时让其指向对象的类型暂定，后续会给其进行强制类型转换，使其所指对象的类型得到明确
实例：char* test = (char*)malloc(sizeof(char)*10);
这里malloc分配一段内存空间，其返回的是一个地址（未确定地址所指对象的类型，等价于void*），再进行强制类型转换
*/ 
    return (*(long*)a - *(long*)b);
    // 这里对void*的a强制类型转换后再解引用
}

long compareStrings(const void* a,const void* b)
{
    if(*(string*)a > *(string*)b)
    {
        return 1;
    }
    else if(*(string*)a < *(string*)b)
    {
        return -1;
    }
    else
        return 0;
}


#if 1
int main(void)
{
    long test;
    // int a,b;
    string a,b;
    string tstring;
    // test = get_a_target_lone();
    // tstring = get_a_target_string();
    // cout<<test<<std::endl;
    // cout<<tstring<<std::endl;
    cin >> a >> b;
    // test = compareLonges(&b, &a);
    test = compareStrings(&a, &b);
    cout<<test<<std::endl;
    return 0;
}
#endif