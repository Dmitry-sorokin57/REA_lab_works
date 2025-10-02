#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
template <typename T> class MinHeap {
private:
    vector<T> heap;
// Get the parent index
    int parent(int index) { return (index - 1) / 2; }
// Get the left child index
    int leftChild(int index) { return (2* index + 1); }
// Get the right child index
    int rightChild(int index) { return (2* index + 2); }
// Heapify up to maintain heap property
    void heapifyUp(int index)
    {
        while (index && heap[index] < heap[parent(index)]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }
// Heapify down to maintain heap property
    void heapifyDown(int index)
    {
        int left = leftChild(index);
        int right = rightChild(index);
        int smallest = index;
        if (left < heap.size()
            && heap[left] < heap[smallest])
        smallest = left;
        if (right < heap.size()
            && heap[right] < heap[smallest])
            smallest = right;
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }
public:
// Check if the heap is empty
    bool isEmpty() const { return heap.empty(); }
// Get the size of the heap
    int size() const { return heap.size(); }
// Get the minimum element
    T getMin() const
    {
        if (isEmpty())
            throw runtime_error("Heap is empty");
        return heap.front();
    }
// Insert a new key
    void insert(T key)
    {
        heap.push_back(key);
        int index = size() - 1;
        heapifyUp(index);
    }
// Extract the minimum element
    T extractMin()
    {
        if (isEmpty())
            throw runtime_error("Heap is empty");
        T root = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }
// Delete a specific node
    void deleteNode(T key)
    {
        int index = -1;
// Find the index of the node to delete
        for (int i = 0; i < size(); ++i) {
            if (heap[i] == key) {
                index = i;
                break;
            }
        }
        if (index == -1)
            throw runtime_error(
        "Key not found in the heap");
// Replace the node with the last element
        heap[index] = heap.back();
        heap.pop_back();
// Restore heap property
        heapifyUp(index);
        heapifyDown(index);
    }
// Decrease key function
    void decreaseKey(int i, T newValue)
    {
        if (i < 0 || i >= size() || newValue > heap[i])
            throw invalid_argument("Invalid index or new value");
        heap[i] = newValue;
        heapifyUp(i);
    }
// Print the heap elements
    void printHeap() const
    {
        for (const T& elem : heap)
            cout << elem << " ";
        cout << endl;
    }
};
int main()
{
    MinHeap<int> minHeap;
    minHeap.insert(3);
    minHeap.insert(2);
    minHeap.insert(15);
    minHeap.insert(5);
    minHeap.insert(4);
    minHeap.insert(45);
    cout << "Min Heap: ";
    minHeap.printHeap();
    cout << "Minimum element: " << minHeap.getMin() << endl;
    minHeap.extractMin();
    cout << "After extracting min: ";
    minHeap.printHeap();
// Delete node from min-heap
    minHeap.deleteNode(4);
    cout << "After deleting 4: ";
    minHeap.printHeap();
// Decrease key in min-heap
    minHeap.decreaseKey(2, 1);
    cout << "After decreasing key at index 2 to 1: ";
    minHeap.printHeap();
    return 0;
}
