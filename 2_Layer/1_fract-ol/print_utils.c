/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:48:12 by regea-go          #+#    #+#             */
/*   Updated: 2023/06/01 18:30:01 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


//Colors are 0xRRGGBBAA -- R = Red; G = Green; B = Blue; A = Alpha -> 
void	print_color(int value, mlx_image_t *img, int x, int y)
{
	if (value >= 900 && value <= 1000)
		mlx_put_pixel(img, x, y, 0x000000ff); 	  
	else if (value >= 800 && value < 900) 
		mlx_put_pixel(img, x, y, 0x00faf0ff);	
	else if (value >= 700 && value < 800)
		mlx_put_pixel(img, x, y, 0xe91970ff);	
	else if (value >= 600 && value < 700)
		mlx_put_pixel(img, x, y, 0x458be4ff);
	else if (value >= 500 && value < 600)
		mlx_put_pixel(img, x, y, 0x43cd80ff);
	else if (value >= 400 && value < 500)
		mlx_put_pixel(img, x, y, 0xffec8bff);
	else if (value >= 300 && value < 400)
		mlx_put_pixel(img, x, y, 0xb88b00ff);
	else if (value >= 200 && value < 300)
		mlx_put_pixel(img, x, y, 0xdb75a0ff);
	else if (value >= 100 && value < 200)
		mlx_put_pixel(img, x, y, 0xd269eeff);	
	else if (value % 10 >= 9)				//Values for points outside the set
		mlx_put_pixel(img, x, y, 0x3355aaff);
	else if (value % 10 >= 8)
		mlx_put_pixel(img, x, y, 0x3355aaee);
	else if (value % 10 >= 7)
		mlx_put_pixel(img, x, y, 0x3355aadd);
	else if (value % 10 >= 6)
		mlx_put_pixel(img, x, y, 0x3355aacc);
	else if (value % 10 >= 5)
		mlx_put_pixel(img, x, y, 0x3355aabb);
	else if (value % 10 >= 4)
		mlx_put_pixel(img, x, y, 0x3355aaaa);
	else if (value % 10 >= 3)
		mlx_put_pixel(img, x, y, 0x3355aa99);
	else if (value % 10 >= 2)
		mlx_put_pixel(img, x, y, 0x3355aa77);
	else if (value % 10 >= 1)
		mlx_put_pixel(img, x, y, 0x3355aa55);
	else if (value % 10 >= 0)
		mlx_put_pixel(img, x, y, 0x000000FF);
		
}