#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	printf("Content-type:text/html\r\n\r\n");
	printf("<html><title>Cgi HelloWorld!</tile>\n");
	printf("<body><h1>HELLO WORLD!!!</h1></body>");
	printf("</html>\n");
	return 0;
}

