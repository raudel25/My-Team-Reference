#include <bits/stdc++.h>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b
#define ll long long
#define vi vector<int>
#define vll vector<long long>

using namespace std;

class Trie
{
private:
    int cant_string;
    int cant_string_me;
    int cant_node;
    char value;
    vector<Trie> children;

    int insert(string s, int ind)
    {
        cant_string_me++;
        int cant_new_node = 0;

        if (ind == s.size())
        {
            cant_string++;
            return 0;
        }

        int find = find_child(s[ind]);

        if (find == -1)
        {
            cant_new_node++;
            children.push_back(Trie(s[ind]));
            find = children.size() - 1;
        }

        ind++;
        int aux = children[find].insert(s, ind);
        cant_node += (aux + cant_new_node);

        return aux + cant_new_node;
    }

    int find_child(char a)
    {
        int find = -1;
        for (int i = 0; i < children.size(); i++)
        {
            if (children[i].value == a)
                find = i;
        }

        return find;
    }

public:
    Trie(char a)
    {
        cant_string = 0;
        cant_node = 0;
        cant_string_me = 0;
        value = a;
    }

    void insert(string s) { insert(s, 0); }

    int cant_words() { return cant_string_me; }

    int size() { return cant_node; }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}