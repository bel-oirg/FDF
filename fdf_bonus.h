/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:36:58 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/17 21:58:34 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "fdf.h"

//mouse
int		mouse_release(int mouse_hook, int x, int y, t_buddha *v);
int		mouse_clicked(int mouse_hook, int x, int y, t_buddha *v);
int		mouse_move(int x, int y, t_buddha *v);

//keyboard
int		key_hook(int key, t_buddha *v);

#endif
