/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:14:42 by myener            #+#    #+#             */
/*   Updated: 2018/12/03 14:59:55 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#define BUFF_SIZE 32 /*taille d'exemple dans le sujet, a modif pr tester*/

    int     get_next_line(const int fd, char **line);

#endif