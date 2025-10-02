import java.util.*;


class MinHeap<T extends Comparable<T>> {
    private ArrayList<T> heap;

    // Get the parent index
    private int parent(int index) { return (index - 1) / 2; }

    // Get the left child index
    private int leftChild(int index) { return (2 * index + 1); }

    // Get the right child index
    private int rightChild(int index) { return (2 * index + 2); }

    // Heapify up to maintain heap property
    private void heapifyUp(int index) {
        while (index > 0 && heap.get(index).compareTo(heap.get(parent(index))) < 0) {
            // Swap elements
            T temp = heap.get(index);
            heap.set(index, heap.get(parent(index)));
            heap.set(parent(index), temp);
            index = parent(index);
        }
    }

    // Heapify down to maintain heap property
    private void heapifyDown(int index) {
        int left = leftChild(index);
        int right = rightChild(index);
        int smallest = index;
        
        if (left < heap.size() && heap.get(left).compareTo(heap.get(smallest)) < 0) {
            smallest = left;
        }
        if (right < heap.size() && heap.get(right).compareTo(heap.get(smallest)) < 0) {
            smallest = right;
        }
        if (smallest != index) {
            // Swap elements
            T temp = heap.get(index);
            heap.set(index, heap.get(smallest));
            heap.set(smallest, temp);
            heapifyDown(smallest);
        }
    }

    // Constructor
    public MinHeap() {
        heap = new ArrayList<>();
    }

    // Check if the heap is empty
    public boolean isEmpty() { return heap.isEmpty(); }

    // Get the size of the heap
    public int size() { return heap.size(); }

    // Get the minimum element
    public T getMin() {
        if (isEmpty())
            throw new RuntimeException("Heap is empty");
        return heap.get(0);
    }

    // Insert a new key
    public void insert(T key) {
        heap.add(key);
        int index = size() - 1;
        heapifyUp(index);
    }

    // Extract the minimum element
    public T extractMin() {
        if (isEmpty())
            throw new RuntimeException("Heap is empty");
        T root = heap.get(0);
        heap.set(0, heap.get(heap.size() - 1));
        heap.remove(heap.size() - 1);
        if (!isEmpty()) {
            heapifyDown(0);
        }
        return root;
    }

    // Delete a specific node
    public void deleteNode(T key) {
        int index = -1;
        // Find the index of the node to delete
        for (int i = 0; i < size(); ++i) {
            if (heap.get(i).equals(key)) {
                index = i;
                break;
            }
        }
        if (index == -1)
            throw new RuntimeException("Key not found in the heap");
        
        // Replace the node with the last element
        heap.set(index, heap.get(heap.size() - 1));
        heap.remove(heap.size() - 1);
        
        // Restore heap property
        if (index < heap.size()) {
            heapifyUp(index);
            heapifyDown(index);
        }
    }

    // Decrease key function
    public void decreaseKey(int i, T newValue) {
        if (i < 0 || i >= size() || newValue.compareTo(heap.get(i)) > 0)
            throw new IllegalArgumentException("Invalid index or new value");
        heap.set(i, newValue);
        heapifyUp(i);
    }

    // Print the heap elements
    public void printHeap() {
        for (T elem : heap)
            System.out.print(elem + " ");
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        MinHeap<Integer> minHeap = new MinHeap<>();
        minHeap.insert(3);
        minHeap.insert(2);
        minHeap.insert(15);
        minHeap.insert(5);
        minHeap.insert(4);
        minHeap.insert(45);
        
        System.out.print("Min Heap: ");
        minHeap.printHeap();
        System.out.println("Minimum element: " + minHeap.getMin());
        
        minHeap.extractMin();
        System.out.print("After extracting min: ");
        minHeap.printHeap();
        
        // Delete node from min-heap
        minHeap.deleteNode(4);
        System.out.print("After deleting 4: ");
        minHeap.printHeap();
        
        // Decrease key in min-heap
        minHeap.decreaseKey(2, 1);
        System.out.print("After decreasing key at index 2 to 1: ");
        minHeap.printHeap();
    }
}
