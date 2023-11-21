#include "main.h"

void times_table(void)
{
    int iz, der, den, mul, result;
    int i = 0;

    for (den = 0; den != 10; den++)
    {
        mul = 0;
        
        /*print the 0 * 9 table*/
        while (i != 10)
        {
          result = den * mul;

		iz = (result / 10) + '0';
    		der = (result % 10) + '0';

            if (result == 0 && i == 0 && den == 0)
            {
                _putchar(result + '0');
                _putchar(',');
                _putchar(' ');
		_putchar(' ');
            }
            else if (i == 9)
            {
                if (result < 10)
                {
                    _putchar(result + '0');
                    _putchar('\n');
                }
                else
                {
                    _putchar(iz);
                    _putchar(der);
                    _putchar('\n');
                }
            }
            else
            {
                if (result < 10)
                {
                    _putchar(result + '0');
                }
                else
                {
                    _putchar(iz);
                    _putchar(der);
                }
		if (den * mul + den > 9)
		{
                	_putchar(',');
                	_putchar(' ');
		}
		else
		{
			_putchar(',');
			_putchar(' ');
			_putchar(' ');
		}
                if (den != 0)
                    mul++;
            }
            i++;
        }
        i = 0;
     }
}
