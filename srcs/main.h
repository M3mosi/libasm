#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#define	LGREEN		"\033[32;1m"
#define RESET   	"\033[0m"
#define BLACK   	"\033[30m"      		/* Black */
#define RED     	"\033[31m"      		/* Red */
#define GREEN   	"\033[32m"      		/* Green */
#define YELLOW  	"\033[33m"      		/* Yellow */
#define BLUE    	"\033[34m"      		/* Blue */
#define MAGENTA 	"\033[35m"      		/* Magenta */
#define CYAN    	"\033[36m"      		/* Cyan */
#define WHITE   	"\033[37m"      		/* White */
#define BOLDBLACK   "\033[1m\033[30m"		/* Bold Black */
#define BOLDRED     "\033[1m\033[31m"		/* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"		/* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"		/* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"		/* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"		/* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"		/* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"		/* Bold White */


typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

size_t		ft_strlen(char *s);
ssize_t		ft_write(int fd, const void *buf, size_t nbyte);
ssize_t		ft_read(int fd, void *buf, size_t nbyte);
char		*ft_strcpy(char *dst, char *src);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(const char *s1);
void		ft_list_push_front(t_list **begin_list, void *data);
int			ft_list_size(t_list *begin_list);
void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
														void (*free_fct)(void*));
int			ft_atoi_base(char *str, char *base);
void		ft_list_sort(t_list **begin_list,int (*cmp)());

#endif