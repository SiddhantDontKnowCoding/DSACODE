#include <iostream>
#include <vector>

class Set {
private:
    std::vector<int> _s;

public:
    Set(int initElementsCount) {
        for (int i = 0; i < initElementsCount; ++i) {
            int e;
            std::cout << "Enter Element " << (i + 1) << ": ";
            std::cin >> e;
            add(e);
        }
    }

    std::vector<int> get_set() const {
        return _s;
    }

    void print() const {
        std::cout << "\n{ ";
        for (size_t i = 0; i < _s.size(); ++i) {
            std::cout << _s[i];
            if (i != _s.size() - 1) {
                std::cout << " , ";
            }
        }
        std::cout << " }\n";
    }

    size_t size() const {
        return _s.size();
    }

    bool contains(int e) const {
        return std::find(_s.begin(), _s.end(), e) != _s.end();
    }

    bool isEmpty() const {
        return _s.empty();
    }

    void add(int e) {
        if (!contains(e)) {
            _s.push_back(e);
        }
    }

    void remove(int e) {
        auto it = std::find(_s.begin(), _s.end(), e);
        if (it != _s.end()) {
            _s.erase(it);
        }
    }

    bool equals(const Set& setB) const {
        if (_s.size() != setB._s.size()) {
            return false;
        }
        return isSubsetOf(setB);
    }

    bool isSubsetOf(const Set& setB) const {
        for (int e : _s) {
            if (!setB.contains(e)) {
                return false;
            }
        }
        return true;
    }

    bool isProperSubset(const Set& setB) const {
        return isSubsetOf(setB) && !setB.isSubsetOf(*this);
    }

    Set unionWith(const Set& setB) const {
        Set newSet(0);
        for (int e : _s) {
            newSet.add(e);
        }
        for (int e : setB._s) {
            newSet.add(e);
        }
        return newSet;
    }

    Set intersectWith(const Set& setB) const {
        Set newSet(0);
        for (int e : _s) {
            if (setB.contains(e)) {
                newSet.add(e);
            }
        }
        return newSet;
    }

    Set differenceWith(const Set& setB) const {
        Set newSet(0);
        for (int e : _s) {
            if (!setB.contains(e)) {
                newSet.add(e);
            }
        }
        return newSet;
    }
};
