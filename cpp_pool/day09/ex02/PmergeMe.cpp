#include "PmergeMe.hpp"

CustomSort::CustomSort(std::string expression) : _expression(expression) {
    parse();
}

CustomSort::CustomSort(const CustomSort& other) {
    *this = other;
}

CustomSort& CustomSort::operator=(const CustomSort& other) {
    _expression = other._expression;
    return *this;
}

CustomSort::~CustomSort() {}

void CustomSort::parse() {
    std::set<int> dup;

    std::istringstream ss(_expression);
    std::string token;

    while (ss >> token) {
        char *endptr;
        long int num = strtol(token.c_str(), &endptr, 10);
        if (*endptr != '\0' || num < 0)
            throw std::runtime_error("Error: Bad Expression");
        dup.insert(num);
        vec.push_back(num);
        
    }
    if (dup.size() != vec.size())
        throw std::runtime_error("Error: Duplicate Element");

    deque.assign(vec.begin(), vec.end());

}

void CustomSort::makePairs(std::vector<std::pair<int, int> >& pairs) {
    for (size_t i = 0; i < vec.size(); i += 2) {
        if (i + 1 < vec.size()) {
            int lesser = std::min(vec[i], vec[i + 1]);
            int greater = std::max(vec[i], vec[i + 1]);
            pairs.push_back(std::make_pair(lesser, greater));
        }
    }
}

void CustomSort::merge(std::vector<std::pair<int, int> >& pairs, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    std::vector<std::pair<int, int> > left(n1);
    std::vector<std::pair<int, int> > right (n2);

    for (int i = 0; i < n1; i++)
        left[i] = pairs[start + i];
    for (int j = 0; j < n2 ; j++)
        right[j] = pairs[mid + 1 + j];

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2) {
        if (left[i].second <= right[j].second) {
            pairs[k] = left[i];
            i++;
        } else {
            pairs[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        pairs[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        pairs[k] = right[j];
        k++;
        j++;
    }
}

void CustomSort::mergeSort(std::vector<std::pair<int, int> >& pairs, int start, int end) {
    if (start >= end)
        return ;
    int mid = start + (end - start) / 2;
    mergeSort(pairs, start, mid);
    mergeSort(pairs, mid + 1, end);
    merge(pairs, start, mid, end);
}


void CustomSort::sortVec() {
    std::clock_t start = std::clock();

    std::vector<std::pair<int, int> > pairs;
    int unpaired = vec.size() % 2 != 0 ? vec.back() : -1;
    makePairs(pairs);
    // for (size_t i = 0; i < pairs.size(); i++) {
    //     std::cout << "first: " << pairs[i].first << " second: " << pairs[i].second << std::endl;
    // }
    mergeSort(pairs, 0, pairs.size() - 1);
    // for (size_t i = 0; i < pairs.size(); i++) {
    //     std::cout << "first: " << pairs[i].first << " second: " << pairs[i].second << std::endl;
    // }

    std::vector<int> sorted;
    for (size_t i = 0; i < pairs.size(); i++)
        sorted.push_back(pairs[i].second);

    for (size_t i = 0; i < pairs.size(); i++)
        sorted.insert(std::upper_bound(sorted.begin(), sorted.end(), pairs[i].first), pairs[i].first);
    
    if (unpaired != -1)
        sorted.insert(std::upper_bound(sorted.begin(), sorted.end(), unpaired), unpaired);

    std::cout << "After: ";
    for (size_t i = 0; i < sorted.size(); i++) 
        std::cout << sorted[i] << " ";
    std::cout << std::endl;

    std::clock_t end = std::clock();
    double durationInUs = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << vec.size() << " : " << std::fixed << std::setprecision(5) << durationInUs << " us" << std::endl;
}

void CustomSort::makePairs(std::deque<std::pair<int, int> >& pairs) {
    for (size_t i = 0; i < vec.size(); i += 2) {
        if (i + 1 < vec.size()) {
            int lesser = std::min(vec[i], vec[i + 1]);
            int greater = std::max(vec[i], vec[i + 1]);
            pairs.push_back(std::make_pair(lesser, greater));
        }
    }
}

void CustomSort::mergeSort(std::deque<std::pair<int, int> >& pairs, int start, int end) {
    if (start >= end)
        return ;
    int mid = start + (end - start) / 2;
    mergeSort(pairs, start, mid);
    mergeSort(pairs, mid + 1, end);
    merge(pairs, start, mid, end);
}

void CustomSort::merge(std::deque<std::pair<int, int> >& pairs, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    std::deque<std::pair<int, int> > left(n1);
    std::deque<std::pair<int, int> > right (n2);

    for (int i = 0; i < n1; i++)
        left[i] = pairs[start + i];
    for (int j = 0; j < n2 ; j++)
        right[j] = pairs[mid + 1 + j];

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2) {
        if (left[i].second <= right[j].second) {
            pairs[k] = left[i];
            i++;
        } else {
            pairs[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        pairs[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        pairs[k] = right[j];
        k++;
        j++;
    }
}

void CustomSort::sortDeque() {
    std::clock_t start = std::clock();

    std::deque<std::pair<int, int> > pairs;
    int unpaired = deque.size() % 2 != 0 ? deque.back() : -1;
    makePairs(pairs);
    mergeSort(pairs, 0, pairs.size() - 1);
    std::deque<int> sorted;
    for (size_t i = 0; i < pairs.size(); i++)
        sorted.push_back(pairs[i].second);

    for (size_t i = 0; i < pairs.size(); i++)
        sorted.insert(std::upper_bound(sorted.begin(), sorted.end(), pairs[i].first), pairs[i].first);
    
    if (unpaired != -1)
        sorted.insert(std::upper_bound(sorted.begin(), sorted.end(), unpaired), unpaired);

    // for (size_t i = 0; i < sorted.size(); i++) 
    //     std::cout << sorted[i] << " ";
    // std::cout << std::endl;

    std::clock_t end = std::clock();
    double durationInUs = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << deque.size() << " : " << std::fixed << std::setprecision(5) << durationInUs << " us" << std::endl;
}





void CustomSort::print() {
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " " ;
    }
    std::cout << std::endl;
}


