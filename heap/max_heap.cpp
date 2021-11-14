#include<iostream>

class max_heap{
    public:
        int capacity;//maximum capacity
        int heap_size;//current size
        int *heap_arr;
        max_heap(int n){
            heap_size=0;
            capacity=n;
            heap_arr=new int[capacity];
        }
        int parent(int index){
            return (index-1)/2;
        }
        int left_child(int index){
            return 2*index+1;
        }
         int right_child(int index){
            return 2*index+2;
        }
        void swap(int &x,int &y){
            int temp=x;
            x=y;
            y=temp;
        }
        void Max_heapify(int i){
            int lchild=left_child(i);
            int rchild=right_child(i);
            int largest=i;
            static int l{2};
            if(lchild<heap_size && heap_arr[lchild]>heap_arr[i]){
                largest=lchild;
            }
            if(rchild<heap_size&&heap_arr[rchild]>heap_arr[largest]){
                largest=rchild;
            }
            if(largest!=i){
                swap(heap_arr[i],heap_arr[largest]);
                Max_heapify(largest);
            }
        }
        void push_heap(int num){
            if(heap_size==capacity){
                printf("heap full \n");
                return ;
            }
            heap_size++;
            int i{heap_size-1};
            heap_arr[i]=num;
            while(i!=0 && heap_arr[i]>heap_arr[parent(i)]){
                swap(heap_arr[i],heap_arr[parent(i)]);
                i=parent(i);
            }
        }
        int extract_max(){
            if(heap_size==0){
                printf("heap is empty");
                return -2222;
            }
            if(heap_size==1){
                heap_size--;
                return heap_arr[0];
            }
            int root=heap_arr[0];
            heap_arr[0]=heap_arr[heap_size-1];
            heap_size--;
            Max_heapify(0);
            return root;
        }
};

int main()
{
    max_heap h(7);
    h.push_heap(40);
    h.push_heap(35);
    h.push_heap(30);
    h.push_heap(15);
    h.push_heap(10);
    h.push_heap(25);
    h.push_heap(5);
    std::cout<<h.extract_max()<<"\n";
    std::cout<<h.extract_max()<<"\n";

    return 0;
}