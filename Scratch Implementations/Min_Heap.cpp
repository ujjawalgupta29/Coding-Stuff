#include<bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> heap;
    
public:
    MinHeap(vector<int> array)
    {
        this-> heap = buildHeap(array);
    }

    vector<int> buildHeap(vector<int> array)
    {
        int firstParent = (array.size() - 1 -1) / 2;
        for(int i = firstParent; i>=0; i--)
        {
            shiftDown(i, array.size()-1, array);
            // cout<<"For i = "<<i<<endl;
            // for(int j=0; j<array.size(); j++)
            //     cout<<array[j]<<" ";

            // cout<<endl;
        }
        return array;
    }

    void shiftUp(int sid)
    {
        int parentIdx = (sid - 1) / 2;
        int currentIdx = sid;

        while(parentIdx > 0)
        {
            if(this->heap[currentIdx] < this->heap[parentIdx] )
            {
                swap(this->heap[currentIdx], this->heap[parentIdx]);
                currentIdx = parentIdx;
                parentIdx = (currentIdx - 1) / 2;
            }

            else
            {
                break;
            }
            
        }
    }
//48 12 24 7 8 -5 24 391 24 56 2 6 8 41
    void shiftDown(int currentIdx, int endIdx, vector<int> &array)
    {
        int leftChildIdx = (2 * currentIdx + 1);

        while(leftChildIdx <= endIdx)
        {
            // cout<<"lchild = "<<leftChildIdx<<endl;
            int rightChildIdx = (leftChildIdx + 1 <= endIdx) ? (leftChildIdx + 1) : -1;
            int idxToSwap;

            if(rightChildIdx != -1)
                idxToSwap = (array[leftChildIdx] < array[rightChildIdx]) ? leftChildIdx : rightChildIdx;
            
            else
            {
                idxToSwap = leftChildIdx;
            }

            // cout<<"Indexs "<<currentIdx << " " <<idxToSwap<<endl;
            // cout<<"values = "<<array[currentIdx] <<" " << array[idxToSwap]<<endl;
            
            if(array[currentIdx] > array[idxToSwap])
            {
                swap(array[currentIdx], array[idxToSwap]);
                currentIdx = idxToSwap;
                leftChildIdx = 2 * currentIdx + 1;
            }

            else
            {
                break;
            }
            
        }
    }

    int peek()
    {
        return this->heap[0];
    }

    void remove()
    {
        swap(this->heap[0], this->heap[this->heap.size() - 1]);
        this->heap.pop_back();
        shiftDown(0, this->heap.size() - 1, this->heap);
    }

    void insert(int x)
    {
        this->heap.push_back(x);
        shiftUp(this->heap.size() - 1);
    }

    void display()
    {
        for(int i=0; i<this->heap.size(); i++)
            cout<<this->heap[i]<<" ";
        cout<<endl;
    }
};

int main()
{
    int n;
    cin>>n;

    vector<int> array(n);
    
    for(int i=0; i<n; i++)
    {
        cin>>array[i];
    }

    MinHeap minHeap(array);
    minHeap.display();
    minHeap.insert(76);
    minHeap.display();
    cout<<"Top Element = "<<minHeap.peek()<<endl;
    minHeap.remove();
    minHeap.display();
    minHeap.remove();
    minHeap.display();
    minHeap.insert(87);

    return 0;
}