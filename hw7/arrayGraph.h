#ifndef ARRAYGRAPH_H
#define ARRAYGRAPH_H
#include "graph.h"
#include "arrayQueue.h"
#include <string>


template<class LabelType> //i quite perfer itemtype
class ArrayGraph: public GraphInterface<LabelType>{
    static const int CITYCOUNT = 5;
    int distance[CITYCOUNT][CITYCOUNT];
    std::string cities[CITYCOUNT];
    int numVert, numEdge;
public:
    ArrayGraph();
    ArrayGraph(const ArrayGraph& old);
    int getNumVertices() const;
    int getNumEdges() const;
    bool add(LabelType start, LabelType end, int edgeWeight);
    bool remove(LabelType start, LabelType end);
    int getEdgeWeight(LabelType start, LabelType end) const;
    void depthFirstTraversal(LabelType start, void visit(LabelType&));
    void breadthFirstTraversal(LabelType start, void visit(LabelType&));
    int getCityCount() const;
protected:
    void removeVertex(int);
    int getIndex(std::string) const;
    bool isVertIsolated(int) const;
    //recursive functions
    void depthFirstTraversalHelper(int, void visit(LabelType&), bool []);
    void breadthFirstTraversalHelper(int, void visit(LabelType&), bool []);
};
#include "arrayGraph.cpp"
#endif