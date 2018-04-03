#include<iostream>
#include<climits>
using namespace std;
struct Heap
{
    int heap_size,capacity;
    int *harr;
};
struct Heap *createMinheap(int cap)
{
    struct Heap *h = new Heap();
    h->heap_size=0;
    h->capacity =cap;
    h->harr = new int[cap];
    return h;
}
void swap(int *a,int *b)
{
    int tmp =*a;
    *a=*b;
    *b=tmp;
}
int parent(int i)
{
    return (i-1)/2;
}
int left(int i)
{
    return (2*i+1);
}
int right(int i)
{
    return (2*i+2);
}
void insertkey(struct Heap *h,int key)
{
    if(h->heap_size == h->capacity) {
        cout<<"did not insert key";
        return;
    }
    h->heap_size++;
    int i = h->heap_size - 1;
    h->harr[i] = key;
    while( i!= 0 &&  h->harr[parent(i)] > h->harr[i]) {
        swap(&h->harr[parent(i)],&h->harr[i]);
        i = parent(i);
    }

}

// get min element
int getMin(struct Heap *h)
{
    return h->harr[0];
}

void MinHeapify(struct Heap *h,int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if( l < h->heap_size && h->harr[l] < h->harr[i])
        smallest = l;
    if( r < h->heap_size && h->harr[r] < h->harr[smallest])
        smallest =r;
    if(smallest!=i) {
        swap(&h->harr[i],&h->harr[smallest]);
        MinHeapify(h,smallest);
    }
}

void decreaseKey(struct Heap *h,int i,int new_val)
{
    h->harr[i] = new_val;
    while( i!=0 && h->harr[parent(i)] > h->harr[i]) {
        swap(&h->harr[parent(i)],&h->harr[i]);
        i = parent(i);
    }
}

// extract Min element
int extractMin(struct Heap *h)
{
    if(h->heap_size <=0 )
        return INT_MAX;
    if( h->heap_size == 1 ) {
        h->heap_size--;
        return h->harr[0];
    }

    int root = h->harr[0];
    h->harr[0] = h->harr[h->heap_size-1];
    h->heap_size--;
    MinHeapify(h,0);
    return root;
}

//
void deleteKey(struct Heap *h,int i)
{
    decreaseKey(h,i,INT_MIN);
    extractMin(h);
}


void print(struct Heap *h)
{
    for(int i=0;i<h->capacity;i++)
    cout<<h->harr[i]<<" ";
}
int main()
{
    struct Heap *h =createMinheap(11);
    insertkey(h,3);
    insertkey(h,2);
    deleteKey(h,1);
    insertkey(h,15);
    insertkey(h,5);
    insertkey(h,4);
    insertkey(h,45);
    cout<< extractMin(h)<<endl;
    cout<< getMin(h) <<endl;
    decreaseKey(h,2,1);
    cout<< getMin(h) <<endl;
//    print(h);
    return 0;
}
