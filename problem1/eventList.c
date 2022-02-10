#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList));
    eventList->head = NULL;
    eventList->last = NULL;
    eventList->isEmpty = 0;
    return eventList;
}

void DestroyEventList(EventList *this)
{

    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{
    Event *recorrido = this->head;
    if (this->isEmpty != 0)
    {

        while (recorrido != NULL)
        {
            if (*(recorrido->eventName + 2) == *(name + 2) && *(recorrido->eventName + 3) == *(name + 3))
            {
                return recorrido;
            }
            recorrido = recorrido->next;
        }
    }
    else
    {
        return NULL;
    }

    return NULL;
}

void AddEvent(EventList *this, Event *event)
{

    Event *recorrido = this->head;

    if (this->isEmpty != 0)
    {
        while (recorrido != NULL)
        {
            if (*(recorrido->eventName + 2) == *(event->eventName + 2) && *(recorrido->eventName + 3) == *(event->eventName + 3))
            {
                return;
            }
            recorrido = recorrido->next;
        }
        this->last->next = event;
        this->last = event;
    }
    else
    {
        this->head = event;
        this->last = event;
        this->isEmpty = 1;
    }
}

void RemoveEvent(EventList *this, char *name)
{
    Event *recorrido = this->head;
    Event *new_recorrido = this->head;
    int8_t contador = 1;
    if (this->isEmpty != 0)
    {
        Event bandera;
        Event *recorrido = this->head;
        int8_t contador = 0;
        if (this->isEmpty != 0)
        {

            do
            {
                if (*(this->head->eventName + 2) == *(name + 2))
                {
                    DestroyEvent(this->head);
                    this->head = this->head->next;
                    break;
                }
                else if (*(recorrido->next->eventName + 2) == *(name + 2))
                {
                    DestroyEvent(recorrido->next);
                    recorrido->next = recorrido->next->next;
                    break;
                }
                else
                {
                    contador = contador + 1;
                    if (contador == 7)
                    {

                        return;
                    }
                }

                recorrido = recorrido->next;
                contador = contador + 1;
               
                /*if (recorrido == NULL)
                {
                    while (contador != 0)
                    {
                        if (!(*(new_recorrido->eventName + 2) == *(name + 2) && *(new_recorrido->eventName + 3) == *(name + 3)))
                        {
                            return;
                        }
                        new_recorrido = new_recorrido->next;
                        contador = contador - 1;
                    }
                }*/

            } while (recorrido != NULL);

            if (this->head == NULL)
            {
                this->isEmpty = 0;
            }
        }
        else
        {
            return;
        }
    }
}

void ListEvents(EventList *this)
{
    // imprime esto si la lista está vacía

    Event *recorrido = this->head;
    // int8_t contador = 0;

    if (this->isEmpty != 0)
    {

        while (recorrido != NULL)
        {

            printf("%s\n", recorrido->eventName);
            recorrido = recorrido->next;
        }
    }
    else
    {
        printf("empty\n");
    }
}
