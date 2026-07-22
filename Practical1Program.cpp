#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        swap(arr[i], arr[min]);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Merge Function
void merge(int arr[], int low, int mid, int high)
{
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= high)
        temp[k++] = arr[j++];

    for(int i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}

// Merge Sort
void mergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

// Partition Function (First Element as Pivot)
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j)
    {
        while(arr[i] <= pivot && i < high)
            i++;

        while(arr[j] > pivot && j > low)
            j--;

        if(i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);

    return j;
}

// Quick Sort
void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Bubble Sort
    bubbleSort(arr, n);
    cout << "\nBubble Sort: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Selection Sort
    selectionSort(arr, n);
    cout << "\nSelection Sort: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Insertion Sort
    insertionSort(arr, n);
    cout << "\nInsertion Sort: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Merge Sort
    mergeSort(arr, 0, n - 1);
    cout << "\nMerge Sort: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Quick Sort
    quickSort(arr, 0, n - 1);
    cout << "\nQuick Sort: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}