#include "../include/ExpressionTree.hpp"

ExpressionTree::ExpressionTree() : root(nullptr) {}

ExpressionTree::ExpressionTree(const std::string &expression) {
    std::string postfix = get_postfix_expr(expression);
    root = build_tree(postfix);
}

Node<char> *ExpressionTree::get_root() const {
    return this->root;
}

std::string ExpressionTree::get_postfix_expr(const std::string &expr) {
    std::string postfix = "";
    Deque<char> storage;

    for (size_t i = 0; i != expr.size(); ++i) {
        char c = expr[i];

        if (!is_operator(c) && c != '(' && c != ')') {
            postfix += c;
        } else if (c == '(') {
            storage.push_front(c);
        } else if (c == ')') {
            while (storage.begin().get_node()->data != '(') {
                postfix += storage.pop_front();
            }
            storage.pop_front();
        } else {
            if (c == '-' && expr[i - 1] == '(') c = '~';

            while (!storage.empty() && (find_priority(storage.begin().get_node()->data) >= find_priority(c))) {
                postfix += storage.pop_front();
            }
            storage.push_front(c);
        }
    }

    while (!storage.empty()) {
        postfix += storage.pop_front();
    }
    return postfix;
}

Node<char> *ExpressionTree::build_tree(const std::string &postfix_notation) {
    if (postfix_notation.length() == 0) return nullptr;

    Deque<Node<char> *> storage;

    for (char c: postfix_notation) {
        if (c == '~') {
            Node<char> *node_x = storage.pop_front();

            Node<char> *node = new Node<char>('-', nullptr, node_x);
            storage.push_front(node);
        } else if (is_operator(c)) {
            Node<char> *node_x = storage.pop_front();

            Node<char> *node_y = storage.pop_front();

            Node<char> *node = new Node<char>(c, node_y, node_x);
            storage.push_front(node);
        } else {
            storage.push_front(new Node<char>(c));
        }
    }

    return storage.begin().get_node()->data;
}

void ExpressionTree::print_postfix_expr(Node<char> *curr_node) const {
    if (curr_node == nullptr) return;

    print_postfix_expr(curr_node->prev);
    print_postfix_expr(curr_node->next);
    std::cout << curr_node->data;
}

void ExpressionTree::print_infix_expr(Node<char> *curr_node) const {
    if (curr_node == nullptr) return;

    if (is_operator(curr_node->data)) {
        std::cout << '(';
    }

    print_infix_expr(curr_node->prev);
    std::cout << curr_node->data;
    print_infix_expr(curr_node->next);

    if (is_operator(curr_node->data)) {
        std::cout << ')';
    }
}

void ExpressionTree::delete_branch(Node<char> *curr_node) {
    if (curr_node == nullptr) return;

    delete_branch(curr_node->prev);
    delete_branch(curr_node->next);

    curr_node = nullptr;
    delete curr_node;
}

void ExpressionTree::print_tree(Node<char> *curr_node, const size_t &height) const {
    if (curr_node != nullptr) {
        print_tree(curr_node->next, height + 1);
        for (size_t i = 0; i < height; ++i) {
            std::cout << "\t";
        }
        std::cout << curr_node->data << "\n";
        print_tree(curr_node->prev, height + 1);
    }
}

size_t ExpressionTree::find_priority(char c) const {
    if (c == '~') {
        return 4;
    } else if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    }

    return 0;
}

bool ExpressionTree::is_operator(char o) const {
    return (o == '+' || o == '-' || o == '*' || o == '/' || o == '^');
}

ExpressionTree::~ExpressionTree() {
    delete_branch(root);
}

Node<char> *ExpressionTree::lab_task(Node<char> *curr_node) {
    if (curr_node == nullptr) return curr_node;

    if (curr_node->data == '^' and curr_node->next and curr_node->next->data > '1') {
        Node<char> *new_node = new Node<char>('*');
        new_node->prev = curr_node->prev;
        new_node->next = curr_node;
        --new_node->next->next->data;

        new_node->prev = lab_task(new_node->prev);
        new_node->next = lab_task(new_node->next);

        return new_node;
    } else if (curr_node->data == '^' and curr_node->next and curr_node->next->data == '1') {
        Node<char> *new_node = curr_node->prev;

        return new_node;
    }

    curr_node->prev = lab_task(curr_node->prev);
    curr_node->next = lab_task(curr_node->next);
    return curr_node;
}

void ExpressionTree::lab_task() {
    root = lab_task(root);
}
