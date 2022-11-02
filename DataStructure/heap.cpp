#include <bits/stdc++.h>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b
#define ll long long
#define vi vector<int>
#define vll vector<long long>

using namespace std;

struct node
{

private:
    int _valor;

public:
    node(int n)
    {
        _valor = n;
    }

    int get_valor() { return _valor; }
};

class Heap
{

private:
    vector<node> p;
    int _size;

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int father(int i) { return (i - 1) / 2; }

    void heapify_top_min(int i)
    {
        if (i >= _size / 2)
            return;
        if (p[i].get_valor() > p[left(i)].get_valor() || p[i].get_valor() > p[right(i)].get_valor())
        {
            int item = p[left(i)].get_valor() > p[right(i)].get_valor() ? right(i) : left(i);

            node aux = p[i];
            p[i] = p[item];
            p[item] = aux;

            heapify_top_min(item);
        }
    }

    void heapify_top_max(int i)
    {
        if (i >= _size / 2)
            return;
        if (p[i].get_valor() < p[left(i)].get_valor() || p[i].get_valor() < p[right(i)].get_valor())
        {
            int item = p[left(i)].get_valor() < p[right(i)].get_valor() ? right(i) : left(i);

            node aux = p[i];
            p[i] = p[item];
            p[item] = aux;

            heapify_top_max(item);
        }
    }

    void heapify_bottom_min(int i)
    {
        if (i == 0)
            return;
        if (p[i].get_valor() < p[father(i)].get_valor())
        {
            node aux = p[i];
            p[i] = p[father(i)];
            p[father(i)] = aux;

            heapify_bottom_min(father(i));
        }
    }

    void heapify_bottom_max(int i)
    {
        if (i == 0)
            return;
        if (p[i].get_valor() > p[father(i)].get_valor())
        {
            node aux = p[i];
            p[i] = p[father(i)];
            p[father(i)] = aux;

            heapify_bottom_min(father(i));
        }
    }

public:
    Heap()
    {
        _size = 0;
    }

    void push(node n)
    {
        if (_size == p.size())
            p.push_back(n);
        else
            p[_size - 1] = n;

        heapify_bottom_max(p.size() - 1);
        _size++;
    }

    node top()
    {
        return p[0];
    }

    void pop()
    {
        p[0] = p[_size - 1];

        heapify_top_max(0);

        _size--;
    }

    int size()
    {
        return _size;
    }
};

int main()
{
    ios_base::sync_with_stdio();
    cin.tie();

    Heap a = Heap();

    node n1 = node(3);
    node n2 = node(4);

    a.push(n1);
    a.push(n2);

    a.pop();

    a.push(node(6));
    a.push(node(5));
    a.pop();

    cout << a.top().get_valor() << "\n";
    cout << a.size() << "\n";

    return 0;
}