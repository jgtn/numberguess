/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   print_arc.h
 * Author: charlie
 *
 * Created on May 19, 2018, 1:52 AM
 */

#ifndef PRINT_ARC_H
#define PRINT_ARC_H

/*Librerias utilizadas por la funcion*/
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_color.h> //Para usar colores
#include <allegro5/allegro_primitives.h> //Manejo de figuras en display
#include <allegro5/allegro_font.h> //Manejo de fonts
#include <allegro5/allegro_ttf.h> //Manejo de ttfs
#include <math.h>//CTE M_PI

/*Constantes de la funcion*/

#define ARCTIME_POS_X    D_WIDTH/4      //posicion en x del conjunto arco-tiempo
#define ARCTIME_POS_Y    D_HEIGHT/4     //posicion en y del conjunto arco-tiempo
#define STRING_BUFF_LEN  30             //largo del string donde se guarda el numero a mostrar
#define MYFONT           "Roboto-Regular.ttf"
#define MYFONTSIZE       36
/*Prototipos de funcion*/

/*********************************************************************
*printTime()                        
* Recibe: 2 floats, uno es el tiempo transcurrido hasta el momento y
 * el otro es el total de tiempo que tarda la secuencia
 * Devuelve: un int. En caso de que haya habido un error devuelve un 0, sino un 1
* Requiere: definicion del diplay en el que escribir
 * **********************************************************************/           

int printTime (float elapsedt, float totalt );



#endif /* PRINT_ARC_H */

