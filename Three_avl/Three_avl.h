#pragma once
#include "..\\Base_Table\Base_Table.h"
#include <iostream>
#include <utility>

using namespace std;

template <typename TKey, typename TValue>
class AVL_Tree : public Base_Table<TKey, TValue> {
private:
    struct Node {
        TKey key;
        TValue value;
        Node* left;
        Node* right;
        int height;
    };

    Node* root;
    vector<pair<TKey, TValue>> data; // Вектор для хранения данных

    int height(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int balanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node* insert(Node* node, TKey key, TValue value) {
        if (node == nullptr) {
            Node* newNode = new Node;
            newNode->key = key;
            newNode->value = value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            newNode->height = 1;
            return newNode;
        }

        if (key < node->key)
            node->left = insert(node->left, key, value);
        else if (key > node->key)
            node->right = insert(node->right, key, value);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        if (balance > 1 && key < node->left->key)
            return rotateRight(node);

        if (balance < -1 && key > node->right->key)
            return rotateLeft(node);

        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, TKey key) {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else {
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->value = temp->value;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = balanceFactor(root);

        if (balance > 1 && balanceFactor(root->left) >= 0)
            return rotateRight(root);

        if (balance > 1 && balanceFactor(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        if (balance < -1 && balanceFactor(root->right) <= 0)
            return rotateLeft(root);

        if (balance < -1 && balanceFactor(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    void destroyTree(Node* root) {
        if (root != nullptr) {
            destroyTree(root->left);
            destroyTree(root->right);
            delete root;
        }
    }

public:
    AVL_Tree() : root(nullptr) {}

    bool IsFull() const override {
        return false;
    }

    TValue* Find(TKey key) override {
        Node* current = root;
        while (current != nullptr) {
            if (key == current->key)
                return &(current->value);
            else if (key < current->key)
                current = current->left;
            else
                current = current->right;
        }
        return nullptr;
    }

    void Insert(TKey key, TValue value) override {
        root = insert(root, key, value);
        data.push_back(make_pair(key, value)); // Добавляем пару ключ-значение в вектор
    }

    void Delete(TKey key) override {
        root = deleteNode(root, key);
        // Также нужно удалить соответствующую пару из вектора
        auto it = find_if(data.begin(), data.end(), [key](const auto& pair) { return pair.first == key; });
        if (it != data.end())
            data.erase(it);
    }

    int Reset(void) override {
        destroyTree(root);
        root = nullptr;
        data.clear(); // Очищаем вектор
        return 0;
    }

    int IsTabEnded(void) const override {
        return currentIndex >= data.size();
    }

    int GoNext(void) override {
        currentIndex++;
        return currentIndex;
    }

    TKey GetKey(void) const override {
        return data[currentIndex].first;
    }

    TValue GetValuePtr(void) const override {
        return data[currentIndex].second;
    }

    ostream& Print(ostream& os) const override {
        os << "Авл дерево:" << endl;
        for (size_t i = 0; i < data.size(); ++i) {
            os << " Ключ: " << data[i].first << " Значение: ";
            os << static_cast<ostream&>(data[i].second); // Приведение типа TPolinom к ostream
            os << endl;
        }
        return os;
    }



    ~AVL_Tree() {
        destroyTree(root);
    }
};

template <typename TKey, typename TValue>
ostream& operator<<(ostream& os, const AVL_Tree<TKey, TValue>& table) {
    return table.Print(os);
}