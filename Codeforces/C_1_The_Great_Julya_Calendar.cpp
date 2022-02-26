#include <iostream>
#include <queue>
#include <cassert>
using namespace std;
typedef long long int64;
// Max substraction 9
// So only the last two digit will change
// We can store all the digits except the last two
// Initially we can store all the digits in priority queue.
// Then take the top element each time and substract it.
// Also we should replace previous last two digits with the new ones.

class AHeap
{
protected:
    int64 *heapArray; // Pointer to the heapArray array
    int n;            // Number of elements now in the heapArray
    void shiftDown(int pos)
    {
        while (!isLeaf(pos))
        { // Stop if pos is a leaf
            int64 largest = pos;
            int64 lc = leftChild(pos);
            int64 rc = rightChild(pos);
            if ((lc < n) && (heapArray[lc] > heapArray[largest]))
            {
                largest = lc; // Set lc to greater child’s value
            }
            if ((rc < n) && (heapArray[rc] > heapArray[largest]))
            {
                largest = rc; // Set rc to greater child’s value
            }
            if (largest == pos)
                return;
            swap(heapArray[pos], heapArray[largest]); // Swap with child
            pos = largest;                            // Move down
        }
    }
    void shiftUp(int pos)
    {
        while (pos != 0 && (heapArray[pos] > heapArray[parent(pos)]))
        {
            swap(heapArray[pos], heapArray[parent(pos)]); // Swap with parent
            pos = parent(pos);                            // Move up
        }
    }
    bool isLeaf(int pos) const // True if pos is a leaf
    {
        return (pos >= n / 2) && (pos < n);
    }
    int leftChild(int pos) const
    {
        return 2 * pos + 1;
    } // Return leftchild position
    int rightChild(int pos) const
    {
        return 2 * pos + 2;
    }                         // Return rightchild position
    int parent(int pos) const // Return parent position
    {
        return (pos - 1) / 2;
    }

public:
    AHeap(vector<int64> h) // Constructor
    {
        n = h.size();
        heapArray = new int64[n];
        for (int i = 0; i < n; i++)
        {
            heapArray[i] = h[i];
        }
        buildHeap();
    }
    ~AHeap()
    {
        delete[] heapArray;
    }
    int size() const // Return current heapArray size
    {
        return n;
    }
    void buildHeap() // Heapify contents of heapArray
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            shiftDown(i);
        }
    }
    int removeFirst()
    {
        swap(heapArray[0], heapArray[--n]); // Swap first with last value
        if (n > 0)
        {
            shiftDown(0); // shiftdown new root val
        }
        return heapArray[n]; // Return deleted value
    }
    void insert(const int64 &it)
    {
        n++;
        heapArray[n - 1] = it; // Start at end of heapArray
        // Now sift up until curr’s parent > curr
        if (n > 0)
        {
            shiftUp(n - 1);
        }
    }
};
class PriorityQueue : AHeap
{
private:
    int getPos(const int64 &key, int pos)
    {
        if (pos >= n)
        {
            return -1;
        }
        if (this->heapArray[pos] == key)
        {
            return pos;
        }
        else if (this->isLeaf(pos))
        {
            return -1;
        }
        int l = getPos(key, this->leftChild(pos));
        int r = getPos(key, this->rightChild(pos));
        if (l != -1 && r != -1)
        {
            return min(l, r);
        }
        else if (l != -1)
        {
            return l;
        }
        else if (r != -1)
        {
            return r;
        }
        else
        {
            return -1;
        }
    }
    void heapChangeKey(int pos, const int64 &key)
    {
        this->heapArray[pos] = key;
        this->shiftUp(pos);
        this->shiftDown(pos);
    }

public:
    PriorityQueue(vector<int64> h) : AHeap(h)
    {
    }
    int64 extractMax()
    {
        return this->removeFirst(); // Return deleted value
    }
    const int getMax()
    {
        // assert(this->n > 0, "AHeap is empty");
        return this->heapArray[0]; // Return deleted value
    }
    void changeKey(const int64 &oldKey, const int64 &newKey)
    {
        int pos = getPos(oldKey, 0);
        if (pos == -1)
            insert(newKey);
        else
            heapChangeKey(pos, newKey);
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << heapArray[i] << " ";
        }
        cout << endl;
    }
    void push(const int64 &it)
    {
        insert(it);
    }
};
int solve(int n)
{
    int c = 0;
    int a = n;
    vector<int64> digits;
    while (a)
    {
        digits.push_back(a % 10);
        a /= 10;
    }
    PriorityQueue pq(digits);
    // cout << "->";
    // pq.print();
    while (n)
    {
        int maxDigit = pq.getMax();
        int a = n;
        n -= maxDigit;
        int b = n;
        while (a != b)
        {
            // cout << a << " " << b << endl;
            int tmp1 = a % 10;
            int tmp2 = b % 10;
            a /= 10;
            b /= 10;
            // cout << "Replace: " << tmp1 << " " << tmp2 << endl;
            if (tmp1 != tmp2)
                pq.changeKey(tmp1, tmp2);
            // cout << "->";
            // pq.print();
        }
        // pq.print();
        // cout << x0 << " " << x1 << " " << y0 << " " << y1 << endl;

        // cout << n << endl;
        c++;
    }
    return c;
}
int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
}