
#include "include/TxText.h"
#include "include/TxTCtext.h"
#include "include/TxTypes.h"
#include "include/TxTPronouns.h"
#include "include/TxTables.h"
#include<string>
#include<iostream>
#include<chrono>

struct Timer{

  std::chrono::system_clock::time_point start;
  Timer(){
    start = std::chrono::system_clock::now();
  }
  ~Timer(){
    auto end =std::chrono::system_clock::now();
    
    std::chrono::duration<float,std::milli> duration = end - start;
    
    std::cout << duration.count() << " ms "<<std::endl;
    
  }
  
};

using namespace std;
int main(){
  
  // The class TxText work fine
  TxText *tex;
  tex = new TxText("Nada.txt");
  cout << tex->GetTextName() << endl;
  tex->SetTextName("Halo.txt");
  cout << tex->GetTextName() << endl;
  //tex->LoadText();
  tex->SetTextName("pp.txt");
  tex->LoadText();
  //cout << tex->GetText() << endl;

  //----------------------------//

  // The class TxTCext work fine

  TxTCtext *CTex;
  CTex = new TxTCtext(*tex);
  //cout <<"1: " <<CTex->GetText() << endl;
  CTex->LowercaseA();
  //cout << "2: " <<CTex->GetText() << endl;
  CTex->UppercaseA();
  //cout << "3: " <<CTex->GetText() << endl;
  CTex->PunctuationR();
  //cout << "4: " <<CTex->GetText() << endl;
  CTex->ExclamationR();
  //cout << "5: " <<CTex->GetText() << endl;
  CTex->UppercaseA();
  //cout << "6: " <<CTex->GetText() << endl;

  //--------------------------------------//
  
  //--------------------------------------//
  Timer Time;
  TxTypes *t = new TxTypes(*CTex);
  
  // TxTPronouns P;
   vector<string> vec=t->GetWordVector();
   //for(int i=0;i<vec.size();i++)
   //  cout << vec.at(i) << endl;
   //cout << vec[15] << endl;
   //cout << vec[15].size() << endl;
  //--------------------------------------//

  TxTables *Table =new TxTables(*t);
  Table->GetTable("frequency");
  Table->PronounsUR();
  Table->PrepositionsUR();
  Table->ConjunctionsUR();
  
  
  return 0;
}
