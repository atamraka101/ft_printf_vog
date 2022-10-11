#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int	p = 5;
	int a = 0;
	int b = 0;

	printf("\nBasic Eval Tests\n");

	printf("\nCharacters & Strings\n\n");

	printf("|%%|\n");
	ft_printf("|%%|\n");
	printf("|%.%| |%%|\n");
	ft_printf("|%%| |%%|\n");
	printf("\n");

	printf("|%c|\n", 'A');
	ft_printf("|%c|\n", 'A');
	printf("\n");
	printf("|%10.c|\n", 'A');
	ft_printf("|%10.c|\n", 'A');
	printf("\n");
	printf("|%-10.c|\n", 'A');
	ft_printf("|%-10c|\n", 'A');
	printf("\n");
	printf("|%c| |%%| |%c|\n", 'A', 'b');
	ft_printf("|%c| |%%| |%c|\n", 'A', 'b');
	printf("\n");
	printf("|%c%%%c|\n", 'A', 'b');
	ft_printf("|%c%%%c|\n", 'A', 'b');
	printf("\n");
	printf("|%10c|%-10%|%-10c|\n", 'A', 'b');
	ft_printf("|%10c|%-10%|%-10c|\n", 'A', 'b');

	printf("\n");
	printf("|%s|\n", "Hello World!");
	ft_printf("|%s|\n", "Hello World!");
	printf("\n");
	printf("|%s|\n", NULL);
	ft_printf("|%s|\n", NULL);
	printf("\n");
	printf("|%20.3s|\n", "Hello World!");
	ft_printf("|%20.3s|\n", "Hello World!");
	printf("\n");
	printf("|%-20.3s|\n", NULL);
	ft_printf("|%-20.3s|\n", NULL);
	printf("\n");
	printf("|%20.3s%-20.3s|\n", "Hello World!", NULL);
	ft_printf("|%20.3s%-20.3s|\n", "Hello World!", NULL);

	printf("\n");

	printf("\nInts, U-Ints and all that good stuff\n\n");

	printf("\n");
	printf("|%d|\n", 42);
	ft_printf("|%d|\n", 42);
	printf("\n");
	printf("|%4d|\n", 42);
	ft_printf("|%4d|\n", 42);
	printf("\n");
	printf("|%04d|\n", 42);
	ft_printf("|%04d|\n", 42);
	printf("\n");
	printf("|%-4d|\n", 42);
	ft_printf("|%-4d|\n", 42);
	printf("\n");
	printf("|%+4d|\n", 42);
	ft_printf("|%+4d|\n", 42);
	printf("\n");
	printf("|%.8d|\n", 42);
	ft_printf("|%.8d|\n", 42);
	printf("\n");
	printf("|%10.4d|\n", 42);
	ft_printf("|%10.4d|\n", 42);
	printf("\n");
	printf("|%-10.4d|\n", 42);
	ft_printf("|%-10.4d|\n", 42);
	printf("\n");
	printf("|%.d|\n", 42);
	ft_printf("|%.d|\n", 42);
	printf("\n");
	printf("|%10.d|\n", 42);
	ft_printf("|%10.d|\n", 42);

	printf("|%d|\n", -42);
	ft_printf("|%d|\n", -42);
	printf("\n");
	printf("|%4d|\n", -42);
	ft_printf("|%4d|\n", -42);
	printf("\n");
	printf("|%04d|\n", -42);
	ft_printf("|%04d|\n", -42);
	printf("\n");
	printf("|%-4d|\n", -42);
	ft_printf("|%-4d|\n", -42);
	printf("\n");
	printf("|%+4d|\n", -42);
	ft_printf("|%+4d|\n", -42);
	printf("\n");
	printf("|%.8d|\n", -42);
	ft_printf("|%.8d|\n", -42);
	printf("\n");
	printf("|%10.4d|\n", -42);
	ft_printf("|%10.4d|\n", -42);
	printf("\n");
	printf("|%-10.4d|\n", -42);
	ft_printf("|%-10.4d|\n", -42);
	printf("\n");
	printf("|%.d|\n", -42);
	ft_printf("|%.d|\n", -42);
	printf("\n");
	printf("|%10.d|\n", -42);
	ft_printf("|%10.d|\n", -42);

	printf("\n");
	printf("|%d|\n", 0);
	ft_printf("|%d|\n", 0);
	printf("\n");
	printf("|%4d|\n", 0);
	ft_printf("|%4d|\n", 0);
	printf("\n");
	printf("|%04d|\n", 0);
	ft_printf("|%04d|\n", 0);
	printf("\n");
	printf("|%-4d|\n", 0);
	ft_printf("|%-4d|\n", 0);
	printf("\n");
	printf("|%+4d|\n", 0);
	ft_printf("|%+4d|\n", 0);
	printf("\n");
	printf("|%.8d|\n", 0);
	ft_printf("|%.8d|\n", 0);
	printf("\n");
	printf("|%10.4d|\n", 0);
	ft_printf("|%10.4d|\n", 0);
	printf("\n");
	printf("|%-10.4d|\n", 0);
	ft_printf("|%-10.4d|\n", 0);
	printf("\n");
	printf("|%.d|\n", 0);
	ft_printf("|%.d|\n", 0);
	printf("\n");
	printf("|%10.d|\n", 0);
	ft_printf("|%10.d|\n", 0);
	printf("\n");
	printf("|%10.d|\n", 0);
	ft_printf("|%10.d|\n", 0);
	printf("\n");
	printf("|%+.d|\n", 0);
	ft_printf("|%+.d|\n", 0);
	printf("\n\nMax & Mods\n\n");

	printf("\n");
	printf("|%d|\n", 2147483647);
	ft_printf("|%d|\n", 2147483647);
	printf("\n");
	printf("|%lld|\n", 9223372036854775807LL);
	ft_printf("|%lld|\n", 9223372036854775807LL);
	printf("\n");
	printf("|%d|\n", 2147483649L);
	ft_printf("|%d|\n", 2147483649L);
	printf("\n");
	printf("|%ld|\n", 2147483649L);
	ft_printf("|%ld|\n", 2147483649L);

	printf("\n\nUnsigned ints\n");

	printf("\n");
	printf("|%u|\n", 42);
	ft_printf("|%u|\n", 42);
	printf("\n");
	printf("|%4u|\n", 42);
	ft_printf("|%4u|\n", 42);
	printf("\n");
	printf("|%04u|\n", 42);
	ft_printf("|%04u|\n", 42);
	printf("\n");
	printf("|%-4u|\n", 42);
	ft_printf("|%-4u|\n", 42);
	printf("\n");
	printf("|%+4u|\n", 42);
	ft_printf("|%+4u|\n", 42);
	printf("\n");
	printf("|%.8u|\n", 42);
	ft_printf("|%.8u|\n", 42);
	printf("\n");
	printf("|%10.4u|\n", 42);
	ft_printf("|%10.4u|\n", 42);
	printf("\n");
	printf("|%-10.4u|\n", 42);
	ft_printf("|%-10.4u|\n", 42);
	printf("\n");
	printf("|%.u|\n", 42);
	ft_printf("|%.u|\n", 42);
	printf("\n");
	printf("|%10.u|\n", 42);
	ft_printf("|%10.u|\n", 42);
	printf("\n");
	printf("|%u|\n", 4294967295);
	ft_printf("|%u|\n", 4294967295);
	printf("\n");
	printf("|%u|\n", 4294967296);
	ft_printf("|%u|\n", 4294967296);
	printf("\n");
	printf("|%lu|\n", 4294967296L);
	ft_printf("|%lu|\n", 4294967296L);
	printf("\n");
	printf("|%llu|\n", 18446744073709551615ULL);
	ft_printf("|%llu|\n", 18446744073709551615ULL);

	printf("\n");


	printf("\nHex's\n");
	printf("\n");

	printf("|%x|\n", 42);
	ft_printf("|%x|\n", 42);
	printf("\n");
	printf("|%4x|\n", 42);
	ft_printf("|%4x|\n", 42);
	printf("\n");
	printf("|%04x|\n", 42);
	ft_printf("|%04x|\n", 42);
	printf("\n");
	printf("|%-4x|\n", 42);
	ft_printf("|%-4x|\n", 42);
	printf("\n");
	printf("|%4x|\n", 42);
	ft_printf("|%4x|\n", 42);
	printf("\n");
	printf("|%.8x|\n", 42);
	ft_printf("|%.8x|\n", 42);
	printf("\n");
	printf("|%10.4x|\n", 42);
	ft_printf("|%10.4x|\n", 42);
	printf("\n");
	printf("|%-10.4x|\n", 42);
	ft_printf("|%-10.4x|\n", 42);
	printf("\n");
	printf("|%.x|\n", 42);
	ft_printf("|%.x|\n", 42);
	printf("\n");
	printf("|%10.x|\n", 42);
	ft_printf("|%10.x|\n", 42);
	printf("\n");
	printf("|%020x|\n", 42);
	ft_printf("|%020x|\n", 42);
	printf("\n");
	printf("|%020.5x|\n", 42);
	ft_printf("|%020.5x|\n", 42);

	printf("\n");
	printf("|%x|\n", 0);
	ft_printf("|%x|\n", 0);
	printf("\n");
	printf("|%4x|\n", 0);
	ft_printf("|%4x|\n", 0);
	printf("\n");
	printf("|%04x|\n", 0);
	ft_printf("|%04x|\n", 0);
	printf("\n");
	printf("|%-4x|\n", 0);
	ft_printf("|%-4x|\n", 0);
	printf("\n");
	printf("|%4x|\n", 0);
	ft_printf("|%4x|\n", 0);
	printf("\n");
	printf("|%.8x|\n", 0);
	ft_printf("|%.8x|\n", 0);
	printf("\n");
	printf("|%10.4x|\n", 0);
	ft_printf("|%10.4x|\n", 0);
	printf("\n");
	printf("|%-10.4x|\n", 0);
	ft_printf("|%-10.4x|\n", 0);
	printf("\n");
	printf("|%.x|\n", 0);
	ft_printf("|%.x|\n", 0);
	printf("\n");
	printf("|%10.x|\n", 0);
	ft_printf("|%10.x|\n", 0);
	printf("\n");
	printf("|%10.x|\n", 0);
	ft_printf("|%10.x|\n", 0);
	printf("\n");
	printf("|%.x|\n", 0);
	ft_printf("|%.x|\n", 0);

	printf("\n");
	printf("|%#x|\n", 42);
	ft_printf("|%#x|\n", 42);
	printf("\n");
	printf("|%#4x|\n", 42);
	ft_printf("|%#4x|\n", 42);
	printf("\n");
	printf("|%#04x|\n", 42);
	ft_printf("|%#04x|\n", 42);
	printf("\n");
	printf("|%#-4x|\n", 42);
	ft_printf("|%#-4x|\n", 42);
	printf("\n");
	printf("|%#4x|\n", 42);
	ft_printf("|%#4x|\n", 42);
	printf("\n");
	printf("|%#.8x|\n", 42);
	ft_printf("|%#.8x|\n", 42);
	printf("\n");
	printf("|%#10.4x|\n", 42);
	ft_printf("|%#10.4x|\n", 42);
	printf("\n");
	printf("|%#-10.4x|\n", 42);
	ft_printf("|%#-10.4x|\n", 42);
	printf("\n");
	printf("|%#.x|\n", 42);
	ft_printf("|%#.x|\n", 42);
	printf("\n");
	printf("|%#10.x|\n", 42);
	ft_printf("|%#10.x|\n", 42);
	printf("\n");
	printf("|%#020x|\n", 42);
	ft_printf("|%#020x|\n", 42);
	printf("\n");
	printf("|%#020.5x|\n", 42);
	ft_printf("|%#020.5x|\n", 42);

	printf("\n");
	printf("|%#x|\n", 0);
	ft_printf("|%#x|\n", 0);
	printf("\n");
	printf("|%#4x|\n", 0);
	ft_printf("|%#4x|\n", 0);
	printf("\n");
	printf("|%#04x|\n", 0);
	ft_printf("|%#04x|\n", 0);
	printf("\n");
	printf("|%#-4x|\n", 0);
	ft_printf("|%#-4x|\n", 0);
	printf("\n");
	printf("|%#4x|\n", 0);
	ft_printf("|%#4x|\n", 0);
	printf("\n");
	printf("|%#.8x|\n", 0);
	ft_printf("|%#.8x|\n", 0);
	printf("\n");
	printf("|%#10.4x|\n", 0);
	ft_printf("|%#10.4x|\n", 0);
	printf("\n");
	printf("|%#-10.4x|\n", 0);
	ft_printf("|%#-10.4x|\n", 0);
	printf("\n");
	printf("|%#.x|\n", 0);
	ft_printf("|%#.x|\n", 0);
	printf("\n");
	printf("|%#10.x|\n", 0);
	ft_printf("|%#10.x|\n", 0);
	printf("\n");
	printf("|%#10.x|\n", 0);
	ft_printf("|%#10.x|\n", 0);
	printf("\n");
	printf("|%#.x|\n", 0);
	ft_printf("|%#.x|\n", 0);

	printf("\n\n");
	printf("|%X|\n", 42);
	ft_printf("|%X|\n", 42);
	printf("\n");
	printf("|%4X|\n", 42);
	ft_printf("|%4X|\n", 42);
	printf("\n");
	printf("|%04X|\n", 42);
	ft_printf("|%04X|\n", 42);
	printf("\n");
	printf("|%-4X|\n", 42);
	ft_printf("|%-4X|\n", 42);
	printf("\n");
	printf("|%4X|\n", 42);
	ft_printf("|%4X|\n", 42);
	printf("\n");
	printf("|%.8X|\n", 42);
	ft_printf("|%.8X|\n", 42);
	printf("\n");
	printf("|%10.4X|\n", 42);
	ft_printf("|%10.4X|\n", 42);
	printf("\n");
	printf("|%-10.4X|\n", 42);
	ft_printf("|%-10.4X|\n", 42);
	printf("\n");
	printf("|%.X|\n", 42);
	ft_printf("|%.X|\n", 42);
	printf("\n");
	printf("|%10.X|\n", 42);
	ft_printf("|%10.X|\n", 42);
	printf("\n");
	printf("|%020X|\n", 42);
	ft_printf("|%020X|\n", 42);
	printf("\n");
	printf("|%020.5X|\n", 42);
	ft_printf("|%020.5X|\n", 42);

	printf("\n");
	printf("|%X|\n", 0);
	ft_printf("|%X|\n", 0);
	printf("\n");
	printf("|%4X|\n", 0);
	ft_printf("|%4X|\n", 0);
	printf("\n");
	printf("|%04X|\n", 0);
	ft_printf("|%04X|\n", 0);
	printf("\n");
	printf("|%-4X|\n", 0);
	ft_printf("|%-4X|\n", 0);
	printf("\n");
	printf("|%4X|\n", 0);
	ft_printf("|%4X|\n", 0);
	printf("\n");
	printf("|%.8X|\n", 0);
	ft_printf("|%.8X|\n", 0);
	printf("\n");
	printf("|%10.4X|\n", 0);
	ft_printf("|%10.4X|\n", 0);
	printf("\n");
	printf("|%-10.4X|\n", 0);
	ft_printf("|%-10.4X|\n", 0);
	printf("\n");
	printf("|%.X|\n", 0);
	ft_printf("|%.X|\n", 0);
	printf("\n");
	printf("|%10.X|\n", 0);
	ft_printf("|%10.X|\n", 0);
	printf("\n");
	printf("|%10.X|\n", 0);
	ft_printf("|%10.X|\n", 0);
	printf("\n");
	printf("|%.X|\n", 0);
	ft_printf("|%.X|\n", 0);

	printf("\n");
	printf("|%#X|\n", 42);
	ft_printf("|%#X|\n", 42);
	printf("\n");
	printf("|%#4X|\n", 42);
	ft_printf("|%#4X|\n", 42);
	printf("\n");
	printf("|%#04X|\n", 42);
	ft_printf("|%#04X|\n", 42);
	printf("\n");
	printf("|%#-4X|\n", 42);
	ft_printf("|%#-4X|\n", 42);
	printf("\n");
	printf("|%#4X|\n", 42);
	ft_printf("|%#4X|\n", 42);
	printf("\n");
	printf("|%#.8X|\n", 42);
	ft_printf("|%#.8X|\n", 42);
	printf("\n");
	printf("|%#10.4X|\n", 42);
	ft_printf("|%#10.4X|\n", 42);
	printf("\n");
	printf("|%#-10.4X|\n", 42);
	ft_printf("|%#-10.4X|\n", 42);
	printf("\n");
	printf("|%#.X|\n", 42);
	ft_printf("|%#.X|\n", 42);
	printf("\n");
	printf("|%#10.X|\n", 42);
	ft_printf("|%#10.X|\n", 42);
	printf("\n");
	printf("|%#020X|\n", 42);
	ft_printf("|%#020X|\n", 42);
	printf("\n");
	printf("|%#020.5X|\n", 42);
	ft_printf("|%#020.5X|\n", 42);

	printf("\n");
	printf("|%#X|\n", 0);
	ft_printf("|%#X|\n", 0);
	printf("\n");
	printf("|%#4X|\n", 0);
	ft_printf("|%#4X|\n", 0);
	printf("\n");
	printf("|%#04X|\n", 0);
	ft_printf("|%#04X|\n", 0);
	printf("\n");
	printf("|%#-4X|\n", 0);
	ft_printf("|%#-4X|\n", 0);
	printf("\n");
	printf("|%#4X|\n", 0);
	ft_printf("|%#4X|\n", 0);
	printf("\n");
	printf("|%#.8X|\n", 0);
	ft_printf("|%#.8X|\n", 0);
	printf("\n");
	printf("|%#10.4X|\n", 0);
	ft_printf("|%#10.4X|\n", 0);
	printf("\n");
	printf("|%#-10.4X|\n", 0);
	ft_printf("|%#-10.4X|\n", 0);
	printf("\n");
	printf("|%#.X|\n", 0);
	ft_printf("|%#.X|\n", 0);
	printf("\n");
	printf("|%#10.X|\n", 0);
	ft_printf("|%#10.X|\n", 0);
	printf("\n");
	printf("|%#10.X|\n", 0);
	ft_printf("|%#10.X|\n", 0);
	printf("\n");
	printf("|%#.X|\n", 0);
	ft_printf("|%#.X|\n", 0);

	printf("\nOctals\n");
	printf("\n");
	printf("|%o|\n", 42);
	ft_printf("|%o|\n", 42);
	printf("\n");
	printf("|%4o|\n", 42);
	ft_printf("|%4o|\n", 42);
	printf("\n");
	printf("|%04o|\n", 42);
	ft_printf("|%04o|\n", 42);
	printf("\n");
	printf("|%-4o|\n", 42);
	ft_printf("|%-4o|\n", 42);
	printf("\n");
	printf("|%4o|\n", 42);
	ft_printf("|%4o|\n", 42);
	printf("\n");
	printf("|%.8o|\n", 42);
	ft_printf("|%.8o|\n", 42);
	printf("\n");
	printf("|%10.4o|\n", 42);
	ft_printf("|%10.4o|\n", 42);
	printf("\n");
	printf("|%-10.4o|\n", 42);
	ft_printf("|%-10.4o|\n", 42);
	printf("\n");
	printf("|%.o|\n", 42);
	ft_printf("|%.o|\n", 42);
	printf("\n");
	printf("|%10.o|\n", 42);
	ft_printf("|%10.o|\n", 42);
	printf("\n");
	printf("|%020o|\n", 42);
	ft_printf("|%020o|\n", 42);
	printf("\n");
	printf("|%020.5o|\n", 42);
	ft_printf("|%020.5o|\n", 42);

	printf("\n");
	printf("|%o|\n", 0);
	ft_printf("|%o|\n", 0);
	printf("\n");
	printf("|%4o|\n", 0);
	ft_printf("|%4o|\n", 0);
	printf("\n");
	printf("|%04o|\n", 0);
	ft_printf("|%04o|\n", 0);
	printf("\n");
	printf("|%-4o|\n", 0);
	ft_printf("|%-4o|\n", 0);
	printf("\n");
	printf("|%4o|\n", 0);
	ft_printf("|%4o|\n", 0);
	printf("\n");
	printf("|%.8o|\n", 0);
	ft_printf("|%.8o|\n", 0);
	printf("\n");
	printf("|%10.4o|\n", 0);
	ft_printf("|%10.4o|\n", 0);
	printf("\n");
	printf("|%-10.4o|\n", 0);
	ft_printf("|%-10.4o|\n", 0);
	printf("\n");
	printf("|%.o|\n", 0);
	ft_printf("|%.o|\n", 0);
	printf("\n");
	printf("|%10.o|\n", 0);
	ft_printf("|%10.o|\n", 0);
	printf("\n");
	printf("|%10.o|\n", 0);
	ft_printf("|%10.o|\n", 0);
	printf("\n");
	printf("|%.o|\n", 0);
	ft_printf("|%.o|\n", 0);

	printf("\n");
	printf("|%#o|\n", 42);
	ft_printf("|%#o|\n", 42);
	printf("\n");
	printf("|%#4o|\n", 42);
	ft_printf("|%#4o|\n", 42);
	printf("\n");
	printf("|%#04o|\n", 42);
	ft_printf("|%#04o|\n", 42);
	printf("\n");
	printf("|%#-4o|\n", 42);
	ft_printf("|%#-4o|\n", 42);
	printf("\n");
	printf("|%#4o|\n", 42);
	ft_printf("|%#4o|\n", 42);
	printf("\n");
	printf("|%#.8o|\n", 42);
	ft_printf("|%#.8o|\n", 42);
	printf("\n");
	printf("|%#10.4o|\n", 42);
	ft_printf("|%#10.4o|\n", 42);
	printf("\n");
	printf("|%#-10.4o|\n", 42);
	ft_printf("|%#-10.4o|\n", 42);
	printf("\n");
	printf("|%#.o|\n", 42);
	ft_printf("|%#.o|\n", 42);
	printf("\n");
	printf("|%#10.o|\n", 42);
	ft_printf("|%#10.o|\n", 42);
	printf("\n");
	printf("|%#020o|\n", 42);
	ft_printf("|%#020o|\n", 42);
	printf("\n");
	printf("|%#020.5o|\n", 42);
	ft_printf("|%#020.5o|\n", 42);

	printf("\n");
	printf("|%#o|\n", 0);
	ft_printf("|%#o|\n", 0);
	printf("\n");
	printf("|%#4o|\n", 0);
	ft_printf("|%#4o|\n", 0);
	printf("\n");
	printf("|%#04o|\n", 0);
	ft_printf("|%#04o|\n", 0);
	printf("\n");
	printf("|%#-4o|\n", 0);
	ft_printf("|%#-4o|\n", 0);
	printf("\n");
	printf("|%#4o|\n", 0);
	ft_printf("|%#4o|\n", 0);
	printf("\n");
	printf("|%#.8o|\n", 0);
	ft_printf("|%#.8o|\n", 0);
	printf("\n");
	printf("|%#10.4o|\n", 0);
	ft_printf("|%#10.4o|\n", 0);
	printf("\n");
	printf("|%#-10.4o|\n", 0);
	ft_printf("|%#-10.4o|\n", 0);
	printf("\n");
	printf("|%#.o|\n", 0);
	ft_printf("|%#.o|\n", 0);
	printf("\n");
	printf("|%#10.o|\n", 0);
	ft_printf("|%#10.o|\n", 0);
	printf("\n");
	printf("|%#10.o|\n", 0);
	ft_printf("|%#10.o|\n", 0);
	printf("\n");
	printf("|%#.o|\n", 0);
	ft_printf("|%#.o|\n", 0);


	printf("\n\nPointers\n");

	printf("\n");
	printf("|%p|\n", &p);
	ft_printf("|%p|\n", &p);
	printf("\n");
	printf("|%30p|\n", &p);
	ft_printf("|%30p|\n", &p);
	printf("\n");
	printf("|%030p|\n", &p);
	ft_printf("|%030p|\n", &p);
	printf("\n");
	printf("|%p|\n", NULL);
	ft_printf("|%p|\n", NULL);


	printf("\n\nFloats\n");

	printf("\n");
	printf("|%f|\n", 0.5);
	ft_printf("|%f|\n", 0.5);
	printf("\n");
	printf("|%f|\n", 1.5);
	ft_printf("|%f|\n", 1.5);
	printf("\n");
	printf("|%.f|\n", 0.5);
	ft_printf("|%.f|\n", 0.5);
	printf("\n");
	printf("|%.f|\n", 1.5);
	ft_printf("|%.f|\n", 1.5);
	printf("\n");
	printf("|%.f|\n", 2.5);
	ft_printf("|%.f|\n", 2.5);
	printf("\n");
	printf("|%.f|\n", 3.5);
	ft_printf("|%.f|\n", 3.5);
	printf("\n");
	printf("|%.1f|\n", 3.55);
	ft_printf("|%.1f|\n", 3.55);
	printf("\n");
	printf("|%.1Lf|\n", 3.55L);
	ft_printf("|%.1Lf|\n", 3.55L);
	printf("\n");
	printf("|%.1f|\n", 42.42);
	ft_printf("|%.1f|\n", 42.42);
	printf("\n");
	printf("|%.1Lf|\n", 42.42L);
	ft_printf("|%.1Lf|\n", 42.42L);
	printf("\n");
	printf("|%f|\n", 42.42);
	ft_printf("|%f|\n", 42.42);
	printf("\n");
	printf("|%Lf|\n", 42.42L);
	ft_printf("|%Lf|\n", 42.42L);
	printf("\n");
	printf("|%.4f|\n", 12345.56432354637);
	ft_printf("|%.4f|\n", 12345.56432354637);
	printf("\n");
	printf("|%.4Lf|\n", 12345.56432354637L);
	ft_printf("|%.4Lf|\n", 12345.56432354637L);
	printf("\n");
	printf("|%.12f|\n", 12345.56432354637);
	ft_printf("|%.12f|\n", 12345.56432354637);
	printf("\n");
	printf("|%.12Lf|\n", 12345.56432354637L);
	ft_printf("|%.12Lf|\n", 12345.56432354637L);
	printf("\n");
	printf("|%.5f|\n", 2.55505);
	ft_printf("|%.5f|\n", 2.55505);
	printf("\n");
	printf("|%.5Lf|\n", 2.555505L);
	ft_printf("|%.5Lf|\n", 2.555505L);

	printf("\n");
	printf("|%f|\n", 1 / 0.0);
	ft_printf("|%f|\n", 1 / 0.0);
	printf("\n");
	printf("|%f|\n", -1 / 0.0);
	ft_printf("|%f|\n", -1 / 0.0);
	printf("\n");
	printf("|%f|\n", 0.0 / 0);
	ft_printf("|%f|\n", 0.0 / 0);
	printf("\n");
	printf("|%f|\n", -0.0);
	ft_printf("|%f|\n", -0.0);

	printf("\n\nWildcard\n");
	printf("\n");
	printf("|%*d|\n", 10, 42);
	ft_printf("|%*d|\n", 10, 42);
	printf("\n");
	printf("|%.*d|\n", 10, 42);
	ft_printf("|%.*d|\n", 10, 42);
	printf("\n");
	printf("|%*.*d|\n", 10, 5, 42);
	ft_printf("|%*.*d|\n", 10, 5, 42);
	printf("\n");
	printf("|%+*d|\n", 10, 42);
	ft_printf("|%+*d|\n", 10, 42);
	printf("\n");
	printf("|%+.*d|\n", 10, 42);
	ft_printf("|%+.*d|\n", 10, 42);
	printf("\n");
	printf("|%+*.*d|\n", 10, 5, 42);
	ft_printf("|%+*.*d|\n", 10, 5, 42);




	printf("\n\nAll together now\n\n");

	//printf("All basic format specifiers:|%%|%c|%s|%d|%i|%#o|%#x|%#X|%p|%f|\n", 'A', "Hello World!", 42, 42, 42, 42, 42, &p, 42.42);
	//ft_printf("All basic format specifiers:|%%|%c|%s|%d|%i|%#o|%#x|%#X|%p|%f|\n", 'A', "Hello World!", 42, 42, 42, 42, 42, &p, 42.42);

	a = printf("All basic format specifiers:|%%|%c|%s|%d|%i|%#o|%#x|%#X|%p|%f|\n", 'A', "Hello World!", 42, 42, 42, 42, 42, &p, 42.42);
	b = ft_printf("All basic format specifiers:|%%|%c|%s|%d|%i|%#o|%#x|%#X|%p|%f|\n", 'A', "Hello World!", 42, 42, 42, 42, 42, &p, 42.42);

	printf("\nPrintf Return:\n|%i|\nFt_printf Return:\n|%i|\n\n\n", a, b);


	system("leaks a.out");
	return (0);
}
