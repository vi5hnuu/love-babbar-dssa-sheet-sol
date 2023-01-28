/*
Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.

If a folder[i] is located within another folder[j], it is called a sub-folder of it.

The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.

For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.
 

Example 1:

Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
Output: ["/a","/c/d","/c/f"]
Explanation: Folders "/a/b" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.
Example 2:

Input: folder = ["/a","/a/b/c","/a/b/d"]
Output: ["/a"]
Explanation: Folders "/a/b/c" and "/a/b/d" will be removed because they are subfolders of "/a".
Example 3:

Input: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
Output: ["/a/b/c","/a/b/ca","/a/b/d"]
 

Constraints:

1 <= folder.length <= 4 * 104
2 <= folder[i].length <= 100
folder[i] contains only lowercase letters and '/'.
folder[i] always starts with the character '/'.
Each folder name is unique.
*/

//TLE 31/32
// class Trie {
//     class Node{
//         public:
//             string folderName;
//             vector<Node*> children{};
//             bool eow{};//end of word
//             Node(string fname){
//                 this->folderName=fname;
//             }
//     };
//     Node *root{};

//     void insert(Node *root,istringstream &pathstream){
//         string fname;
//         getline(pathstream,fname,'/');

//         bool nodeFound=false;
//         for(Node *node:root->children){
//             if(node->folderName==fname){
//                 // cout<<"collide "<<fname<<endl;
//                 if(pathstream.peek()==-1){//nothing in stream
//                     node->eow=true;
//                 }
//                 nodeFound=true;
//                 insert(node,pathstream);
//                 break;
//             }
//         }
//         if(!nodeFound){
//             Node *rt=root;
//             while(fname.length()>0){
//                 Node *tmp=new Node(fname);
//                 // cout<<"Inserting "<<fname<<endl;
//                 if(pathstream.peek()==-1){
//                     tmp->eow=true;
//                 }
//                 rt->children.push_back(tmp);
//                 rt=tmp;

//                 fname="";
//                 getline(pathstream,fname,'/');
//             }
//         }
//     }

//     void getPathsARS(Node *root,vector<string> &paths,string path="") {
//         if(!root){
//             return; //this can never happen as root('/') is always there 
//         }
//         for(Node *node:root->children){
//             if(node->eow){
//                 paths.push_back(path+"/"+node->folderName);
//                 continue;
//             }
//             getPathsARS(node,paths,path+"/"+node->folderName);
//         }
//     }
//     void releaseMemory(Node *root){
//         if(!root){
//             return;
//         }
//         // cout<<"deleting "<<root->character<<endl;
//         for(Node *node:root->children){
//             releaseMemory(node);
//         }
//         delete root;
//     }
// public:
//     Trie(vector<string> &paths) {
//         root=new Node("/");
//         for(string &path:paths){
//             insert(path);
//         }
//     }
//     ~Trie(){
//         releaseMemory(root);
//         root=nullptr;
//     }
    
//     void insert(string path) {
//         istringstream pathstream(path.substr(1)+"/");
//         this->insert(root,pathstream);
//     }

//     //getPathsARS -> get paths after removing subfolders
//     vector<string> getPathsARS() {
//          vector<string> paths;
//          getPathsARS(root,paths);
//          return paths;
//     }
// };
// class Solution {
// public:
//     vector<string> removeSubfolders(vector<string>& folder) {
//         Trie folderStructure{folder};
//         return folderStructure.getPathsARS();
//     }
// };

///////////////////////////////
class Trie {
    class Node{
        public:
            string folderName;
            vector<Node*> children{};
            bool eow{};//end of word
            Node(string fname){
                this->folderName=fname;
            }
    };
    Node *root{};

    void insert(Node *root,istringstream &pathstream){
        string fname;
        getline(pathstream,fname,'/');

        bool nodeFound=false;
        for(Node *node:root->children){
            if(node->folderName==fname){
                // cout<<"collide "<<fname<<endl;
                if(node->eow){
                //short file system already in .. as in /a alreay in tree
                //and now we trying to insert /a/*
                    return;
                }
                if(pathstream.peek()==-1){//nothing in stream
                    node->eow=true;
                }
                nodeFound=true;
                insert(node,pathstream);
                break;
            }
        }
        if(!nodeFound){
            Node *rt=root;
            while(fname.length()>0){
                Node *tmp=new Node(fname);
                // cout<<"Inserting "<<fname<<endl;
                if(pathstream.peek()==-1){
                    tmp->eow=true;
                }
                rt->children.push_back(tmp);
                rt=tmp;

                fname="";
                getline(pathstream,fname,'/');
            }
        }
    }

    void getPathsARS(Node *root,vector<string> &paths,string path="") {
        if(!root){
            return; //this can never happen as root('/') is always there 
        }
        for(Node *node:root->children){
            if(node->eow){
                paths.push_back(path+"/"+node->folderName);
                continue;
            }
            getPathsARS(node,paths,path+"/"+node->folderName);
        }
    }
    void releaseMemory(Node *root){
        if(!root){
            return;
        }
        // cout<<"deleting "<<root->character<<endl;
        for(Node *node:root->children){
            releaseMemory(node);
        }
        delete root;
    }
public:
    Trie(vector<string> &paths) {
        root=new Node("/");
        for(string &path:paths){
            insert(path);
        }
    }
    ~Trie(){
        releaseMemory(root);
        root=nullptr;
    }
    
    void insert(string path) {
        istringstream pathstream(path.substr(1)+"/");
        this->insert(root,pathstream);
    }

    //getPathsARS -> get paths after removing subfolders
    vector<string> getPathsARS() {
         vector<string> paths;
         getPathsARS(root,paths);
         return paths;
    }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie folderStructure{folder};
        return folderStructure.getPathsARS();
    }
};