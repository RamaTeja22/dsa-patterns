class BrowserHistory {
public:
    // Two stacks, one for current tracing & other for history tracing
    stack<string>curr,history;
    BrowserHistory(string homepage) {
        curr.push(homepage);
    }
    
    void visit(string url) {
        curr.push(url);
        while(!history.empty()){
            history.pop();
        }
    }
    
    string back(int steps) {
        while(steps-- && !curr.empty()){
        if(curr.size()==1)
        return curr.top();
        string now=curr.top();
        curr.pop();
        history.push(now);
        }
        return curr.top();
    }
    
    string forward(int steps) {
        while(steps-- && !history.empty()){
            string now=history.top();
            history.pop();
            curr.push(now);
        }
        return curr.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */