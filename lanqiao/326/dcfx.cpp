#include "stdio.h"
#include "string.h"
int main(){
//定义简单的哈希表并确定表长为128(因为ASCII码只占一个字节8位)并赋初值为0
    int a[128]={0};
    char s[1000];
    scanf("%s",s);
    int len=strlen(s);
//max用于更新最大次数，t用于更新对应的字符
    int max = 0;
    char t = 0;
//完成哈希表的建立(即遍历一遍字符串得到值键对)
    for(int i=0;i<len;i++){
        a[s[i]]++;
        if (max<a[s[i]])
{//完成最大次数的扫描，以及该情况下对应键的记录
            max = a[s[i]];
            t = s[i];
}//若出现相同次数利用ASCII码来进行判断，小的记录下来
        else if (max==a[s[i]]){
            if (t>s[i])
    {
                t = s[i];
    }
    
}
}//最后进行字符以及对应次数的输出即可。
    printf("%c\n%d",t,max);
}
