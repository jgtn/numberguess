#include "allegro_init.h"

/******************************************************
* FUNCIÓN allegro_init()
*
* Esta función inicializa los componentes necesarios de allegro para
* que el juego pueda funcionar-
*
* RECIBE:
* --------
*
* DEVUELVE:
* + Un 1 entero si la inicialización fue exitosa, o un 0 si no lo fue,
*
* REQUIERE:
* + Constante TIME (double), que define la apreciación del timer.
******************************************************/

int allegro_init(void)
{
  /************************
  RUTINAS DE INICIALIZACIÓN
  ************************/

  ALLEGRO_EVENT_QUEUE *event_queue = NULL;
  ALLEGRO_TIMER *timer = NULL;
  ALLEGRO_DISPLAY *display = NULL;

  if(!al_init())                                            // Inicializo cola de eventos de Allegro
  {
    printf("Error, no se pudo inicializar Allegro\n");
    return 0;
  }

  if(!al_init_primitives_addon())
  {
    printf("Error, no se pudo inicializar Primitives Add-on\n");
    return 0;
  }

  timer = al_create_timer(TIME);                           // Inicializo temporizador de juego

  if(!timer)
  {
    printf("Error, no se pudo inicializar el timer\n");
    al_shutdown_primitives_addon();
    return 0;
  }

  event_queue = al_create_event_queue();                    // Inicializo cola de eventos

  if(!event_queue)
  {
    printf("Error, no se pudo inicializar la cola de eventos\n");
    al_shutdown_primitives_addon();
    al_destroy_timer(timer);
    return 0;
  }

  display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);   // Inicializo display (interfaz)

  if(!display)
  {
    printf("Error, no se pudo inicializar el display\n");
    al_shutdown_primitives_addon();
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    return 0;
  }

  if(!al_init_font_addon())                                   // Inicializa fuentes
  {
    printf("Error, no se pudo inicializar font\n");
    al_shutdown_primitives_addon();
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    return 0;
  }

  if(!al_init_ttf_addon())                                    // Inicializa fuentes
  {
    printf("Error, no se pudo inicializar ttf\n");
    al_shutdown_primitives_addon();
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    return 0;
  }


  return 1;                                                     // Si la inicialización es correcta, devuelvo un 1

}
