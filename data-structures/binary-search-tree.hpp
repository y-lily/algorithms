#include <functional>
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


    void inorder_walk(std::shared_ptr<Node>& x, const std::function<void(T)>& action) {
        if (!x) { return; }

        inorder_walk(x->left, action);
        action(x->key);
        inorder_walk(x->right, action);
    }

    std::shared_ptr<Node> search(const std::shared_ptr<Node>& x, const T& k) const {
        if ((!x) || (k == x->key)) { return x; }

        return (k < x->key) ? (search(x->left, k)) : (search(x->right, k));
    }

    std::shared_ptr<Node> iterative_search(std::shared_ptr<Node> x, const T& k) const {
        while ((x) && (k != x->key))
            x = (k < x->key) ? (x->left) : (x->right);

        return x;
    }

    std::shared_ptr<Node> minimum(std::shared_ptr<Node> x) const {
        for (; x->left; x = x->left)
            ;
        return x;
    }

    std::shared_ptr<Node> maximum(std::shared_ptr<Node> x) const {
        for (; x->right; x = x->right)
            ;
        return x;
    }

    std::shared_ptr<Node> predecessor(std::shared_ptr<Node> x) const {
        if (x->left) { return maximum(x->left); }

        auto p = x->parent;
        while ((p) && (x == p->left)) {
            x = p;
            p = x->parent;
        }

        return p;
    }

    std::shared_ptr<Node> successor(std::shared_ptr<Node> x) const {
        if (x->right) { return minimum(x->right); }

        auto s = x->parent;
        while ((s) && (x == s->right)) {
            x = s;
            s = x->parent;
        }

        return s;
    }

    void insert(const T& v) {
        if (!root) {
            root = std::make_shared<Node>(Node { v });
            return;
        }

        auto x = root;
        auto p = x;

        while (x) {
            p = x;
            x = (v < x->key) ? (x->left) : (x->right);
        }

        x = std::make_shared<Node>(Node { v });
        x->parent = p;

        if ((x->key) < (p->key))
            p->left = x;
        else
            p->right = x;
    }

    // void transplant(std::shared_prt<Node>& x, std::shared_ptr<Node>& y);
    // void remove(std::shared_ptr<Node>& x);

public:

    // void push(const T& value);
    // T& pop(const T& value);
    // bool contains(const T& value) const;
    // T min() const;
    // T max() const;
    // T root_value() const;
};
