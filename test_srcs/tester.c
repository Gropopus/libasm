/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:21:00 by user42            #+#    #+#             */
/*   Updated: 2021/04/01 13:51:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>


#define BLACK           "\033[0;30m"
#define RED             "\033[0;31m"
#define GREEN           "\033[0;32m"
#define YELLOW          "\033[0;33m"
#define BLUE            "\033[0;34m"
#define PURPLE          "\033[0;35m"
#define CYAN            "\033[0;36m"
#define GREY            "\033[0;37m"
#define NC              "\033[0m"

char	*ft__strcpy(char *dst, char *src);
char	*ft__strdup(char *src);
size_t	ft__strlen(char *str);
int	ft__strcmp(char *s1, char *s2);
size_t	ft__write(int fd, const void *buf, size_t count);
size_t	ft__read(int fd, void *buf, size_t count);

void	ft_putstr(char *str)
{
	int i;
	int ret;

	i = 0;
	while (str[i])
	{
		ret = ft__write(1, &str[i],1);
		i++;
	}
	printf("\nret = %d\n", ret);
}

void	putstr(char *str)
{
	int i;
	int ret;

	i = 0;
	while (str[i])
	{
		ret = write(1, &str[i],1);
		i++;
	}
	printf("\nret = %d\n", ret);
}

void	test_ft__read(char *str)
{
         char buff[10000];
         int fd;
         int ret;
         fd = open(str, O_RDONLY);
         printf("Argument[3] test:\n");
         while ((ret = ft__read(fd, buff, 1000)) != 0)
         {       
                 if (ret < 0)
                 {
                         printf("%smine ret read:        %d\n", CYAN, ret);
                         printf("errno:  %d%s\n", errno, NC);
                         return;
		}
		buff[ret] = '\0';
	}       
	printf("%smine  ret=%d\nbuffer->\n%s%s\n", CYAN, ret, NC, buff);
	close(fd);
}

void	test_read(char *str)
{
        char buff[10000];
        int fd;
        int ret;
        fd = open(str, O_RDONLY);
	while ((ret = read(fd, buff, 1000)) != 0)
	{
                 if (ret < 0)
                 {
			 printf("%sreal ret read:        %d\n", GREEN, ret);
                         printf("errno:  %d%s\n", errno, NC);
			 return;
		}
		buff[ret] = '\0';
	}
	printf("\n%sreal  ret=%d\nbuffer->\n%s%s", GREEN, ret, NC, buff);
	close(fd);
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		printf("%sError:%s\nEnter two strings and the path to a file as 3rd arguments\n", RED, NC);
		return (0);
	}
	printf("%s########################################################################\n", PURPLE);
	printf("#    _      _ _                           _            _               #\n");
	printf("#   | |    (_) |                         | |          | |              #\n");
	printf("#   | |     _| |__   __ _ ___ _ __ ___   | |_ ___  ___| |_ ___ _ __    #\n");
	printf("#   | |    | | '_ \\ / _` / __| '_ ` _ \\  | __/ _ \\/ __| __/ _ \\ '__|   #\n");
	printf("#   | |____| | |_) | (_| \\__ \\ | | | | | | ||  __/\\__ \\ ||  __/ |      #\n");
	printf("#   |______|_|_.__/ \\__,_|___/_| |_| |_|  \\__\\___||___/\\__\\___|_|      #\n");
	printf("#                                                                      #\n");
	printf("########################################################################%s\n", NC);
	
	printf("\n%sEvery results from my lib will be displayed in this color%s\n", CYAN, NC);
	printf("%sEvery results from the real functions will be displayed in this color%s\n\n", GREEN, NC);
	char *str = NULL;
	char dest[6000];
	char dest2[6000];
	
	printf("		%s#############################\n", YELLOW);
	printf("		#	   ft_strlen	    #\n");
	printf("		%s#############################%s\n\n", YELLOW, NC);
	
	printf("Argument[1] test:\n");
	printf("%smine	%zu%s\n", CYAN, ft__strlen(av[1]), NC);
	printf("%sreal	%lu%s\n", GREEN, strlen(av[1]), NC);
	
	printf("\nArgument[2] test:\n");
	printf("%smine	%zu%s\n", CYAN, ft__strlen(av[2]), NC);
	printf("%sreal	%lu%s\n", GREEN, strlen(av[2]), NC);	
	printf("\nempty string: (only mine because the real one is segfaulting)\n");
	printf("%snull	%zu%s\n\n", CYAN, ft__strlen(str), NC);
	
	
	printf("		%s#############################\n", YELLOW);
	printf("		#         ft_strcpy         #\n");
	printf("		%s#############################%s\n\n", YELLOW, NC);
	printf("Argument[1] test:\n");
	printf("%smine	%s%s\n", CYAN, ft__strcpy(dest,av[1]), NC);
        printf("%sreal	%s%s\n", GREEN, strcpy(dest,av[1]), NC);
	printf("Argument[2] test:\n");
	printf("%smine	%s%s\n", CYAN, ft__strcpy(dest2,av[2]), NC);
	printf("%sreal	%s%s\n", GREEN, strcpy(dest,av[2]), NC);
	printf("\nempty string:\n");
	printf("%smine null	%s%s\n", CYAN, ft__strcpy(dest, str), NC);
	printf("%sreal null	%s%s\n\n", GREEN, ft__strcpy(dest,str), NC);
        
	
	printf("		%s#############################\n", YELLOW);
	printf("		#         ft__strcmp        #\n");
	printf("		%s#############################%s\n", YELLOW, NC);
	printf("Argument[1] && Argument[2] comparison:\n");
	printf("%smine:	%d%s\n", CYAN, ft__strcmp(av[1], av[2]), NC);
	printf("%sreal:	%d%s\n", GREEN, strcmp(av[1], av[2]), NC);
	printf("\nempty string:\n");
	printf("%snull mine	%d%s\n\n", CYAN, ft__strcmp(av[1], str), NC);
        
	
	printf("		%s#############################\n", YELLOW);
	printf("		#         ft__write         #\n");
	printf("		%s#############################%s\n\n", YELLOW, NC);
	printf("Argument[1] test:\n");
	printf("%s	->mine%s", CYAN, NC);
	ft_putstr(av[1]);
	printf("\n%s	->real%s", GREEN, NC);
        putstr(av[1]);
	printf("\nArgument[2] test:\n");
	printf("%s	->mine%s", CYAN, NC);
        ft_putstr(av[2]);
	printf("\n%s	->real%s", GREEN, NC);
        putstr(av[2]);
	printf("\nArgument[1] errno test:\n");
	ft__write(1, &av[1][1000000000], 4);
	printf("%smine errno:	%d\n%s", CYAN, errno, NC);
	write(1, &av[1][1000000000], 4);
	printf("%sreal errno:	%d\n%s", GREEN, errno, NC);
	printf("\nArgument[2] errno test:\n");
	ft__write(99, &av[2][0], 1);
	printf("%smine errno:	%d\n%s", CYAN, errno, NC);
	write(99, &av[2][0], 1);
	printf("%sreal errno:	%d\n%s", GREEN, errno, NC);
	printf("\n\n");
	
	printf("		%s#############################\n", YELLOW);
	printf("		#         ft__strdup        #\n");
	printf("		%s#############################\n\n%s", YELLOW, NC);
	
	printf("Argument[1] test:\n");	
	printf("%smine	%s%s\n", CYAN, ft__strdup(av[1]), NC);
	printf("%sreal	%s%s\n", GREEN, strdup(av[1]), NC);
	printf("\nArgument[2] test:\n");
	printf("%smine	%s%s\n", CYAN, ft__strdup(av[2]), NC);
	printf("%sreal	%s%s\n", GREEN, strdup(av[2]), NC);
	printf("\nempty string:\n");
	printf("%smine	%s%s\n\n", CYAN, ft__strdup(str), GREEN);
	
	
	printf("                %s#############################\n", YELLOW);
   	printf("                #         ft__read          #\n");
        printf("                %s#############################\n\n%s", YELLOW, NC);	

	test_ft__read(av[3]);
	test_read(av[3]);
	return (0);
}
