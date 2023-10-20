class NestedIterator {
private:
    std::vector<int> flattened;
    int index;
    
    std::vector<int> flatten(const std::vector<NestedInteger>& nested) {
        std::vector<int> result;
        for (const auto& ni : nested) {
            if (ni.isInteger()) {
                result.push_back(ni.getInteger());
            } else {
                auto subList = flatten(ni.getList());
                result.insert(result.end(), subList.begin(), subList.end());
            }
        }
        return result;
    }

public:
    NestedIterator(std::vector<NestedInteger> nestedList) {
        flattened = flatten(nestedList);
        index = 0;
    }

    int next() {
        return flattened[index++];
    }

    bool hasNext() {
        return index < flattened.size();
    }
};