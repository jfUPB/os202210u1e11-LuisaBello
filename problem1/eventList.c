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
            if (strcmp(name, recorrido->eventName) == 0)
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
            if (strcmp(event->eventName, recorrido->eventName) == 0)
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
    Event *new_recorrido = SearchEvent(this, name);

    if (new_recorrido == NULL)
    {
        return;
    }

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

                recorrido = recorrido->next;

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
