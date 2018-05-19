
int num_compare(int guess, int rand_num)
  {
    ALLEGRO_FONT * font = NULL;
    font = al_load_ttf_font(MYFONT,MYFONTSIZE,0 ); //HAY CREAR UN FONT PARA CADA TAMAÑO DE LETRA :(
    al_clear_to_color(BLACK);                       // clear del display
    if (!font)
    {
        fprintf(stderr, "Could not load the required font\n");
        return -1;                                                                // devuelvo error
    }

    if(guess-rand_num == 0)
    {
      al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*0.0, D_HEIGHT*0.5,ALLEGRO_ALIGN_LEFT, "Felicitaciones! Adivinaste el número\n");
      al_destroy_font(font);
      return 0;
    }

    else if(guess>rand_num)
    {
      al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*0.0, D_HEIGHT*0.5,ALLEGRO_ALIGN_LEFT, "Probá con un número menor\n");
    }

    else
     {
       al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*0.0, D_HEIGHT*0.5,ALLEGRO_ALIGN_LEFT, "Probá con un número mayor\n");
     }

     al_destroy_font(font);
     return 1;
  }
