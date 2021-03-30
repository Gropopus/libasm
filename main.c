# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

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

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft__write(1, &str[i],1);
		i++;
	}
}

void	putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i],1);
		i++;
	}
}

int main(int ac, char **av)
{
	int ret;
	int ret1;

	if (ac == 1)
	{
		printf("Error\nEnter 2 strings please\n");
		return (0);
	}
	printf("%sEvery results from my lib will be display in this color%s\n", CYAN, NC);
	printf("%sEvery results from the real functions will be display in this color%s\n\n", GREEN, NC);
	char *str = NULL;
	char dest[6000];
	printf("		%s#############################\n", YELLOW);
	printf("		#	   ft_strlen	    #\n");
	printf("		%s#############################%s\n\n", YELLOW, NC);
	printf("%smine	%zu%s\n", CYAN, ft__strlen(av[1]), NC);
	printf("%sreal	%lu%s\n", GREEN, strlen(av[1]), NC);
	printf("\nempty string: (only mine because the real one is segfaulting)\n");
	printf("%snull	%zu%s\n\n", CYAN, ft__strlen(str), NC);
	printf("		%s#############################\n", YELLOW);
	printf("		#         ft_strcpy         #\n");
	printf("		%s#############################%s\n\n", YELLOW, NC);
	printf("%smine	%s%s\n", CYAN, ft__strcpy(dest,av[1]), NC);
	printf("%sreal	%s%s\n", GREEN, strcpy(dest,av[1]), NC);
	printf("\nempty string:\n");
	printf("%smine null	%s%s\n", CYAN, ft__strcpy(dest, str), NC);
	printf("%sreal null	%s%s\n\n", GREEN, ft__strcpy(dest,str), NC);
        printf("		%s#############################\n", YELLOW);
	printf("		#         ft__strcmp        #\n");
	printf("		%s#############################%s\n", YELLOW, NC);
	printf("%smine:	%d%s\n", CYAN, ft__strcmp(av[1], av[2]), NC);
	printf("%sreal:	%d%s\n", GREEN, strcmp(av[1], av[2]), NC);
	printf("\nempty string:\n");
	printf("%snull mine	%d%s\n\n", CYAN, ft__strcmp(av[1], str), NC);
        printf("		%s#############################\n", YELLOW);
	printf("		#         ft__write         #\n");
	printf("		%s#############################%s\n\n", YELLOW, NC);
	printf("	%s->mine%s", CYAN, NC);
		ft_putstr(av[1]);
	printf("\n	%s->real%s", GREEN, NC);
	putstr(av[1]);
	printf("\n\n");
	printf("		%s#############################\n", YELLOW);
	printf("		#         ft__strdup        #\n");
	printf("		%s#############################\n\n%s", YELLOW, NC);
	printf("%smine	%s%s\n", CYAN, ft__strdup(av[1]), NC);
	printf("%sreal	%s%s\n", GREEN, strdup(av[1]), NC);
	printf("\nempty string:\n");
	printf("%smine	%s%s\n\n", CYAN, ft__strdup(str), GREEN);
	printf("                %s#############################\n", YELLOW);
   	printf("                #         ft__read          #\n");
        printf("                %s#############################\n\n%s", YELLOW, NC);	
	//printf("%smine:	%d%s", CYAN, ft___read());
	return (0);
}
