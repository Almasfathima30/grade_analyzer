#include<iostream>
#include<stack>
#include<queue>
#include<chrono>
using namespace std;
using namespace chrono;
template<class T>
class MyStack
{
    private:
    T data[10000];
    int top;
    public:
    MyStack()
    {
        top==1;
    }
    void push(T value)
    {
        if(top<9999)
        data[++top]=value;
    }
    void pop()
    {
        if(top>=0)
        top--;
    }
};
template<class T>
class MyQueue
{
    private:
    T data[10000];
    int front,rear;
    public:
    MyQueue()
    {
        front=0;
        rear=-1;
    }
    void enqueue(T value)
    {
        if(rear<9999)
        data[++rear]=value;
    }
    void dequeue()
    {
        if(front<=rear)
        front++;
    }
};
int main()
{
    const int N=10000;
    //custom stack benchmark
    auto start=high_resolution_clock::now();
    MyStack<int>mystack;
    for(int i=0;i<N;i++)
    mystack.push(i);
    for(int i=0;i<N;i++)
    mystack.pop();
    auto end=high_resolution_clock::now();
    auto CustomStackTime=duration_cast<microseconds>(end-start);
    //STL stack benchmark
    start=high_resolution_clock::now();
    stack<int>stlstack;
    for(int i=0;i<N;i++)
    stlstack.push(i);
    for(int i=0;i<N;i++)
    stlstack.pop();
    end=high_resolution_clock::now();
    auto STLStackTime=duration_cast<microseconds>(end-start);
    //Custom queue benchmark
    start=high_resolution_clock::now();
    MyQueue<int>myqueue;
    for(int i=0;i<N;i++)
    myqueue.enqueue(i);
    for(int i=0;i<N;i++)
    myqueue.dequeue();
    end=high_resolution_clock::now();
    auto CustomQueueTime=duration_cast<microseconds>(end-start);
    //STL queue benchmark
    start=high_resolution_clock::now();
    queue<int>stlqueue;
    for(int i=0;i<N;i++)
    stlqueue.push(i);
    for(int i=0;i<N;i++)
    stlqueue.pop();
    end=high_resolution_clock::now();
    auto STLQueueTime=duration_cast<microseconds>(end-start);
    cout<<"Custom Stack Time:"<<CustomStackTime.count()<<" microseconds"<<endl;
    cout<<"STL Stack Time:"<<STLStackTime.count()<<" microseconds"<<endl;
    cout<<"Custom Queue Time:"<<CustomQueueTime.count()<<" microseconds"<<endl;
    cout<<"STL Queue Time:"<<STLQueueTime.count()<<" microseconds"<<endl;
    return 0;
}
