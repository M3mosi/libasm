/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:40:08 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/27 12:41:51 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int			ft_strlen(const char *s);
char		*ft_strcpy(const char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_write(int fd, const void *buf, int nbytes);
int			ft_read(int fildes, void *buf, int nbyte);
char		*ft_strdup(const char *s1);
#endif
