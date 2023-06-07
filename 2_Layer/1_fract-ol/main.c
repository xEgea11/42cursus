/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:35:50 by regea-go          #+#    #+#             */
/*   Updated: 2023/06/01 18:12:30 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Put a valid argument");
		return (1);
	}
	//MLX42
	mlx_t	*mlx;
	mlx_image_t *img;
	
	//Not a void ptr anymore; returns mlx_t data -- it has void* window, void* context, int width, int height, delta_time
	mlx = mlx_init(WIDTH, HEIGHT, "fractol42", true);
	if(!mlx)
		return (1);
	//MLX42
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	
	//It sets the image, but how can i edit it?
	print_set(img, argv[1]);	//0 for mandelbrot, 1 for julia

	//What are the parameters??
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);

	//If ESC pressed  
	
	//mlx_terminate(mlx);
}

