#include "event.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Event *CreateEvent(char *name)
{
    Event *event = malloc(sizeof(Event));
    sscanf(name, "%s", event->eventName);
    event->next=NULL;
    return event;
}

void DestroyEvent(Event *this)
{
    free(this);
}
