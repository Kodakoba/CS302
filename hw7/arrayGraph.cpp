#include "arrayGraph.h"

template <class LabelType>
ArrayGraph<LabelType>::ArrayGraph(){
    numVert = 0;
    numEdge = 0;
    for(int i = 0; i < CITYCOUNT; i++){
        for(int j = 0; j < CITYCOUNT; j++){
            distance[i][j] = 0;
        }
    }
}

template <class LabelType>
ArrayGraph<LabelType>::ArrayGraph(const ArrayGraph& old){
    numVert = old.numVert;
    numEdge = old.numEdge;
    for(int i = 0; i < CITYCOUNT; i++){
        for(int j = 0; j < CITYCOUNT; j++){
            distance[i][j] = old.distance[i][j];
        }
    }
    for(int i = 0; i < numVert; i++){
        cities[i] = old.cities[i];
    }
}

template <class LabelType>
int ArrayGraph<LabelType>::getNumVertices() const{
    return numVert;
}

template <class LabelType>
int ArrayGraph<LabelType>::getNumEdges() const{
    return numEdge;
}

template <class LabelType>
bool ArrayGraph<LabelType>::add(LabelType start, LabelType end, int edgeWeight){
    int startIndex = getIndex(start);
    int endIndex = getIndex(end);
    if(startIndex == -1){ //check beginning is real
        if(numVert < CITYCOUNT){
            cities[numVert] = start;
            numVert++;
        }
        else{
            return false;
        }
    }
    if(endIndex == -1){ //check endian-ness
        if(numVert < CITYCOUNT){
            cities[numVert] = end;
            numVert++;
        }
        else{
            return false;
        }
    }
    startIndex = getIndex(start); //update values here, since we modified them above
    endIndex = getIndex(end);
    if(startIndex == -1 || endIndex == -1){ //if neither are true still something has gone horibly wrong
        return false;
    }
    distance[startIndex][endIndex] = edgeWeight; //the real add function
    numEdge++;
    return true;
}

template <class LabelType>
bool ArrayGraph<LabelType>::remove(LabelType start, LabelType end){
    int startIndex = getIndex(start);
    int endIndex = getIndex(end);
    if(startIndex == -1 || endIndex == -1){ //can't remove what doesn't exist
        return false;
    }
    distance[startIndex][endIndex] = 0;
    numEdge--; //yeah i totally ctrl+c/ctrl+v'd the last block since it should work in reverse lol
    if(isVertIsolated(startIndex) == true){
        removeVertex(startIndex);
    }
    if(isVertIsolated(endIndex) == true){
        removeVertex(endIndex);
    }
    return true; //or 1, as I keep instinctively doing./
}

template <class LabelType>
int ArrayGraph<LabelType>::getEdgeWeight(LabelType start, LabelType end) const{
    int startIndex = getIndex(start);
    int endIndex = getIndex(end);
    if(startIndex == -1 || endIndex == -1){ //can't return what doesn't exist
        return -23; //recognizable error code?
    }
    return distance[startIndex][endIndex];
}

template <class LabelType>
void ArrayGraph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)){
    int startIndex = getIndex(start);
    if(startIndex == -1){
        return;
    }
    bool oldCity[CITYCOUNT] = {false}; //is it an old city we visited? Default = no
    depthFirstTraversalHelper(startIndex, visit, oldCity);
}

template <class LabelType>
void ArrayGraph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)){
    int startIndex = getIndex(start);
    if(startIndex == -1){
        return;
    }
    bool oldCity[CITYCOUNT] = {false};
    breadthFirstTraversalHelper(startIndex, visit, oldCity);
}

template <class LabelType>
void ArrayGraph<LabelType>::removeVertex(int index){
    for(int i = index; i < numVert -1; i++){
        cities[i] = cities[i+1];
    }
    for(int i = index; i < numVert -1; i++){
        for(int j = 0; j < CITYCOUNT; j++){
            distance[i][j] = distance[i+1][j];
        }
    }
    for(int i = index; i < numVert -1; i++){
        for(int j = 0; j < CITYCOUNT; j++){
            distance[j][i] = distance[j][i+1];
        }
    }
    numVert--;
}

template <class LabelType>
int ArrayGraph<LabelType>::getIndex(std::string cityName) const{
    for(int i=0; i < numVert; i++){
        if(cities[i] == cityName){
            return i;
        }
    }
    return -1; //don't set this to a 16bit integer
}

template <class LabelType>
bool ArrayGraph<LabelType>::isVertIsolated(int index) const{
    for(int i = 0; i < CITYCOUNT; i++){
        if(distance[index][i] != 0){
            return false;
        }
    }
    return true;
}
//recursive functions
template <class LabelType>
void ArrayGraph<LabelType>::depthFirstTraversalHelper(int startIndex, void (*visit)(LabelType&), bool oldCity[]){
    oldCity[startIndex] = true;
    LabelType vertLabel = cities[startIndex];
    visit(vertLabel);
    for(int i = 0; i < numVert; i++){
        if(distance[startIndex][i] != 0 && !oldCity[i]){
            depthFirstTraversalHelper(i, visit, oldCity);
        }
    }
}

template <class LabelType>
void ArrayGraph<LabelType>::breadthFirstTraversalHelper(int startIndex, void (*visit)(LabelType&), bool oldCity[]){
    ArrayQueue<int> vertQueue;
    oldCity[startIndex] = true;
    vertQueue.enqueue(startIndex);
    while(!vertQueue.isEmpty()){
        int currVertIndex = vertQueue.peekFront();
        vertQueue.dequeue();
        LabelType currVertLabel = cities[currVertIndex];
        visit(currVertLabel);
        for(int i = 0; i < numVert; i++){
            if(distance[currVertIndex][i] != 0 && !oldCity[i]){
                oldCity[i] = true;
                vertQueue.enqueue(i);
            }
        }
    }
}

template <class LabelType>
int ArrayGraph<LabelType>::getCityCount() const{
    return CITYCOUNT;
}