#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
	void *ptr;
	int i;
	int *i_ptr;

	ptr = i_ptr;
	dprintf(2, "ptr = %p\n", ptr);
	dprintf(2, "dptr = %ld\n", ptr);
	dprintf(2, "ptr = %p\n", (int *)ptr + 1);
	dprintf(2, "dptr = %ld\n", (int *)ptr + 1);
}
