/*
 * File:   Guess_The_Number.c
 * Author: facundofarall
 *
 * Created on May 18, 2018, 11:07 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Guess_The_Number.h"

/*
 *
 */
int main(int argc, char** argv)
{
  if(!allegro_init()) // Inicialización de herramientas necesarias de allegro, con mensajes de error incluidos
  {
    return 0;
  }

  ALLEGRO_EVENT_QUEUE *event_queue = NULL;
  ALLEGRO_TIMER *timer = NULL;
  ALLEGRO_DISPLAY *display = NULL;

  timer = al_create_timer(1.0/FPS);                           // Inicializo temporizador de juego
  event_queue = al_create_event_queue();                    // Inicializo cola de eventos
  display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);   // Inicializo display (interfaz)

  al_register_event_source(event_queue, al_get_display_event_source(display));  // Registro al display y al timer como generadores de eventos en la queue
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_clear_to_color(al_map_rgb(0,0,0));                                         // Inicializo el display-buffer en negro
	al_flip_display();                                                            // Imprimo buffer en display


  /************************
            JUEGO
  ************************/
  int num_min, num_max, num, range, start_game, guess, right_guess;
  char key_event;
  unsigned int contador = 0;                                                   // Inicializo contador de tiempo de juego
  ALLEGRO_EVENT allegro_event;                                                // Defino estructura evento de Allegro

  srand(time(NULL));                                                           // Inicicializo seed de número aleatorio (con datos de la fecha actual)

  while(key_event != 'n')
  {
    num_min = NUM_MIN;
    num_max = NUM_MAX;
    range = num_max-num_min;
    num = rand()%range+num_min;                                                  // Defino número aleatorio a adivinar
    right_guess = 1;

    printf("Presione cualquier tecla para comenzar\n");
    while(right_guess)
    {
      changemode(BUFFERED_OFF);
      while (start_game = !kbhit())
      {
        start_game = 0;                                                           // Instrucción simbólica, sin objetivo práctico.
      }
      getch();                                                                    // Pull del buffer de entrada
      changemode(BUFFERED_ON);

      al_start_timer(timer);                                                       // Inicio el temporizador

      /***********************
         Análisis de eventos
      ***********************/
      if(al_get_next_event(event_queue,&allegro_event))                           // Tomo el siguiente evento de queue
      {
        if(allegro_event.type == ALLEGRO_EVENT_TIMER)                             // No haría falta, porque es el unico tipo de evento válido
        {
          contador++;                                                             // Incremento el contador de tiempo de juego
        }
      }

      changemode(BUFFERED_OFF);

      if(kbhit())
      {
        scanf("%d", &guess); // Esto no se si va a funcionar.
        if(guess < num)
        {
          printf("Intenta con un número más grande\n");
          printf("Tiempo transcurrido: %d seg.\n",contador);                      // Esto es de prueba, después ponemos la parte gráfica dale
        }
        else if(guess > num)
        {
          printf("Intenta con un número más chico\n");
          printf("Tiempo transcurrido: %d seg.\n",contador);
        }
        else
        {
          printf("FELICITACIONES! Usted acertó (Tiempo: %d seg.)\n",contador);
          right_guess = 0;
        }
      }
      changemode(BUFFERED_ON);
    }

    printf("¿Desea continuar? ('n' si desea salir, cualquier otra tecla para continuar)\n");
    changemode(BUFFERED_OFF);
    key_event = getch();
    changemode(BUFFERED_ON);
  }


  /*******************************
  Destrucción de variables en heap
  *******************************/

  al_destroy_display(display);
  al_destroy_event_queue(event_queue);
  al_destroy_timer(timer);
  al_shutdown_primitives_addon();
  return (EXIT_SUCCESS);
}
