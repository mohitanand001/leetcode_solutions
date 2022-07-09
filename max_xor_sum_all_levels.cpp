#include<bits/stdc++.h>
using namespace std;

class Node
{
   public: 
      Node *children[2];
      bool is_end;

      bool contains_child(int ch)
      {
         return children[ch] != nullptr;
      }

      Node* get_child(int ch)
      {
         return children[ch];
      }

      void put_child(int ch, Node* node)
      {
         children[ch] = node;
      }
};


class Trie
{

   public: Node* root;
   map<int, int> lvl_max_1, lvl_max_0;

   Trie()
   {
      root = new Node();
   }

   void insert(long n)
   {
      Node* temp = root;
      long ith_bit;


      for(int i = 31; i >= 0; i--)
      {
         ith_bit = ((n >> i) & 1);

         if(ith_bit)
            lvl_max_1[i]++;
         else
            lvl_max_0[i]++;

         if(!temp->contains_child(ith_bit))
         {
            temp->put_child(ith_bit, new Node());
         }

         temp = temp->get_child(ith_bit);
      }
   }

   int mx_sum(long n)
   {
      Node* temp = root;
      long ith_bit;
      long ans = 0;

      for(int i = 31; i >= 0; i--)
      {
         ith_bit = ((n >> i) & 1);

         if(lvl_max_1[i] > lvl_max_0[i])
         {
            if(temp->contains_child(0))
            {
               temp = temp->get_child(0);
            }
            else
            {
               ans = ans + (1 << i);
               temp = temp->get_child(1);
            }
         }
         else
         {
            if(temp->contains_child(1))
            {
               ans = ans + (1 << i);
               temp = temp->get_child(1);
            }
            else
               temp = temp->get_child(0);
         }

         // cout << temp->val;

         

      }

      return ans;

   }
};




long long maximumPossibleScore (int N, vector<long long> A) {
   // Write your code here


   Trie trie;

   for(int i = 0; i < A.size(); i++)
      trie.insert(A[i]);

   // for(auto it = trie.lvl_max_1.begin(); it != trie.lvl_max_1.end(); ++it)
   //    cout << (it->first) << " " << (it->second) << endl;

   // cout << (trie.mx_sum(0)) << endl;

   long long m =  trie.mx_sum(0);
   long long sm = 0;
   for(int i = 0; i < A.size(); i++)
      sm += (A[i] ^ m);

   return sm; 
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i_A = 0; i_A < N; i_A++)
    {
    	cin >> A[i_A];
    }

    long long out_;
    out_ = maximumPossibleScore(N, A);
    cout << out_;
}
