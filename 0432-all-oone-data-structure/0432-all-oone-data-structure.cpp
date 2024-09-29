// class AllOne {
// public:

//         struct Node{

//             int count;
//             list<string>keys;
//             Node * prev;
//             Node * next;

//             Node(int c)
//             {
//                 count=c;
//                 prev=nullptr;
//                 next=nullptr;
//             }
            
//         };

//         unordered_map<string,Node*>mp; //stores string and its respective adress;

//             Node * head;
//             Node * last;

//     AllOne() {

//         head= new Node(0); //declaring a dummy node that acts as a refrence 
//         last=head;
        
//     }

//     void addNode(Node* prevs , int count)
//     {
//         Node * newNode= new Node(count);

//         newNode->next=prevs->next;
//         newNode->prev=prevs;

//         if(newNode->next!=nullptr)
//         {
//             newNode->next->prev=newNode;
//         }

//         prevs->next=newNode;

//         if(prevs==last)
//         {
//             last=newNode;
//         }
//     }

//     void removeNode(Node* Ele)
//     {
//         Ele->prev->next=Ele->next;

//         if(Ele->next!=nullptr)
//         {
//             Ele->next->prev=Ele->prev;
//         }

//         if(last==Ele)
//         {
//             last=Ele->prev;
//         }

//         delete(Ele);
//     }
    
//     void inc(string key) {

//             if(mp.find(key)==mp.end())
//             {
//                 if(head->next==nullptr || head->next->count!=1)
//                 {
//                     addNode(head,1);
//                 }

//                 head->next->keys.push_front(key);
//                 mp[key]=(head->next);
//             }

//             else{

//                 Node * currnode = mp[key];
//                 int thiscount= currnode->count;
                
//                 if(currnode->next == nullptr || currnode->next->count != thiscount+1)
//                 {
//                     addNode(currnode,thiscount+1);
//                 }

//                 currnode->next->keys.push_back(key);
//                 mp[key]=currnode->next;
//                 currnode->keys.remove(key);

//                 if(currnode->keys.empty())
//                 {
//                     removeNode(currnode);
//                 }

//             }
        
//     }
    
//     void dec(string key) {

//             Node * currnode=mp[key];
//             int thiscount=currnode->count;

//             if(thiscount==1)
//             {
//                 mp.erase(key);
//             }

//             else{

//                 if(currnode->prev->count!=thiscount-1)
//                 {
//                     addNode(currnode->prev,thiscount-1);
//                 }

//                 currnode->prev->keys.push_back(key);
//                 mp[key]=currnode->prev;

//             }

//             currnode->keys.remove(key);

//             if(currnode->keys.empty())
//             {
//                 removeNode(currnode);
//             }
        
//     }
    
//     string getMaxKey() {

//         if(last==head)
//         {
//             return "";
//         }
        
//         return last->keys.front();
        
//     }
    
//     string getMinKey() {

//         if(head->next==nullptr)
//         {
//             return "";
//         }

//         return head->next->keys.front();
//     }
// };

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */


class AllOne {
public:

        unordered_map<string,int>mp;
        set<pair<int,string>>st;


    
    
    void inc(string key) {

            int n=mp[key];
            mp[key]++;
            st.insert({n+1,key});
            st.erase({n,key});
        
    }
    
    void dec(string key) {

        int n=mp[key];
        mp[key]--;
        st.erase({n,key});
        if(mp[key]>0) st.insert({n-1,key});
        else mp.erase(key);
        
    }
    
    string getMaxKey() {

        if(!st.empty()) return st.rbegin()->second;
        return "";
    }
    
    string getMinKey() {
        
            if(!st.empty()) return st.begin()->second;
             return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */