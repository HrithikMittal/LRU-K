/*
author:-Adhikansh Mittal
Date:-28-11-18
*/

#include<stdio.h>
#include<iostream>
#include<climits>
using namespace std;

void swap(int *x, int *y);

class MinHeap
{
    int *harr;
    int capacity;
    int heap_size;
public:
    MinHeap(int a[], int size);
    void MinHeapify(int i);
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }

    int extractMin();
    int getMin() { return harr[0]; }
};

MinHeap::MinHeap(int a[], int size)
{
    heap_size = size;
    harr = a;
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}

int MinHeap::extractMin()
{
    if (heap_size == 0)
        return INT_MAX;

    int root = harr[0];

    if (heap_size > 1)
    {
        harr[0] = harr[heap_size-1];
        MinHeapify(0);
    }
    heap_size--;

    return root;
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int kthSmallest(int arr[], int n, int k)
{
    MinHeap mh(arr, n);
    for (int i=0; i<k-1; i++)
        mh.extractMin();
    return mh.getMin();
}

int findLRU(int time[], int n,int v){
    int i, pos = -1;
    int master = kthSmallest(time, n, v);
    for(i=0;i<n;i++)
    {
        if(time[i] == master)
        {
            pos = i;
            break;
        }
    }
    return pos;
}

int main()
{
    int fram, page, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d",&fram);
    int k;
    printf("Enter the value of K:");
    scanf("%d",&k);
    printf("Enter number of pages: ");
    scanf("%d",&page);
    printf("Enter reference string: ");
    for(i=0;i<page;++i)
    {
        scanf("%d",&pages[i]);
    }

    for(i=0;i<fram;++i)
    {
        frames[i] = -1;
    }

    for(i=0;i<page;++i)
    {
        flag1 = flag2 = 0;
        for(j=0;j<fram;++j)
        {
            if(frames[j] == pages[i])
            {
                counter = counter+1;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }
        if(flag1==0)
        {
            for(j=0;j<fram;++j)
            {
                if(frames[j] == -1)
                {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0)
        {
            pos = findLRU(time, fram, k);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }

        printf("\n");

        for(j=0;j<fram;++j)
         {
            printf("%d\t", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d", faults);

    return 0;
}
