#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, *ptr;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    ptr = (int *)calloc(n , sizeof(int));
    
    
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",ptr+i);
    }
    for (int i = 0; i < n; ++i)
    {
        printf("%d",*(ptr+i));
    }
    


}
