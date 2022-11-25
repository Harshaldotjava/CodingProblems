#include <iostream>
using namespace std;

class Block{
    private:
        int BLOCK_NO = 0;
        int nonce = 0;
        int data = 0;
        int prev_hash;
        int hash = 0;
        Block *prev_block = NULL;
        bool currupt = false;
    public:
        void setBlockNo(int no){
            BLOCK_NO = no;
        }
        void setPrevBlock(Block *block){
            prev_block = block;
        }

        void setPrevHash(int hash){
            prev_hash = hash;
        }
        Block* getPrevBlock(){
            return prev_block;
        }
        int getHash(){
            return hash;
        }
        void setCorrupt(){
            corrupt = true;
        }
        void isCorrupt(){
            return corrupt;
        }
};

class Blockchain{
    Block *last_block = NULL;
    Block *genesis_block = NULL;
    static int number_of_blocks;
    
    public:
    void addBlock(Block *block){
        if(last_block == NULL){
            number_of_blocks = 0;
            last_block = block;
            last_block->setPrevHash(0) ;
            last_block->setPrevBlock(NULL);
            last_block->setBlockNo(++number_of_blocks);
            genesis_block = last_block;
            return;
        }

        block->setPrevHash(last_block->getHash());
        block->setPrevBlock(last_block);
        last_block->setBlockNo(++number_of_blocks);
        last_block = block;
        return;
    }
    
};
    

int main(){

    return 0;
}
