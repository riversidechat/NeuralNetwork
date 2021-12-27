#pragma once

class Neuron;

class Layer
{
    public:
    Neuron* m_neurons;
    unsigned int m_numNeurons;
    double m_bias;
    
    public:
    Layer(const unsigned int& numNeurons, const unsigned int& numConnections);
    
    const unsigned int& Count() const { return m_numNeurons; }
    
    void Print(const unsigned int& Depth) const;
    
    Neuron& operator[](unsigned int i);
    const Neuron& operator[](unsigned int i) const;
};