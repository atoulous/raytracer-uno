/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:00:18 by atoulous          #+#    #+#             */
/*   Updated: 2016/11/22 18:18:31 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	free_obj(t_var *var)
{
	free(OBJ_STR);
	free(OBJ_NAME);
	free(OBJ_TYPE);
	free(OBJ_STR_COLOR);
	free(OBJ_RGB);
	free(var->object[OBJ]);
}

void	free_var(t_var *var)
{
	free(DOC);
	free(SCENE_NAME);
	free(CAMERA);
	free(ORIGIN);
	free(RENDER);
}

void	free_all(t_var *var)
{
	mlx_destroy_image(MLX, IMG);
	MLX = NULL;
	WIN = NULL;
	IMG = NULL;
	TH = -1;
	while (++TH < NB_TH)
		free(var->ray[TH]);
	OBJ = -1;
	while (++OBJ < NB_OBJ)
		free_obj(var);
	free(var->object);
	free_var(var);
	free(var);
}

int		ft_crossquit(t_var *var)
{
	free_all(var);
	ft_exit("rtv1 quit, all well freed");
	return (0);
}
