#include <bits/stdc++.h> 
using namespace std;

// template<typename K, typename V>
// void print_map(std::unordered_map<K,V> const &m)
// {
// 	for (auto const& pair: m) {
// 		std::cout << "{" << pair.first << ": " << pair.second << "}\n";
// 	}
// }

int main(){

    int n;
    cin>>n;
    int arr[n];

    for(int i = 0; i < n; i++) cin>>arr[i];

    unordered_map<int,bool> umap;

    for(int i = 0; i < n; i++) 
      umap.insert(pair<int,bool>(arr[i], true));

    for(int i = 0; i < n; i++){
        if (umap.find(arr[i] - 1) != umap.end()) {
             umap.at(arr[i]) = false;
      }
    }
    // print_map(umap);  
    int msp = 0;
    int ml = 0;
    for(int i = 0; i < n; i++){
        if(umap.at(arr[i]) == true){
            int tl = 1;
            int tsp = arr[i];
            while(umap.find(tsp + tl) != umap.end()){
                tl++;
            }

            if(tl > ml){
                ml = tl;
                msp = tsp;
            }

        }
    }
    // cout<<ml<<"  "<<msp<<endl;

    for(int i = 0 ; i < ml ; i++){
        cout<<msp+i<<endl;
    }

return 0;
}











































































































































































































































