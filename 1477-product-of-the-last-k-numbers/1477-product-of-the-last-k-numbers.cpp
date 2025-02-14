class ProductOfNumbers {
public:

    vector<int>prod={1};
    int multi=1;
    ProductOfNumbers() {

        prod.reserve(40001);
    }
    
    void add(int num) {
         
         if(num == 0)
         {
            prod={1};
            multi=1;
         }

         else 
         {
                multi *= num;
                prod.push_back(multi);
         }
    }
    
    int getProduct(int k) {
        int n=prod.size();
        if(k>=n) return 0;
        return prod[n-1]/prod[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */