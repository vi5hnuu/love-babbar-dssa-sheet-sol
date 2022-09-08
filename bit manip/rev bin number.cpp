/*
//32 iteration
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(short int i=0;i<32;i++){
           int bit=(n>>i)&1;
            res=res | (bit<<(31-i));
        }
        return res;
    }
};
*/


//no. of bits in num iteration < 32
class Solution {
public:
    uint32_t reverseBits(uint32_t num) {
        if(!num)
            return num;

        uint32_t nnum=0;
        int size=sizeof(num)*8;
        while(num){
            nnum<<=1;
            nnum=nnum | (num&1);
            num>>=1;
            size--;
        }
        return nnum<<size;
    }
};
