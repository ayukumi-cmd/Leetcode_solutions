class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();


        int xor1=0;
        int xor2=0;

        for(int i=0; i<n1; i++){
            xor1^=nums1[i];
        }

        for(int j=0; j<n2; j++){
            xor2^=nums2[j];
        }



        if(n1&1 and n2&1){return xor1^xor2;}
        else if(n1&1){return xor2;}
        else if(n2&1){return xor1;}
        else {return 0;}
    }
};