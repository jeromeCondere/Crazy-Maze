#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

void keyboard(SDL_Event *event,int *continuer)
{
SDL_WaitEvent(event); /* On attend un événement qu'on récupère dans event */
        switch(event->type) /* On teste le type d'événement */
        {

        case SDL_KEYDOWN:
            switch (event->key.keysym.sym)
            {
                case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
                    *continuer = 0;
                    break;
            }
            break;
        }

}



#endif // EVENT_H_INCLUDED
