#include <iostream>
#include <vector>
#include <unordered_map>
int64_t A, L;

void Print(const std::vector<int8_t> &in) {
  for(int x : in) {
    std::cout << x << ",";
  }
  std::cout << std::endl;
}

int Encode(const std::vector<int8_t> &in) {
  int encoded = 0;
  for(int8_t x : in) {
    encoded = encoded*3+x;
  }
  return encoded;
}

void Decode(int encoded, std::vector<int8_t>& decoded) {
  for(int i=decoded.size()-1; i>=0; --i) {
    decoded[i] = encoded%3;
    encoded/=3;
  }
}


void GenerateNeighbors(std::vector<int8_t> &in, int start, std::vector<int> &encoded_out) {
  if(start>=in.size()) {
    std::vector<int8_t> out(in.size());
    for(int i=0;i<in.size();++i) {
      out[i] = in[i]-1;
    }
    encoded_out.push_back(Encode(out));
  }
  bool zeroes_found = false;
  for(int i=start;i<in.size();++i) {
    if(in[i] == 0) {
      // Generate neighbor by adding at least one enchilada.
      zeroes_found = true;
      // Cover single row.
      in[i] = 3;
      GenerateNeighbors(in, i+1, encoded_out);
      in[i] = 0;
      // Cover multiple rows, if possible.
      if(((i+2)<in.size()) && (in[i+1]==0) && (in[i+2]==0)) {
        in[i] = in[i+1] = in[i+2] = 1;
        GenerateNeighbors(in, i+3, encoded_out);
        in[i] = in[i+1] = in[i+2] = 0;
      }
      break;
    }
  }
  // The first column is full, generate the unique neighbor by just subtracting 1.
  if((start==0) && !zeroes_found) {
    std::vector<int8_t> out(in.size());
    for(int i=0;i<in.size();++i) {
      out[i] = in[i]-1;
    }
    encoded_out.push_back(Encode(out));
  }
}

void IndexResiduals(int8_t A) {
  std::unordered_map<std::vector<int8_t>, int> M;
  std::vector<int8_t> in(A, 0);
  std::vector<std::vector<int8_t>> out;
  GenerateNeighbors(in,0,out);
  for(const auto&v : out) {
    auto &[it, added] = M.emplace(v, M.size());
  }
  
  for(const auto&[v, i] : M) {
    std::cout << i << ": ";
    Print(v);
  }
  
}

void GenerateTransitionMatrix() {
  
}



int64_t Solve() {
  IndexResiduals(7);
  /*std::vector<int8_t> in(7, 0);
  std::vector<std::vector<int8_t>> out;
  GenerateNeighbors(in, 0, out);
  for(const auto& v : out) {
    Print(v);
  }*/
  return 0;
}

int main(){
  //std::cin >> A >> L;
  std::cout << Solve();
}

