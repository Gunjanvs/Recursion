// stoneGame.cpp
#include<iostream>
using namespace std ;

bool stoneGame(vector<int>& piles) {

	int alice = 0 ;
	int bob = 0;
	int i = 0 ;
	int j = piles.size()-1;
	int count = 1 ;


	while(i<j){
		if (piles[i] >= piles[j]){
			if (count %2!= 0)
			{
				alice += piles[i];
				i++;
			}
			else {
				bob += piles[i];
				i++;
			}
		}
		else {
			if (count %2!= 0)
			{
				alice += piles[i];
				j--;
			}
			else {
				bob += piles[i];
				j--;
			}
		}
	}
	if (alice > bob)
	{
		return true;
	}
	else {
		return false;
	}
}

int main(){
	vector<int> piles{3,7,2,3};
	cout << stoneGame(piles);
}