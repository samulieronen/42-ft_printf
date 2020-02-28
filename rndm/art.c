/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   art.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:22:37 by seronen           #+#    #+#             */
/*   Updated: 2020/02/19 17:54:17 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

int     art(int code, char **codestr)
{
	int check;

	check = 0;
	if (code == 1)
	{
		ft_putstr("Optional: You can use './ft_printf -showart' to show the authors artwork\nOR\nIf you like to see only the artwork, use ./ftprintf -onlyart\n\n");
		return (0);
	}
	if (code == 2 && (ft_strcmp(codestr[1], "-onlyart") == 0))
		check++;
	if (code == 2 && (ft_strcmp(codestr[1], "-showart") == 0))
		check++;
	if (check < 1)
		return (0);
	if (code == 2)
	{
		printf(MAGENTA"																											\n");
		printf(MAGENTA"																											\n");
		printf(MAGENTA"	 /$$$$$$$  /$$$$$$$  /$$$$$$ /$$   /$$ /$$$$$$$$ /$$$$$$$$"); 
		printf(BLUE"		 ______________							\n");
		printf(MAGENTA"	| $$__  $$| $$__  $$|_  $$_/| $$$ | $$|__  $$__/| $$_____/");	
		printf(BLUE"    		|[]	    42 |							\n");
		printf(MAGENTA"	| $$  \\ $$| $$  \\ $$  | $$  | $$$$| $$   | $$   | $$");		
		printf(BLUE"   			|  __________  |						\n");
		printf(MAGENTA"	| $$$$$$$/| $$$$$$$/  | $$  | $$ $$ $$   | $$   | $$$$$");	
		printf(BLUE"			|  | HOOD   |  |						\n");
		printf(MAGENTA"	| $$____/ | $$__  $$  | $$  | $$  $$$$   | $$   | $$__/");		
		printf(BLUE"			|  | PRINTF |  |						\n");
		printf(MAGENTA"	| $$      | $$\\   $$  | $$  | $$ \\  $$   | $$   | $$");			
		printf(BLUE"			|  |________|  |						\n");
		printf(MAGENTA"	| $$      | $$  | $$ /$$$$$$| $$ \\  $$   | $$   | $$");		
		printf(BLUE"			|   ________   |						\n");
		printf(MAGENTA"	|__/      |__/  |__/|______/|__/  \\__/   |__/   |__/");			
		printf(BLUE"			|   [ [ ]  ]   |						\n");
		printf(BLUE"										\\___[_[_]__]___|													\n");
		printf(LMAGENTA"										 																	\n");
 		printf(LMAGENTA"	 /$$																									\n");
		printf(LMAGENTA"	| $$																									\n");
		printf(LMAGENTA"	| $$$$$$$  /$$   /$$       ");
		printf(YELLOW" /$$$$$$$  /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$$   /$$$$$$  /$$$$$$$ 		\n");
		printf(LMAGENTA"	| $$__  $$| $$  | $$       ");
		printf(YELLOW"/$$_____/ /$$__  $$ /$$__  $$ /$$__  $$| $$__  $$ /$$__  $$| $$__  $$		\n");
		printf(LMAGENTA"	| $$  \\ $$| $$  | $$      ");
		printf(YELLOW"|  $$$$$$ | $$$$$$$$| $$  \\__/| $$  \\ $$| $$  \\ $$| $$$$$$$$| $$  \\ $$	\n");
		printf(LMAGENTA"	| $$  | $$| $$  | $$       ");
		printf(YELLOW"\\____  $$| $$_____/| $$      | $$  | $$| $$  | $$| $$_____/| $$  | $$		\n");
		printf(LMAGENTA"	| $$$$$$$/|  $$$$$$$       ");
		printf(YELLOW"/$$$$$$$/|  $$$$$$$| $$      |  $$$$$$/| $$  | $$|  $$$$$$$| $$  | $$		\n");
		printf(LMAGENTA"	|_______/  \\____  $$      ");
		printf(YELLOW"|_______/  \\_______/|__/       \\______/ |__/  |__/ \\_______/|__/  |__/	\n");
		printf(LMAGENTA"	           /$$  | $$																					\n");
		printf(LMAGENTA"	          |  $$$$$$/																					\n");
		printf(LMAGENTA"	           \\______/																					\n");
		printf(NORMAL);
		if (ft_strcmp(codestr[1], "-onlyart") == 0)
			return (1);
	}
	return (0);
}