#include <bits/stdc++.h>
using namespace std;
class UnionFind
{
    public:
    UnionFind();
    string find(string node);
    void unify(string node1,string node2);
    private:
    map<string,int> root;
    map<string,int> id;
    vector<string> sid;
    vector<int> size;
};
UnionFind::UnionFind()
 {
     root.insert(pair<string,int>("A",0));
     root.insert(pair<string,int>("B",1));
     root.insert(pair<string,int>("C",2));
     root.insert(pair<string,int>("D",3));
     root.insert(pair<string,int>("E",4));
     root.insert(pair<string,int>("F",5));
     root.insert(pair<string,int>("G",6));
     root.insert(pair<string,int>("H",7));
     root.insert(pair<string,int>("I",8));
     root.insert(pair<string,int>("J",9));
     id.insert(pair<string,int>("A",0));
     id.insert(pair<string,int>("B",1));
     id.insert(pair<string,int>("C",2));
     id.insert(pair<string,int>("D",3));
     id.insert(pair<string,int>("E",4));
     id.insert(pair<string,int>("F",5));
     id.insert(pair<string,int>("G",6));
     id.insert(pair<string,int>("H",7));
     id.insert(pair<string,int>("I",8));
     id.insert(pair<string,int>("J",9));
     size.push_back(1);
     size.push_back(1);
     size.push_back(1);
     size.push_back(1);
     size.push_back(1);
     size.push_back(1);
     size.push_back(1);
     size.push_back(1);
     size.push_back(1);
     size.push_back(1);
     sid.push_back("A");
     sid.push_back("B");
     sid.push_back("C");
     sid.push_back("D");
     sid.push_back("E");
     sid.push_back("F");
     sid.push_back("G");
     sid.push_back("H");
     sid.push_back("I");
     sid.push_back("J");

 }
 string UnionFind::find(string node) {
     while(root[node]!=id[node]) {
         node=sid[root[node]];
     }
     return sid[root[node]];
 }
 void UnionFind::unify(string node1,string node2)
 {
     if(root[node1]==root[node2]) return;

     if(size[id[node1]]>size[id[node2]]) {
         size[id[node1]]+=size[id[node2]];
         size[id[node2]]=size[id[node1]];
          while(root[node2]!=id[node2]) {
              node2=sid[root[node2]];
         }
         root[node2]=root[node1];
     }
     else {
         size[id[node2]]+=size[id[node1]];
         size[id[node1]]=size[id[node2]];
         while(root[node1]!=id[node1]) {
              node1=sid[root[node1]];
         }
         root[node1]=root[node2];
     }
     return;
 }

 int main(void) {
     UnionFind test;
     test.unify("A","D");//D become root of A
     test.unify("B","C");//C become root of B
     test.unify("D","G");//D become root of G
     test.unify("B","A");//D become root of B and C
     cout << test.find("B") << endl;
     cout << test.find("C") << endl;
     test.unify("E","F");//F become root of E
     test.unify("E","H");//F become root of H
     test.unify("H","I");//F become root of I
     test.unify("I","J");//F become root of J
     test.unify("C","J");//F become root of D ,A ,C,B,G
     cout << test.find("G") << endl;
     cout << test.find("C") << endl;
     cout << test.find("J") << endl;
     cout << test.find("D") << endl;
     return 0;
 }