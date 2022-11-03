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
    bool is_leaft(int i) { return i >= _size / 2; }

    void heapify_down_min(int i)
    {
        if (is_leaft(i))
            return;
        if (p[i].get_valor() > p[left(i)].get_valor() || p[i].get_valor() > p[right(i)].get_valor())
        {
            int item = p[left(i)].get_valor() > p[right(i)].get_valor() ? right(i) : left(i);

            node aux = p[i];
            p[i] = p[item];
            p[item] = aux;

            heapify_down_min(item);
        }
    }

    void heapify_down_max(int i)
    {
        if (is_leaft(i))
            return;
        if (p[i].get_valor() < p[left(i)].get_valor() || p[i].get_valor() < p[right(i)].get_valor())
        {
            int item = p[left(i)].get_valor() < p[right(i)].get_valor() ? right(i) : left(i);

            node aux = p[i];
            p[i] = p[item];
            p[item] = aux;

            heapify_down_max(item);
        }
    }

    void heapify_up_min(int i)
    {
        if (i == 0)
            return;
        if (p[i].get_valor() < p[father(i)].get_valor())
        {
            node aux = p[i];
            p[i] = p[father(i)];
            p[father(i)] = aux;

            heapify_up_min(father(i));
        }
    }

    void heapify_up_max(int i)
    {
        if (i == 0)
            return;
        if (p[i].get_valor() > p[father(i)].get_valor())
        {
            node aux = p[i];
            p[i] = p[father(i)];
            p[father(i)] = aux;

            heapify_up_max(father(i));
        }
    }

    bool is_heap_min(int i)
    {
        if (is_leaft(i))
            return true;

        return p[left(i)].get_valor() >= p[i].get_valor() && p[right(i)].get_valor() >= p[i].get_valor();
    }

    bool is_heap_max(int i)
    {
        if (is_leaft(i))
            return true;

        return p[left(i)].get_valor() <= p[i].get_valor() && p[right(i)].get_valor() <= p[i].get_valor();
    }

    void build_heap_min()
    {
        for (int i = size() - 1; i >= 0; i++)
        {
            if (!is_heap_min(i))
                heapify_down_min(i);
        }
    }

    void build_heap_max()
    {

        for (int i = size() - 1; i >= 0; i--)
        {
            if (!is_heap_max(i))
            {
                heapify_down_max(i);
            }
        }
    }

public:
    Heap()
    {
        _size = 0;
    }

    Heap(vector<node> &v)
    {
        p = v;
        _size = p.size();

        build_heap_max();
    }

    void push(node n)
    {
        if (_size == p.size())
            p.push_back(n);
        else
            p[_size] = n;

        _size++;

        heapify_up_max(_size - 1);
    }

    node top()
    {
        return p[0];
    }

    void pop()
    {
        p[0] = p[_size - 1];

        _size--;

        heapify_down_max(0);
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

    return 0;
}