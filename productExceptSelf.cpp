#include <vector>
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int tam = nums.size();
        std::vector<int> esquerda = nums;
        std::vector<int> direita = nums;
        std::vector<int> result(tam);
        
        for (int i = 1, j = tam-2; i < tam; i++,j--) {
            esquerda[i] *= esquerda[i-1];
            direita[j] *= direita[j+1];
        }
        
        result[0] = direita[1];
        result[tam-1] = esquerda[tam-2];
        for (int i = 1; i < tam-1; i++) {
            result[i] = esquerda[i-1] * direita[i+1];
        }
        
        return result;
    }
};