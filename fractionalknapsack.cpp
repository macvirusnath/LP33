#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Item{
    int weight;
    int value;
    double ratio;
};
bool compare(Item a, Item b){
    return a.ratio> b.ratio;
}
double knapsack(int capacity,vector<Item> & items){
  sort(items.begin(),items.end(),compare);
  int curr_weight=0;
  double total_val=0.0;
  for(const auto item : items){
    if(curr_weight+item.weight<=capacity){
        total_val+=item.value;
        curr_weight+=item.weight;
    }
    else {
        double remain=capacity-curr_weight;
        total_val+=(remain/item.weight)*item.value;
        curr_weight+=remain;
    }
  }
    cout<<"current weight is given as "<<curr_weight<<endl;
  return total_val;
}

int main(){
  
  int n;
  cout<<"enter the no of items"<<endl;
  cin>>n;
  vector<Item> items(n);
  int capacity;
  cout<<"enter the capacity of bag"<<endl;
  cin>>capacity;
  cout<<"enter data of the weight and then value"<<endl;
  
  for(int i=0;i<n;i++){
    cin>>items[i].weight;
    cin>>items[i].value;
    items[i].ratio=static_cast<double>(items[i].value/items[i].weight);
  }
 cout<<"maximum ans is "<<knapsack(capacity,items);
return 0;
}