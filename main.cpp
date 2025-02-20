#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>
#include <list>
#include <random>

using ms = std::chrono::milliseconds;

std::random_device rd;
std::mt19937 gen(rd());

int random(int range) {
    std::uniform_int_distribution<> dis(0, range);
    return dis(gen);
}

auto vectorInsert(std::vector<int>& v, int N) {
    auto startVec = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        int num = random(N);
        auto it = v.begin();
        while (it != v.end() && *it < num) {
            ++it;
        }
        v.insert(it, num);
    }
    auto endVec = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<ms>(endVec - startVec).count();
}

auto vectorRemove(std::vector<int>& v, int N){
    auto startVec = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < N && !v.empty(); ++i){
        int numIndex = random(v.size() - 1);
        auto it = v.begin();
        while(numIndex--) ++it;
        v.erase(it);
    }

    auto endVec = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(endVec - startVec).count();
}


auto listInsert(std::list<int>& l, int N) {
    auto startList = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        int num = random(N);
        auto it = l.begin();
        while (it != l.end() && *it < num) {
            ++it;
        }
        l.insert(it, num);
    }
    auto endList = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(endList - startList).count();
}

auto listRemove(std::list<int>& l, int N) {
    auto startList = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N && !l.empty(); ++i) {
        int numIndex = random(l.size() - 1);
        auto it = l.begin();
        while(numIndex--) ++it;
        l.erase(it);
    }
    auto endList = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(endList - startList).count();
}

int main() {
    const int N = 50000;
    std::vector<int> v;
    std::list<int> l;
    v.reserve(N);

    // Perform list operations
    auto listIn = listInsert(l, N);
    auto listRe = listRemove(l, N);

    // Perform vector operations
    auto vecIn = vectorInsert(v, N);
    auto vecRe = vectorRemove(v, N);

    const int width = 25;// Column width for the labels and values

    std::cout << "Performance Difference for "<< N << " elements in vector and list:\n";
    std::cout << std::left << std::setw(width) << "-------------" << std::endl;
    

    // Vector section
    std::cout << std::left << std::setw(width) << "Vector:" << std::endl;
    std::cout << std::left << std::setw(width) << "-------------" << std::endl;

    std::cout << std::left << std::setw(width) << "Insertion:" << " | " <<  vecIn << " ms" << std::endl;

    std::cout << std::left << std::setw(width) << "Deletion:" << " | "  << vecRe << " ms" << std::endl;

    std::cout << std::left << std::setw(width) << "Total:" << " | " <<  (vecIn + vecRe) << " ms" << std::endl;
    std::cout << std::endl;
    
    // List section
    std::cout << std::left << std::setw(width) << "List:" << std::endl;
    std::cout << std::left << std::setw(width) << "-------------" << std::endl;

    std::cout << std::left << std::setw(width) << "Insertion:" << " | " << listIn << " ms" << std::endl;
    
    std::cout << std::left << std::setw(width) << "Deletion:" << " | "  << listRe << " ms" << std::endl;

    std::cout << std::left << std::setw(width) << "Total:" << " | " << (listIn + listRe) << " ms"<< std::endl;
    std::cout << std::endl;

    // Performance difference section
    std::cout << std::left << std::setw(width) << "Performance Difference:" << " | " << (listIn + listRe - vecIn - vecRe) << " ms"<< std::endl;
        
    return 0;
}
