  /***************************************************************************//**
  @file     +Nombre del archivo (ej: template.h)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/

#ifndef NUM_COMPARE
#define NUM_COMPARE

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
 /*Librerias utilizadas por la funcion*/
 #include <stdio.h>
 #include <allegro5/allegro5.h>
 #include <allegro5/allegro_color.h> //Para usar colores
 #include <allegro5/allegro_primitives.h> //Manejo de figuras en display
 #include <allegro5/allegro_font.h> //Manejo de fonts
 #include <allegro5/allegro_ttf.h> //Manejo de ttfs
 #include <math.h>//CTE M_PI

 /*Constantes de la funcion*/


 #define STRING_BUFF_LEN  30             //largo del string donde se guarda el numero a mostrar
 #define MYFONT           "Roboto-Regular.ttf"
 #define MYFONTSIZE       36
 #define D_WIDTH 640
 #define D_HEIGHT 800


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/



/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/



/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

// +ej: extern unsigned int anio_actual;+


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
int num_compare(int guess, int rand_num);
/**
 * @brief TODO: completar descripcion
 * @param param1 Descripcion parametro 1
 * @param param2 Descripcion parametro 2
 * @return Descripcion valor que devuelve
*/
// +ej: char lcd_goto (int fil, int col);+


/*******************************************************************************
 ******************************************************************************/

#endif // NUM_COMPARE
