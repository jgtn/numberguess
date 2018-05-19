/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: charlie
 *
 * Created on May 18, 2018, 11:36 PM
 */



#include"print_arc.h" //Usar este










#include <time.h>//OJO SOLO PARA MAIN DE PRUEBA



#define D_WIDTH		800     //solo para main de prueba
#define D_HEIGHT	800     //solo para main de prueba



    






/*
 * MAIN DE PRUEBA
 */
int main(int argc, char** argv) {
    ALLEGRO_DISPLAY *display = NULL; 
    
   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }
 
   if(!al_init_primitives_addon()){
	  fprintf(stderr, "failed to initialize primitives!\n");
	  return -1;
   }
    
   al_init_font_addon(); // initialize the font addon
   al_init_ttf_addon();// initialize the ttf (True Type Font) addon
   
   display = al_create_display(D_WIDTH, D_HEIGHT);
 
   if(!display) {
	  al_shutdown_primitives_addon();
	  fprintf(stderr, "failed to create display!\n");
      return -1;
   }
   
   
   al_clear_to_color(al_color_name("black"));
   al_flip_display();
   
   
   clock_t t;
   
   while((t=clock())<= 10*(CLOCKS_PER_SEC))
   {
       printTime((t/(CLOCKS_PER_SEC*1.0)),10);
   }
   
   
   
   

    al_destroy_display(display);
    al_shutdown_primitives_addon();
   return 0;
}




/*********************************************************************
*printTime()                        
* Recibe: 2 floats, uno es el tiempo transcurrido hasta el momento y
 * el otro es el total de tiempo que tarda la secuencia
 * Devuelve: en caso de que haya habido un error devuelve un 0, sino un 1
* Requiere: definicion del diplay en el que escribir
 * **********************************************************************/       
int printTime (float elapsedt, float totalt)
    {
        float currentpercent =1.0-(elapsedt/totalt);    //valor entre 0 y 1 que utilizo para colores y el angulo del arco 
        char str [STRING_BUFF_LEN];//arreglo en el que guardo el string con el numero que voy a imprimir
        int check=snprintf(str,STRING_BUFF_LEN,"%.2f",(totalt-elapsedt));
        if (check<0)
        {
            fprintf(stderr, "Could not load create string.\n");
                return 0;
        }
            
        
        
        
        ALLEGRO_FONT * font = NULL;
        font = al_load_ttf_font(MYFONT,MYFONTSIZE,0 ); //HAY CREAR UN FONT PARA CADA TAMAÑO DE LETRA :( 
 
        if (!font)
        {
            fprintf(stderr, "Could not load 'disney.ttf'.\n");
            return 0;
        } 
            
        
        
   
        al_clear_to_color(al_color_name("black")); //acordarse de hacer esto en algun momento*/
        
        
        al_draw_arc (ARCTIME_POS_X, ARCTIME_POS_Y, 100, -3.14/2, -2*M_PI*currentpercent, al_map_rgb(255*(1-currentpercent),255*(currentpercent),0),10); //arco que simboliza tiempo a display
        al_draw_text(font, al_map_rgb(255*(1-currentpercent),255*(currentpercent),0), ARCTIME_POS_X, ARCTIME_POS_Y-20,ALLEGRO_ALIGN_CENTER, str); //tiempo (numero) a display
        al_flip_display();
        al_destroy_font(font);
        return 1;
       
    }   
   
   
   
   