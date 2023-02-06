/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goulem <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 01:20:49 by goulem            #+#    #+#             */
/*   Updated: 2023/02/06 02:05:37 by goulem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Before delving deeper into the Mandelbrot set and its properties, let's take
 * a look first at one of the most important concepts of mathematics, on which 
 * the fractal is based: complex numbers
 *
 * The complex number is basically the combination of a real number(part) and an 
 * imaginary number(part). Which means: if we note 'a' the real part and 'b' the 
 * imaginary part, the number complex, denoted z, will be z = a+ib .
 * Also, a,b belongs to real numbers and i = √-1 --> i^2 = −1 .
 *
 * Complex numbers can be used to represent a point in a coordinate system.
 * For example, the coordinate point (5; 2) can be represented by the complex number 5 + 2i.
 * In this example ;  the real part of the complex number corresponds to the abscissa of the 
 * point and the part imaginary on the ordinate
 *
 * The distance OM corresponds to the modulus of the number z (also called the complex norm).
 * It can therefore be deduced that The modulus of z, denoted |z|, and defind by : 
 *                              |a+ib| = sqrt(a^2+b^2).
 */


/*  You think we're done ! Oops, sorry to disappoint you : Our second concept that we must know is :
 *                                         The Sequences .
 * 
 * In mathematics, a sequence is a list of things, typically numbers, which are called the terms of the sequence.
 * A sequence can be defined directly as a function of n. This is the simplest case Example: U(n) = 4n + 1 
 * 
 * However , there is another method to define a sequence : we define the first term of the sequence and a
 * recurrence formula that will allow us to calculate a term based on the previous one.
 *
 *             example: the first term U0 = 1 and the recurrence formula Un+1 = 2Un - 2.
 */


/*
 * I hope you have understood what I have explained so far. And remember, what has been mentioned is only the 
 * simple basics that we will need in this project. However,  if you want to go deeper , kindly search on both:
 *                                                    google & youtube 
 */


/*
 * It sounds like you want to talk about the most inportant , about something magical. Well ,  here is what is 
 * considered as something more than magic : Fractals (Fractals are infinitely complex patterns that are 
 * self-similar across different scales. They are created by repeating a simple process over and over in an
 * ongoing feedback loop)
 *
 */
 

 /*  Let's start with the Mandelbrot set :
  *  Let us set a constant c ∈ C and  from this constant we define a sequence Zn(c) by recurrence:
  *                                     - Z0(c) = 0
  *                                     - Zn+1(c) = Zn(c)^2 + c
  *
  * The Mandelbrot set is a fractal that is defined as the set of points c of the complex plane for
  *  which the recurring sequence defined by Zn+1 = Zn^2 + c and the condition Z0 = 0 does not tend 
  *  to infinity (in modulus).
  *
  * And yet , his kind of calculation is very complicated for ourcomputer . therefore, we only need 
  * to test if the Zn module exceeds 2 at any given time . If he does not , then it's a  part of the fractal .
  * 
  * So we will simply check that it does not exceed 2 up to a certain rank ,  large enough to that it is
  * reasonable to think that it will not exceed it afterwards. This is the rank (called number of iterations) .
  * If the Number of iterations is not big enough, we will consider too many points as part of fractal, whereas
  * if the number of iterations is too large, the fractal will tend to be too sharp
  */

/*
 * That's why we're going to Define 2 variables for the number Z : one for the real part Z_reel and one for the
 *  imaginary part Z_imag  . the same will apply for c . 
 *  The  Zn+1 = Zn^2 + c  becomes :
 *                                     z = z^2 + c
 *                                       = (z_r + i*z_i)^2 + (c_r + i*c_i)
 *                                       = (z_r)^2 + 2i*z_r * z_i + (i*z_i)^2 + c_r + i*c_i
 *                                       = (z_r)^2 + 2i*z_r*z_i − (z_i)^2 + c_r + i*c_i
 *                                       = (z_r^2 − z_i^2 + c_r) + i(2*z_r*z_i + c_i)
 *
 * All that remains is to separate the reel  part and the imaginary part :
 *                        Zn_r = (z_r)^2 − (z_i)^2 + c_r
 *                        Zn_i = 2*z_r*z_i + c_i
 */


/*
 * Moreover, instead of calculating the modulus of z and comparing it to 2, we will just calculate 
 * the square of its components (real part and imaginary part) and compare the result to 4 :
 *       |Z| = |a + ib| = sqrt(a^2 + b^2) < 2 --> a^2 + b^2 < 4
 */


/*
 * And here we go , The most exciting part is just beginning ! Let's turn all this talk into an  elegant C code 
 */

