#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
    int v1, v2, weight;
};

bool comp(Edge start, Edge end){
    return start.weight < end.weight;
}

int main(){
    int V, E;
    cin >> V >> E;
    
    Edge* input = new Edge[E];
    
    for(int i=0; i<E; i++){
        cin >> input[i].v1 >> input[i].v2 >> input[i].weight;
    }
    
    Edge* output = new Edge[V-1];
    
    sort(input, input+E, comp);
    
    int* parent = new int[V];
    
    for(int i=0; i<V; i++){
        parent[i] = i;
    }
    
    int count = 0;
    
    int k = 0;
    
    while(count < (V-1)){
        int start = input[k].v1 , end = input[k].v2;
        
        int parent1 = start, parent2 = end;
        
        while(parent1 != parent[parent1]){
            parent1 = parent[parent1];
        }
        
        
        while(parent2 != parent[parent2]){
            parent2 = parent[parent2];
        }
        
        if(parent1 != parent2){
            output[count].v1 = start; 
            output[count].v2 = end;
            output[count].weight = input[k].weight;
            parent[parent1] = parent2;
            count++;
        }
        
        
        k++;
    }
    
    for(int i=0; i<V-1; i++){
        if(output[i].v1 < output[i].v2){
        cout << output[i].v1 <<" "<< output[i].v2 <<" "<< output[i].weight << endl;
        }else{
        cout << output[i].v2 <<" "<< output[i].v1 <<" "<< output[i].weight << endl;    
        }
    }
}