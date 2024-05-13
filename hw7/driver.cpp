#include "arrayGraph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <climits>

#define MAX_CITY_COUNT 5 //easier to define here than using this->CITYCOUNT

void populateGraph(ArrayGraph<std::string>&, const std::string&);
void swap(std::string&, std::string&);
void graphSeek(ArrayGraph<std::string>&, std::string[], int, int, double&, std::string&, std::ofstream&);
void visit(std::string&);

double calculateFuel(int);

int calcPathLen(ArrayGraph<std::string>&, std::string[], int);

std::string newPathString(std::string[], int);

int main(){
    ArrayGraph<std::string> graph;
    populateGraph(graph, "path.txt");
    std::ofstream outFile("allPath.txt"); //curse you traveler sales guy
    if(outFile.is_open() == false){
        std::cout << "Could not open allPath.txt" << std::endl;
        return 1;
    }
    double minCost = LLONG_MAX; //oh deer.
    std::string optimalPath = " ";
    std::string cities[MAX_CITY_COUNT] = {"SF", "Vegas", "Seattle", "SLC", "Reno"};
    graphSeek(graph, cities, 0, MAX_CITY_COUNT-2, minCost, optimalPath, outFile);
    outFile << "\nBEST PATH:\n"<< cities[4] << " -> " << optimalPath << " -> " << cities[4] << "\n Cost: $" << minCost << "\n";
    if(minCost < LLONG_MAX){
        std::cout << "\nBEST PATH:\n"<< cities[4] << " -> " << optimalPath << " -> " << cities[4] << "\n Cost: $" << minCost << std::endl;
    }
    else{
        std::cout << "No path found." << std::endl;
    }
    outFile.close();
    return 0;
}

void populateGraph(ArrayGraph<std::string>& graph, const std::string& fileName){
    std::ifstream file(fileName);
    std::string city1, city2;
    int distance;
    while(file >> city1 >>city2 >> distance){
        std::cout << "c1: " << city1 << " c2: " << city2 << " dist: " << distance << std::endl;
        graph.add(city1, city2, distance);
        graph.add(city2, city1, distance); //to preserve the matrix structure
    }
}

void swap(std::string& a, std::string& b){
    std::string tempPtr;
    tempPtr = a;
    a = b;
    b = tempPtr;
}

void graphSeek(ArrayGraph<std::string>& graph, std::string array[], int start, int end, double& minimumCost, std::string& bestPath, std::ofstream& outFile){
    if(start == end){
        int distance = calcPathLen(graph, array, end);
        if(distance >= 0){ // to account for my bad mistake of "error codes"
            int totalDist = calcPathLen(graph, array, end);
            double cost = calculateFuel(totalDist);
            std::string currPath = "Reno -> " + newPathString(array, end) + " -> Reno";
            outFile << currPath << " - Distancece: " << distance << " mi. Cost: $" << cost << "\n";
            if(cost < minimumCost){
                minimumCost = cost;
                bestPath = newPathString(array, end);
            }
        }
    }
    else{
        for(int i = start; i <= end; i++){
            swap(array[start], array[i]);
            graphSeek(graph, array, start+1, end, minimumCost, bestPath, outFile); //ooOOOOoooOOooo recursive functions for the soul
            swap(array[start], array[i]); // put it back
        }
    }
}

void visit(std::string& city){
    std::cout << " " << city << " \n";
}

double calculateFuel(int distance){
    double fuelEfficiency, costPerGal, result;
    fuelEfficiency = 40.0;
    costPerGal = 3.50;
    result = (distance/fuelEfficiency)*costPerGal;
    return result;
}

int calcPathLen(ArrayGraph<std::string>& graph, std::string array[], int size){
    int totalDist = 0;
    std::string startingCity = "Reno";
    totalDist += graph.getEdgeWeight(startingCity, array[0]);
    for(int i = 0; i < size - 1; i++){
        totalDist += graph.getEdgeWeight(array[i], array[i+1]);
    }
    totalDist += graph.getEdgeWeight(array[size-1], startingCity);
    return totalDist; //if i did perimeters right, this should be accurate
}

std::string newPathString(std::string array[], int size){
    std::string path;
    for(int i = 0; i < size; i++){
        if(i !=0){
            path += " -> ";
        }
        path += array[i];
    }
    return path;
}