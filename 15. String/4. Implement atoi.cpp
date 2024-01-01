class Solution {
    bool isDigit(char c){
        return c=='0' or c=='1' or c=='2' or c=='3' or c=='4' or c=='5' or c=='6' or c=='7' or c=='8' or c=='9';
    }

    int ctoi(char c){
        switch(c){
            case '0': return 0;
            case '1': return 1;
            case '2': return 2;
            case '3': return 3;
            case '4': return 4;
            case '5': return 5;
            case '6': return 6;
            case '7': return 7;
            case '8': return 8;
            case '9': return 9;
            default : return -1;
        }
    }

public:
    int myAtoi(string s) {
        string no="";
        int n = s.length();
        int sign = 1;

        for(int i=0; i<n; i++){
            if(s[i]!=' '){
                if(s[i]=='-'){
                    sign = -1;
                    i++;
                }
                else if(s[i]=='+'){
                    i++;
                }
                while(s[i]=='0')    i++;
                while(isDigit(s[i])){
                    no.push_back(s[i]);
                    i++;
                }
                break;
            }
        }
        long num = 0;
        n = no.length();
        long mul = 1;
        if(sign == 1){
            if(n>10) return INT_MAX;
            for(int i=n-1; i>=0; i--){
                num += ctoi(no[i]) * mul;
                mul *= 10;
                if(num > INT_MAX) {
                    return INT_MAX;
                }
            }
        }
        else{
            if(n>10) return INT_MIN;
            for(int i=n-1; i>=0; i--){
                num -= ctoi(no[i]) * mul;
                mul *= 10;
                if(num < INT_MIN){
                    return INT_MIN;
                }
            }
        }
        
        return (int)num;
    }
};
