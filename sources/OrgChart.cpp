#include "OrgChart.hpp"
using namespace std;

namespace ariel{

    //help function to find the father and return the node
    node* OrgChart::find(node& n, string father) {
        if (n.str == father) {
            return &n;
        }

        node* result = NULL;
        for (node& x : n.tree) {
            result = find(x, father);
            if (result != NULL) {
                return result;
            }
        }
        return NULL;
    }
    
    OrgChart::OrgChart() : num(0)
    {}

    OrgChart::OrgChart(const OrgChart& other) {
        this->root = other.root;
        this->num = other.num;
    }

    OrgChart& OrgChart::operator=(const OrgChart& other) {
        this->root = other.root;
        this->num = other.num;
        return *this;
    }

    OrgChart &OrgChart::add_root(string root) {
        this->root.str = root;
        if (num == 0) {
            num++;
        }
        return *this;
    }

    OrgChart &OrgChart::add_sub(string father, string son) {
        node* f = find(root, father);
        if (f == NULL) {
            throw runtime_error("father not found");
        }

        node new_node;
        new_node.str = son;
        f->tree.push_back(new_node);
        num++;

        return *this;
    }
    
    iterator OrgChart::begin() const {
        return begin_level_order();
    }

    iterator OrgChart::end() const {
        return end_level_order();
    }

    iterator OrgChart::begin_level_order() const {
        if (num == 0) {
            return end_level_order();
        }

        vector<string> result;
        queue<node> Q;
        Q.push(root);
        while (!Q.empty()) {
            result.push_back(Q.front().str);
            //push in the node from the end to the beginnig.
            for (node& n : Q.front().tree) {
                Q.push(n);
            }
            Q.pop();
        }

        return iterator(result);
    }

    iterator OrgChart::end_level_order() const {
        // if (num == 0) throw std::exception();
        return iterator(vector<string>());
    }


    //for this fuction i have been helped by this site: https://www.techiedelight.com/reverse-level-order-traversal-binary-tree/#:~:text=Given%20a%20binary%20tree%2C%20print,level%20from%20left%20to%20right.
    iterator OrgChart::begin_reverse_order() const { 
        if (num == 0) {
            return end_reverse_order();
        }

        // create an empty queue and enqueue the root node
        vector<string> result;
        queue<node> Q;
        Q.push(root);

        // loop till queue is empty
        while (!Q.empty()) {
            //iterator insert (iterator position, const value_type& val);
            result.insert(result.begin(), Q.front().str);
             for (int i = (int)Q.front().tree.size() - 1; i >= 0; i--) {
                Q.push(Q.front().tree[(size_t)i]);
            }
            Q.pop();
        }

        return iterator(result);
    }

    iterator OrgChart::end_reverse_order() const {
        // if (num == 0) throw std::exception();
        return iterator(vector<string>());
    }

    //Preorder (Root, Left, Right) - like dfs  with stack
    iterator OrgChart::begin_preorder() const {
        if (num == 0) {
            return end_preorder();
        }
        vector<string> result;
        stack<node> S;
        S.push(root);
        while (!S.empty()) {
            //used to push elements into a vector from the back.
            result.push_back(S.top().str);
            node current = S.top();
            //used to remove and get the element from the front of the stack
            S.pop();
            //we go from end to start
            for (int i = (int)current.tree.size() - 1; i >= 0; i--) {
                S.push(current.tree[(size_t)i]);
            }
        }
        return iterator(result);
    }

    iterator OrgChart::end_preorder() const {
        return iterator(vector<string>());
    }

    iterator OrgChart::reverse_order() const {
        return end_reverse_order();
    }

    ostream &operator<<(ostream &out, const OrgChart &root){
        if(root.num == 0){
            return out;
        }

        for (auto it = root.begin_level_order(); it != root.end_level_order(); ++it)
        {
            out << (*it) << " " ;
        }
        return out;
    }

}
