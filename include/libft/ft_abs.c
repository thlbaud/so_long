/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:03:09 by tmouche           #+#    #+#             */
/*   Updated: 2024/01/08 11:05:34 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}
