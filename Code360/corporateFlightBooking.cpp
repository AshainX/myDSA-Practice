#include <bits/stdc++.h> 
vector< int > corpFlightBookings(vector< vector < int > > &bookings, int n) {
	// Write your code here.
	vector<int> result(n,0);

	for(auto booking : bookings){
		int start = booking[0];
		int end = booking[1];
		int seat = booking[2];

		result[start-1]+=seat;
		if(end<n){
			result[end]-=seat;
		}

	}
	for(int i = 1 ; i<n; i++){
		result[i] += result[i-1];
	}

	//result.pop_back();
	return result;
}

// Takeaways :
// if i use extra space in  vector<int> result(n+1,0); then i should use result.pop_back() to remove any extra space.
// this was an easy method to solve through prefix sum  