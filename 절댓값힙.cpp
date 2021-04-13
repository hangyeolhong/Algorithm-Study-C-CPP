#include<iostream>
#include<cmath>
 
#define MAX 100010
using namespace std;
 
int N, Heap_Idx;
int Heap_Array[MAX];
 
bool Compare(int A, int B)
{
    int dA = abs(A);
    int dB = abs(B);
    if (dA <= dB)
    {
        if (dA == dB)
        {
            if (A < B)
            {
                return true;
            }
            else return false;
        }
        return true;
    }
    return false;
}
 
void Swap(int &A, int &B) { int Temp = A; A = B; B = Temp; }
 
void Heap_push(int data)
{
    int Idx = ++Heap_Idx;
    Heap_Array[Idx] = data;
 
    while ((Idx != 1) && Compare(data, Heap_Array[Idx / 2]) == true)
    {
        Swap(Heap_Array[Idx], Heap_Array[Idx / 2]);
        Idx = Idx / 2;
    }
}
 
int Heap_pop()
{
    if (Heap_Idx == 0) return 0;
    int Result = Heap_Array[1];
    Heap_Array[1] = Heap_Array[Heap_Idx--];
    
    int Parent = 1;
    int Child;
    while (1)
    {
        Child = Parent * 2;
        if (Child + 1 <= Heap_Idx && Compare(Heap_Array[Child + 1], Heap_Array[Child]) == true) Child++;
        if (Child > Heap_Idx || Compare(Heap_Array[Parent], Heap_Array[Child]) == true) break;
        Swap(Heap_Array[Parent], Heap_Array[Child]);
        Parent = Child;
    }
 
    return Result;
}
 
void Solution()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a; cin >> a;
        if (a == 0) cout << Heap_pop() << endl;
        else Heap_push(a);
    }
}
 
void Solve()
{
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
    
    return 0;
}
 

