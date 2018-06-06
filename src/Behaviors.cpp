#include "Behaviors.h"

int Behaviors::jump(void* data){
    printf("HERE");
    Protagonist* object =  ((Protagonist*)data);
    int MaxHeight = object->getYPosition()- 100;
    int OriginalHeight = object->getYPosition();
    while(object->getYPosition()!=MaxHeight){
        int ypos = object->getYPosition()-10;
        printf("YPOS %d \n", ypos);
        object->changePosition(object->getXPosition(),ypos);
        SDL_Delay(100);
    }
  //  while(object->getYPosition()!=OriginalHeight){
  //      int ypos = object->getYPosition()-1;
  //      printf("YPOS %d \n", ypos);
  //      object->changePosition(object->getXPosition(),ypos);
   // }

    return 0;
}
