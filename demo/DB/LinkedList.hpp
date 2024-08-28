// TODO

template <class T>
struct Node {
    T val;
    Node *next; 
};

template <class T>
struct LinkedList {
    int siz;

    Node<T> *head;
    Node<T> *tail;

    LinkedList() {}
    
    LinkedList(const T _init[], const int _siz) {
        init(_init, _siz);
    }
    
    ~LinkedList() {}

    void init() {
        head = nullptr;
        tail = nullptr;
        siz = 0;
    }

    void init(const T _init[], int _siz) {
        head = nullptr;
        tail = nullptr;
        siz = _siz;
        
        for (int i = 0; i < siz; i++) {
            Node<T> *t = new Node<T>;
            t->val = _init[i];
            t->next = nullptr;
            
            if (tail == nullptr) {
                head = tail = t;
            } else {
                tail->next = t;
                tail = t;
            }
        }
    }

    bool insert(int _x, const T &_val) {
        if (_x < 0 || _x >= siz) {
            return false;
        }

        Node<T> *t = new Node<T>;
        for (int i = 0; i < siz; i++) {
            t = t->next;
        }
        siz++;
    }

    void push_back(const T &_val) {
        insert(siz, _val);
    }

    void push_front(const T _val) {
        insert(0, _val);
    }

    int size() { return siz; }
    
    void clear() {
        siz = 0;
        head = tail = nullptr;
    }

    constexpr T operator[](unsigned x) {
        Node<T> *t = head;
        for (int i = 0; i < x && t != nullptr; i++) {
            t = t->next;       
        }
        return t->val;
    }

    constexpr void operator+=(const LinkedList<T> &_L) {
        tail->next = _L.head;
        siz += _L.siz;
    }
};

template<class T>
constexpr LinkedList<T> operator+(const LinkedList<T> &A, const LinkedList<T> &B) {
    LinkedList<T> C;
    C.head = A.head;
    C.tail = B.tail;
    A.tail->next = B.head;
    C.siz = A.siz + B.siz;
    return C;
}
