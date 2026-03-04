//link: https://neetcode.io/problems/serialize-and-deserialize-binary-tree/question
/*

The fullworkflow: 
1. (root, res(which is empty)) --> dfsserializer ---> it modifies res and we get res = ["1", "2", "N", "N", "3", "N", "N"]
2. pass this res and "," --> join --> "1,2,N,N,3,N,N" (a string)
3. this string and index is passed to ---> split ---> which converts it to the vector of strings again.
4. pass this vector to dfsdeserializer which converts it to a tree and returns the root node.

The split function:
1. Recieves a string to split, and a delimiter char ',' (it's char not string as getline can't process strings)
2. Define a stringstream from the string.
3. Get item from the stream (It stops if we encounter the delimiter), and push it to the vector elems;
4. return the vector of stings elems

The join function:
1. Receives a vector of strings and a delimiter "," (as a string)
2. Define a ostringstream to write.
3. If it's the first element, don't add the delimiter in the string.
4. Add the delimiter and the item to the string.

The recursive dfsSerializer function:
1. Gets the root and a blank res vector.
2. Base case: If the node is nullptr, push "N" and return;
3. else convert the value to string and push it.
4. call dfsSerializer(left node) and defsSerializer(right node)

The recursive dfsDeserializer function:
1. Gets a vector and an iterator i,
2. If value at i is N, the return nullptr and i++;
3. Else, convert the value to integer and define a new node having this value. ++
4. call left node = dfsDeserializer(vector, i) and right node = dfsDeserializer(vector, i)
5. Return root

Use pass by reference in every function.

*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector <string> res;
        dfsSerialize (root, res);
        return join(res, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector <string> vals = split(data, ',');
        int i = 0;
        return dfsDeserialize(vals, i);
    }

private:
    void dfsSerialize(TreeNode* node, vector <string>& res){
        if(!node) {
            res.push_back("N");
            return;
        }
        res.push_back(to_string(node->val));
        dfsSerialize(node->left, res);
        dfsSerialize(node->right, res);
    }

    TreeNode* dfsDeserialize(vector<string>& vals, int& i){
        if(vals[i] == "N") {
            i++;
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = dfsDeserialize(vals, i);
        node->right = dfsDeserialize(vals, i);
        return node;
    }

    vector <string> split(const string &s, char delim) {
        vector <string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    string join (const vector <string> &v, const string &delim) {
        ostringstream s;
        for ( const auto &i : v) {
            if (&i != &v[0]) s << delim;
            s << i;
        }
        return s.str();
    }
};