/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:42:17 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/27 12:43:16 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H 

typedef struct	s_list
{
	void			*data;
	struct s_list 	*next;
}				t_list;

char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *dst, const char *src);
int			ft_read(int fildes, void *buf, int nbyte);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strlen(const char *s);
int			ft_write(int fildes, const void *buf, int nbyte);
int			ft_list_size(t_list *lst);
int			ft_list_push_front(t_list **begin_list, void *data);
int			ft_atoi_base(char *str, char *base);
void		ft_list_sort(t_list **begin_list, int (*cmp)());
void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

#endif
