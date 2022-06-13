#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

namespace ariel {

    struct node {
        string str;
        vector<node> tree;
    };

    class iterator {
        vector<string> items;
    public:
        iterator(const vector<string>& items) : items(items) {}

        //get first iterator
        string operator*() {
            return items[0];
        }
        //get pointer to first ellemnt
        string* operator->() {
            return &(items[0]);
        }

        //mekaden and erase 
        iterator& operator++() {
            items.erase(items.begin());
            return *this;
        }

        bool operator!=(const iterator& other) const {
            return items != other.items;
        }

        bool operator==(const iterator& other) const {
            return items == other.items;
        }
    };

    class OrgChart {
    private:
        node root;
        int num;
        node* find(node& n, string father);
    public:
        OrgChart();
        OrgChart(const OrgChart& other);
        OrgChart& operator=(const OrgChart& other);
        OrgChart(OrgChart&& other) = default;
        OrgChart& operator=(OrgChart&& other) = default;
        ~OrgChart() = default;
        OrgChart &add_root(string root);
        OrgChart &add_sub(string father, string son);
        iterator begin_level_order() const ;
        iterator end_level_order() const ;
        iterator begin_reverse_order() const ;
        iterator end_reverse_order() const ;
        iterator begin_preorder() const ;
        iterator end_preorder() const ;
        iterator reverse_order() const ;
        iterator begin() const ; 
        iterator end() const ;
        friend ostream &operator<<(ostream &out, const OrgChart &root);
    };
}
