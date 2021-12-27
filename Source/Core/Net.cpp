#include<stdlib.h>
#include<iostream>
#include"Net.hpp"

Net::Net(const std::initializer_list<unsigned int>& layers)
{
    m_layers = (Layer*)malloc(layers.size() * sizeof(Layer));
    m_numLayers = layers.size();
    
    for(unsigned int i = 0; i < layers.size(); ++i)
    {
        unsigned int numNeurons = *(layers.begin() + i);
        unsigned int numConnections = ((i + 1) < layers.size()) ? *(layers.begin() + i + 1) : 0;
        //std::cout << "Created Layer" << std::endl;
        m_layers[i] = Layer(numNeurons, numConnections);
    }
}

void Net::Print(const unsigned int& Depth) const
{
    for(unsigned int i = 0; i < m_numLayers; ++i)
    {
        std::cout << "Layer ID: " << i << std::endl;
        if(Depth - 1)
            m_layers[i].Print(Depth - 1);
    }
}

void Net::FeedForward(const std::initializer_list<double>& inputs)
{
    
}