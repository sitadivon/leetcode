class IntStack{
public:
    IntStack() = default;
    ~IntStack();
    void push(int item);
    int pop();
    int get_top();
    int sum_top2() const;
    int sum_all();
private:
    struct Node{
        int item;
        Node *next;
    };
    // Node *top;
    Node *top = nullptr;        // Modifty0: run successful in VS, but not pass on leetcode.
};

class Solution {
public:
    int calPoints(vector<string>& ops) {
        IntStack sk;
        for(auto &op: ops){
            /*
            switch(op){
                case "+":   sk.push(sk.sum_top2()); break;        
                case "D":   sk.push(2 * sk.top());  break;
                case "C":   sk.pop();               break;
                default:    sk.push(stoi(op));
            }
            */
            if(op == "+")
                sk.push(sk.sum_top2());
            else if(op == "D")
                // sk.push(2 * sk.top());  
                sk.push(2 * sk.get_top()); // Modify1
            else if(op == "C")
                sk.pop();
            else
                sk.push(stoi(op));
        }
        return sk.sum_all();
    }
};



void IntStack::push(int item){
    auto old_top = top;
    // shared_ptr<Node> new_node(new Node());
    Node *new_node = new Node();
    new_node->item = item;
    if(top != nullptr)
        new_node->next = old_top;
    top = new_node;
}

int IntStack::pop(){
    int item = top->item;
    Node *old_top = top;
    top = top->next;
    delete old_top;
    return item;
}
int IntStack::get_top(){
    return top->item;
}

int IntStack::sum_top2() const{
    return top->item + top->next->item;
}

int IntStack::sum_all(){
    int _sum = 0;
    Node *temp;
    while(top != nullptr){
        _sum += top->item;
        temp = top;
        top = top->next;
        delete temp;
    }
    return _sum;
}

IntStack::~IntStack(){
    Node *temp;
    while(top != nullptr){
        temp = top;
        top = top->next;
        delete temp;
    }
}