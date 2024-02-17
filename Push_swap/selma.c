#include <unistd.h>
#include <stdio.h>

int function_tejriba(int pointer)
{
	pointer = 10;
	return 0;
}
int main ()
{
	int selma = 5;
	printf("l9ima lewla = %d\n", selma);
	function_tejriba(selma);
	printf("l9ima tanya = %d", selma);

}