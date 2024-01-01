class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.length(), n2 = version2.length();
        int i=0, j=0;
        while(i<n1 and j<n2){
            string s1 = "", s2 = "";
            while(i<n1 and version1[i] != '.'){
                s1.push_back(version1[i]);
                i++;
            }
            i++;

            while(j<n2 and version2[j] != '.'){
                s2.push_back(version2[j]);
                j++;
            }
            j++;

            int x1 = stoi(s1), x2 = stoi(s2);
            if(x1 < x2) return -1;
            else if(x1 > x2 )    return 1;
        }
        while(i<n1){
            string s1 = "";
            while(i<n1 and version1[i] != '.'){
                s1.push_back(version1[i]);
                i++;
            }
            i++;

            int x1 = stoi(s1);
            if(x1 > 0) return 1;
        }
        while(j<n2){
            string s2 = "";

            while(j<n2 and version2[j] != '.'){
                s2.push_back(version2[j]);
                j++;
            }
            j++;
            int  x2 = stoi(s2);
            if(x2 > 0) return -1;
        }
        return 0;
    }
};
