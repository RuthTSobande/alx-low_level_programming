#include "main.h"
#include <stdio.h>


/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */

int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
<<<<<<< HEAD
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
=======
		if (s[i] == '-')
			++d;
		if (s[i] >= '0' && s[i] <= '9')
>>>>>>> 8c107ecb728efb4ed435f5f6785cd31daee953be
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}
<<<<<<< HEAD

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
=======
	if (f == 0)
		return (0);
	return (n);

>>>>>>> 8c107ecb728efb4ed435f5f6785cd31daee953be
}
