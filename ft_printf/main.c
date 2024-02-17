#include <stdio.h>
#include <stdarg.h>

int sum_variadic(int count, ...)
{
    va_list args;

    va_start(args, count);
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}
int main ()
{
	int i = sum_variadic(4, 2, 3, 4, 5);
	printf("%d" , i);
}