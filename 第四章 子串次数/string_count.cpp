#include<string.h>
#include<stdio.h>

int count1(char* str,char* s);

int main()
{
	char s1[100]={'0'},s2[100]={'0'};
	int count;
	printf("please input the main string\n");
	gets(s1);
	printf("please input the sub string\n");
	gets(s2);
	count=count1(s1,s2);
	printf("the number is %d",count);
	return 0;
}

int count1(char* str,char* s)
{
    char* s1;
    char* s2;
    int count = 0;
    while(*str!='\0')
    {
        s1 = str;//whileѭ����ÿ�ζ�Ҫ��ʼ�����Ա���֡�����Ӵ���ʱָ�������¶�λ
        s2 = s;
        while(*s2 == *s1 && (*s2!='\0') && (*s1!='\0'))
        {
            s2++;
            s1++;
        }
        if(*s2 == '\0')
            count++;
        str++;//����������һλ�ַ�������������˵s1ָ��ָ����һλ�ַ�
    }
    return count;
}
