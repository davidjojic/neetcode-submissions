class PrefixTree {
private:
    struct Polje{
        unordered_map<char, Polje*> reci;
        bool krajReci;

        Polje(){
            krajReci = false;
        }
    };

    Polje* pocetak;

public:
    PrefixTree() {
        pocetak = new Polje();
    }
    
    void insert(string word) {
        Polje* tren = pocetak;

        for(char c : word){
            auto ptr = tren->reci.find(c);

            if(ptr == tren->reci.end()){
                tren->reci[c] = new Polje();
            }

            tren = tren->reci[c];
        }

        tren->krajReci = true;
    }
    
    bool search(string word) {
        Polje* tren = pocetak;

        for(char c : word){
            auto ptr = tren->reci.find(c);

            if(ptr == tren->reci.end())
                return false;

            tren = tren->reci[c];
        }

        return tren->krajReci;
    }
    
    bool startsWith(string prefix) {
        Polje* tren = pocetak;

        for(char c : prefix){
            auto ptr = tren->reci.find(c);

            if(ptr == tren->reci.end())
                return false;

            tren = tren->reci[c];
        }

        return true;
    }
};