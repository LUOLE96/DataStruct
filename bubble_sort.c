#include <stdio.h>
#include <string.h>
/* 冒泡排序*/
static int print_array(int *array,int array_size)
{
    int i;
    for(i = 0;i < array_size;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}

static int bubble_sort(int *array,int array_size)
{
    int i,j,temp;
    for(i = 0;i < array_size - 1;i++)
    {
        for(j = 0;j < array_size - 1 - i;j++)
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp; 
            }
        }
    }
    return 0;
}

/*选择排序*/
static int selection_sort(int *array,int array_size)
{
    int i,j,k,temp;
    for(i = 0;i < array_size - 1;i++)
    {
        k = i;
        for(j = i + 1;j < array_size;j++)
        {
            if(array[j] < array[k])
            {
                k = j;
            }
            if(i != k)
            {
                temp = array[i];
                array[i] = array[k];
                array[k] = temp;
            }
        }
    }
}

/*快速排序*/

/*十进制转为二进制*/
static int base_convert(void)
{
    int num,base;
    int numstr[128];
    int i = 0;

    printf("please input a num and basenum\n");
    scanf("%d%d",&num,&base);

    do
    {
        numstr[i] = num % base;
        num = num/base;
        i++;
    } while (num != 0);
    
    int array_len = strlen(numstr);
    for(i--;i >= 0;i--)
    {
        if(numstr[i] >= 10)
        {
            printf("%c",numstr[i] - 10 + 'A');
        }
        else
            printf("%d ",numstr[i]);
    }
    printf("\n");
}

/*1000以内的质数
*删除法
*/
static int primer(void)
{
    char num[1001] = {0};
    
}

int main(void)
{
    int array_size;
    int array_test[] = {12,56,3,4,89,324,90,74};

    print_array(array_test,array_size);

    //bubble_sort(array_test,array_size);
    //selection_sort(array_test,array_size);
    base_convert();

    print_array(array_test,array_size);
    
    return 0;
}