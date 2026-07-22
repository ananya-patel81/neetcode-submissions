class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t b = 0;
        for(int i = 31;i>=0;i--){
            uint32_t bit = (n>>i)&1 ;
            b+= (bit<<(31-i));
        }
        return b;


        
    }
};
