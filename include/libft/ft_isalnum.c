/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:20:08 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/09 10:54:09 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		|| (c >= 48 && c <= 57))
		return (8);
	return (0);
}
