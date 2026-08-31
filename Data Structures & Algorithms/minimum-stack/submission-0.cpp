class MinStack {
private:
    list<int> lista;
    list<int> minlista;
public:
    MinStack() {
    }
    
    void push(int val) {
        lista.push_front(val);
        if(minlista.empty()){
            minlista.push_front(val);
        }else{
            minlista.push_front(min(val,*minlista.begin()));
        }
    }
    
    void pop() {
        lista.erase(lista.begin());
        minlista.erase(minlista.begin());
    }
    
    int top() {
        return *lista.begin();
    }
    
    int getMin() {
        return *minlista.begin();
    }
};
