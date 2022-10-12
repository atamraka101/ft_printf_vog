#include <stdio.h>
# include "includes/ft_printf.h"

void test_char()
{
	int x, y;
	x = 0;
	y = 0;
	printf("Testing char ***\n");
	printf("Testing Basics\n");

	x += ft_printf("%c", 'a');
	x += ft_printf("abc%cxyz,", NULL);
	x += ft_printf("%c small string", '\0');
	x += ft_printf("the char is: %c", 'a');
	x += ft_printf("the char is: %c", '\0');
	x += ft_printf("n%cs", 'a');
	x += ft_printf("%c%c%c%c%c", 'a', 'i', 'u', 'e', 'o');
	x += ft_printf("l%cl%cl%cl%cl%c", 'a', 'i', 'u', 'e', 'o');
	x += ft_printf("l%cl%cl%cl%cl%c", '\0', '\0', '\0', 'e', '\0');

	printf("\n");

	y += printf("%c", 'a');
	y += printf("abc%cxyz,", NULL);
	y += printf("%c small string", '\0');
	y += printf("the char is: %c", 'a');
	y += printf("the char is: %c", '\0');
	y += printf("n%cs", 'a');
	y += printf("%c%c%c%c%c", 'a', 'i', 'u', 'e', 'o');
	y += printf("l%cl%cl%cl%cl%c", 'a', 'i', 'u', 'e', 'o');
	y += printf("l%cl%cl%cl%cl%c", '\0', '\0', '\0', 'e', '\0');
	printf("\n");
	printf("x: %d, y:%d\n", x, y);

	x = 0;
	y = 0;
	printf("Testing with width\n");

	x += ft_printf("%1c", 'a');
	x += ft_printf("%1c", '\0');
	x += ft_printf("%10c", 'b');
	x += ft_printf("%10c", '\0');
	x += ft_printf("%2c", 'c');
	x += ft_printf("%020c", 'c');
	x += ft_printf("%0-20c", 'd');
	x += ft_printf("there are 15 spaces between this text and the next char%15c", 'd');
	x += ft_printf("%5chis paragraph is indented", 't');
	x += ft_printf("%5c now you see", '\0');
	x += ft_printf("The number %7c represents luck", '7');

	printf("\n");

	y += printf("%1c", 'a');
	y += printf("%1c", '\0');
	y += printf("%10c", 'b');
	y += printf("%10c", '\0');
	y += printf("%2c", 'c');
	y += printf("%020c", 'c');
	y += printf("%0-20c", 'd');
	y += printf("there are 15 spaces between this text and the next char%15c", 'd');
	y += printf("%5chis paragraph is indented", 't');
	y += printf("%5c now you see", '\0');
	y += printf("The number %7c represents luck", '7');
	printf("\n");
	printf("x: %d, y:%d\n", x, y);

	x = 0;
	y = 0;
	printf("Testing with width and -\n");

	x += ft_printf("%-c", 'p');
	x += ft_printf("%-1c", 'b');
	x += ft_printf("%-5c", 'w');
	x += ft_printf(" kk daora%-5cblz", 'w');
	x += ft_printf("%-20carigatou", 'w');
	x += ft_printf("%-c%-c%-4c%-11c", 'a', 'b', 'c', 'd');
	x += ft_printf("%-ci%-cp%4cs%-11cx", 'a', 'b', 'c', 'd');
	x += ft_printf("%----ci%---cp%4cs%--11cx", 'a', 'b', 'c', 'd');
	x += ft_printf("%-c%-c%c*", 0, '1', 1);
	x += ft_printf("%-2c%-3c%-4c*", 0, 'a', 0);

	printf("\n");

	y += printf("%-c", 'p');
	y += printf("%-1c", 'b');
	y += printf("%-5c", 'w');
	y += printf(" kk daora%-5cblz", 'w');
	y += printf("%-20carigatou", 'w');
	y += printf("%-c%-c%-4c%-11c", 'a', 'b', 'c', 'd');
	y += printf("%-ci%-cp%4cs%-11cx", 'a', 'b', 'c', 'd');
	y += printf("%----ci%---cp%4cs%--11cx", 'a', 'b', 'c', 'd');
	y += printf("%-c%-c%c*", 0, '1', 1);
	y += printf("%-2c%-3c%-4c*", 0, 'a', 0);
	printf("\n");

	printf("x: %d, y:%d\n", x, y);
}

void test_percentage()
{
	int x, y;
	x = 0;
	y = 0;
	printf("Testing %%\n");
	x += ft_printf("%%");
	x += ft_printf("100%%");
	x += ft_printf("%%p is how you print a pointer in printf");
	x += ft_printf("the '%%%%' is used to print a %% in printf");
	x += ft_printf("%%%%%%%%%%%%%%%%");
	x += ft_printf("%%c%%s%%p%%d%%i%%u%%x%%X%%");
	printf("\n");

	y += printf("%%");
	y += printf("100%%");
	y += printf("%%p is how you print a pointer in printf");
	y += printf("the '%%%%' is used to print a %% in printf");
	y += printf("%%%%%%%%%%%%%%%%");
	y += printf("%%c%%s%%p%%d%%i%%u%%x%%X%%");
	printf("\n");

	printf("x: %d, y:%d\n", x, y);
	/*x += ft_printf("%c - %s - %p %d - %i - %u - %x %X %%", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000));
	x += ft_printf("%c - %s - %p %d - %i - %u - %x %X %%", '\0', "test", (void *)-1, 20, -20, -1, -1, 200000000));
	x += ft_printf("%c - %s - %p %d - %i - %u - %x %X %%", 'c', "", (void *)-1, 20, -20, -1, -1, 200000000));
	x += ft_printf("%i - %s - %p %d - %c - %u - %x %X %%", 20, "", (void *)-1, '\0', -20, -1, -1, 200000000));
	x += ft_printf("%c - %s - %p %d - %i - %u - %x %X %%", 'b', null_str, NULL, 20, -20, -1, -1, 200000000));
	x += ft_printf("%c %s - %p - %d - %i %u - %x - %X %%", '\0', null_str, (void *)0xdeadc0de, 0, (int)-2147483648, -1, -1, 200000000));*/
}

void test_demo()
{
	printf("%.1X\n", 0x1a);
	printf("%.4X\n", 11);
	printf("%.0X\n", 0);
	printf("%.1X\n", -1);
	printf("%.10X\n", -1);
	printf("%.14X\n", -1);
	printf("%.8X\n", 0);
	printf("%.1s\n", "us");

	unsigned long long x = 9206717838488594929;
	/*ft_printf("%%d: %d\n", (int) x);
	ft_printf("%%hd: %hd\n", (short)x);
	ft_printf("%%hhd: %hhd\n", (char) x);
	ft_printf("%%ld: %ld\n", (long)x);
	ft_printf("%%lld: %lld\n", (long long)x);*/
	/*printf("\n");
	printf("%%d: %+50.20d x\n", (int) x);*/

	printf("%%hd:% hd\n", (short)x);
	printf("%%hhd:%hhd\n", (char) x);
	printf("%%ld: %ld\n", (long)x);
	printf("%%lld: %5lld\n", (long long)x);
	printf("%5d\n", 3);
	printf("%.0s\n", "hello");
	printf("%.0d\n", 0);
	printf("%.5d\n", 3);  // use of precision filed
	printf("%05d\n", 3);  // use of 0 flag to prepend with 0
	printf("%.5d\n", -3);  // use of precision filed
	printf("%05d\n", -3);  // use of 0 flag to prepend with 0*/
	printf("abc%sxyz\n", "");
}

void test_string()
{
	int x = 0;
	int y = 0;
	char *null_str = NULL;

	printf("Testing string ***\n");
	printf("Testing Basics ***********\n");

	x += ft_printf("%s", "");
	x += ft_printf("this is a %s", "test");
	x += ft_printf("this is 1 %s with %s %s", "test", "multiple", "strings");
	x += ft_printf("%s%s%s%s", "This ", "is", " an ugly ", "test");
	x += ft_printf("%s", "This is a rather simple test.");
	x += ft_printf("%s", "-2");
	x += ft_printf("%s", "-24");
	x += ft_printf("%s", "-stop");
	x += ft_printf("%s", "-0003");
	x += ft_printf("%s", "000-0003");
	x += ft_printf("%s", "0x42");
	x += ft_printf("%s", "0x0000042");
	x += ft_printf("some naugty tests: %s", "0000%");
	x += ft_printf("some naugty tests: %s", "    %");
	x += ft_printf("some naugty tests: %s", "%000");
	x += ft_printf("%s", "bea thought but bea forgot the loop that the chars cause she was floaty during the amsterdam siren call. she got me by surprise you probably read my mind that look in your eyes and judging by your own cries you probably read my mind this is a really long string and if you see this you must look at your return values!kthxbai this must have more than 127 chars by now isnt it ok 4242 4 life 1337 code everyday to the moon!");
	x += ft_printf("%s", null_str);
	x += ft_printf("%s everywhere", null_str);
	x += ft_printf("everywhere %s", null_str);
	x += ft_printf("%s", "h");
	x += ft_printf("t%st%s", "a", "u");
	x += ft_printf("%s%s%s%s%s%s", "a", "i", "u", "e", "o", "l");

	printf("\n");
	printf("\n");

	y += printf("%s", "");
	y += printf("this is a %s", "test");
	y += printf("this is 1 %s with %s %s", "test", "multiple", "strings");
	y += printf("%s%s%s%s", "This ", "is", " an ugly ", "test");
	y += printf("%s", "This is a rather simple test.");
	y += printf("%s", "-2");
	y += printf("%s", "-24");
	y += printf("%s", "-stop");
	y += printf("%s", "-0003");
	y += printf("%s", "000-0003");
	y += printf("%s", "0x42");
	y += printf("%s", "0x0000042");
	y += printf("some naugty tests: %s", "0000%");
	y += printf("some naugty tests: %s", "    %");
	y += printf("some naugty tests: %s", "%000");
	y += printf("%s", "bea thought but bea forgot the loop that the chars cause she was floaty during the amsterdam siren call. she got me by surprise you probably read my mind that look in your eyes and judging by your own cries you probably read my mind this is a really long string and if you see this you must look at your return values!kthxbai this must have more than 127 chars by now isnt it ok 4242 4 life 1337 code everyday to the moon!");
	y += printf("%s", null_str);
	y += printf("%s everywhere", null_str);
	y += printf("everywhere %s", null_str);
	y += printf("%s", "h");
	y += printf("t%st%s", "a", "u");
	y += printf("%s%s%s%s%s%s", "a", "i", "u", "e", "o", "l");
	printf("\n");
	printf("x:%d, y: %d\n", x, y);

	x = y = 0;
	printf("String with width ***********\n");

	x += ft_printf("%1s", "a");
	x += ft_printf("%1s", "abc");
	x += ft_printf("%7s", "a");
	x += ft_printf("%7s", "abc");
	x += ft_printf("%1s", "-42");
	x += ft_printf("%2s", "-42");
	x += ft_printf("%3s", "-42");
	x += ft_printf("%4s", "-42");
	x += ft_printf("%5s", "-42");
	x += ft_printf("%6s", "-42");
	x += ft_printf("%1s", null_str);
	x += ft_printf("%2s", null_str);
	x += ft_printf("%5s", null_str);
	x += ft_printf("%6s", null_str);
	x += ft_printf("%7s", null_str);
	x += ft_printf("%7s is as easy as %13s", "abc", "123");
	x += ft_printf("%13s are the three first letter of the %3s", "a, b and c", "alphabet");
	x += ft_printf("%s%13s%42s%3s", "a, b and c", " are letters", " of the", " alphabet");
	x += ft_printf("%sc%13sd%42sp%3sx", "a, b and c", " are letters", " of the", " alphabet");
	x += ft_printf("%sc%13sd%42sp%3sx", "a, b and c", " are letters", " of the", " alphabet");


	printf("\n");
	printf("\n");

	y += printf("%1s", "a");
	y += printf("%1s", "abc");
	y += printf("%7s", "a");
	y += printf("%7s", "abc");
	y += printf("%1s", "-42");
	y += printf("%2s", "-42");
	y += printf("%3s", "-42");
	y += printf("%4s", "-42");
	y += printf("%5s", "-42");
	y += printf("%6s", "-42");
	y += printf("%1s", null_str);
	y += printf("%2s", null_str);
	y += printf("%5s", null_str);
	y += printf("%6s", null_str);
	y += printf("%7s", null_str);
	y += printf("%7s is as easy as %13s", "abc", "123");
	y += printf("%13s are the three first letter of the %3s", "a, b and c", "alphabet");
	y += printf("%s%13s%42s%3s", "a, b and c", " are letters", " of the", " alphabet");
	y += printf("%sc%13sd%42sp%3sx", "a, b and c", " are letters", " of the", " alphabet");
	y += printf("%sc%13sd%42sp%3sx", "a, b and c", " are letters", " of the", " alphabet");
	printf("\n");
	printf("x:%d, y: %d\n", x, y);

	x = y = 0;
	printf("String with precision ***********\n");
	x += ft_printf("%.s", "hi there");
	x += ft_printf("%.0s", "hi there");
	x += ft_printf("%.1s", "hi there");
	x += ft_printf("%.2s", "hi there");
	x += ft_printf("%.3s", "hi there");
	x += ft_printf("%.4s", "hi there");
	x += ft_printf("%.7s", "hi there");
	x += ft_printf("%.8s", "hi there");
	x += ft_printf("%.9s", "hi there");
	x += ft_printf("%.12s", "hi there");
	x += ft_printf("%.s", "-42");
	x += ft_printf("%.0s", "-42");
	x += ft_printf("%.1s", "-42");
	x += ft_printf("%.2s", "-42");
	x += ft_printf("%.3s", "-42");
	x += ft_printf("%.4s", "-42");
	x += ft_printf("%.7s", "-42");
	x += ft_printf("%.1s", null_str);
	x += ft_printf("%.2s", null_str);
	x += ft_printf("%.5s", null_str);
	x += ft_printf("%.6s", null_str);
	x += ft_printf("%.7s", null_str);
	x += ft_printf("%.2s, motherfucker", "hi there");
	x += ft_printf("This %.3s a triumph ", "wasabi");
	x += ft_printf("%.4s making a %.4s here: %.13s", "I'm delighted", "notation", "HUGE SUCCESS!");
	x += ft_printf("It's %.4s to over%.50s my%s", "hardware", "state", " satisfaction");
	x += ft_printf("%.11s%.6s%.4s", "Aperture", " Scientists", "ce");
	x += ft_printf("%1.s", "21-school.ru"); //Rustem (bnidia)
	x += ft_printf("%10.1s", "21-school.ru"); //Rustem (bnidia)

	printf("\n\n");
	y += printf("%0.s", "hi there");
	y += printf("%.0s", "hi there");
	y += printf("%.1s", "hi there");
	y += printf("%.2s", "hi there");
	y += printf("%.3s", "hi there");
	y += printf("%.4s", "hi there");
	y += printf("%.7s", "hi there");
	y += printf("%.8s", "hi there");
	y += printf("%.9s", "hi there");
	y += printf("%.12s", "hi there");
	y += printf("%.s", "-42");
	y += printf("%.0s", "-42");
	y += printf("%.1s", "-42");
	y += printf("%.2s", "-42");
	y += printf("%.3s", "-42");
	y += printf("%.4s", "-42");
	y += printf("%.7s", "-42");
	y += printf("%.1s", null_str);
	y += printf("%.2s", null_str);
	y += printf("%.5s", null_str);
	y += printf("%.6s", null_str);
	y += printf("%.7s", null_str);
	y += printf("%.2s, motherfucker", "hi there");
	y += printf("This %.3s a triumph ", "wasabi");
	y += printf("%.4s making a %.4s here: %.13s", "I'm delighted", "notation", "HUGE SUCCESS!");
	y += printf("It's %.4s to over%.50s my%s", "hardware", "state", " satisfaction");
	y += printf("%.11s%.6s%.4s", "Aperture", " Scientists", "ce");
	y += printf("%1.s", "21-school.ru"); //Rustem (bnidia)
	y += printf("%10.1s", "21-school.ru"); //Rustem (bnidia)

	printf("\n");
	printf("x:%d, y: %d\n", x, y);

	x = y = 0;
	printf("String with widths, precisions and - ***********\n");

	x += ft_printf("%-9sScience!", "Aperture");
	x += ft_printf("We %-s what we %8s, %-2s we %-20s", "do", "must", "because", "can");
	x += ft_printf("%--4s %s %------------------9s of %s of %-5s", "for", "the", "goooood", "aaall", "us");
	x += ft_printf("%--4.1s %s %------------------9.3s of %s of %-5.7s", "for", "the", "goooood", "aaall", "us");
	x += ft_printf("%--.sp--.su kkkk", "pegadinha po");
	x += ft_printf("%-9sScience!", "-42");

	printf("\n\n");

	y += printf("%-9sScience!", "Aperture");
	y += printf("We %-s what we %8s, %-2s we %-20s", "do", "must", "because", "can");
	y += printf("%--4s %s %------------------9s of %s of %-5s", "for", "the", "goooood", "aaall", "us");
	y += printf("%--4.1s %s %------------------9.3s of %s of %-5.7s", "for", "the", "goooood", "aaall", "us");
	y += printf("%--.sp--.su kkkk", "pegadinha po");
	y += printf("%-9sScience!", "-42");

	printf("\n");
	printf("x:%d, y: %d\n", x, y);

}
void test_pointer()
{
	int x, y;
	int test = 42;
	char *mallocked = malloc(2);
	int *ptr = &test;

	printf("Testing pointer ***\n");
	printf("Testing Basics ***********\n");
	x = y = 0;
	x += ft_printf("%p", &test);
	x += ft_printf("%p is a virtual memory address", &test);
	x += ft_printf("The address of the answer is %p", &test);
	x += ft_printf("The address is %p, so what?", &test);
	x += ft_printf("A pointer at %p points to %p", &test, &ptr);
	x += ft_printf("This %p is a very strange address", (void *)(long int)test);
	x += ft_printf("This %p is an address from the heap", mallocked);
	x += ft_printf("%-20p", NULL);
	x += ft_printf("The NULL macro represents the %p address", NULL);
	x += ft_printf("This %p is even stranger", (void *)-1);
	x += ft_printf("abc%-20pxyz\n", NULL);
    x += ft_printf("abc%20pxyz\n", NULL);
    x += ft_printf("abc%.20pxyz\n", NULL);

	printf("\n\n");
	y += printf("%p", &test);
	y += printf("%p is a virtual memory address", &test);
	y += printf("The address of the answer is %p", &test);
	y += printf("The address is %p, so what?", &test);
	y += printf("A pointer at %p points to %p", &test, &ptr);
	y += printf("This %p is a very strange address", (void *)(long int)test);
	y += printf("This %p is an address from the heap", mallocked);
	y += printf("%-20p", NULL);
	y += printf("The NULL macro represents the %p address", NULL);
	y += printf("This %p is even stranger", (void *)-1);
	y += printf("abc%-20pxyz\n", NULL);
    y += printf("abc%20pxyz\n", NULL);
    y += printf("abc%.20pxyz\n", NULL);

	printf("\n");
	free(mallocked);

	printf("x: %d, y:%d\n", x, y);


	x = y = 0;
	printf("pointer with width ***********\n");

	char c;
	x += ft_printf("%1p", &c);
	x += ft_printf("%30p", &c);
	x += ft_printf("%12p", (void *)0x7ffe6b8e60c6);
	x += ft_printf("%13p", (void *)0x7ffe6b8e60c5);
	x += ft_printf("%14p", (void *)0x7ffe6b8e60c4);
	x += ft_printf("the address is %12p", (void *)0x7ffe6b8e60c7);
	x += ft_printf("the address is %13p", (void *)0x7ffe6b8e60c8);
	x += ft_printf("the address is %14p", (void *)0x7ffe6b8e60c9);
	x += ft_printf("the address is %1p", (void *)0);
	x += ft_printf("the address is %2p", (void *)0);
	x += ft_printf("the address is %3p", (void *)0);
	x += ft_printf("the address is %4p", (void *)0);
	x += ft_printf("the address is %8p", (void *)0);
	x += ft_printf("%12p is the address", (void *)0x7ffe6b8e60c7);
	x += ft_printf("%13p is the address", (void *)0x7ffe6b8e60c8);
	x += ft_printf("%14p is the address", (void *)0x7ffe6b8e60c9);
	x += ft_printf("%1p is the address", (void *)0);
	x += ft_printf("%2p is the address", (void *)0);
	x += ft_printf("%3p is the address", (void *)0);
	x += ft_printf("%4p is the address", (void *)0);
	x += ft_printf("%8p is the address", (void *)0);

	printf("\n\n");

	y += printf("%1p", &c);
	y += printf("%30p", &c);
	y += printf("%12p", (void *)0x7ffe6b8e60c6);
	y += printf("%13p", (void *)0x7ffe6b8e60c5);
	y += printf("%14p", (void *)0x7ffe6b8e60c4);
	y += printf("the address is %12p", (void *)0x7ffe6b8e60c7);
	y += printf("the address is %13p", (void *)0x7ffe6b8e60c8);
	y += printf("the address is %14p", (void *)0x7ffe6b8e60c9);
	y += printf("the address is %1p", (void *)0);
	y += printf("the address is %2p", (void *)0);
	y += printf("the address is %3p", (void *)0);
	y += printf("the address is %4p", (void *)0);
	y += printf("the address is %8p", (void *)0);
	y += printf("%12p is the address", (void *)0x7ffe6b8e60c7);
	y += printf("%13p is the address", (void *)0x7ffe6b8e60c8);
	y += printf("%14p is the address", (void *)0x7ffe6b8e60c9);
	y += printf("%1p is the address", (void *)0);
	y += printf("%2p is the address", (void *)0);
	y += printf("%3p is the address", (void *)0);
	y += printf("%4p is the address", (void *)0);
	y += printf("%8p is the address", (void *)0);

	printf("\n");
	printf("x:%d, y: %d\n", x, y);


	x = y = 0;
	printf("pointer with width and - ***********\n");

	x += ft_printf("that's the way it %-20pis", "");
	x += ft_printf("as soon as %-10possible", (void *) -1);
	x += ft_printf("as soon as %-16peasible", (void *) (((long int)3 << 42) + 15));
	x += ft_printf("as soon as %-16peasible", (void *) (((long int)3 << 42) + 15));
	x += ft_printf("thats %-psrobably not a good idea", (void *) 13);
	x += ft_printf("%------21pwhoa wtf is that", (void *) 13);
	x += ft_printf("%------21p yeah i'm %p running out %--p of ideas", (void *) 13, (void *) 65, (void *) -1);

	printf("\n\n");

	y += printf("that's the way it %-20pis", "");
	y += printf("as soon as %-10possible", (void *) -1);
	y += printf("as soon as %-16peasible", (void *) (((long int)3 << 42) + 15));
	y += printf("as soon as %-16peasible", (void *) (((long int)3 << 42) + 15));
	y += printf("thats %-psrobably not a good idea", (void *) 13);
	y += printf("%------21pwhoa wtf is that", (void *) 13);
	y += printf("%------21p yeah i'm %p running out %--p of ideas", (void *) 13, (void *) 65, (void *) -1);


	//x += ft_
	//));
	printf("\n");
	printf("x:%d, y: %d\n", x, y);
}

void test_int()
{
	int x = 0;
	int y = 0;

	printf("Testing int ***\n");
	printf("Testing Basics ***********\n");

	x += ft_printf("%d", 0);
	x += ft_printf("%d", 10);
	x += ft_printf("%d, %d", 10, 20);
	x += ft_printf("%d%d%d%d", 10, 20, 30, 5);
	x += ft_printf("%d %d", 2147483647, (int)-2147483648);
	x += ft_printf("42 - 84 is %d", -42);
	x += ft_printf("%d C is the lowest temperature in the universe", -273);
	x += ft_printf("%dxC is the lowest temperature in the universe", -273);
	x += ft_printf("%dsC is the lowest temperature in the universe", -273);
	x += ft_printf("%dpC is the lowest temperature in the universe", -273);

	printf("\n\n");

	y += printf("%d", 0);
	y += printf("%d", 10);
	y += printf("%d, %d", 10, 20);
	y += printf("%d%d%d%d", 10, 20, 30, 5);
	y += printf("%d %d", 2147483647, (int)-2147483648);
	y += printf("42 - 84 is %d", -42);
	y += printf("%d C is the lowest temperature in the universe", -273);
	y += printf("%dxC is the lowest temperature in the universe", -273);
	y += printf("%dsC is the lowest temperature in the universe", -273);
	y += printf("%dpC is the lowest temperature in the universe", -273);

	printf("\n");
	printf("x:%d, y: %d\n", x, y);

	x = y = 0;
	printf("int with width ***********\n");

	x += ft_printf("%1d", 0);
	x += ft_printf("%1d", -4);
	x += ft_printf("%10d", 42);
	x += ft_printf("%42d", 42000);
	x += ft_printf("%20d", -42000);
	x += ft_printf("wait for it... %50d", 42);
	x += ft_printf("%20d is how many tests are going to be made", 8000);
	x += ft_printf("%5d", 2147483647);
	x += ft_printf("%30d", 2147483647);
	x += ft_printf("%10d", 2147483647);
	x += ft_printf("%5d", (int)-2147483648);
	x += ft_printf("%30d", (int)-2147483648);
	x += ft_printf("%10d", (int)-2147483648);
	x += ft_printf("%11d", (int)-2147483648);
	x += ft_printf("%12d", (int)-2147483648);
	x += ft_printf("%12d, %20d, %2d, %42d", (int)-2147483648, 3, 30, -1);
	x += ft_printf("%12d, %d, %2d, %42d", (int)-2147483648, 3, 30, -1);
	x += ft_printf("%14d%20d%2d%d", (int)-2147483648, 3, 30, -1);
	x += ft_printf("%14dc%20ds%2dx%du", (int)-2147483648, 3, 30, -1);

	printf("\n\n");

	y += printf("%1d", 0);
	y += printf("%1d", -4);
	y += printf("%10d", 42);
	y += printf("%42d", 42000);
	y += printf("%20d", -42000);
	y += printf("wait for it... %50d", 42);
	y += printf("%20d is how many tests are going to be made", 8000);
	y += printf("%5d", 2147483647);
	y += printf("%30d", 2147483647);
	y += printf("%10d", 2147483647);
	y += printf("%5d", (int)-2147483648);
	y += printf("%30d", (int)-2147483648);
	y += printf("%10d", (int)-2147483648);
	y += printf("%11d", (int)-2147483648);
	y += printf("%12d", (int)-2147483648);
	y += printf("%12d, %20d, %2d, %42d", (int)-2147483648, 3, 30, -1);
	y += printf("%12d, %d, %2d, %42d", (int)-2147483648, 3, 30, -1);
	y += printf("%14d%20d%2d%d", (int)-2147483648, 3, 30, -1);
	y += printf("%14dc%20ds%2dx%du", (int)-2147483648, 3, 30, -1);
	printf("\n");
	printf("x:%d, y: %d\n", x, y);

	x = y = 0;
	printf("int with precisions ***********\n");

	x += ft_printf("%.1d", 2);
	x += ft_printf("%.2d", 3);
	x += ft_printf("%.4d", 32);
	x += ft_printf("%.3d", 420000);
	x += ft_printf("%.0d", 420000);
	x += ft_printf("%.3d", -1);
	x += ft_printf("%.3d", -1234);
	x += ft_printf("%.4d", -1234);
	x += ft_printf("%.5d", -1234);
	x += ft_printf("%.5d", (int)-2147483648);
	x += ft_printf("%.9d", (int)-2147483648);
	x += ft_printf("%.10d", (int)-2147483648);
	x += ft_printf("%.11d", (int)-2147483648);
	x += ft_printf("%.12d", (int)-2147483648);
	x += ft_printf("%.13d", (int)-2147483648);
	x += ft_printf("%.5d", 2147483647);
	x += ft_printf("%.9d", 2147483647);
	x += ft_printf("%.10d", 2147483647);
	x += ft_printf("%.11d", 2147483647);
	x += ft_printf("%.12d", 2147483647);
	x += ft_printf("%.0d", 2);
	x += ft_printf("%.0d", 2147483647);
	x += ft_printf("%.0d", 0);
	x += ft_printf("%.0d", 10);
	x += ft_printf("%.d", 10);
	x += ft_printf("%.d", 0);
	x += ft_printf("I'm gonna watch %.3d", 7);
	x += ft_printf("%.3d is the movie I'm gonna watch", 7);
	x += ft_printf("Then take these %.7d things and get the hell out of here", 2);
	x += ft_printf("Bla %.2di bla %.5dsbla bla %.dx bla %.d", 127, 42, 1023, 0);
	x += ft_printf("%.4d%.2d%.20d%.0d%.0d%.d%.d%.d", 127, 0, 1023, 0, (int)-2147483648, 0, 1, (int)-2147483648);

	printf("\n\n");

	y += printf("%.1d", 2);
	y += printf("%.2d", 3);
	y += printf("%.4d", 32);
	y += printf("%.3d", 420000);
	y += printf("%.0d", 420000);
	y += printf("%.3d", -1);
	y += printf("%.3d", -1234);
	y += printf("%.4d", -1234);
	y += printf("%.5d", -1234);
	y += printf("%.5d", (int)-2147483648);
	y += printf("%.9d", (int)-2147483648);
	y += printf("%.10d", (int)-2147483648);
	y += printf("%.11d", (int)-2147483648);
	y += printf("%.12d", (int)-2147483648);
	y += printf("%.13d", (int)-2147483648);
	y += printf("%.5d", 2147483647);
	y += printf("%.9d", 2147483647);
	y += printf("%.10d", 2147483647);
	y += printf("%.11d", 2147483647);
	y += printf("%.12d", 2147483647);
	y += printf("%.0d", 2);
	y += printf("%.0d", 2147483647);
	y += printf("%.0d", 0);
	y += printf("%.0d", 10);
	y += printf("%.d", 10);
	y += printf("%.d", 0);
	y += printf("I'm gonna watch %.3d", 7);
	y += printf("%.3d is the movie I'm gonna watch", 7);
	y += printf("Then take these %.7d things and get the hell out of here", 2);
	y += printf("Bla %.2di bla %.5dsbla bla %.dx bla %.d", 127, 42, 1023, 0);
	y += printf("%.4d%.2d%.20d%.0d%.0d%.d%.d%.d", 127, 0, 1023, 0, (int)-2147483648, 0, 1, (int)-2147483648);

	printf("\n");
	printf("x:%d, y: %d\n", x, y);

	x = y = 0;
	printf("int with widths, precisions and - ***********\n");
	x += ft_printf("%-d", 0);
	x += ft_printf("%-d", 1);
	x += ft_printf("%-d", 10);
	x += ft_printf("%-d", -10);
	x += ft_printf("%-d", 5000);
	x += ft_printf("%-d", -5000);
	x += ft_printf("%-d", (int)-2147483648);
	x += ft_printf("%-d", 2147483647);
	x += ft_printf("%-1d", 0);
	x += ft_printf("%-1d", 1);
	x += ft_printf("%-1d", 10);
	x += ft_printf("%-1d", -10);
	x += ft_printf("%-1d", 5000);
	x += ft_printf("%-1d", -5000);
	x += ft_printf("%-1d", (int)-2147483648);
	x += ft_printf("%-1d", 2147483647);
	x += ft_printf("%-10d", 0);
	x += ft_printf("%-10d", 1);
	x += ft_printf("%-10d", 10);
	x += ft_printf("%-10d", -10);
	x += ft_printf("%-10d", 5000);
	x += ft_printf("%-10d", -5000);
	x += ft_printf("%-10d", (int)-2147483648);
	x += ft_printf("%-10d", 2147483647);
	x += ft_printf("%-.d", 0);
	x += ft_printf("%-.1d", 1);
	x += ft_printf("%-.2d", 10);
	x += ft_printf("%-.3d", -10);
	x += ft_printf("%-.4d", 5000);
	x += ft_printf("%-.5d", -5000);
	x += ft_printf("%-.6d", (int)-2147483648);
	x += ft_printf("%-.7d", 2147483647);
	x += ft_printf("%-1.8d", 0);
	x += ft_printf("%-1.9d", 1);
	x += ft_printf("%-1.10d", 10);
	x += ft_printf("%-1.0d", -10);
	x += ft_printf("%-1.6d", 5000);
	x += ft_printf("%-1.4d", -5000);
	x += ft_printf("%-1.10d", (int)-2147483648);
	x += ft_printf("%-1.12d", 2147483647);
	x += ft_printf("%-10.d", 0);
	x += ft_printf("%-10.10d", 1);
	x += ft_printf("%-10.5d", 10);
	x += ft_printf("%-10.2d", -10);
	x += ft_printf("%-10.5d", 5000);
	x += ft_printf("%-10.5d", -5000);
	x += ft_printf("%-10.15d", (int)-2147483648);
	x += ft_printf("%-10.5d", 2147483647);
	x += ft_printf("%-15.d", 0);
	x += ft_printf("%-15.10d", 1);
	x += ft_printf("%-15.5d", 10);
	x += ft_printf("%-15.2d", -10);
	x += ft_printf("%-15.5d", 5000);
	x += ft_printf("%-15.5d", -5000);
	x += ft_printf("%-15.15d", (int)-2147483648);
	x += ft_printf("%-15.5d", 2147483647);
	x += ft_printf("%-4.5d%d%4d%-10d-d5%-.3d", 3, 4, 5, 6, 7);
	x += ft_printf("%-4.5d%d%4d%-10d-d5%-.3d", 300000, 400000, 500000, 600000, 700000);
	x += ft_printf("%-4.5d%d%4d%-10d-d5%-.3d", -300000, -400000, -500000, -600000, -700000);
	x += ft_printf("%-4.5d%d%4d%-10d-d5%-.3d", 2147483647, 2141483647, 2141483647, 2141483647, 2141483647);
	x += ft_printf("%-4.5d%d%4d%-10d-d5%-.3d", (int)-2147483648, (int)-2141483648, (int)-2141483648, (int)-2141483648, (int)-2141483648);

	printf("\n\n");

	y += printf("%-d", 0);
	y += printf("%-d", 1);
	y += printf("%-d", 10);
	y += printf("%-d", -10);
	y += printf("%-d", 5000);
	y += printf("%-d", -5000);
	y += printf("%-d", (int)-2147483648);
	y += printf("%-d", 2147483647);
	y += printf("%-1d", 0);
	y += printf("%-1d", 1);
	y += printf("%-1d", 10);
	y += printf("%-1d", -10);
	y += printf("%-1d", 5000);
	y += printf("%-1d", -5000);
	y += printf("%-1d", (int)-2147483648);
	y += printf("%-1d", 2147483647);
	y += printf("%-10d", 0);
	y += printf("%-10d", 1);
	y += printf("%-10d", 10);
	y += printf("%-10d", -10);
	y += printf("%-10d", 5000);
	y += printf("%-10d", -5000);
	y += printf("%-10d", (int)-2147483648);
	y += printf("%-10d", 2147483647);
	y += printf("%-.d", 0);
	y += printf("%-.1d", 1);
	y += printf("%-.2d", 10);
	y += printf("%-.3d", -10);
	y += printf("%-.4d", 5000);
	y += printf("%-.5d", -5000);
	y += printf("%-.6d", (int)-2147483648);
	y += printf("%-.7d", 2147483647);
	y += printf("%-1.8d", 0);
	y += printf("%-1.9d", 1);
	y += printf("%-1.10d", 10);
	y += printf("%-1.0d", -10);
	y += printf("%-1.6d", 5000);
	y += printf("%-1.4d", -5000);
	y += printf("%-1.10d", (int)-2147483648);
	y += printf("%-1.12d", 2147483647);
	y += printf("%-10.d", 0);
	y += printf("%-10.10d", 1);
	y += printf("%-10.5d", 10);
	y += printf("%-10.2d", -10);
	y += printf("%-10.5d", 5000);
	y += printf("%-10.5d", -5000);
	y += printf("%-10.15d", (int)-2147483648);
	y += printf("%-10.5d", 2147483647);
	y += printf("%-15.d", 0);
	y += printf("%-15.10d", 1);
	y += printf("%-15.5d", 10);
	y += printf("%-15.2d", -10);
	y += printf("%-15.5d", 5000);
	y += printf("%-15.5d", -5000);
	y += printf("%-15.15d", (int)-2147483648);
	y += printf("%-15.5d", 2147483647);
	y += printf("%-4.5d%d%4d%-10d-d5%-.3d", 3, 4, 5, 6, 7);
	y += printf("%-4.5d%d%4d%-10d-d5%-.3d", 300000, 400000, 500000, 600000, 700000);
	y += printf("%-4.5d%d%4d%-10d-d5%-.3d", -300000, -400000, -500000, -600000, -700000);
	y += printf("%-4.5d%d%4d%-10d-d5%-.3d", 2147483647, 2141483647, 2141483647, 2141483647, 2141483647);
	y += printf("%-4.5d%d%4d%-10d-d5%-.3d", (int)-2147483648, (int)-2141483648, (int)-2141483648, (int)-2141483648, (int)-2141483648);

	printf("\n");
	printf("x:%d, y: %d\n", x, y);

	x = y = 0;

	printf("int with widths, precisions and 0 ***********\n");
	x += ft_printf("%01d", 0);
	x += ft_printf("%01d", -4);
	x += ft_printf("%010d", 42);
	x += ft_printf("%042d", 42000);
	x += ft_printf("%020d", -42000);
	x += ft_printf("wait for it... %050d", 42);
	x += ft_printf("%020d is how many tests are going to be made", 8000);
	x += ft_printf("%05d", 2147483647);
	x += ft_printf("%030d", 2147483647);
	x += ft_printf("%010d", 2147483647);
	x += ft_printf("%05d", (int)-2147483648);
	x += ft_printf("%030d", (int)-2147483648);
	x += ft_printf("%010d", (int)-2147483648);
	x += ft_printf("%011d", (int)-2147483648);
	x += ft_printf("%012d", (int)-2147483648);
	x += ft_printf("%012d, %20d, %2d, %42d", (int)-2147483648, 3, 30, -1);
	x += ft_printf("%012d, %d, %2d, %42d", (int)-2147483648, 3, 30, -1);
	x += ft_printf("%014d%020d%02d%0d", (int)-2147483648, 3, 30, -1);
	x += ft_printf("%014dc%020ds%02dx%0du", (int)-2147483648, 3, 30, -1);
	x += ft_printf("%01.d", 0);
	x += ft_printf("%01.0d", 1);
	x += ft_printf("%02.0d", 0);
	x += ft_printf("%03.0d", 0);
	x += ft_printf("%01.1d", 0);
	x += ft_printf("%01.2d", 0);
	x += ft_printf("%01.3d", 0);
	x += ft_printf("%01.0d", -4);
	x += ft_printf("%01.1d", -4);
	x += ft_printf("%01.2d", -4);
	x += ft_printf("%01.3d", -4);
	x += ft_printf("%01.0d", 4);
	x += ft_printf("%01.1d", 4);
	x += ft_printf("%01.2d", 4);
	x += ft_printf("%01.3d", 4);
	x += ft_printf("%010.20d", 42);
	x += ft_printf("%042.2d", 42000);
	x += ft_printf("%042.20d", 42000);
	x += ft_printf("%042.42d", 42000);
	x += ft_printf("%042.52d", 42000);
	x += ft_printf("%020.10d", -42000);
	x += ft_printf("%020.20d", -42000);
	x += ft_printf("%020.30d", -42000);
	x += ft_printf("wait for it... %050.50d", 42);
	x += ft_printf("%020.19d is how many tests are going to be made", 8000);
	x += ft_printf("%020.20d is how many tests are going to be made", 8000);
	x += ft_printf("%020.21d is how many tests are going to be made", 8000);
	x += ft_printf("%05d", 2147483647);
	x += ft_printf("%030d", 2147483647);
	x += ft_printf("%09d", 2147483647);
	x += ft_printf("%010d", 2147483647);
	x += ft_printf("%011d", 2147483647);
	x += ft_printf("%05d", (int)-2147483648);
	x += ft_printf("%030d", (int)-2147483648);
	x += ft_printf("%010d", (int)-2147483648);
	x += ft_printf("%011d", (int)-2147483648);
	x += ft_printf("%012d", (int)-2147483648);
	x += ft_printf("%012d, %20d, %2d, %000042d", (int)-2147483648, 3, 30, -1);
	x += ft_printf("%012d, %d, %002d, %42d", (int)-2147483648, 3, 30, -1);
	x += ft_printf("%0014.2d%020d%0002.d%000.5d", (int)-2147483648, 3, 30, -1);
	x += ft_printf("%014dc%020ds%02dx%0du", (int)-2147483648, 3, 30, -1);

	printf("\n\n");

	y += printf("%01d", 0);
	y += printf("%01d", -4);
	y += printf("%010d", 42);
	y += printf("%042d", 42000);
	y += printf("%020d", -42000);
	y += printf("wait for it... %050d", 42);
	y += printf("%020d is how many tests are going to be made", 8000);
	y += printf("%05d", 2147483647);
	y += printf("%030d", 2147483647);
	y += printf("%010d", 2147483647);
	y += printf("%05d", (int)-2147483648);
	y += printf("%030d", (int)-2147483648);
	y += printf("%010d", (int)-2147483648);
	y += printf("%011d", (int)-2147483648);
	y += printf("%012d", (int)-2147483648);
	y += printf("%012d, %20d, %2d, %42d", (int)-2147483648, 3, 30, -1);
	y += printf("%012d, %d, %2d, %42d", (int)-2147483648, 3, 30, -1);
	y += printf("%014d%020d%02d%0d", (int)-2147483648, 3, 30, -1);
	y += printf("%014dc%020ds%02dx%0du", (int)-2147483648, 3, 30, -1);
	y += printf("%01.d", 0);

	y += printf("%01.0d", 1);
	y += printf("%02.0d", 0);
	y += printf("%03.0d", 0);
	y += printf("%01.1d", 0);
	y += printf("%01.2d", 0);
	y += printf("%01.3d", 0);
	y += printf("%01.0d", -4);
	y += printf("%01.1d", -4);
	y += printf("%01.2d", -4);
	y += printf("%01.3d", -4);
	y += printf("%01.0d", 4);
	y += printf("%01.1d", 4);
	y += printf("%01.2d", 4);
	y += printf("%01.3d", 4);
	y += printf("%010.20d", 42);
	y += printf("%042.2d", 42000);
	y += printf("%042.20d", 42000);
	y += printf("%042.42d", 42000);
	y += printf("%042.52d", 42000);
	y += printf("%020.10d", -42000);
	y += printf("%020.20d", -42000);
	y += printf("%020.30d", -42000);
	y += printf("wait for it... %050.50d", 42);
	y += printf("%020.19d is how many tests are going to be made", 8000);
	y += printf("%020.20d is how many tests are going to be made", 8000);
	y += printf("%020.21d is how many tests are going to be made", 8000);
	y += printf("%05d", 2147483647);
	y += printf("%030d", 2147483647);
	y += printf("%09d", 2147483647);
	y += printf("%010d", 2147483647);
	y += printf("%011d", 2147483647);
	y += printf("%05d", (int)-2147483648);
	y += printf("%030d", (int)-2147483648);
	y += printf("%010d", (int)-2147483648);
	y += printf("%011d", (int)-2147483648);
	y += printf("%012d", (int)-2147483648);
	y += printf("%012d, %20d, %2d, %000042d", (int)-2147483648, 3, 30, -1);
	y += printf("%012d, %d, %002d, %42d", (int)-2147483648, 3, 30, -1);
	y += printf("%0014.2d%020d%0002.d%000.5d", (int)-2147483648, 3, 30, -1);
	y += printf("%014dc%020ds%02dx%0du", (int)-2147483648, 3, 30, -1);

	printf("\n");
	printf("x:%d, y: %d\n", x, y);

	x = y = 0;
	printf("int with and ' ' ***********\n");
	x += ft_printf("% d", 0);
	x += ft_printf("% d", 1);
	x += ft_printf("% d", -1);
	x += ft_printf("%    d", 0);
	x += ft_printf("%   d", 1);
	x += ft_printf("%  d", -1);
	x += ft_printf("% d", 2147483647);
	x += ft_printf("% d", (int)-2147483648);
	x += ft_printf("%   d", 2147483647);
	x += ft_printf("%  d", (int)-2147483648);
	x += ft_printf("% d", 2178647);
	x += ft_printf("% d", (int)-2144348);
	x += ft_printf("%   d", 2147837);
	x += ft_printf("%  d", (int)-2147486);
	x += ft_printf("%  d this is %d getting% di hard :/", (int)-2147486, -2, 42);

	printf("\n\n");
	y += printf("% d", 0);
	y += printf("% d", 1);
	y += printf("% d", -1);
	y += printf("%    d", 0);
	y += printf("%   d", 1);
	y += printf("%  d", -1);
	y += printf("% d", 2147483647);
	y += printf("% d", (int)-2147483648);
	y += printf("%   d", 2147483647);
	y += printf("%  d", (int)-2147483648);
	y += printf("% d", 2178647);
	y += printf("% d", (int)-2144348);
	y += printf("%   d", 2147837);
	y += printf("%  d", (int)-2147486);
	y += printf("%  d this is %d getting% di hard :/", (int)-2147486, -2, 42);
	printf("\n");
	printf("x:%d, y: %d\n", x, y);

	x = y = 0;
	printf("int with and '+' ***********\n");

	x += ft_printf("%+d", 0);
	x += ft_printf("%+d", 1);
	x += ft_printf("%+d", -1);
	x += ft_printf("%+d", 24);
	x += ft_printf("%+d", 42);
	x += ft_printf("%+d", -42);
	x += ft_printf("%+d", 2147483647);
	x += ft_printf("%+d", (int)-2147483648);
	x += ft_printf("%+++d", 2147483647);
	x += ft_printf("%++d", (int)-2147483648);
	x += ft_printf("%+d", 2178647);
	x += ft_printf("%+d", (int)-2144348);
	x += ft_printf("%+++d", 2147837);
	x += ft_printf("%++d", (int)-2147486);
	x += ft_printf("%++d this is %d getting%+di hard :/", (int)-2147486, -2, 42);

	printf("\n\n");
	y += printf("%+d", 0);
	y += printf("%+d", 1);
	y += printf("%+d", -1);
	y += printf("%+d", 24);
	y += printf("%+d", 42);
	y += printf("%+d", -42);
	y += printf("%+d", 2147483647);
	y += printf("%+d", (int)-2147483648);
	y += printf("%+++d", 2147483647);
	y += printf("%++d", (int)-2147483648);
	y += printf("%+d", 2178647);
	y += printf("%+d", (int)-2144348);
	y += printf("%+++d", 2147837);
	y += printf("%++d", (int)-2147486);
	y += printf("%++d this is %d getting%+di hard :/", (int)-2147486, -2, 42);
	printf("\n");
	printf("x:%d, y: %d\n", x, y);

	x = y = 0;
	printf("int with and '+' ***********\n");

	ft_printf("out:%020dEnd\n", -42000);
    ft_printf("out:%0.20dEnd\n", 42000);
    ft_printf("out:%0+20dEnd\n", 42000);
    ft_printf("out:%-+20dEnd\n", 42000);
    ft_printf("out:%-20dEnd\n", 42000);
    ft_printf("out:%+20dEnd\n", 42000);
    ft_printf("out:% 020dEnd\n", 42000);

	printf("\n\n");
	printf("out:%020dEnd\n", -42000);
    printf("out:%0.20dEnd\n", 42000);
    printf("out:%0+20dEnd\n", 42000);
    printf("out:%-+20dEnd\n", 42000);
    printf("out:%-20dEnd\n", 42000);
     printf("out:%+20dEnd\n", 42000);
    printf("out:% 020dEnd\n", 42000);
}
void test_uint()
{
	int x, y;
	x = 0;
	y = 0;
	printf("Testing uint ***\n");
	printf("Testing Basics\n");

	x += ft_printf("%u", 42);
	x += ft_printf("%u", 0);
	x += ft_printf("%u", 2147483647);
	x += ft_printf("%u", (unsigned int)2147483648);
	x += ft_printf("%u", (unsigned int)3147983649);
	x += ft_printf("%u", (unsigned int)4294967295);
	x += ft_printf("%u to the power of %u is %u", 2, 32, (unsigned int)4294967295);
	x += ft_printf("%u%u%u%u", (unsigned int)429896724, 0, 32, (unsigned int)4294967295);
	printf("\n\n");

	y += printf("%u", 42);
	y += printf("%u", 0);
	y += printf("%u", 2147483647);
	y += printf("%u", (unsigned int)2147483648);
	y += printf("%u", (unsigned int)3147983649);
	y += printf("%u", (unsigned int)4294967295);
	y += printf("%u to the power of %u is %u", 2, 32, (unsigned int)4294967295);
	y += printf("%u%u%u%u", (unsigned int)429896724, 0, 32, (unsigned int)4294967295);

	printf("\n");
	printf("x: %d, y:%d\n", x, y);

	x = y = 0;

	printf("Testing with width and -\n");

	x += ft_printf("%1u", 0);
	x += ft_printf("%2u", 1);
	x += ft_printf("%1u", 1000);
	x += ft_printf("%4u", 1000);
	x += ft_printf("%30u", 1000);
	x += ft_printf("%9u is the biggest unsigned int", (unsigned int)-1);
	x += ft_printf("%10uis the biggest unsigned int", (unsigned int)-1);
	x += ft_printf("%11uis the biggest unsigned int", (unsigned int)-1);
	x += ft_printf("the biggest unsigned int is %9u", (unsigned int)-1);
	x += ft_printf("the biggest unsigned int is %10u", (unsigned int)-1);
	x += ft_printf("the biggest unsigned int is %11u", (unsigned int)-1);
	x += ft_printf("Here are some numbers: %1u%2u%5u%3u%9u and %ui", 11, (unsigned int)-1, 2, 200, 3, 10);

	printf("\n\n");

	y += printf("%1u", 0);
	y += printf("%2u", 1);
	y += printf("%1u", 1000);
	y += printf("%4u", 1000);
	y += printf("%30u", 1000);
	y += printf("%9u is the biggest unsigned int", (unsigned int)-1);
	y += printf("%10uis the biggest unsigned int", (unsigned int)-1);
	y += printf("%11uis the biggest unsigned int", (unsigned int)-1);
	y += printf("the biggest unsigned int is %9u", (unsigned int)-1);
	y += printf("the biggest unsigned int is %10u", (unsigned int)-1);
	y += printf("the biggest unsigned int is %11u", (unsigned int)-1);
	y += printf("Here are some numbers: %1u%2u%5u%3u%9u and %ui", 11, (unsigned int)-1, 2, 200, 3, 10);


	printf("\n");
	printf("x: %d, y:%d\n", x, y);

	x = y = 0;

	printf("Testing with precision\n");
	x += ft_printf("%.1u", 1);
	x += ft_printf("%.2u", 1);
	x += ft_printf("%.2u", 0);
	x += ft_printf("%.0u", 0);
	x += ft_printf("%.u", 0);
	x += ft_printf("%.2u", 30000);
	x += ft_printf("%.20u", 30000);
	x += ft_printf("%.0u", (unsigned int)-1);
	x += ft_printf("%.5u", (unsigned int)-1);
	x += ft_printf("%.9u", (unsigned int)-1);
	x += ft_printf("%.10u", (unsigned int)-1);
	x += ft_printf("%.11u", (unsigned int)-1);
	x += ft_printf("%.10uis a big number", (unsigned int)-1);
	x += ft_printf("%.0uis a big number", (unsigned int)-1);
	x += ft_printf("%.4us a big number", (unsigned int)-1);
	x += ft_printf("%.9uxs a big number", (unsigned int)-1);
	x += ft_printf("%.11ups a big number", (unsigned int)-1);
	x += ft_printf("the number is %.0u", (unsigned int)-1);
	x += ft_printf("the number is %.u", (unsigned int)-1);
	x += ft_printf("the number is %.5u", (unsigned int)-1);
	x += ft_printf("the number is %.9u", (unsigned int)-1);
	x += ft_printf("the number is %.10u", (unsigned int)-1);
	x += ft_printf("the number is %.11u", (unsigned int)-1);
	x += ft_printf("the number is %.11u", (unsigned int)-1);
	x += ft_printf("%.0uis a big number", 0);
	x += ft_printf("%.4us a big number", 0);
	x += ft_printf("the number is %.0u", 0);
	x += ft_printf("the number is %.u", 0);
	x += ft_printf("the number is %.5u", 0);
	x += ft_printf("%u%.5u%.0u%.u%.9u", 5, 55, 2, 0, 42);
	x += ft_printf("%us%.5ui%.0uc%.up%.9ux", 5, 55, 2, 0, 42);
	printf("\n\n");

	y += printf("%.1u", 1);
	y += printf("%.2u", 1);
	y += printf("%.2u", 0);
	y += printf("%.0u", 0);
	y += printf("%.u", 0);
	y += printf("%.2u", 30000);
	y += printf("%.20u", 30000);
	y += printf("%.0u", (unsigned int)-1);
	y += printf("%.5u", (unsigned int)-1);
	y += printf("%.9u", (unsigned int)-1);
	y += printf("%.10u", (unsigned int)-1);
	y += printf("%.11u", (unsigned int)-1);
	y += printf("%.10uis a big number", (unsigned int)-1);
	y += printf("%.0uis a big number", (unsigned int)-1);
	y += printf("%.4us a big number", (unsigned int)-1);
	y += printf("%.9uxs a big number", (unsigned int)-1);
	y += printf("%.11ups a big number", (unsigned int)-1);
	y += printf("the number is %.0u", (unsigned int)-1);
	y += printf("the number is %.u", (unsigned int)-1);
	y += printf("the number is %.5u", (unsigned int)-1);
	y += printf("the number is %.9u", (unsigned int)-1);
	y += printf("the number is %.10u", (unsigned int)-1);
	y += printf("the number is %.11u", (unsigned int)-1);
	y += printf("the number is %.11u", (unsigned int)-1);
	y += printf("%.0uis a big number", 0);
	y += printf("%.4us a big number", 0);
	y += printf("the number is %.0u", 0);
	y += printf("the number is %.u", 0);
	y += printf("the number is %.5u", 0);
	y += printf("%u%.5u%.0u%.u%.9u", 5, 55, 2, 0, 42);
	y += printf("%us%.5ui%.0uc%.up%.9ux", 5, 55, 2, 0, 42);

	printf("\n");
	printf("x: %d, y:%d\n", x, y);

	x = y = 0;

	printf("Testing with widths, precisions and -\n");
	x += ft_printf("%-u", 0);
	x += ft_printf("%-u", 1);
	x += ft_printf("%-u", 10);
	x += ft_printf("%-u", -10);
	x += ft_printf("%-u", 5000);
	x += ft_printf("%-u", -5000);
	x += ft_printf("%-u", (unsigned int)-1);
	x += ft_printf("%-u", 2147483647);
	x += ft_printf("%-1u", 0);
	x += ft_printf("%-1u", 1);
	x += ft_printf("%-1u", 10);
	x += ft_printf("%-1u", -10);
	x += ft_printf("%-1u", 5000);
	x += ft_printf("%-1u", -5000);
	x += ft_printf("%-1u", (unsigned int)-1);
	x += ft_printf("%-1u", 2147483647);
	x += ft_printf("%-10u", 0);
	x += ft_printf("%-10u", 1);
	x += ft_printf("%-10u", 10);
	x += ft_printf("%-10u", -10);
	x += ft_printf("%-10u", 5000);
	x += ft_printf("%-10u", -5000);
	x += ft_printf("%-10u", -1);
	x += ft_printf("%-10u", 2147483647);
	x += ft_printf("%-.u", 0);
	x += ft_printf("%-.1u", 1);
	x += ft_printf("%-.2u", 10);
	x += ft_printf("%-.3u", -10);
	x += ft_printf("%-.4u", 5000);
	x += ft_printf("%-.5u", -5000);
	x += ft_printf("%-.6u", -1);
	x += ft_printf("%-.7u", 2147483647);
	x += ft_printf("%-1.8u", 0);
	x += ft_printf("%-1.9u", 1);
	x += ft_printf("%-1.10u", 10);
	x += ft_printf("%-1.0u", -10);
	x += ft_printf("%-1.6u", 5000);
	x += ft_printf("%-1.4u", -5000);
	x += ft_printf("%-1.10u", -1);
	x += ft_printf("%-1.12u", 2147483647);
	x += ft_printf("%-10.u", 0);
	x += ft_printf("%-10.10u", 1);
	x += ft_printf("%-10.5u", 10);
	x += ft_printf("%-10.2u", -10);
	x += ft_printf("%-10.5u", 5000);
	x += ft_printf("%-10.5u", -5000);
	x += ft_printf("%-10.15u", -1);
	x += ft_printf("%-10.5u", 2147483647);
	x += ft_printf("%-15.u", 0);
	x += ft_printf("%-15.10u", 1);
	x += ft_printf("%-15.5u", 10);
	x += ft_printf("%-15.2u", -10);
	x += ft_printf("%-15.5u", 5000);
	x += ft_printf("%-15.5u", -5000);
	x += ft_printf("%-15.15u", -1);
	x += ft_printf("%-15.5u", 2147483647);
	x += ft_printf("%-4.5u%u%4u%-10u-u5%-.3u", 3, 4, 5, 6, 7);
	x += ft_printf("%-4.5u%u%4u%-10u-u5%-.3u", 300000, 400000, 500000, 600000, 700000);
	x += ft_printf("%-4.5u%u%4u%-10u-u5%-.3u", -300000, -400000, -500000, -600000, -700000);
	x += ft_printf("%-4.5u%u%4u%-10u-u5%-.3u", 2147483647, 2141483647, 2141483647, 2141483647, 2141483647);
	x += ft_printf("%-4.5u%u%4u%-10u-u5%-.3u", -1, -1, -1, -1, -1);

	printf("\n\n");

	y += printf("%-u", 0);
	y += printf("%-u", 1);
	y += printf("%-u", 10);
	y += printf("%-u", -10);
	y += printf("%-u", 5000);
	y += printf("%-u", -5000);
	y += printf("%-u", (unsigned int)-1);
	y += printf("%-u", 2147483647);
	y += printf("%-1u", 0);
	y += printf("%-1u", 1);
	y += printf("%-1u", 10);
	y += printf("%-1u", -10);
	y += printf("%-1u", 5000);
	y += printf("%-1u", -5000);
	y += printf("%-1u", (unsigned int)-1);
	y += printf("%-1u", 2147483647);
	y += printf("%-10u", 0);
	y += printf("%-10u", 1);
	y += printf("%-10u", 10);
	y += printf("%-10u", -10);
	y += printf("%-10u", 5000);
	y += printf("%-10u", -5000);
	y += printf("%-10u", -1);
	y += printf("%-10u", 2147483647);
	y += printf("%-.u", 0);
	y += printf("%-.1u", 1);
	y += printf("%-.2u", 10);
	y += printf("%-.3u", -10);
	y += printf("%-.4u", 5000);
	y += printf("%-.5u", -5000);
	y += printf("%-.6u", -1);
	y += printf("%-.7u", 2147483647);
	y += printf("%-1.8u", 0);
	y += printf("%-1.9u", 1);
	y += printf("%-1.10u", 10);
	y += printf("%-1.0u", -10);
	y += printf("%-1.6u", 5000);
	y += printf("%-1.4u", -5000);
	y += printf("%-1.10u", -1);
	y += printf("%-1.12u", 2147483647);
	y += printf("%-10.u", 0);
	y += printf("%-10.10u", 1);
	y += printf("%-10.5u", 10);
	y += printf("%-10.2u", -10);
	y += printf("%-10.5u", 5000);
	y += printf("%-10.5u", -5000);
	y += printf("%-10.15u", -1);
	y += printf("%-10.5u", 2147483647);
	y += printf("%-15.u", 0);
	y += printf("%-15.10u", 1);
	y += printf("%-15.5u", 10);
	y += printf("%-15.2u", -10);
	y += printf("%-15.5u", 5000);
	y += printf("%-15.5u", -5000);
	y += printf("%-15.15u", -1);
	y += printf("%-15.5u", 2147483647);
	y += printf("%-4.5u%u%4u%-10u-u5%-.3u", 3, 4, 5, 6, 7);
	y += printf("%-4.5u%u%4u%-10u-u5%-.3u", 300000, 400000, 500000, 600000, 700000);
	y += printf("%-4.5u%u%4u%-10u-u5%-.3u", -300000, -400000, -500000, -600000, -700000);
	y += printf("%-4.5u%u%4u%-10u-u5%-.3u", 2147483647, 2141483647, 2141483647, 2141483647, 2141483647);
	y += printf("%-4.5u%u%4u%-10u-u5%-.3u", -1, -1, -1, -1, -1);
	printf("\n");
	printf("x: %d, y:%d\n", x, y);

	x = y = 0;

	printf("Testing with widths, precisions and 0\n");
	x += ft_printf("%01u", 0);
	x += ft_printf("%01u", -4);
	x += ft_printf("%010u", 42);
	x += ft_printf("%042u", 42000);
	x += ft_printf("%020u", -42000);
	x += ft_printf("wait for it... %050u", 42);
	x += ft_printf("%020u is how many tests are going to be maie", 8000);
	x += ft_printf("%05u", 2147483647);
	x += ft_printf("%030u", 2147483647);
	x += ft_printf("%010u", 2147483647);
	x += ft_printf("%05u", -1);
	x += ft_printf("%030u", -1);
	x += ft_printf("%010u", -1);
	x += ft_printf("%011u", -1);
	x += ft_printf("%012u", -1);
	x += ft_printf("%012u, %20u, %2u, %42u", -1, 3, 30, -1);
	x += ft_printf("%012u, %u, %2u, %42u", -1, 3, 30, -1);
	x += ft_printf("%014u%020u%02u%0u", -1, 3, 30, -1);
	x += ft_printf("%014uc%020us%02ux%0ui", -1, 3, 30, -1);
	x += ft_printf("%01.u", 0);
	x += ft_printf("%01.0u", 0);
	x += ft_printf("%02.0u", 0);
	x += ft_printf("%03.0u", 0);
	x += ft_printf("%01.1u", 0);
	x += ft_printf("%01.2u", 0);
	x += ft_printf("%01.3u", 0);
	x += ft_printf("%01.0u", 4);
	x += ft_printf("%01.1u", 4);
	x += ft_printf("%01.2u", 4);
	x += ft_printf("%01.3u", 4);
	x += ft_printf("%010.20u", 42);
	x += ft_printf("%042.2u", 42000);
	x += ft_printf("%042.20u", 42000);
	x += ft_printf("%042.42u", 42000);
	x += ft_printf("%042.52u", 42000);
	x += ft_printf("wait for it... %050.50u", 42);
	x += ft_printf("%020.19u is how many tests are going to be made", 8000);
	x += ft_printf("%020.20u is how many tests are going to be made", 8000);
	x += ft_printf("%020.21u is how many tests are going to be made", 8000);
	x += ft_printf("%05u", 2147483647);
	x += ft_printf("%030u", 2147483647);
	x += ft_printf("%09u", 2147483647);
	x += ft_printf("%010u", 2147483647);
	x += ft_printf("%011u", 2147483647);
	x += ft_printf("%05u",  -1);
	x += ft_printf("%030u", -1);
	x += ft_printf("%010u", -1);
	x += ft_printf("%011u", -1);
	x += ft_printf("%012u", -1);
	x += ft_printf("%012u, %20u, %2u, %000042u", -1, 3, 30, -1);
	x += ft_printf("%012u, %u, %002u, %42u", -1, 3, 30, -1);
	x += ft_printf("%0014.2u%020u%0002.u%000.5u", -1, 3, 30, -1);
	x += ft_printf("%014uc%020us%02ux%0ui", -1, 3, 30, -1);
	printf("\n\n");

	y += printf("%01u", 0);
	y += printf("%01u", -4);
	y += printf("%010u", 42);
	y += printf("%042u", 42000);
	y += printf("%020u", -42000);
	y += printf("wait for it... %050u", 42);
	y += printf("%020u is how many tests are going to be maie", 8000);
	y += printf("%05u", 2147483647);
	y += printf("%030u", 2147483647);
	y += printf("%010u", 2147483647);
	y += printf("%05u", -1);
	y += printf("%030u", -1);
	y += printf("%010u", -1);
	y += printf("%011u", -1);
	y += printf("%012u", -1);
	y += printf("%012u, %20u, %2u, %42u", -1, 3, 30, -1);
	y += printf("%012u, %u, %2u, %42u", -1, 3, 30, -1);
	y += printf("%014u%020u%02u%0u", -1, 3, 30, -1);
	y += printf("%014uc%020us%02ux%0ui", -1, 3, 30, -1);
	y += printf("%01.u", 0);
	y += printf("%01.0u", 0);
	y += printf("%02.0u", 0);
	y += printf("%03.0u", 0);
	y += printf("%01.1u", 0);
	y += printf("%01.2u", 0);
	y += printf("%01.3u", 0);
	y += printf("%01.0u", 4);
	y += printf("%01.1u", 4);
	y += printf("%01.2u", 4);
	y += printf("%01.3u", 4);
	y += printf("%010.20u", 42);
	y += printf("%042.2u", 42000);
	y += printf("%042.20u", 42000);
	y += printf("%042.42u", 42000);
	y += printf("%042.52u", 42000);
	y += printf("wait for it... %050.50u", 42);
	y += printf("%020.19u is how many tests are going to be made", 8000);
	y += printf("%020.20u is how many tests are going to be made", 8000);
	y += printf("%020.21u is how many tests are going to be made", 8000);
	y += printf("%05u", 2147483647);
	y += printf("%030u", 2147483647);
	y += printf("%09u", 2147483647);
	y += printf("%010u", 2147483647);
	y += printf("%011u", 2147483647);
	y += printf("%05u",  -1);
	y += printf("%030u", -1);
	y += printf("%010u", -1);
	y += printf("%011u", -1);
	y += printf("%012u", -1);
	y += printf("%012u, %20u, %2u, %000042u", -1, 3, 30, -1);
	y += printf("%012u, %u, %002u, %42u", -1, 3, 30, -1);
	y += printf("%0014.2u%020u%0002.u%000.5u", -1, 3, 30, -1);
	y += printf("%014uc%020us%02ux%0ui", -1, 3, 30, -1);

	printf("\n");
	printf("x: %d, y:%d\n", x, y);


}

void test_hex()
{
	//ft_printf("abc%xxyz\n", 27);
	ft_printf("abc:%#llx:xyz\n", 1);
	ft_printf("abc:%#llx:xyz\n", 0);
	ft_printf("abc%0#llxxyz\n", (long long unsigned int)0);
    ft_printf("abc%#.0xjkl\n", 0);
	ft_printf("abc%#025xjkl\n", 0);
    ft_printf("abc%#025xjkl\n", 17);
    ft_printf("abc%025xjkl\n", 17);
    ft_printf("abc%-25xjkl\n", 17);
    ft_printf("abc%-#25xjkl\n", 17);
    ft_printf("abc%#25xjkl\n", 255);

	printf("\n\n");
	printf("abc:%#llx:xyz\n", 1);
	printf("abc:%#llx:xyz\n", 0);
	printf("abc:%#llx:xyz\n", (long long unsigned int)0);
    printf("abc%#.0xjkl\n", 0);
	printf("abc%#025xjkl\n", 0);
    printf("abc%#025xjkl\n", 17);
    printf("abc%025xjkl\n", 17);
    printf("abc%-25xjkl\n", 17);
    printf("abc%-#25xjkl\n", 17);
    printf("abc%#25xjkl\n", 255);
	printf("\n\n");

	ft_printf("abc:%#llX:xyz\n", 1);
	ft_printf("abc:%#llX:xyz\n", 0);
	ft_printf("abc%0#llXxyz\n", (long long unsigned int)0);
    ft_printf("abc%#.0Xjkl\n", 0);
	ft_printf("abc%#025Xjkl\n", 0);
    ft_printf("abc%#025Xjkl\n", 17);
    ft_printf("abc%025Xjkl\n", 17);
    ft_printf("abc%-25Xjkl\n", 17);
    ft_printf("abc%-#25Xjkl\n", 11);
    ft_printf("abc%#25Xjkl\n", 255);


}

void test_float()
{
	int x, y;

	x = y = 0;

	printf("Testing float\n");
	printf("Error Testing [-]inf ****************\n");
	x += ft_printf("%.20f", (-1.0 / 0.0));
    x += ft_printf("%-20f", (-1.0 / 0.0));
    x += ft_printf("abc%20fxyz", (-1.0 / 0.0));
    x += ft_printf("abc%.20fxyz", (-1.0 / 0.0));
	printf("\n\n");

	y += printf("%.20f", (-1.0 / 0.0));
    y += printf("%-20f", (-1.0 / 0.0));
    y += printf("abc%20fxyz", (-1.0 / 0.0));
    y += printf("abc%.20fxyz", (-1.0 / 0.0));
	printf("\n");

	printf("x: %d, y:%d\n", x, y);

	x = y = 0;

	printf("Error Testing []inf ****************\n");
	x += ft_printf("%.20f", (1.0 / 0.0));
    x += ft_printf("%-20f", (1.0 / 0.0));
    x += ft_printf("abc%20fxyz", (1.0 / 0.0));
    x += ft_printf("abc%.20fxyz", (1.0 / 0.0));
	printf("\n\n");

	y += printf("%.20f", (1.0 / 0.0));
    y += printf("%-20f", (1.0 / 0.0));
    y += printf("abc%20fxyz", (-.0 / 0.0));
    y += printf("abc%.20fxyz", (1.0 / 0.0));
	printf("\n");

	printf("x: %d, y:%d\n", x, y);

	x = y = 0;

	printf("Error Testing []inf ****************\n");
	//x += ft_printf("abc%-20fxyz", (0.0 / 0.0));
	x += ft_printf("abc%-20Lfxyz", (0.0/0.0));
	x += ft_printf("abc%-20fxyz", (0.0/0.0));
	x += ft_printf("abc%-20Lfxyz", NULL);
	printf("\n\n");

	y += printf("abc%-20Lfxyz", (0.0/0.0));
	y += printf("abc%-20fxyz", (0.0/0.0));
	y += printf("abc%-20Lfxyz", NULL);
	printf("\n");

	printf("x: %d, y:%d\n", x, y);

	ft_printf("Test .f: %.3f\n", -42.42);
	x = y = 0;
	/*ft_printf("Test .f: %.f\n", 42.42);
	ft_printf("Test .1f: %.1f\n", 42.42);
	ft_printf("Test .2f: %.2f\n", 42.42);
	ft_printf("Test .4f: %.4f\n", 42.42);
	ft_printf("Test .8f: %.8f\n", 42.42);

	ft_printf("%.20f\n", (-1.0 / 0.0));
    ft_printf("abc%-20fxyz\n", (-1.0 / 0.0));
    ft_printf("abc%20fxyz\n", (-1.0 / 0.0));
    ft_printf("abc%.20fxyz\n", (-1.0 / 0.0));

	ft_printf("%0.20f\n", NULL);
    ft_printf("abc%-20fxyz\n", (1.0 / 0.0));
    ft_printf("abc%020fxyz\n", (1.0 / 0.0));
    ft_printf("abc%.20fxyz\n", (1.0 / 0.0));
	printf("\n");
	ft_printf("abc%-20fxyz\n", (0.0 / 0.0));*/

	/*printf("\n\n");
	printf("%.20f\n", NULL);
    printf("abc%fxyz\n", (0.0 / 0.0));
    printf("abc%20fxyz\n", (-1.0 / 0.0));
    printf("abc%.20fxyz\n", (-1.0 / 0.0));*/

	//ft_printf("Test:%lf\n", (double) 42.43);
	//printf("Test:%f\n", (double) 42.43);
}

int main(void)
{

	test_char();

	//test_percentage();
	//test_demo();

	//test_string();
	//test_pointer();
	//test_int();
	//test_uint();
	//test_hex();
	//test_float();

	//ft_printf("out:%uEnd\n", (unsigned int)-5);
	//printf("out:%u, %lluEnd\n", (unsigned int)-3, -5);
	//ft_printf("Out:%0.30luEnd\n", 9390402001010022233);
	//printf("Out:%0.30luEnd\n", 9390402001010022233);
	//printf("out:%0.20dEnd\n", 42000);
	//printf("abc%-10.7sxyz\n", "Hello World");

	//ft_printf("%d\n", -327671);
	//display_number(100023, 8);
	/*ft_printf("out:%020dEnd\n", -42000);
    ft_printf("out:%020dEnd\n", 42000);
    ft_printf("out:%0+20dEnd\n", 42000);
    ft_printf("out:%-+20dEnd\n", 42000);
    ft_printf("out:%-20dEnd\n", 42000);
    ft_printf("out:%+20dEnd\n", 42000);
    ft_printf("out:% 020dEnd\n", 42000);

	printf("\n\n");
	printf("out:%020dEnd\n", -42000);
    printf("out:%020dEnd\n", 42000);
    printf("out:%0+20dEnd\n", 42000);
    printf("out:%-+20dEnd\n", 42000);
    printf("out:%-20dEnd\n", 42000);
     printf("out:%+20dEnd\n", 42000);
    printf("out:% 020dEnd\n", 42000);*/

	system("leaks ft_printf");
	return (0);
}

/*int main()
{
	long long x = 3276717838488594929;
	printf("%d\n", (int) x);
	printf("%hd\n", (short)x);
	printf("%hhd\n", (char) x);
	printf("%ld\n", (long)x);
	printf("%lld\n", (long long)x);
	return (0);
}
*/
