// TODO 1: rewrite the function exchange() by substituting its arguments with templates
template <class E>

void exchange(E &var1, E &var2) 
{
    E temp=var1; 
    var1=var2; var2=temp;
}

// TODO 2: rewrite the function declaration by using templates
template <class D,class C>

void sortVec(vector<D>& vec1,vector<C>& vec2) {
    int n = vec1.size();
    for (int i=0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (vec1[j] < vec1[i]) {
               exchange<D>(vec1[i], vec1[j]);
               exchange<C>(vec2[i], vec2[j]);
            }
        }
    }
}

