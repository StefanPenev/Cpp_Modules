#include "PmergeMe.hpp"
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <cerrno>
#include <climits>
#include <cstdio>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { static_cast<void>(other); }
PmergeMe::~PmergeMe() {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { static_cast<void>(other); return *this; }

void PmergeMe::validateAndBenchmarkSort(int argc, char** argv) {
    checkInput(argc, argv);

    std::vector<unsigned int> vecInput;
    std::deque<unsigned int> deqInput;

    for (int i = 1; i < argc; ++i) {
        std::istringstream ss(argv[i]);
        long val = -1;
        ss >> val;
        if (val <= 0 || !ss || ss.peek() != EOF || val > static_cast<long>(UINT_MAX)) {
            std::cerr << "Error" << std::endl;
            std::exit(1);
        }
        vecInput.push_back(static_cast<unsigned int>(val));
        deqInput.push_back(static_cast<unsigned int>(val));
    }

    printContainer("Before:", vecInput);

    clock_t startVec = clock();
    fordJohnsonSortVector(vecInput);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    fordJohnsonSortDeque(deqInput);
    clock_t endDeq = clock();

    printContainer("After:", vecInput);

    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << vecInput.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deqInput.size()
              << " elements with std::deque : " << timeDeq << " us" << std::endl;
}

void PmergeMe::checkInput(int argc, char** argv) {
    (void) argv;
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        std::exit(1);
    }
}

// Insertion sort for small vector ranges [left, right)
void PmergeMe::insertionSortVector(std::vector<unsigned int>& container, size_t left, size_t right) {
    for (size_t i = left + 1; i < right; ++i) {
        unsigned int key = container[i];
        size_t j = i;
        while (j > left && container[j - 1] > key) {
            container[j] = container[j - 1];
            --j;
        }
        container[j] = key;
    }
}

// Insertion sort for small deque ranges [left, right)
void PmergeMe::insertionSortDeque(std::deque<unsigned int>& container, size_t left, size_t right) {
    for (size_t i = left + 1; i < right; ++i) {
        unsigned int key = container[i];
        size_t j = i;
        while (j > left && container[j - 1] > key) {
            container[j] = container[j - 1];
            --j;
        }
        container[j] = key;
    }
}

std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t n) {
    std::vector<size_t> indices;
    if (n == 0) return indices;
    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    // Generate Jacobsthal numbers up to n
    while (jacob.back() < n) {
        jacob.push_back(jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2]);
    }
    std::vector<bool> used(n, false);
    // First: Jacobsthal indices in reverse order
    for (size_t j = jacob.size() - 1; j > 0; --j) {
        size_t idx = jacob[j];
        if (idx < n && !used[idx]) {
            indices.push_back(idx);
            used[idx] = true;
        }
    }
    // Second: fill in remaining indices
    for (size_t i = 0; i < n; ++i) {
        if (!used[i]) indices.push_back(i);
    }
    return indices;
}

std::vector<unsigned int>::iterator PmergeMe::binaryInsertVector(
    std::vector<unsigned int>& container,
    unsigned int value,
    size_t left,
    size_t right)
{
    std::vector<unsigned int>::iterator low = container.begin() + left;
    std::vector<unsigned int>::iterator high = container.begin() + right;
    while (low < high) {
        std::vector<unsigned int>::iterator mid = low + (high - low) / 2;
        if (*mid < value)
            low = mid + 1;
        else
            high = mid;
    }
    return container.insert(low, value);
}

std::deque<unsigned int>::iterator PmergeMe::binaryInsertDeque(
    std::deque<unsigned int>& container,
    unsigned int value,
    size_t left,
    size_t right)
{
    std::deque<unsigned int>::iterator low = container.begin() + left;
    std::deque<unsigned int>::iterator high = container.begin() + right;
    while (low < high) {
        std::deque<unsigned int>::iterator mid = low + (high - low) / 2;
        if (*mid < value)
            low = mid + 1;
        else
            high = mid;
    }
    return container.insert(low, value);
}

void PmergeMe::fordJohnsonSortVector(std::vector<unsigned int>& container) {
    size_t n = container.size();
    if (n <= 1) return;
    // Use insertion sort for small n to avoid recursion overhead
    if (n <= 10) {
        insertionSortVector(container, 0, n);
        return;
    }

    std::vector<size_t> mainIdx, pendIdx;
    // Pairing and chain-building in a single readable loop
    for (size_t i = 0; i + 1 < n; i += 2) {
        size_t maxIdx = container[i] < container[i + 1] ? i + 1 : i;
        size_t minIdx = container[i] < container[i + 1] ? i : i + 1;
        mainIdx.push_back(maxIdx);
        pendIdx.push_back(minIdx);
    }
    if (n % 2) mainIdx.push_back(n-1);

    std::vector<unsigned int> mainChain;
    mainChain.reserve(mainIdx.size());
    for (size_t i = 0; i < mainIdx.size(); ++i)
        mainChain.push_back(container[mainIdx[i]]);
    fordJohnsonSortVector(mainChain);

    std::vector<size_t> jacobOrder = generateJacobsthalIndices(pendIdx.size());
    for (size_t k = 0; k < jacobOrder.size(); ++k) {
        size_t idx = jacobOrder[k];
        if (idx >= pendIdx.size()) continue;
        unsigned int value = container[pendIdx[idx]];
        binaryInsertVector(mainChain, value, 0, mainChain.size());
    }
    std::swap(container, mainChain);
}

void PmergeMe::fordJohnsonSortDeque(std::deque<unsigned int>& container) {
    size_t n = container.size();
    if (n <= 1) return;
    // Use insertion sort for small n to avoid recursion overhead
    if (n <= 10) {
        insertionSortDeque(container, 0, n);
        return;
    }

    std::vector<size_t> mainIdx, pendIdx;
    // Pairing and chain-building in a single readable loop
    for (size_t i = 0; i + 1 < n; i += 2) {
        size_t maxIdx = container[i] < container[i + 1] ? i + 1 : i;
        size_t minIdx = container[i] < container[i + 1] ? i : i + 1;
        mainIdx.push_back(maxIdx);
        pendIdx.push_back(minIdx);
    }
    if (n % 2) mainIdx.push_back(n-1);

    std::deque<unsigned int> mainChain;
    mainChain.resize(mainIdx.size());
    for (size_t i = 0; i < mainIdx.size(); ++i)
        mainChain[i] = container[mainIdx[i]];
    fordJohnsonSortDeque(mainChain);

    std::vector<size_t> jacobOrder = generateJacobsthalIndices(pendIdx.size());
    for (size_t k = 0; k < jacobOrder.size(); ++k) {
        size_t idx = jacobOrder[k];
        if (idx >= pendIdx.size()) continue;
        unsigned int value = container[pendIdx[idx]];
        binaryInsertDeque(mainChain, value, 0, mainChain.size());
    }
    std::swap(container, mainChain);
}