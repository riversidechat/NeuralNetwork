#include<iostream>
#include<stdlib.h>
#include<cmath>

#include"Neuron.hpp"

double Neuron::eta = 1.0;
double Neuron::alpha = 0.5;

Neuron::Neuron(unsigned int numConnections, unsigned int myIndex) : m_numConnections(numConnections)
{
    m_connections = (Connection*)malloc(numConnections * sizeof(Connection));
    
    for(unsigned int i = 0; i < numConnections; ++i)
    {
        double weight = Neuron::RandomWeight();
        //std::cout << "        Created Connection" << std::endl;
        m_connections[i] = { weight, 0.0 };
    }
    m_myIndex = myIndex;
}

void Neuron::Print(const unsigned int& Depth) const
{
    for(unsigned int i = 0; i < m_numConnections; ++i)
    {
        std::cout << "        Connection ID: " << i << " ";
        std::cout << "( Weight: " << m_connections[i].weight << ", DeltaWeight: " << m_connections[i].deltaWeight << " )" << std::endl;
    }
}
