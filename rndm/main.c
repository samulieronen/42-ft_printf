/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:30:35 by seronen           #+#    #+#             */
/*   Updated: 2020/02/28 15:11:05 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "rndm/art.c"
#include "libft/includes/ft_printf.h"
#include "libft/includes/libft.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
# define NORMAL "\033[0m" //dese colors not needed :((
# define BLACK "\033[22;30m"
# define RED "\033[22;31m"
# define GREEN "\033[22;32m"
# define BROWN "\033[22;33m"
# define BLUE "\033[22;34m"
# define MAGENTA "\033[22;35m"
# define CYAN "\033[22;36m"
# define GRAY "\033[22;37m"
# define DGRAY "\033[01;30m"
# define LRED "\033[01;31m"
# define LGREEN "\033[01;32m"
# define YELLOW "\033[01;33m"
# define LBLUE "\033[01;34m"
# define LMAGENTA "\033[01;35m"
# define LCYAN "\033[01;36m"
# define WHITE "\033[01;37m" // dese colors not needed :((

long max = 0;
long res = 0;

int	check(int my, int real)
{
	max++;
	if (real != my)
	{
		ft_printf(RED"Returnvalue: Diff KO :(\nReturn values don't match. Error on output!\n");
		ft_printf("user: %d VS real: %d\n", my, real);
		ft_printf(NORMAL);
	}
	else
	{
		ft_printf(GREEN"Returnvalue: Diff OK :D\n");
		ft_printf(NORMAL);
		res++;
	}
	return (0);
}

int	hazard(void)
{
	int my;
	int real;

	ft_printf("\n\nHAZARDOUS!\n\n");
	my = ft_printf("user : Hello world! 42\n");
	real = printf("real : Hello world! 42\n");
	check(my, real);
	my = ft_printf("USER : int tests (d and i) tests: d: %d i: %i, min_int: %d \n", 42, 0, -2147483648);
	real = printf("REAL : int tests (d and i) tests: d: %d i: %i, min_int: %ld \n", 42, 0, -2147483648);
	check(my, real);
	my = ft_printf("user : octal (o) tests: 42: %o, 0: %o, -12345: %o\n", 42, 0, -12345);
	real = printf("real : octal (o) tests: 42: %o, 0: %o, -12345: %o\n", 42, 0, -12345);
	check(my, real);
	my = ft_printf("user : unsigned (u) tests: 42: %u, 0: %u, U_INT_MAX: %u\n", 42, 0, UINT_MAX);
	real = printf("real : unsigned (u) tests: 42: %u, 0: %u, U_INT_MAX: %u\n", 42, 0, UINT_MAX);
	check(my, real);
	my = ft_printf("user : string null: %s\n", NULL);
	real = printf("real : string null: %s\n", NULL);
	check(my, real);
	int	arr[3] = {1, 2, 3};
	char *hello = "hello";
	char goodbye[10] = {"goodbye"};
	char *ciao = malloc(5);
	strcpy(ciao, "ciao");
	ft_printf("arr address: %p, string literal address: %p, stack address: %p, heap address:%p\n", (void*)arr, &hello, goodbye, ciao);
	printf("arr address: %p, string literal address: %p, stack address: %p, heap address:%p\n", (void*)arr, &hello, goodbye, ciao);
	my = ft_printf("user : {%   %}\n");
	real = printf("real : {% %}\n");
	check(my, real);
	my = ft_printf("user : %lo\n", LONG_MIN);
	real = printf("real : %lo\n", LONG_MIN);
	check(my, real);
	free(ciao);
	printf("\nEND OF HAZARDOUS\n\n");
	return (0);	
}

int	noparam()
{
	ft_printf("%c\n", NULL);
	ft_printf("user : %p\n", NULL);
	printf("real : %p\n", NULL);
	ft_printf("user : %s\n", NULL);
	printf("real : %s\n", NULL);
	ft_printf("%d\n", NULL);
	printf("%d\n", NULL);
//	ft_printf("%i");
//	ft_printf("%o");
//	ft_printf("%u");
	ft_printf("%x\n", NULL);
	ft_printf("%X\n", NULL);
	ft_printf("%f\n", NULL);
	printf("%f\n", NULL);
	return (0);
}

int main(int argc, char **argv)
{
	int my = 0;
	int real = 0;
	char *test;
	
//	if (art(argc, argv) != 0)
//		return (0);

	if (argc == 1)
		ft_printf("\nIf you want to test leaks: ./ft_printf -leaks\n\n");
	printf("\n\nWARMUP\n\n");

	my = ft_printf("|%6.10s|\n", "jahuwahu");
	real = printf("|%6.10s|\n", "jahuwahu");
	check(my, real);
	my = ft_printf("%%%%\n");
	real = printf("%%%%\n");
	check(my, real);


	printf("\n\nRANDOM WITH *-FLAG\n\n");

	real = printf("real string : |%*s|\n", 10, "jduong");
	my = ft_printf("myyy string : |%*s|\n", 10, "jduong");
	check(my, real);
	real = printf("real string : |%.*s|\n", 5, "jduong");
	my = ft_printf("myyy string : |%.*s|\n", 5, "jduong");
	check(my, real);
	real = printf("real string : |%*.*s|\n", 10, 5, "jduong");
	my = ft_printf("myyy string : |%*.*s|\n", 10, 5, "jduong");
	check(my, real);
	real = printf("real string : |%-*.*s|\n", 10, 5, "jduong");
	my = ft_printf("myyy string : |%-*.*s|\n", 10, 5, "jduong");
	check(my, real);

	printf("\n\nSTRINGS %%s\n\n");

	my = ft_printf("jduong |%s|\n", "jahuwahu");
	real = printf("jduong |%s|\n", "jahuwahu");
	check(my, real);
	my = ft_printf("jduong |%.5s|\n", "jahuwahu");
	real = printf("jduong |%.5s|\n", "jahuwahu");
	check(my, real);
	my = ft_printf("jduong |%.s|\n", "jahuwahu");
	real = printf("jduong |%.s|\n", "jahuwahu");
	check(my, real);
	my = ft_printf("jduong |%.0s|\n", "jahuwahu");
	real = printf("jduong |%.0s|\n", "jahuwahu");
	check(my, real);
	my = ft_printf("jduong |%3.5s|\n", "jahuwahu");
	real = printf("jduong |%3.5s|\n", "jahuwahu");
	check(my, real);
	my = ft_printf("jduong |%10.4s|\n", "jahuwahu");
	real = printf("jduong |%10.4s|\n", "jahuwahu");
	check(my, real);
	my = ft_printf("jduong |%-10.4s|\n", "jahuwahu");
	real = printf("jduong |%-10.4s|\n", "jahuwahu");
	check(my, real);

	printf("\n\nPOINTERS %%p\n\n");

	int pptr = 50;
	int *ptr = &pptr;
	real = printf("real = Addr of ptr: |%p|\n", ptr);
	my = ft_printf("myyy = Addr of ptr: |%p|\n", ptr);
	check(my, real);
	real = printf("real = Addr of ptr: |%5p|\n", ptr);
	my = ft_printf("myyy = Addr of ptr: |%5p|\n", ptr);
	check(my, real);
	real = printf("real = Addr of ptr: |%-*p|\n", 20, ptr);
	my = ft_printf("myyy = Addr of ptr: |%-*p|\n", 20, ptr);
	check(my, real);
	real = printf("real = Addr of ptr: |%20p|\n", ptr);
	my = ft_printf("myyy = Addr of ptr: |%20p|\n", ptr);
	check(my, real);
	real = printf("real = Addr of ptr: |%-15p|\n", ptr);
	my = ft_printf("myyy = Addr of ptr: |%-15p|\n", ptr);
	check(my, real);
	real = printf("real = Addr of ptr: |%15p|\n", ptr);
	my = ft_printf("myyy = Addr of ptr: |%15p|\n", ptr);
	check(my, real);
	real = printf("real = Addr of ptr: |%15p|\n", ptr);
	my = ft_printf("myyy = Addr of ptr: |%15p|\n", ptr);
	check(my, real);
	real = printf("real = Addr of ptr: |% 14p|\n", ptr);
	my = ft_printf("myyy = Addr of ptr: |% 14p|\n", ptr);
	check(my, real);

	printf("\n\nDECIMALS AND INTS %%d & %%i\n\n");

	real = printf("real = decimal : |%d|\n", 2000);
	my = ft_printf("myyy = decimal : |%d|\n", 2000);
	check(my, real);
	real = printf("real = decimal : |%10d|\n", 2000);
	my = ft_printf("myyy = decimal : |%10d|\n", 2000);
	check(my, real);
	real = printf("real = decimal : |%.10d|\n", 20011);
	my = ft_printf("myyy = decimal : |%.10d|\n", 20011);
	check(my, real);
	real = printf("real = decimal : |%-10.9d|\n", 2000);
	my = ft_printf("myyy = decimal : |%-10.9d|\n", 2000);
	check(my, real);
	real = printf("real = decimal : |%-10d|\n", 2000);
	my = ft_printf("myyy = decimal : |%-10d|\n", 2000);
	check(my, real);
	real = printf("real = decimal : |%010d|\n", 2000);
	my = ft_printf("myyy = decimal : |%010d|\n", 2000);
	check(my, real);
	real = printf("real = decimal : |%010d|\n", -2);
	my = ft_printf("myyy = decimal : |%010d|\n", -2);
	check(my, real);
	real = printf("real = decimal : |%d|\n", -2);
	my = ft_printf("myyy = decimal : |%d|\n", -2);
	check(my, real);
	real = printf("real = decimal with %%i : |%i|\n", 2000);
	my = ft_printf("myyy = decimal with %%i : |%i|\n", 2000);
	check(my, real);
	real = printf("real = decimal with %%i : |%20.10i|\n", -2000);
	my = ft_printf("myyy = decimal with %%i : |%20.10i|\n", -2000);
	check(my, real);
	real = printf("real = decimal with %%i : |%-+20.10i|\n", 2000);
	my = ft_printf("myyy = decimal with %%i : |%-+20.10i|\n", 2000);
	real = printf("real = decimal with %%i : |%20s|\n", "s");
	check(my, real);
	real = 0;
	my = ft_printf("myyy = decimal with %%i : |%li|\n", (long)2000);
	real = printf("real = decimal with %%i : |%li|\n", (long)2000);
	check(my, real);
	my = ft_printf("myyy = decimal with %%i : |%hi|\n", (short)20);
	real = printf("real = decimal with %%i : |%hi|\n", (short)20);
	check(my, real);
	my = ft_printf("myyy = decimal with %%i : |%lli|\n", (long long)200000);
	real = printf("real = decimal with %%i : |%lli|\n", (long long)200000);
	check(my, real);
	my = ft_printf("myyy = decimal with %%i : |%hhi|\n", (signed char)100);
	real = printf("real = decimal with %%i : |%hhi|\n", (signed char)100);
	check(my, real);

	ft_printf("\n****** TEST #5 ******\n\n");
	ft_printf("'%- 10i'\n'%- 10lli'\n", 3, (long long)300);
 	printf("'%- 10i'\n'%- 10lli'\n\n", 3, (long long)300);

	my = ft_printf("myyy = decimal with %%i : |%*20.4i|\n", 40, 2000);
	real = printf("real = decimal with %%i : |%*20.4i|\n", 40, 2000);
	check(my, real);

	printf("\n\nCHARS %%c\n\n");

	real = printf("real char : |%c|\n", 'a');
	my = ft_printf("myyy char : |%c|\n", 'a');
	check(my, real);
	real = printf("real char : |%2c|\n", 'h');
	my = ft_printf("myyy char : |%2c|\n", 'h');
	check(my, real);
	real = printf("real char : |%-2c|\n", 'h');
	my = ft_printf("myyy char : |%-2c|\n", 'h');
	check(my, real);

	printf("\n\nOCTALS %%o\n\n");

	real = printf("real octal : |%o|\n", 33);
	my = ft_printf("myyy octal : |%o|\n", 33);
	check(my, real);
	real = printf("real octal : |%.4o|\n", 33);
	my = ft_printf("myyy octal : |%.4o|\n", 33);
	check(my, real);
	real = printf("real octal : |%10o|\n", 33);
	my = ft_printf("myyy octal : |%10o|\n", 33);
	check(my, real);
	real = printf("real octal : |%-10.4o|\n", 33);
	my = ft_printf("myyy octal : |%-10.4o|\n", 33);
	check(my, real);
	real = printf("real octal : |%#o|\n", 33);
	my = ft_printf("myyy octal : |%#o|\n", 33);
	check(my, real);
	real = printf("real octal : |%#010o|\n", 33);
	my = ft_printf("myyy octal : |%#010o|\n", 33);
	check(my, real);
	real = printf("real octal : |%#.10o|\n", 33);
	my = ft_printf("myyy octal : |%#.10o|\n", 33);
	check(my, real);
	real = printf("real octal : |%#-10o|\n", 33);
	my = ft_printf("myyy octal : |%#-10o|\n", 33);
	check(my, real);
	real = printf("real octal : |%.20o|\n", 33);
	my = ft_printf("myyy octal : |%.20o|\n", 33);
	check(my, real);
	ft_printf("'%+025.5d'\n", 3);
 	printf("'%+025.5d'\n", 3);

	printf("\n\nUNSIGNED %%u\n\n");

	real = printf("real unsigned : |%u|\n", -5);
	my = ft_printf("myyy unsigned : |%u|\n", -5);
	check(my, real);
	real = printf("real unsigned : |%.20u|\n", -5);
	my = ft_printf("myyy unsigned : |%.20u|\n", -5);
	check(my, real);
	real = printf("real unsigned : |%020u|\n", -5);
	my = ft_printf("myyy unsigned : |%020u|\n", -5);
	check(my, real);
	real = printf("real unsigned : |%20u|\n", -5);
	my = ft_printf("myyy unsigned : |%20u|\n", -5);
	check(my, real);
	real = printf("real unsigned : |%-20u|\n", -5);
	my = ft_printf("myyy unsigned : |%-20u|\n", -5);
	check(my, real);
	real = printf("real unsigned : |%20.15u|\n", -5);
	my = ft_printf("myyy unsigned : |%20.15u|\n", -5);
	check(my, real);
	real = printf("real unsigned : |%.u|\n", -5);
	my = ft_printf("myyy unsigned : |%.u|\n", -5);
	check(my, real);

	printf("\n\nHEXADECIMAL %%x && %%X\n\n");

	real = printf("real hex : |%x|\n", -15);
	my = ft_printf("myyy hex : |%x|\n", -15);
	check(my, real);
	real = printf("real hex : |%#x|\n", -15);
	my = ft_printf("myyy hex : |%#x|\n", -15);
	check(my, real);
	real = printf("real hex : |%15x|\n", -15);
	my = ft_printf("myyy hex : |%15x|\n", -15);
	check(my, real);
	real = printf("real hex : |%#15x|\n", -15);
	my = ft_printf("myyy hex : |%#15x|\n", -15);
	check(my, real);
	real = printf("real hex : |%.15x|\n", -15);
	my = ft_printf("myyy hex : |%.15x|\n", -15);
	check(my, real);
	real = printf("real hex : |%#.15x|\n", -15);
	my = ft_printf("myyy hex : |%#.15x|\n", -15);
	check(my, real);
	real = printf("real hex : |%#20.15x|\n", -15);
	my = ft_printf("myyy hex : |%#20.15x|\n", -15);
	check(my, real);
	real = printf("real heX : |%#20.15X|\n", -15);
	my = ft_printf("myyy heX : |%#20.15X|\n", -15);
	check(my, real);
	real = printf("real heX : |%X|\n", -15);
	my = ft_printf("myyy heX : |%X|\n", -15);
	check(my, real);

	printf("\n\nFLOATS %%f\n\n");

	float nb = 0.32;
	real = printf("real float : |%f|\n", nb);
	my = ft_printf("myyy float : |%f|\n", nb);
	check(my, real);
	real = printf("real float : |%.2f|\n", nb);
	my = ft_printf("myyy float : |%.2f|\n", nb);
	check(my, real);
	real = printf("real float : |% .2f|\n", nb);
	my = ft_printf("myyy float : |% .2f|\n", nb);
	check(my, real);
	real = printf("real float : |%10.2f|\n", nb);
	my = ft_printf("myyy float : |%10.2f|\n", nb);
	check(my, real);
	real = printf("real float : |%010.2f|\n", nb);
	my = ft_printf("myyy float : |%010.2f|\n", nb);
	check(my, real);
	real = printf("real float : |%.12f|\n", nb);
	my = ft_printf("myyy float : |%.12f|\n", nb);
	check(my, real);
	real = printf("real float : |%3f|\n", nb);
	my = ft_printf("myyy float : |%3f|\n", nb);
	check(my, real);
	real = printf("real float : |% #.2f|\n", nb);
	my = ft_printf("myyy float : |% #.2f|\n", nb);
	check(my, real);
	real = printf("real float : |% 010.2f|\n", nb);
	my = ft_printf("myyy float : |% 010.2f|\n", nb);
	check(my, real);
	real = printf("real float : |%.0f|\n", (float)0);
	my = ft_printf("myyy float : |%.0f|\n", (float)0);
	check(my, real);
	real = printf("real : %f\n", NULL);
	my = ft_printf("myyy : %f\n", NULL);
	check(my, real);
	real = printf("real float : |%-+#020.8f|\n", nb);
	my = ft_printf("myyy float : |%-+#020.8f|\n", nb);
	check(my, real);

	printf("\n\nRANDOM CASES %%RDM\n\n");

	real = printf("real : |%s|\n", NULL);
	my = ft_printf("myyy : |%s|\n", NULL);
	check(my, real);
	real = printf("real : |%s|\n", NULL);
	my = ft_printf("myyy : |%s|\n", NULL);
	check(my, real);
	real = printf("real : |%15s|\n", NULL);
	my = ft_printf("myyy : |%15s|\n", NULL);
	check(my, real);
	real = printf("real : |%.2s|\n", NULL);
	my = ft_printf("myyy : |%.2s|\n", NULL);
	check(my, real);
	real = printf("real : |%10.2s|\n", NULL);
	my = ft_printf("myyy : |%10.2s|\n", NULL);
	check(my, real);
	real = printf("real = decimal : |%+d|\n", 0);
	my = ft_printf("myyy = decimal : |%+d|\n", 0);
	check(my, real);
	real = printf("real = signed char : |%hhd|\n", (signed char)-129);
	my = ft_printf("myyy = signed char : |%hhd|\n", (signed char)-129);
	check(my, real);
	real = printf("real = zerotest 0pad wspace : |% .d|\n", 0);
	my = ft_printf("myyy = zerotest 0pad wspace : |% .0d|\n", 0);
	check(my, real);
	real = printf("real = zerotest : |%d|\n", 0);
	my = ft_printf("myyy = zerotest : |%d|\n", 0);
	check(my, real);
	real = printf("real = zerotest 05wid0pad : |% 5.d|\n", 0);
	my = ft_printf("myyy = zerotest 05wid0pad : |% 5.0d|\n", 0);
	check(my, real);
	real = printf("real : %hd\n", (short)32768);
	my = ft_printf("myyy : %hd\n", (short)32768);
	check(my, real);
	real = printf("real : |%03.2d|\n", 0);
	my = ft_printf("user : |%03.2d|\n", 0);
	check(my, real);	
	real = printf("real : |%03.2d|\n", 1);
	my = ft_printf("user : |%03.2d|\n", 1);
	check(my, real);
	real = printf("real : |%03.2d|\n", -1);
	my = ft_printf("user : |%03.2d|\n", -1);
	check(my, real);
	real = printf("real : |%03.2d|\n", 1);
	my = ft_printf("user : |%03.2d|\n", 1);
	check(my, real);
	real = printf("real : |%03.2d|\n", -1);
	my = ft_printf("user : |%03.2d|\n", -1);
	check(my, real);
	real = printf("real : |%03.2d|\n", -10);
	my = ft_printf("user : |%03.2d|\n", -10);
	check(my, real);
	real = printf("real : |%03.2d|\n", -5);
	my = ft_printf("user : |%03.2d|\n", -5);
	check(my, real);
	real = printf("real : |%+d|\n", 0);
	my = ft_printf("user : |%+d|\n", 0);
	check(my, real);
	real = printf("hex with hash + 08 pad : %#08x\n", 42);
	my = ft_printf("hex with hash + 08 pad : %#08x\n", 42);
	check(my, real);
	real = printf("real x with hash : %#x\n", 0);
	my = ft_printf("user x with hash : %#x\n", 0);
	check(my, real);
	real = printf("real : @moulitest: %#.x %#.0x\n", 0, 0);
	my = ft_printf("user : @moulitest: %#.x %#.0x\n", 0, 0);
	check(my, real);
	real = printf("real : %#x\n", 0);
	my = ft_printf("user : %#x\n", 0);
	check(my, real);
	real = printf("real : @moulitest: %#.o %#.0o\n", 0, 0);
	my = ft_printf("user : @moulitest: %#.o %#.0o\n", 0, 0);
	check(my, real);
	real = printf("real : @moulitest: %#o %#0o\n", 0, 0);
	my = ft_printf("user : @moulitest: %#o %#0o\n", 0, 0);
	check(my, real);
	real = printf("real : @moulitest: %.o %.0o\n", 0, 0);
	my = ft_printf("user : @moulitest: %.o %.0o\n", 0, 0);
	check(my, real);
	real = printf("real : @moulitest: |%5%|\n");
	my = ft_printf("user : @moulitest: |%5%|\n");
	check(my, real);
	real = printf("real : @moulitest: |%-5%|\n");
	my = ft_printf("user : @moulitest: |%-5%|\n");
	check(my, real);
	real = printf("real : @moulitest: |%-05%|\n");
	my = ft_printf("user : @moulitest: |%-05%|\n");
	check(my, real);
	real = printf("real : @moulitest: |%.0%| |%.%|\n");
	my = ft_printf("user : @moulitest: |%.0%| |%.%|\n");
	check(my, real);
	real = printf("real : @moulitest: |%-5.3%|\n");
	my = ft_printf("user : @moulitest: |%-5.3%|\n");
	check(my, real);
	real = printf("real : @moulitest: |%05%|\n");
	my = ft_printf("user : @moulitest: |%05%|\n");
	check(my, real);
	real = printf("real : @moulitest: |% %|\n");
	my = ft_printf("user : @moulitest: |% %|\n");
	check(my, real);
	real = printf("real : @moulitest: |%#%|\n");
	my = ft_printf("user : @moulitest: |%#%|\n");
	check(my, real);
	real = printf("% 5d\n", -2562);
	my = ft_printf("% 5d\n", -2562);
	check(my, real);
	real = printf("%#03.3x\n", 6983);
	my = ft_printf("%#03.3x\n", 6983);
	check(my, real);
	real = printf("real : |%d|\n", 0);
	my = ft_printf("user : |%d|\n", 0);
	check(my, real);
	real = printf("real : |%05d|\n", 0);
	my = ft_printf("user : |%05d|\n", 0);
	check(my, real);
	real = printf("real : |%+05.d|\n", 0);
	my = ft_printf("user : |%+05.d|\n", 0);
	check(my, real);
	real = printf("real : %.20f\n", 1.025978548534310422034);
	my = ft_printf("user : %.20f\n", 1.025978548534310422034);
	check(my, real);
	hazard();
	real = printf("%.20f\n", 1.025978542436587568678);
	my = ft_printf("%.20f\n", 1.025978542436587568678);
	check(my, real);
	real = printf("%.20f\n", 2.593252893583289895);
	my = ft_printf("%.20f\n", 2.593252893583289895);
	check(my, real);
	real = printf("%.20f\n", 10.779);
	my = ft_printf("%.20f\n", 10.779);
	check(my, real);
	real = printf("%.21f\n", 10.778);
	my = ft_printf("%.21f\n", 10.778);
	check(my, real);
	real = printf("%010s is a string\n", "this");
	my = ft_printf("%010s is a string\n", "this");
	check(my, real);
	real = printf("real : |%.x|\n", 0);
	my = ft_printf("user : |%.x|\n", 0);
	check(my, real);
	real = printf("real : [linebreak]\n");
	my = printf("user : [linebreak]\n");
	check(my, real);
	ft_printf("\nDese are undefined, do not worry :)\n\n");
	real = printf("real : \n'%.0p'\n'%.p'\n", 0, 0);
	my = ft_printf("user : \n'%.0p'\n'%.p'\n", 0, 0);
	check(my, real);
//	ft_printf("test : long_long_max + 1, for itoa base :: ", ft_itoa_base(__LONG_LONG_MAX__ + 1, 10));
	printf("\nReturnvalue : %ld out of %ld tests correct!\n\n", res, max);
//	printf("But what happens with noparam!\n\n");
//	noparam();
	printf("\nEND OF TESTS\n%s");
	if (argc == 2 && !ft_strcmp(argv[1], "-leaks"))
		while (1);
	return (0);
}
