#include<stdio.h>

int char_to_binstr(char c, char *s)
{
	int v;
	int i;

	for (i = 7; i >= 0; i--)
	{
		v = c & 0b1;
		s[i] = (char) v + '0';
		c = c >> 1;
	}
	s[8] = '\0';

	return 0;
}

int main(int argc, char **argv)
{
	char c = 'a';
	char s[32];

	char_to_binstr(c, s);
	printf("s = %s\n", s);

	return 0;
}


