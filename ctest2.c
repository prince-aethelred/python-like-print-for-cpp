#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Event handler type definition
typedef void (*EventHandler)(const char *);

// Struct with a function pointer as a member
typedef struct Event
{
    char *name;
    EventHandler onEvent;
} Event;

// Function that will handle the event
void handleEvent(const char *eventName)
{
    printf("Event '%s' has been handled.\n", eventName);
}

// Function to initialize the event
Event *createEvent(const char *name, EventHandler handler)
{
    Event *newEvent = (Event *)malloc(sizeof(Event));
    if (newEvent)
    {
        newEvent->name = strdup(name); // Duplicate the string for safety
        newEvent->onEvent = handler;
    }

    return newEvent;
}

// Main function
int main()
{
    // Create an event and assign the handler
    Event *myEvent = createEvent("MyEvent", handleEvent);

    // Trigger the event
    if (myEvent && myEvent->onEvent)
    {
        myEvent->onEvent(myEvent->name);
    }

    

    // Clean up
    free(myEvent->name);
    free(myEvent);

    return 0;
}
