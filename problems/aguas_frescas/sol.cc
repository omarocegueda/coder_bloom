/*#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>

uint64_t Solve(const uint64_t N) {
  return N*N*N - N;
}

int main(){
  uint64_t N;
  std::cin >> N;
  std::cout << Solve(N) << std::endl;
}

*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	unsigned long long int N;
	cin>>N;
	cout<<pow(N, 3)-N;
	
	
}
