#pragma once

#include<initializer_list>

#include"Layer.hpp"

class Net
{
    private:
    Layer* m_layers;
    unsigned int m_numLayers;
    
    public:
    Net(const std::initializer_list<unsigned int>& layers);
    
    const Layer* GetLayers() const { return m_layers; }
    
    void Print(const unsigned int& Depth) const;
    void FeedForward(const std::initializer_list<double>& inputs);
};