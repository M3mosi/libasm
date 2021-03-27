#include "main.h"

void	printf_list(t_list *list)
{
	while (list)
	{
		printf(BOLDYELLOW"[%s] " RESET, list->data);
		list = list->next;
		if (list)
		printf(BOLDCYAN"->[%s]  \n" RESET, list->data);
	}
	puts("");
}

void	ft_lstclear(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->data)
			free((*list)->data);
		free(*list);
		*list = tmp;
	}
}

void	test_strlen(char *s)
{
	size_t res1;
	size_t res2;

	res1 = 0;
	res2 = 0;
	res1 = ft_strlen(s);
	res2 = strlen(s);
	if (res1 == res2)
		printf("\033[32;1m OK \033[0m\n");
	else
		printf("KO\n");
}

void	test_strcpy(char *src)
{
	char	dest1[512];
	char	dest2[512];

	bzero(dest1, 512);
	bzero(dest2, 512);
	ft_strcpy(dest1, src);
	strcpy(dest2, src);
	if (!strcmp(dest1, dest2))
		printf("\033[32;1m OK \033[0m\n");
	else
		printf("KO\n");
}

void	test_strcmp(char *s1, char *s2)
{
	int	ret1;
	int ret2;

	ret1 = 0;
	ret2 = 0;
	ret1 = ft_strcmp(s1, s2);
	ret2 = strcmp(s1, s2);
	if ((ret1 == 0 && ret2 == 0) || (ret1 < 0 && ret2 < 0)
								|| (ret1 > 0 && ret2 > 0))
		printf("\033[32;1m OK \033[0m\n");
	else
		printf("KO\n");
}

void	test_write(char *s)
{
	char	*buff;
	char	*res1;
	char	*res2;
	int		size;
	int		fd1;
	int		fd2;
	ssize_t ret1;
	ssize_t ret2;

	res1 = malloc(sizeof(char) * 512);
	res1[511] = 0;
	res2 = malloc(sizeof(char) * 512);
	res2[511] = 0;
	ret1 = 0;
	ret2 = 0;
	buff = strdup(s);
	printf("TEST EXISTING FD:					");
	fd1 = open("Test.txt", O_CREAT | O_RDWR, 0777);
	fd2 = open("Orig.txt", O_CREAT | O_RDWR, 0777);
	size = strlen(s);
	ft_write(fd1, buff, size);
	write(fd2, buff, size);
	read(fd1, res1, 512);
	read(fd2, res2, 512);
	close(fd1);
	close(fd2);
	if (strcmp(res1, res2) == 0)
		printf("\033[32;1m OK \033[0m\n");
	else
    {
                printf("ori: |%s|, test: |%s|\n", res2, res1);

		printf("KO\n");
    }
	printf("TEST STDOUT:						\n");
	write(1,"\nTest:    ",strlen("\nTest:    \n"));
	ft_write(STDOUT_FILENO, buff, size);
	write(1,"\nOriginal:",strlen("\nOriginal:\n"));
	write(STDOUT_FILENO, buff, size);
	write(1,"\n",1);
	printf("TEST NOT EXISTING FD:					");
	ret1 = ft_write(-1, buff, size);
	ret2 = write(-1, buff, size);
	if (ret1 == ret2)
		printf("\033[32;1m OK \033[0m\n");
	else
		printf("KO\n");
	printf("TEST RETURN VALUE:					");
	ret1 = ft_write(-1, buff, size);
	ret2 = write(-1, buff, size);
	printf("ft: %zu real: %zu\n", ret1, ret2);
    free(res1);
    free(res2);
}

void	test_read(void)
{
	char b1[512];
	char b2[512];
	ssize_t ret1;
	ssize_t ret2;
	int fd2;

	ret1 = 0;
	ret2 = 0;
	bzero(b1, 512);
	bzero(b2, 512);
	fd2 = open("text.txt", O_RDONLY);
	ft_read(fd2, b1, 512);
	close(fd2);
    fd2 = open("text.txt", O_RDONLY);
	read(fd2, b2, 512);
	printf("TEST EXISTING FD:					");
	if (strcmp(b1, b2) == 0)
		printf("\033[32;1m OK \033[0m\n");
	else
		printf("KO\n");
	bzero(b1, 512);
	bzero(b2, 512);
	printf("TEST STDIN:	    (insert text)				\n");
	ft_read(0, b1, 512);
    printf("TEST STDIN:	    (insert text again)				\n");

	read(0, b2, 512);
	if (strcmp(b1, b2) == 0)
		printf("\033[32;1m OK \033[0m\n");
	else
		printf("KO\n");
	printf("TEST NOT EXISTING FD:					");
	ret1 = ft_read(-1, b1, 512);
	ret2 = read(-1, b2, 512);
	if (ret1 == ret2)
		printf("\033[32;1m OK \033[0m\n");
	else
		printf("KO\n");
	printf("TEST RETURN VALUE:					");
	ret1 = ft_read(-1, b1, 512);
	ret2 = read(-1, b2, 512);
	printf("ft: %zu real: %zu\n", ret1, ret2);
}

void	test_strdup()
{
	char *s1;
	char *s2;

	printf("TEST LONG STRING:					");
	s1 = ft_strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	s2 = strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	if (strcmp(s1, s2) == 0)
		printf("\033[32;1m OK \033[0m\n");
	else
		printf("KO\n");
	printf("TEST EMPTY STRINGS:					");
	s1 = ft_strdup("");
	s2 = strdup("");
	if (strcmp(s1, s2) == 0)
		printf("\033[32;1m OK \033[0m\n");
	else
		printf("KO\n");
}

void	test_list_size()
{
	t_list	list;
	t_list	list_next;
	t_list	list_last;
	list.data = strdup("UNO");
	list.next = &list_next;
	list_next.data = strdup("DUE");
	list_next.next = &list_last;
	list_last.data = strdup("TRE");
	list_last.next = NULL;
	printf("TEST EMPTY LIST:					");
	if (!ft_list_size(NULL))
		printf("\033[32;1m OK \033[0m\n");
	else
		printf("KO\n");
	printf_list(&list);
	printf("TEST THREE LIST:					");
	if (ft_list_size(&list) == 3)
		printf("\033[32;1m OK \033[0m\n");
	else
		printf("KO\n");
}

void	test_list_push_front()
{
	t_list	list;
	list.data = strdup("UNO");
	list.next = NULL;
	t_list	*push_test = &list;
    printf("Begin of the list:");
	printf_list(push_test);
	printf("\nADD DUE:\n");
	ft_list_push_front(&push_test, strdup("DUE"));
	printf_list(push_test);
	printf("\nADD TRE:\n");
	ft_list_push_front(&push_test, strdup("TRE"));
	printf_list(push_test);
	printf("\nADD NULL:\n");
	ft_list_push_front(&push_test, NULL);
	printf_list(push_test);
	printf("\nADD EMPTY:\n");
	ft_list_push_front(&push_test, "");
	printf_list(push_test);
}

void	test_list_sort()
{
	t_list	list;
	list.data = strdup("1");
	list.next = NULL;
	t_list	*sort_test = &list;
	ft_list_push_front(&sort_test, strdup("4"));
	ft_list_push_front(&sort_test, strdup("3"));
	ft_list_push_front(&sort_test, strdup("2"));
	ft_list_push_front(&sort_test, strdup("5"));
	ft_list_push_front(&sort_test, strdup("6"));
	printf_list(sort_test);
	ft_list_sort(&sort_test, &strcmp);
	printf_list(sort_test);
}

void	test_list_remove_if()
{
	t_list	*list = malloc(sizeof(t_list));
	list->data = strdup("A");
	list->next = NULL;
	ft_list_push_front(&list, strdup("B"));
    ft_list_push_front(&list, strdup("B"));
    ft_list_push_front(&list, strdup("B"));
    ft_list_push_front(&list, strdup("B"));
	ft_list_push_front(&list, strdup("C"));
	ft_list_push_front(&list, strdup("D"));
	ft_list_push_front(&list, strdup("E"));
	ft_list_push_front(&list, strdup("F"));
	ft_list_push_front(&list, strdup("F"));
    ft_list_push_front(&list, strdup("H"));
	ft_list_push_front(&list, strdup("F"));

	printf_list(list);
	printf(BOLDRED"\nREMOVE B:\n"RESET);
	ft_list_remove_if(&list, "B", &strcmp, &free);
	printf_list(list);
	printf(LGREEN"\nOK\n"RESET);
	printf(BOLDRED"\nREMOVE A:\n"RESET);
	ft_list_remove_if(&list, "A", &strcmp, &free);
	printf_list(list);
	printf(LGREEN"\nOK\n"RESET);
	printf(BOLDRED"\nREMOVE H:\n"RESET);
	ft_list_remove_if(&list, "H", &strcmp, &free);
	printf_list(list);
	printf(LGREEN"\nOK\n"RESET);
    printf(BOLDRED"\nREMOVE LAST F:\n"RESET);
	ft_list_remove_if(&list, "F", &strcmp, &free);
	printf_list(list);
	printf(LGREEN"\nOK\n"RESET);
	printf(BOLDRED"\nREMOVE C D E:\n"RESET);
	ft_list_remove_if(&list, "C", &strcmp, &free);
	ft_list_remove_if(&list, "D", &strcmp, &free);
	ft_list_remove_if(&list, "E", &strcmp, &free);
    printf_list(list);
	printf(LGREEN"\nOK\n"RESET); 
    free(list);

}

void	test_atoi(void)
{
	int		index;
	char	*str[] = {" +--56", "	---ff", "\v-42", "\f+-+-11101", "  -+00501",
	" +105", "  -+11", "15256", "15", "122", "122", "568", "111", "155",
	"05", "abc56"};
	char	*base[] = {"0123456789", "0123456789abcdef", "0123456789", "01",
	"0123456789", "0123456789", "", "5", "-123456789", "012+3456789",
	"0 1", "012345\t6789", "01\r", "01234506789", "012345067890", "0123456789"};
	for(int i = 0 ; i < 16; i++)
	{
		index = i;
		printf("\n%-9s= %3s\n", "String", str[index]);
		printf("%-9s= %3s\n","Base", base[index]);
		printf(LGREEN"%-9s= %i\n\n" RESET, "Return" , ft_atoi_base_bonus(str[index], base[index]));
	}
}
int		main(int argc, char **argv)
{
    int bonus = 0;

    if(argc == 2)
        if(!strcmp(argv[1], "bonus"))
            bonus = 1;
	printf(MAGENTA ".................................................................................................\n" RESET);
	printf(MAGENTA "███████╗ ██████╗ ██╗ ██████╗ ██╗   ██╗ ██████╗     ██╗     ██╗██████╗  █████╗ ███████╗███╗   ███╗\n" RESET);
	printf(MAGENTA "██╔════╝██╔════╝ ██║██╔═══██╗██║   ██║██╔═══██╗    ██║     ██║██╔══██╗██╔══██╗██╔════╝████╗ ████║\n" RESET);
	printf(MAGENTA "███████╗██║  ███╗██║██║   ██║██║   ██║██║   ██║    ██║     ██║██████╔╝███████║███████╗██╔████╔██║\n" RESET);
	printf(MAGENTA "╚════██║██║   ██║██║██║   ██║╚██╗ ██╔╝██║   ██║    ██║     ██║██╔══██╗██╔══██║╚════██║██║╚██╔╝██║\n" RESET);
	printf(MAGENTA "███████║╚██████╔╝██║╚██████╔╝ ╚████╔╝ ╚██████╔╝    ███████╗██║██████╔╝██║  ██║███████║██║ ╚═╝ ██║\n" RESET);
	printf(MAGENTA "╚══════╝ ╚═════╝ ╚═╝ ╚═════╝   ╚═══╝   ╚═════╝     ╚══════╝╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝\n" RESET);
	printf(MAGENTA ".................................................................................................\n" RESET);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[3;96m-----------------------------------------FT STRLEN-----------------------------------------\n\033[0m");
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	printf("TEST LONG STRING:					");
	test_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	printf("TEST EMPTY STRING:					");
	test_strlen("");
    printf("Press enter to continue");
    getchar();
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[3;96m-----------------------------------------FT STRCPY-----------------------------------------\n\033[0m");
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	printf("TEST NORMAL STRING:					");
	test_strcpy("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	printf("TEST EMPTY SRC:						");
	test_strcpy("");
    printf("Press enter to continue");
    getchar();
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[3;96m-----------------------------------------FT STRCMP-----------------------------------------\n\033[0m");
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	printf("TEST EMPTY STRINGS:					");
	test_strcmp("", "");
	printf("TEST EMPTY STRING 1:					");
	test_strcmp("", "test per la prima stringa vuota");
	printf("TEST EMPTY STRING 2:					");
	test_strcmp("test per la seconda stringa vuota", "");
	printf("TEST LONG STRING:					");
	test_strcmp("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	printf("TEST POS STRING:					");
	test_strcmp("stringcompare", "stringcmp");
	printf("TEST NEG STRING:					");
	test_strcmp("stringcmp", "stringcompare");
    printf("Press enter to continue");
    getchar();
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[3;96m-----------------------------------------FT WRITE-----------------------------------------\n\033[0m");
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	//int fd1;
	//fd1 = open("text.txt", O_CREAT | O_RDWR, 0777);
	test_write("\033[32;1m     1234567890abcdefghijklmnopqrstuvwxyz!£$()=?^& Writing.... things...\033[0m\n");
	//close(fd1);
    printf("Press enter to continue");
    getchar();
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[3;96m------------------------------------------FT READ------------------------------------------\n\033[0m");
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	//int fd2;
	//fd2 = open("text2.txt", O_RDONLY);
	test_read();
	//close(fd2); 
    printf("Press enter to continue");
    getchar();
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[3;96m-----------------------------------------FT STRDUP-----------------------------------------\n\033[0m");
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	test_strdup();
    if (bonus)
    { 
    printf(BOLDYELLOW"*********************************************************************************\n\n\n"RESET);
    printf(BOLDYELLOW" ██████╗  ██████╗ ███╗   ██╗██╗   ██╗███████╗    ██████╗  █████╗ ██████╗ ████████╗\n"RESET);
    printf(BOLDYELLOW" ██╔══██╗██╔═══██╗████╗  ██║██║   ██║██╔════╝    ██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝\n"RESET);
    printf(BOLDYELLOW" ██████╔╝██║   ██║██╔██╗ ██║██║   ██║███████╗    ██████╔╝███████║██████╔╝   ██║   \n"RESET);
    printf(BOLDYELLOW" ██╔══██╗██║   ██║██║╚██╗██║██║   ██║╚════██║    ██╔═══╝ ██╔══██║██╔══██╗   ██║   \n"RESET);
    printf(BOLDYELLOW" ██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝███████║    ██║     ██║  ██║██║  ██║   ██║   \n"RESET);
    printf(BOLDYELLOW" ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝    ╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   \n\n"RESET);
    printf(BOLDYELLOW"\n*********************************************************************************\n\n\n"RESET);
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[3;96m----------------------------------------FT ATOI BASE---------------------------------------\n\033[0m");
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	test_atoi();
	printf("Press enter to continue");
    getchar();
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[3;96m----------------------------------------FT LIST SIZE---------------------------------------\n\033[0m");
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	test_list_size();
    printf("Press enter to continue\n");
    getchar();
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[3;96m-------------------------------------FT LIST PUSH FRONT------------------------------------\n\033[0m");
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	test_list_push_front(); 
    printf("Press enter to continue\n");
    getchar();
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[3;96m---------------------------------------FT LIST SORT----------------------------------------\n\033[0m");
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	test_list_sort();
    printf("Press enter to continue\n");
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[3;96m-------------------------------------FT LIST REMOVE IF-------------------------------------\n\033[0m");
	printf("\e[0;95m-------------------------------------------------------------------------------------------\n\033[0m");
	test_list_remove_if();
	printf("\n");
    printf("\e[0;95m███████╗██╗███╗   ██╗███████╗      ██╗  ███████╗███╗   ██╗██████╗       ██╗  ███████╗██╗███╗   ██╗\n\033[0m");
    printf("\e[0;95m██╔════╝██║████╗  ██║██╔════╝     ██╔╝  ██╔════╝████╗  ██║██╔══██╗     ██╔╝  ██╔════╝██║████╗  ██║\n\033[0m");
    printf("\e[0;95m█████╗  ██║██╔██╗ ██║█████╗      ██╔╝   █████╗  ██╔██╗ ██║██║  ██║    ██╔╝   █████╗  ██║██╔██╗ ██║\n\033[0m");
    printf("\e[0;95m██╔══╝  ██║██║╚██╗██║██╔══╝     ██╔╝    ██╔══╝  ██║╚██╗██║██║  ██║   ██╔╝    ██╔══╝  ██║██║╚██╗██║\n\033[0m");
    printf("\e[0;95m██║     ██║██║ ╚████║███████╗  ██╔╝     ███████╗██║ ╚████║██████╔╝  ██╔╝     ██║     ██║██║ ╚████║\n\033[0m");
    printf("\e[0;95m╚═╝     ╚═╝╚═╝  ╚═══╝╚══════╝  ╚═╝      ╚══════╝╚═╝  ╚═══╝╚═════╝   ╚═╝      ╚═╝     ╚═╝╚═╝  ╚═══╝\n\033[0m");
    char s[] = { 0xE2, 0x99, 0xA5, 0 };
	printf("\n\e[0;95m%s Special thx to ADUREGON && MCOSSU %s\n\n\n\033[0m",s, s);    }	
}