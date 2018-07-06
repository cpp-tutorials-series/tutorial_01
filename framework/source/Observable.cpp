#include "Observable.h"

void Observable::attach(Observer* observer)
{
    observables.push_back(observer);
}