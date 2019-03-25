/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:25:09 by twitting          #+#    #+#             */
/*   Updated: 2019/03/12 23:34:57 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_env	*structure_init(void)
{
	t_env			*env;
	unsigned int	i;

    i = 0;
	env = (t_env *)malloc(sizeof(t_env));
	env->nsectors = 2;
	env->nvertexes = 6;
	env->sector = (t_sector *)malloc(sizeof(t_sector) * (env->nsectors));
	while (i < env->nsectors)
	{
		env->sector[i].vertex = (t_xy *)malloc(sizeof(t_xy) * 4);
		env->sector[i].floor = 0.0;
		env->sector[i].ceiling = 15.0;
		env->sector[i].npoints = 4;
		env->sector[i].light = 1;
		i++;
	}
	env->sector[1].ceiling = 1000.0;
	env->sector[1].floor = 2.0;

	env->sector[0].neighbors = (int *)malloc(sizeof(int) * 4);
	env->sector[0].neighbors[0] = -1;
	env->sector[0].neighbors[1] = -1;
	env->sector[0].neighbors[2] = 1;
	env->sector[0].neighbors[3] = -1;
	env->sector[1].neighbors = (int *)malloc(sizeof(int) * 4);
	env->sector[1].neighbors[0] = 0;
	env->sector[1].neighbors[1] = -1;
	env->sector[1].neighbors[2] = -1;
	env->sector[1].neighbors[3] = -1;
	i = 0;
	env->vertex = (t_xy *)malloc(sizeof(t_xy) * env->nvertexes);
	
	env->vertex[0].x = 5.0;
	env->vertex[0].y = 5.0;
	env->vertex[1].x = 50.0;
	env->vertex[1].y = 5.0;
	env->vertex[2].x = 5.0;
	env->vertex[2].y = 57.0;
	env->vertex[3].x = 5.0;
	env->vertex[3].y = 50.0;
	env->vertex[4].x = 50.0;
	env->vertex[4].y = 50.0;
	env->vertex[5].x = 50.0;
	env->vertex[5].y = 90.0;

	env->sector[0].vertex[0] = env->vertex[0];
	env->sector[0].vertex[1] = env->vertex[1];
	env->sector[0].vertex[2] = env->vertex[4];
	env->sector[0].vertex[3] = env->vertex[3];
	env->sector[1].vertex[0] = env->vertex[3];
	env->sector[1].vertex[1] = env->vertex[4];
	env->sector[1].vertex[2] = env->vertex[5];
	env->sector[1].vertex[3] = env->vertex[2];
	env->player.where.x = 20.0;
	env->player.where.y = 20.0;
	env->player.where.z = env->sector[env->player.sector].floor + EYEHEIGHT;
	env->player.velocity.x = 0.0;
	env->player.velocity.y = 0.0;
	env->player.velocity.z = 0.0;
	env->player.angle = 0.0;
	env->player.sector = 0;
	env->player.yaw = 0.0;


	return (env);
}