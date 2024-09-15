// TODO

template <class T>
struct Node {
    T val = {};
    Node *prev = nullptr;
    Node *next = nullptr;
};

struct LinkedList {
    size_t siz;

    Node *head;
    Node *tail;

    LinkedList() {
        init();
    }
    
    ~LinkedList() {}

    void init() {
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
        siz = 0;
    }

    size_t size() {
        return siz;
    }

    template <class T>
    bool insert(Node *_p, T _val) {
        Node q = new Node();

        
    }

    void push_back(const T &_val) {
    }

    void push_front(const T _val) {
    }

};