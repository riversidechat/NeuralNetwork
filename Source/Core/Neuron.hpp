#pragma once

class Layer;

struct Connection
{
    double weight;
    double deltaWeight;
};


class Neuron
{
    private:
    double m_value;
    Connection* m_connections;
    unsigned int m_numConnections;
    unsigned int m_myIndex;
    double m_gradient;
    
    private:
    static double RandomWeight() { return rand() / double(RAND_MAX); };
    
    public:
    static double eta;
    static double alpha;
    
    public:
    Neuron(unsigned int numConnections, unsigned int myIndex);
    
    void SetValue(const double& value) { m_value = value; }
    const double& GetValue() const { return m_value; }
    
    void Print(const unsigned int& Depth) const;
};

#include"Layer.hpp"