#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define endl cout << '\n'
#define vint vector<int>
#define vll vector<ll>
#define pb push_back
#define S second
#define F first
#define wl int t; cin >> t; while(t--)
#define sort(v) sort(v.begin(),v.end())
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

void merge(int arr[], int start, int mid, int end){
    int left_length = mid - start + 1;
    int right_length = end - mid;

    int L[left_length], R[right_length];
    for(int i = 0; i < left_length; i++) L[i] = arr[start+i];
    for(int i = 0; i < right_length; i++) R[i] = arr[mid+i+1];

    int i = 0, z = 0, k = start;

    while (i < left_length && L[i] <= 0){
        arr[k++] = L[i++];
    }

    while (z < right_length && R[z] <= 0){
         arr[k++] = R[z++];
    }

    while (i < left_length){
        arr[k++] = L[i++];
    }

    while (z < right_length){
        arr[k++] = R[z++];
    }

}
void segregate (int arr[], int start, int end){
    if(end <= start) return;

    int mid = (end+start)/2;
    segregate(arr, start, mid);
    segregate(arr, mid +1, end);
    merge(arr, start, mid, end);
}
int main() {

    int arr[] = { 9, -3, 5, -2, -8, -6, 1, 3 };
    int n = sizeof (arr)/sizeof(arr[0]);

    segregate(arr, 0, n-1);

    cout << "After segregation:\n{";
    for(auto &i : arr) cout << i << ", ";
    cout << '}';
}
