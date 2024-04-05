#pragma once
#include <Base_Table.h>
#include <iostream>
#include <string>

using namespace std;

template <typename TKey, typename TValue>
class  UnorderedTable_mas : public Base_Table<TKey, TValue> {
private:
    size_t index;
    struct recording {
        TKey key;
        TValue* value;
    };
    vector<recording> data{};

public:
    size_t size() const noexcept { return data.size(); }
    TValue& operator[](size_t pos) { return *data[pos].value; } 
    UnorderedTable_mas() : index(0) { count = 0; }

    bool IsFull() const override {
        if (count == TabMaxSize)
            return true;
        else
            return false;
    }

    TValue* Find(TKey key) override {
        for (auto& val : data)
            if (val.key == key) return val.value;
        return nullptr;
    }

    void Insert(TKey key, TValue value) override {
        TValue* newValue = new TValue(value);
        recording tab = { key, newValue };
        data.push_back(tab);
        this->count++;
    }

    void Delete(TKey key) override {
        bool found = false;
        size_t i = 0;
        for (; i < data.size(); ++i) {
            if (data[i].key == key) {
                found = true;
                delete data[i].value;
                break;
            }
        }

        if (found) {
            data.erase(data.begin() + i);
            count--;
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
        index = 0;
        return index;
    }

    int IsTabEnded() const override { return index >= data.size(); }

    int GoNext() override {
        index++;
        return index;
    }

    TKey GetKey() const override { return data[index].key; }

    TValue GetValuePtr() const override { return *data[index].value; }

    ostream& Print(ostream& os) const override {
        os << "Не упорядоченная таблица на векторе:" << endl;
        for (size_t i = 0; i < data.size(); ++i) {
            os << " Ключ: " << data[i].key << " Значение: " << *data[i].value << endl;
        }
        return os;
    }
};

template <typename TKey, typename TValue>
ostream& operator<<(ostream& os, const UnorderedTable_mas<TKey, TValue>& table) {
    return table.Print(os);
}
