#include <bits/stdc++.h>
using namespace std;

class Hash
{
    long long BUCKET; 
    list<long long> *table;

public:
    Hash(long long V); 
    void insertItem(long long x);
    void deleteItem(long long key);
    long long hashFunction(long long x)
    {
        return (x % BUCKET);
    }
    void restart()
    {
        delete [] table;
    } 
    void Search(long long);
};

Hash::Hash(long long b)
{
    this->BUCKET = b;
    table = new list<long long>[BUCKET];
}

void Hash::insertItem(long long key)
{
    long long index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::Search(long long key)
{
    long long index = hashFunction(key);
    list<long long>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        if (*i == key)
            return;
    }
    if (i != table[index].end())
        return;
}
int main()
{
    int set = 10;
    while (set < 31)
    {
        Hash h(1<<set);
        for (int i = 0; i < 1 << set; i++)
        {
            h.insertItem(rand()%(1<<31));
        }
        clock_t Begin, End;
        Begin = clock();
        for(int i=0;i<100000;i++)
        {
            h.Search(rand()%(1<<set));
        }
        End = clock();
        double duration = double(End - Begin) / CLOCKS_PER_SEC;
        cout << fixed << setprecision(6) << duration << endl;
        set++;
        h.restart();
    }
    return 0;
}
