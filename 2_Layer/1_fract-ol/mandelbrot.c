/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:46:47 by regea-go          #+#    #+#             */
/*   Updated: 2023/06/01 18:26:04 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Fast and bad approximation of Mandelbrot	-- We have to look for the good formula

int	mandelbrot(double real, double imag)
{
	double	z_real;
	double	z_imag;
	double	tmp;
	int		iterations;

	z_real = 0.0;
	z_imag = 0.0;
	iterations = 0;													
	//try to understand the process and calculations	Zn+1 = (Zn)^2 + C 
	while (iterations < MAX_ITERATIONS && z_real * z_real + z_imag * z_imag <= 4.0)
	{
		double tmp = 2.0 * z_real * z_imag + imag;
		z_real = z_real * z_real - z_imag * z_imag + real;
		z_imag = tmp;
		iterations++;
	} 
	return iterations;
}
		//Z values, for each point in the plane	 //mouse x axis y axis - Const
int julia(double z_real, double z_imag, double c_real, double c_imag)
{
	double	tmp;
	int		iterations;
	
	iterations = 0;
	while (iterations < MAX_ITERATIONS && z_real * z_real + z_imag * z_imag <= 4.0)
	{
		double tmp = 2.0 * z_real * z_imag + c_imag;
		z_real = z_real * z_real - z_imag * z_imag + c_real;
		z_imag = tmp;
		iterations++;
	} 
	return iterations;
}
// VARIAR LOS VALORES DEL SET DE JULIA AQUI		// OPTIMIZAR EL CODIGO POR LOS DOS BUCLES
void	print_set(mlx_image_t *img, char *str)
{
	double minX = -2.0, maxX = 1.0;
    double minY = -1.5, maxY = 1.5;

    double dx = (maxX - minX) / (double)WIDTH;
    double dy = (maxY - minY) / (double)HEIGHT;

	// CAMBIAR EL FOR POR WHILE
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) 
		{
            double real = minX + x * dx;
            double imag = minY + y * dy;
			if (!strcmp(str, "mandelbrot"))
			{
				int iterations = mandelbrot(real, imag);
				print_color(iterations, img, x, y);
			}
			else if(!strcmp(str, "julia"))
			{
				int iterations = julia(real, imag, -0.25, -0.638); // <----- VARIAR LOS VALORES DEL SET DE JULIA AQUI
				print_color(iterations, img, x, y);
			}	
            
			
        }
	}
}