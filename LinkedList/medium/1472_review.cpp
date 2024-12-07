class BrowserHistory {
public:
    struct page{
        string s;
        struct page* next;
        struct page* prev;
    };
    struct page* head, *current;

    BrowserHistory(string homepage) {
        head = new struct page();
        head -> s = homepage;
        head -> next = NULL;
        head -> prev = NULL;
        current = head;
    }
    
    void visit(string url) {
        current -> next = new struct page();
        current -> next -> prev = current;
        current -> next -> s = url;
        current -> next -> next = NULL;
        current = current -> next;
    }
    
    string back(int steps) {
        int i = steps;
        while(current && i > 0){
            current = current -> prev;
            i --;
        }
        if(!current) current = head;
        return current -> s;
    }
    
    string forward(int steps) {
        struct page* tail = current;
        int i = 0;
        while(current && i < steps){
            tail = current;
            current = current -> next;
            i ++;
        }
        if(!current) current = tail;
        return current -> s;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
