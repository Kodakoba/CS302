//HW 5
//sorting stuff

#include <iostream> //absolutely a need
#include <string> //why ISNT to_string a standard library function???
#include <fstream>
#include <chrono> //why you no chronos
#include <cstdlib> //for rand
#include <cstring> //for memcpy();

struct statistics{ //imagine a data type within a data type...
    unsigned long timeToSolve = 0; //stored in ms or ticks?
    unsigned long comparisons = 0; // metrics for excel
    unsigned long swaps = 0;  //ran out of numbers in int, needed long.
};

void bubbleSort(int [], int, statistics&);
void insertSort(int [], int, statistics&);
void quickSort(int[], int, int, statistics&); //im aware these could've gone in a class, but all may not be used, and i want it to work the first time...
int partition(int[], int, int, statistics&);
void mergeSort(int[], int, int, statistics&);    //plus CL/GDB won't be angry when i debug this. My CPU might not like it, but it'll work. 
void selectionSort(int[], int, statistics&);

bool writeFile(std::string, int, int, statistics unsortedStuff[], statistics sortedStuff[]); //my idea is you pass in an algorithm, a size, and two statistics structures. 

void generateNumbers(int [], int[], int, uint32_t);

int main(){
    //initial setup of variables!
    const int amountIterations = 10;
    const unsigned short smallSize = 1000;
    const unsigned int medSize = 10000;
    const unsigned long largeSize = 100000;
    const uint64_t crazySize = UINT32_MAX; //this will be fun (must change 1000000 to UINT_64_MAX)
    int sizes[] = {smallSize, medSize, largeSize}; //valid context
    std::string algorithms[] = {"bubble", "insert", "merge", "quick", "selection"};
    //loop over some crazy stuff! ready?
    for(std::string& algorithm : algorithms){ //stack overflow suggested this instead of trying to print everything in a confusing constant time state.
        for(int size : sizes){
            //setup variables per iteration
            int* unsortedArray = new int[size];
            int* sortedArray = new int[size];
            statistics unsortedStats[amountIterations], sortedStats[amountIterations];
            //setting up seed + execute gen numbers
            const auto now = std::chrono::system_clock::now();
            const std::time_t currTimeSeed = std::chrono::system_clock::to_time_t(now);
            generateNumbers(unsortedArray, sortedArray, size, currTimeSeed);
            statistics pointless;
            bubbleSort(sortedArray, size, pointless); //the statistics from pointless are...well...yknow...
            //also bubblesort was chosen because it is the most likely to actually be done correctly.
            //Ready for the fun part? (O(n^3))
            for(int i = 0; i < amountIterations; i++){
                int* tempSortingArray = new int[size];
                memcpy(tempSortingArray, unsortedArray, sizeof(int) * size); //from C11 documentation, takes parameters memcpy (to_array, from_array, indexes) 
                auto start = std::chrono::high_resolution_clock::now();
                if(algorithm == "bubble"){
                    bubbleSort(tempSortingArray, size, unsortedStats[i]);
                }
                else if(algorithm == "insert"){
                    insertSort(tempSortingArray, size, unsortedStats[i]);
                }
                else if(algorithm == "merge"){
                    mergeSort(tempSortingArray, 0, size - 1, unsortedStats[i]);
                }
                else if(algorithm == "quick"){
                    quickSort(tempSortingArray, 0, size - 1, unsortedStats[i]);
                }
                else if(algorithm == "selection"){
                    selectionSort(tempSortingArray, size, unsortedStats[i]);
                }
                auto stop = std::chrono::high_resolution_clock::now();
                unsortedStats[i].timeToSolve = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
                delete[] tempSortingArray; //~tempSortingArray(){}
            }
            //now let's do it again on an already sorted set of numbers???
            for(int i = 0; i < amountIterations; i++){
                int* tempSortingArray = new int[size];
                memcpy(tempSortingArray, sortedArray, sizeof(int) * size); //from C11 documentation, takes parameters memcpy (to_array, from_array, indexes) 
                auto start = std::chrono::high_resolution_clock::now();
                if(algorithm == "bubble"){
                    bubbleSort(tempSortingArray, size, sortedStats[i]);
                }
                else if(algorithm == "insert"){
                    insertSort(tempSortingArray, size, sortedStats[i]);
                }
                else if(algorithm == "merge"){
                    mergeSort(tempSortingArray, 0, size - 1, sortedStats[i]);
                }
                else if(algorithm == "quick"){
                    quickSort(tempSortingArray, 0, size - 1, sortedStats[i]);
                }
                else if(algorithm == "selection"){
                    selectionSort(tempSortingArray, size, sortedStats[i]);
                }
                auto stop = std::chrono::high_resolution_clock::now();
                sortedStats[i].timeToSolve = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
                delete[] tempSortingArray; //~tempSortingArray(){}
            }
            writeFile(algorithm, size, amountIterations, unsortedStats, sortedStats);
            delete[] unsortedArray;
            delete[] sortedArray;
        }
    }
    return 0;
}

void bubbleSort(int array[], int size, statistics& stats){
    bool swap;
    for(int i = 0; i < size - 1; i++){
        swap = false;
        for(int j = 0; j < size - i - 1; j++){
            stats.comparisons++;
            if(array[j] > array[j+1]){
                stats.comparisons++;
                std::swap(array[j], array[j+1]);
                stats.swaps++;
                swap = true;
            }
        }
        if(swap == false){
            stats.comparisons++;
            break;
        }
    }
}

void insertSort(int array[], int size, statistics& stats){
    for(int i = 1; i < size; i++){ //skip 0 because there's no "0ith comparison"
        int top = array[i]; //like we a stack
        int j = i-1;
        stats.comparisons++;
        while((j >= 0) && (array[j] > top)){
            array[j+1] = array[j];
            j--;
            stats.swaps++;
            if(j >= 0){
                stats.comparisons++;
            }
        }
        array[j + 1] = top;
    }
}

int partition(int array[], int start, int end, statistics& stats){ //the following is suggested by g4g:
    int pivot = array[start];
    int counter = 0;
    for(int i = start + 1; i <= end; i++){
        if (array[i] <= pivot){
            counter++;
            stats.comparisons++; //because we're comparing ends
        }
    }
    int pivotIndex = start + counter;
    std::swap(array[pivotIndex], array[start]);
    stats.swaps++;
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex){
        while(array[i] <= pivot){
            i++;
            stats.comparisons++;
        }
        while(array[j] > pivot){
            j--;
            stats.comparisons++;
        }
        if (i < pivotIndex && j > pivotIndex){
            std::swap(array[i++], array[j--]);
            stats.swaps++;
        }
    }
    return pivotIndex;
}

void quickSort(int array[], int start, int end, statistics& stats){
    //base case
    if (start >= end){
        return;
    }
    //call a sub-function of partition (according for g4g)
    int part = partition(array, start, end, stats);
    stats.comparisons++; //constitutes a comparison for the below cases.
    quickSort(array, start, part - 1, stats);
    quickSort(array, part + 1, end, stats);
} 

void mergeSort(int array[], int lhs, int rhs, statistics& stats){
    //so basically you start with your base case, and if its not that, keep going. Also there's no swapping, it's just merging.
    if(lhs >= rhs){
        return;
    }
    //repeat this function
    int mid = lhs + (rhs - lhs) / 2;
    mergeSort(array, lhs, mid, stats);
    mergeSort(array, mid+1, rhs, stats);
    //now to /merge/ it
    int lhm = mid - lhs + 1;
    int rhm = rhs - mid;
    //remember to clean this up at the end of the function
    int* leftArr = new int [lhm];
    int* rightArr = new int [rhm];
    //do math for each side
    for(int i = 0; i < lhm; i++){
        leftArr[i] = array[lhs + i];
    }
    for(int j = 0; j < rhm; j++){
        rightArr[j] = array[mid + j + 1]; //i think
    }
    //combine them
    int k = 0, l = 0;
    int m = lhs;
    while((k < lhm) && (l < rhm)){
        stats.comparisons++;
        if(leftArr[k] <= rightArr[l]){
            stats.swaps++; //im pretty sure this counts as a swap
            array[m] = leftArr[k];
            k++;
        }
        else{
            array[m] = rightArr[l];
            l++;
        }
        m++;
    }
    delete[] leftArr;
    delete[] rightArr;
}

void selectionSort(int array[], int size, statistics& stats){
    //like bubble but the other way kinda
    int min;
    for(int i=0; i < size - 1; i++){
        min = i;
        for(int j = i + 1; j < size; j++){
            stats.comparisons++; //this if statement
            if(array[j] < array[min]){
                min = j;
            }
        }
        if(min != i){
            std::swap(array[min], array[i]);
            stats.swaps++;
        }
    }
}

bool writeFile(std::string algorithm, int size, int iterations, statistics unsortedStuff[], statistics sortedStuff[]){
    std::string fileName = algorithm + std::to_string(size) + ".csv";
    std::ofstream outFile(fileName);
    if(outFile.is_open() == false){
        std::cout << "Could not open" << fileName << std::endl;
        return false;
    }
    outFile << "Run Time,Comparisons,Swaps" << std::endl;
    //by sorting
    outFile << "Unsorted," << std::endl;
    for(int i = 0; i < iterations; i++){
        outFile << unsortedStuff[i].timeToSolve << "," << unsortedStuff[i].comparisons << "," << unsortedStuff[i].swaps << "," << std::endl;
    }
    outFile << "Sorted," << std::endl;
    for(int i = 0; i < iterations; i++){
        outFile << sortedStuff[i].timeToSolve << "," << sortedStuff[i].comparisons << "," << sortedStuff[i].swaps << "," << std::endl;
    }
    outFile.close();
    return true;
}

void generateNumbers(int array[], int sortArray[], int size, uint32_t seed){
    srand(seed);
    for(int i = 0; i < size; i++){
        array[i] = rand() % 1000000;
        sortArray[i] = array[i];
    }
}