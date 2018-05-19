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
  if(!allegro_init()) /*Inicialización de herramientas necesarias de allegro, con mensajes de error incluidos*/
  {
    return 0;
  }

  al_register_event_source(event_queue, al_get_display_event_source(display)); // lo c
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  /************************
            JUEGO
  ************************/
  // ya está el archivo de inicializacion. acordate de agregar el prototipo en el header, y la Constante TIME como double-
  // ahora veo que tiene que ser TIME y la agrego al header
  // por lo que entendí del ejemplo, time vendria a ser el intervalo de tirmpo entre eventos de timer. (cada cuanto vamos a incrementar el contador)
  // acordate que hay que registrar el timer, la queue y el display (no se si es necesario el display, por ahi para cerrarlo)


  /*******************************
  Destrucción de variables en heap
  *******************************/

  al_destroy_display(display);
  al_destroy_event_queue(event_queue);
  al_destroy_timer(timer);
  al_shutdown_primitives_addon();
  return (EXIT_SUCCESS);
}
