#include<iostream>
#include<vector>
using namespace std;

std::vector<std::string> name(){
return {"This is generated from dynamic memory allocated vecctor"};
}
int main (){
    std::cout<<"Hello World";
   std::vector<std::string> data=name();
  for(auto i:data){
    std::cout<<i<<endl;
  }
    return 0;
}


//g++ helloworld.cpp -o helloworld && helloworld