class Solution {
public:
    bool isValid(string s) {
           if(s.size() == 0)
        return true;
    stack<char> strst;
    for(int i=0; i<s.size(); ++i){
        if(strst.empty())
        {
            strst.push(s[i]);
        }
        else{
            if(strst.top()=='(' && s[i] == ')'){
                strst.pop();
            }
            else if(strst.top() == '[' && s[i] == ']'){
                 strst.pop();
            }
            else if(strst.top() == '{' && s[i] == '}')
            {
                 strst.pop();
            }
            else{
                strst.push(s[i]);
            }
        }
    }
    if(strst.empty())
        return true;
    return false;
    }
};
