template <class T>
struct Node {
    T val;
    Node *next; 
};

template <class T>
struct LinkedList {
    int N;

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
        N = 0;
    }

    void init(const T _init[], int _siz) {
        N = _siz;
        
        for (int i = 0; i < N; i++) {
            Node<T> *t = new Node<T>;
            t->val = _init[i];
            t->next = nullptr;
            if (tail == nullptr) {

            } else {
                tail->next = t;
                tail = t;
            }
        }
    }

    void insert(int _x, const T &_val) {
        assert(0 <= x && x < N);

        for (int i = 0; i < N; i++) {

        }
        N++;
    }

    constexpr T operator[](int x) {
        assert(0 <= x && x < N);

        Node<T> t = head;
        for (int i = 0; i < x; i++) {
            t = t->next;       
        }
        return t->val;
    }

    constexpr void operator+=(const LinkedList<T> &_L) {
        
    }

};