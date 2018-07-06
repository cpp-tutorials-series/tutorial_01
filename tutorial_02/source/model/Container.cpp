#include <model/Container.h>

Container::Container() : Model()
{

}

Container::~Container()
{

}

void Container::addModel(Model* model)
{
    _models.push_back(model);
}

void Container::removeModel(int index)
{
    _models.erase(_models.begin() + index);   
}

Model* Container::GetModel(int index)
{
    return _models.at(index);
}

void Container::clear()
{
    _models.clear();
}

std::vector<Model*>::const_iterator Container::GetBegin() const
{
    return _models.begin();
}

std::vector<Model*>::const_iterator Container::GetEnd() const
{
    return _models.end();
}

std::vector<Model*> Container::GetModels() const
{
    return _models;
}

int Container::size() const
{
    return _models.size();
}