/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:37:29 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/22 15:58:52 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _XOPEN_SOURCE 600

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>

typedef struct s_static
{
	unsigned char	*c;
	int				*i;
}				t_static;

t_static	g_box;

#endif
