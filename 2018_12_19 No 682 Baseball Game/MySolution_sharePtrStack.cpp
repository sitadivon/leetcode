class IntStack{
public:
    IntStack() = default;
    void push(int item);
    int pop();
    int get_top();      // Add1: need function but not define.
    int sum_top2() const;
    int sum_all();
private:
    struct Node{
        int item;
        shared_ptr<Node> next;
    };
    shared_ptr<Node> top;
};

class Solution {
public:
    int calPoints(vector<string>& ops) {
        IntStack sk;
        for(auto &op: ops){
            /*
            switch(op){
                case "+":   sk.push(sk.sum_top2()); break;          // Delete0: keyword 'case' must follow a integer const expr
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
    shared_ptr<Node> new_node(new Node());
    // Node->item = item;
    new_node->item = item;      // Modify2: slip up slightly
    if(top != nullptr)
        new_node->next = old_top;
    top = new_node;
}

int IntStack::pop(){
    int item = top->item;
    top = top->next;
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
    while(top != nullptr){
        _sum += top->item;
        top = top->next;
    }
    return _sum;
}