#include <cassert>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>

// 2A > N-I0
const int64_t kMax = 1000000000000;
int64_t kMaxStories = 100;
int64_t kMaxInterest = 100;
const int64_t kMod = 1000000007;

bool Solve(const int64_t N, const int64_t A, const int64_t I0, const int64_t Imax) {
  //std::cerr<<"JOOG: N="<<N<<", A="<<A<<", I0="<<I0<<", Imax="<<Imax<<std::endl;
  if(I0 == 0) {
    return false;
  }
  if(Imax == 1) {
    // All stories must be interesting
    return A==N;
  }
  // Now we know: 1<=I0 && 2<=Imax
  return (I0+A) > (N-A); // Remove the Imax ceiling: go all the way up, then all the way down
  // Strategy: Tell I0-1 non-interesting stories first. Worst case, interest will be I=1 and we have room to alternate up and down (because 2<=Imax). This is equivalent to removing the Imax ceiling.
}

bool SolveDP(const int64_t N, const int64_t A, const int64_t I0, const int64_t Imax) {
  int64_t M[kMaxStories+1][kMaxStories+1][kMaxInterest+1];
  // M[n][a][i] = the number of ways to survive when `n` stories remain, `a` (`a` <= `n`) of them are interesting and current interest is `i`
  M[0][0][0] = 0;
  for(int i=1;i<=Imax;++i) {
    M[0][0][i] = 1;
  }
  
  for(int n=1; n<=N; ++n) {
    for(int a=0; a<=n; ++a) {
      M[n][a][0] = 0;
      for(int64_t i=1; i<=Imax; ++i) {
        M[n][a][i] = 0;
        if(a > 0) { // At least one interesting story remaining
          M[n][a][i] = (M[n][a][i] + M[n-1][a-1][std::min(i+1, Imax)])%kMod; // Tell an interesting story
        }
        if (a < n) { // At least one non-interesting story remaining
          M[n][a][i] = (M[n][a][i] + M[n-1][a][std::max(i-1, static_cast<int64_t>(0))])%kMod;
        }
      }
    }
  }
  return M[N][A][I0]>0;
}

void Verify() {
  for(int N=20; N<=100;++N) {  
    std::cerr << "Testing N=" << N<<std::endl;
    for(int A=0; A<=N;++A) {
      for(int Imax = N; Imax<=100;++Imax) {
        for(int I0 = 0; I0 <= Imax; ++I0) {
          if(SolveDP(N, A, I0, Imax)!=Solve(N, A, I0, Imax)) {
            std::cerr<<"Diff: "<<N << ", " << A << ", "<< I0 <<", "<< Imax<<std::endl;
            return;
          }
        }
      }
    }
  }

}


void ValidateInput(const int64_t A, const int64_t B, const int64_t I0, const int64_t Imin, const int64_t Imax) {
  std::cerr << A << " " << B << " " << I0 << " " << Imin << " "<<Imax << std::endl;
  assert(0<=A && A<=kMax);
  assert(0<=B && B<=kMax);
  assert(0<=Imax && Imax<=kMax);
  assert(0<=Imin && Imin<=Imax);
  assert(Imin<=I0 && I0<=Imax);
}

void GenerateGroup(const int group_index, const int group_size, const int64_t N, std::default_random_engine& generator) {
  for(int case_index = 0; case_index < group_size; ++case_index) {
    const bool sol_wanted = case_index % 2;
    std::uniform_int_distribution<int64_t> distribution_I0(1,N);
    const int64_t I0 = distribution_I0(generator);
    int64_t A = -1;;
    if(sol_wanted) { // Then ensure 2A > N-I0
      std::uniform_int_distribution<int64_t> distribution_A((N-I0+1)/2 + 1, N);
      A = distribution_A(generator);
    } else { // Then ensure 2A <= N-I0
      std::uniform_int_distribution<int64_t> distribution_A(0, (N-I0)/2);
      A = distribution_A(generator);
    }
    assert(I0>=1);
    std::uniform_int_distribution<int64_t> distribution_Imin(0,(I0-1)/2);
    const int64_t Imin = distribution_Imin(generator);
    std::uniform_int_distribution<int64_t> distribution_Imax(I0,kMax);
    const int64_t Imax = distribution_Imax(generator);
    ValidateInput(A, N-A, I0, Imin, Imax);
    
    const bool sol = Solve(N, A, I0-Imin, Imax-Imin);
    if(sol != sol_wanted) {
      //retry
      --case_index;
      continue;
    }
    
    // Write input
    {
      std::ostringstream os;
      os<<"group_"<<group_index<<".case_"<<case_index<<".in";
      
      std::ofstream F;
      F.open (os.str());
      F << A << " " << (N-A) << " " << I0 << " " << Imin << " "<<Imax << std::endl;
      F.close();
    }
    // Write output
    {
      std::ostringstream os;
      os<<"group_"<<group_index<<".case_"<<case_index<<".out";
      
      std::ofstream F;
      F.open (os.str());
      F << (sol_wanted?"SI":"NO")<<std::endl;
      F.close();
    }
  }
}

void GenerateCase(const int32_t group_index, const int32_t case_index, const int32_t N, const int32_t A, const int32_t Imin, const int32_t I0, const int32_t Imax) {
  const bool sol = Solve(N, A, I0-Imin, Imax-Imin);
  assert(SolveDP(N, A, I0-Imin, Imax-Imin)==sol);
  {
    std::ostringstream os;
    os << "group_"<<group_index<<".case_"<<case_index<<".in";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d %d %d %d %d\n", A, (N-A), I0, Imin, Imax);
    fclose(F);
  }
  {
    std::ostringstream os;
    os << "group_"<<group_index<<".case_"<<case_index<<".out";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%s\n", sol?"SI":"NO");
    fclose(F);
  }
}

void GenerateCases() {
  std::random_device rd;
  std::default_random_engine generator(rd());
  // Edge cases
  GenerateCase(0, 0, 20, 10, 0, 2, 2);
  GenerateCase(0, 1, 20, 10, 0, 1, 2);
  GenerateCase(0, 2, 22, 21, 0, 1, 1);
  GenerateCase(0, 3, 23, 23, 0, 1, 1);
  GenerateCase(0, 4, 19, 0, 0, 20, 20);
  GenerateCase(0, 5, 100, 50, 0, 2, 2);
  GenerateCase(0, 6, 100, 50, 0, 1, 1);
  GenerateCase(0, 7, 100, 99, 0, 1, 1);
  GenerateCase(0, 8, 100, 100, 0, 1, 1);
  GenerateCase(0, 9, 99, 0, 0, 100, 100);
  
  //-----------------
  GenerateGroup(1, 6, 8342, generator);
  //Do not add edge case (give contestant some points)
  //-----------------
  GenerateGroup(2, 5, 98523, generator);
  GenerateCase( 2, 5, 22, 21, 100, 101, 101);//Edge case: All stories need to be interesting, but one is missing
  //-----------------
  GenerateGroup(3, 5, 234234, generator);
  GenerateCase( 3, 5, 22, 21, 100, 101, 101);//Edge case: All stories need to be interesting, but one is missing
  GenerateCase( 3, 6, 22, 21, 100, 100, 101);//Edge case: starts with Imin 
  //-----------------
  GenerateGroup(4, 5, 5439234, generator);
  GenerateCase( 4, 5, 22, 21, 100, 101, 101);//Edge case: All stories need to be interesting, but one is missing
  GenerateCase( 4, 6, 22, 21, 100, 100, 101);//Edge case: starts with Imin 
  //-----------------
  GenerateGroup(5, 5, 29384232, generator);
  GenerateCase( 5, 5, 22, 21, 100, 101, 101);//Edge case: All stories need to be interesting, but one is missing
  GenerateCase( 5, 6, 22, 21, 100, 100, 101);//Edge case: starts with Imin 
  //-----------------
  GenerateGroup(6, 5, 932840223, generator);
  GenerateCase( 6, 5, 22, 21, 100, 101, 101);//Edge case: All stories need to be interesting, but one is missing
  GenerateCase( 6, 6, 22, 21, 100, 100, 101);//Edge case: starts with Imin 
  //-----------------
  GenerateGroup(7, 5, 3234923492, generator);
  GenerateCase( 7, 5, 22, 21, 100, 101, 101);//Edge case: All stories need to be interesting, but one is missing
  GenerateCase( 7, 6, 22, 21, 100, 100, 101);//Edge case: starts with Imin 
  //-----------------
  GenerateGroup(8, 5, 87324729321, generator);
  GenerateCase( 8, 5, 22, 21, 100, 101, 101);//Edge case: All stories need to be interesting, but one is missing
  GenerateCase( 8, 6, 22, 21, 100, 100, 101);//Edge case: starts with Imin 
  //-----------------
  GenerateGroup(9, 5, 987123120311, generator);
  GenerateCase( 9, 5, 22, 21, 100, 101, 101);//Edge case: All stories need to be interesting, but one is missing
  GenerateCase( 9, 6, 22, 21, 100, 100, 101);//Edge case: starts with Imin 
}



int main(){
  GenerateCases();
  return 0;
  Verify();
  return 0;
  int64_t A, B, I0, Imin, Imax;
  std::cin >> A >> B >> I0 >> Imin >> Imax;
  ValidateInput(A, B, I0, Imin, Imax);
  std::cout << Solve(A+B, A, I0-Imin, Imax-Imin) << std::endl;
  return 0;
}

