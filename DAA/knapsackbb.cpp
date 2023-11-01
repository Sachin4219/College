#include<bits/stdc++.h>
using namespace std;

class Item{
	int value, weight;
	double ratio;
	Item(value, weight){
		this->value=value;
		this->weight=weight;
		this->ratio = value/weight;
	}
};

class knapsackNode(){
	vector<int> items;
	int value, weight;
	knapsackNode(vector<int> items, int weight, int value){
		this->weight=weight;
		this->value=value;
		this->items=items;
	}
};

bool comp(Item a, Item b){
	return a.ratio > b.ratio;
}



class knapsack(){
	vector<Item> items;
	int maxweight;

	knapsack(int maxweight, vector<Item> items){
		this->maxweight = maxweight;
		this->items = items;
	}

	int solve(){
		sort(items.begin(), items.end(), comp);
		int bestvalue=0;
		queue<Item> q;
		q.push({}, 0, 0);
		while(!q.empty()){
			knapsackNode node = q.front();
			q.pop();
			int size = node.items.size();
			if(size == this.items.size)
				bestvalue = max(bestvalue, node.value);
			else{
				Item it = items[size];
				knapsackNode withItem(node.items, node.weight+it.weight, node.value+it.value);
				if(isPromising(withItem, this.maxweight, bestvalue)){
					q.push(withItem);
				}
				knapsackNode withoutItem(node.items, node.weight, node.value);
				if(isPromising(withoutItem, this.maxweight, bestvalue)){
					q.push(withoutItem);
				}
			} 
		}
		return bestvalue;
	}

    bool isPromising(KnapsackNode node, int maxWeight, int bestValue) {
        return node.weight <= maxWeight && node.value + getBound(node) > bestValue;
    }
 
    int getBound(KnapsackNode node) {
        int remainingWeight = this->maxWeight - node.weight;
        int bound = node.value;
 
        for (int i = node.items.size(); i < this->items.size(); i++) {
            Item item = this->items[i];
 
            if (remainingWeight >= item.weight) {
                bound += item.value;
                remainingWeight -= item.weight;
            } else {
                bound += remainingWeight * item.ratio;
                break;
            }
        }
 
        return bound;
    }

};


int main() {
    vector<Item> items = {
        Item(60, 10),
    Item(100, 20),
    Item(120, 30)
    };
    Knapsack knapsack(50, items);
    int result = knapsack.solve();
    cout << "Best value: " << result << endl;
    return 0;
}
