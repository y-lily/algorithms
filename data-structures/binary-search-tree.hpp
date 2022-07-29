#include <functional>
#include <iostream>
#include <memory>


template <typename T>
class BSTree {
private:
    struct Node {
        T key;
        std::shared_ptr<Node> parent = nullptr;
        std::shared_ptr<Node> left = nullptr;
        std::shared_ptr<Node> right = nullptr;

        Node(const T& key) : key { key } {}
    };

    std::shared_ptr<Node> root = nullptr;


    void inorder_walk(std::shared_ptr<Node>& x, std::function<void(T)> action) {
        if (!x) { return; }

        inorder_walk(x->left, action);
        action(x->key);
        inorder_walk(x->right, action);
    }

    std::shared_ptr<Node> search(const std::shared_ptr<Node>& x, const T& k) {
        if (!x || k == x->key) { return x; }

        return k < x->key ? search(x->left, k) : search(x->right, k);
    }

    std::shared_ptr<Node> iterative_search(std::shared_ptr<Node> x, const T& k) {
        while ((x) && (k != x->key)) {
            x = k < x->key ? x->left : x->right;
        }

        return x;
    }

public:

};
