#include "Observer.h"

Observer::Observer(Observable* subject)
{
    _subject = subject;

    // Attach the observable subject to the observer in order to receive the events
    _subject->attach(this);
}

Observable* Observer::GetSubject()
{
    return _subject;
}