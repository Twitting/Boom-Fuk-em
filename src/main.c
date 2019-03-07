/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <ebednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:20:03 by twitting          #+#    #+#             */
/*   Updated: 2019/03/07 14:48:02 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	ft_error(int errnum)
{
	if (errnum == 1)
		ft_putendl_fd("FFFFFFFFFreeeee", 2);
	if (errnum == 2)
		ft_putendl_fd("Memory allocation error, aborting...", 2);
	if (errnum == 3)
		ft_putendl_fd("Something wrong with map file, aborting...", 2);
	if (errnum == 4)
		ft_putendl_fd("SDL initialization has failed, aborting...", 2);
	exit(errnum);
}

int main(void)
{
    t_env	*env;
	int		running;

	running = 1;
	env = structure_init();
	init(env);
	while (running)
		start_engine(env);
	printf("%lf", env->player.where.x);
	SDL_DestroyWindow(env->window);
	SDL_Quit();
	return (0);
}