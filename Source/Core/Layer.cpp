#include<iostream>
#include<stdlib.h>
#include<cassert>
#include"Layer.hpp"
#include"Neuron.hpp"

Layer::Layer(const unsigned int& numNeurons, const unsigned int& numConnections) : m_numNeurons(numNeurons)
{
    m_neurons = (Neuron*)malloc(numNeurons * sizeof(Neuron));
    
    for(unsigned int i = 0; i < numNeurons; ++i)
    {
        //std::cout << "    Created Neuron" << std::endl;
        m_neurons[i] = Neuron(numConnections, i);
    }
    
    m_bias = 1.0;
}

void Layer::Print(const unsigned int& Depth) const
{
    for(unsigned int i = 0; i < m_numNeurons; ++i)
    {
        std::cout << "    Neuron ID: " << i << " ";
        std::cout << "( Value: " << m_neurons[i].GetValue() << " )" << std::endl;
        if(Depth - 1)
            m_neurons[i].Print(Depth - 1);
    }
}

Neuron& Layer::operator[](unsigned int i)
{
    assert(i >= 0 && i < m_numNeurons);
    return m_neurons[i];
}
const Neuron& Layer::operator[](unsigned int i) const
{
    assert(i >= 0 && i < m_numNeurons);
    return m_neurons[i];
}