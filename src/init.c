/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:10:22 by ebednar           #+#    #+#             */
/*   Updated: 2019/04/12 15:39:48 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	texnulling(t_env *env)
{
	int i;
	int	j;

	i = -1;
	while (++i < env->sprcount && env->sprite[i].type != 2)
	{
		j = -1;
		while (++j < 8 && env->sprite[i].type != 2)
			env->sprite[i].texture[j] = NULL;
	}
	i = -1;
	while (++i < (int)env->nsectors)
	{
		j = -1;
		while (++j < 3)
			env->sector[i].text[j] = NULL;
	}
}

void	init_support(t_env *env)
{
	if (!(env->window = SDL_CreateWindow("Doom Nukem 2,5D",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WWIN, HWIN, SDL_WINDOW_OPENGL + SDL_WINDOW_ALLOW_HIGHDPI)))
		ft_error(4);
	env->surface = SDL_GetWindowSurface(env->window);
	initspritelight(env);
	findbutton(env);
}

void	init_support2(t_env *env)
{
	FILE	*input_file;

	if ((input_file = fopen("./save/1/player.dat", "r")))
		fread(&env->save[0], sizeof(t_player), 1, input_file);
	if ((input_file = fopen("./save/2/player.dat", "r")))
		fread(&env->save[1], sizeof(t_player), 1, input_file);
	if ((input_file = fopen("./save/3/player.dat", "r")))
		fread(&env->save[2], sizeof(t_player), 1, input_file);
	if ((input_file = fopen("./save/4/player.dat", "r")))
		fread(&env->save[3], sizeof(t_player), 1, input_file);
}

void	init(t_env *env)
{
	int		i;

	i = 0;
	env->yaw = 0;
	env->player.hp = 100;
	env->quit = 0;
	env->shooting = 0;
	env->ground = 0;
	env->falling = 1;
	env->ducking = 0;
	env->player.eye = EYEHEIGHT;
	env->fps = 0;
	env->oldfps = 60;
	env->timer = 0;
	env->jetpack = 0;
	ft_bzero(env->wsad, 16);
	while (i++ < 4)
		save_game1(env, i);
	sectorlightapply(env);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_error(4);
	else
		init_support(env);
	init_support2(env);
}
