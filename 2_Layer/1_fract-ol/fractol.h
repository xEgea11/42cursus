/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:44:44 by regea-go          #+#    #+#             */
/*   Updated: 2023/05/31 20:23:50 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

# include "./MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>

# define WIDTH 1920
# define HEIGHT 1280
# define MAX_ITERATIONS 1000
# define BPP 8	//Maybe remove later

//????Struct to handle what??
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;


int	    mandelbrot(double real, double imag);
int		julia(double z_real, double z_imag, double c_real, double c_imag); // c is the mouse ptr
void	print_color(int value, mlx_image_t *img, int x, int y);
void	print_set(mlx_image_t *img, char *str);


#endif