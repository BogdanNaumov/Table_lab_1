#pragma once
#include "Base_Table.h"

#include <algorithm>
#include <iostream>
#include <locale>
#include <string>
using namespace std;

template <typename TKey, typename TValue>
class SortArrayTable : public Base_Table<TKey, TValue> {
private:
    size_t currentIndex;
    struct TabRec {
        TKey key;
        TValue* value;
    };
    vector<TabRec> data{};

public:
    size_t size() const noexcept { return data.size(); }
    TValue& operator[](size_t pos) { return data[pos].value; }
    SortArrayTable() : currentIndex(0) {}

    ~SortArrayTable() {
        for (auto& tab : data) {
            delete tab.value;
        }
    }

    TValue* Find(TKey key) override {
        size_t low = 0;
        size_t high = data.size() - 1;

        while (low <= high) {
            size_t mid = low + (high - low) / 2;
            if (data[mid].key == key) {
                return data[mid].value;
            }
            else if (data[mid].key < key) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return nullptr;
    }

    void Insert(TKey key, TValue value) override {
        size_t low = 0;
        size_t high = data.size();
        while (low < high) {
            size_t mid = low + (high - low) / 2;
            if (data[mid].key < key) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        //if (low < data.size() && data[low].key == key) {
        //    throw invalid_argument("Elements is already exist");
        //    return;
        //}

        TValue* newValue = new TValue(value);
        data.insert(data.begin() + low, { key, newValue });
        this->count++;
    }
    
    bool IsFull() const override { return size() >= TabMaxSize; }

    void Delete(TKey key) override {
        size_t low = 0;
        size_t high = data.size();
        while (low < high) {
            size_t mid = low + (high - low) / 2;
            if (data[mid].key < key) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        if (low < data.size() && data[low].key == key) {
            delete data[low].value;
            data.erase(data.begin() + low);

            for (size_t i = low; i < data.size(); ++i) {
                if (data[i].key > key) {
                    data[i].key--; 
                }
            }
            this->count--;
        }
        else {
            throw invalid_argument("Elements is not found");
        }
    }
    


    int Reset() override {
        for (auto& tab : data) {
            delete tab.value;
        }
        data.clear(); 
        currentIndex = 0;
        return currentIndex;
    }

    int IsTabEnded() const override { return currentIndex >= data.size(); }

    int GoNext() override {
        currentIndex++;
        return currentIndex;
    }

    TKey GetKey() const override { return data[currentIndex].key; }
    TValue GetValuePtr() const override { return *data[currentIndex].value; }

    ostream& Print(ostream& os) const override {
        os << "Упорядоченная таблица на векторе:" << endl;
        for (size_t i = 0; i < data.size(); ++i) {
            os << " Ключ: " << data[i].key << " Значение: " << *data[i].value << endl;
        }
        return os;
    }
};

template <typename TKey, typename TValue>
ostream& operator<<(ostream& os, const SortArrayTable<TKey, TValue>& table) {
    return table.Print(os);
}