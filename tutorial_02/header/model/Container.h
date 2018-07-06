#ifndef Container_h
#define Container_h

#include <model/Model.h>
#include <vector>

class Container : public Model
{
    public:
        /// Default constructor
        Container();

        /// Default deconstructor
        ~Container();

        /**
         * Creates a new point with the coordinates provided by the parameters
         * and adds the point to the model
         * 
         * \param x The horizontal coordinate of the new point
         * \param y The vertical coordinate of the new point
         */
        void addModel(Model* model);

        /**
         * Removes the point of the model at the given index
         * 
         * \param index The index of the point that you want to remove
         */
        void removeModel(int index);

        /**
         * Returns a point of the model at the index specified by the parameter
         * 
         * \param index The index of the point you want to return
         */
        Model* GetModel(int index);

        int size() const;

        /// Removes all saved points from the model
        void clear();

        /// Returns the begin iterator of the vector of saved points
        std::vector<Model*>::const_iterator GetBegin() const;

        /// Returns the end iterator of the vector of saved points
        std::vector<Model*>::const_iterator GetEnd() const;

        /// Returns all saved points within this model
        std::vector<Model*> GetModels() const;

    protected:
        std::vector<Model*> _models;
};
#endif