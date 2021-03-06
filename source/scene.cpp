#include "scene.hpp"

void Scene::detachFromLayer(const Node* theNode, const unsigned int theLayerNum) {
    if( theLayerNum >= 0 && theLayerNum < layers.size() ) //making sure it is in range
        for( auto it = layers[theLayerNum].nodes.begin(); it < layers[theLayerNum].nodes.end(); it++ ) //scrolling the layer to find our node
            if( theNode == *it )
                layers[theLayerNum].nodes.erase(it); //erasing it
}

void Scene::addToLayer(Node* theNode, const unsigned int theLayerNum) {
    if( theLayerNum >= 0 ) //making sure (pleonastic?) that we are in the vector range
        if( theLayerNum >= layers.size() ) while( layers.size() <= theLayerNum ) layers.push_back(Layer()); //if this layer does not exists already we create it

    layers[theLayerNum].nodes.push_back(theNode);

}

void Scene::draw(Window& theWindow, const Transformation& theTransformation) const {
    for( auto it = layers.begin(); it < layers.end(); it++ )
        for( auto it2 = it->nodes.begin(); it2 < it->nodes.end(); it2++ )
            theWindow.draw(*(*it2), theTransformation);
}
