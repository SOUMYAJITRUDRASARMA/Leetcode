class ProductOfNumbers {
public:
    vector<int> prefixPdt;

    ProductOfNumbers() {
        prefixPdt.push_back(1);
    }

    void add(int num) {
        if(num) prefixPdt.push_back(prefixPdt.back() * num);
        else prefixPdt.clear(), prefixPdt.push_back(1);
    }

    int getProduct(int k) {
        return (prefixPdt.size() > k)? (prefixPdt.back() / prefixPdt[prefixPdt.size() - k - 1]): 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
