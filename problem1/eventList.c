#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventList = NULL;

    return eventList;
}

void DestroyEventList(EventList *this)
{


    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{


    return NULL;
}

void AddEvent(EventList *this, Event *event)
{
    if (this->isEmpty !=NULL){
        this->last->next=malloc(sizeof(*event));
    }
    
}

void RemoveEvent(EventList *this, char *name)
{
      if (this->isEmpty!=NULL){
          for (int8_t i=0; sizeof(name); i++){
              if(*name.equals(this[i]){
                  free(*name);
              }else

          }
      }
}

void ListEvents(EventList *this)
{
    // imprime esto si la lista está vacía
    printf("empty\n");
}
