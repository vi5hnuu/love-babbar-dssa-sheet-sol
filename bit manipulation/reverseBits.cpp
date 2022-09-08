class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(short int i=0;i<32;i++){
           int bit=(n>>i)&1; //take last bit(from right)
            res=res | (bit<<(31-i)); //or to res from end(left)
        }
        return res;
    }
};