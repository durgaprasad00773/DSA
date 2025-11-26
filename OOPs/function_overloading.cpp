#include <iostream>
using namespace std;
class area
{
    public:
    void calculatearea(int r)
    {
        cout << 3.14*r*r << endl;
    }
    void calculatearea(int l, int b)
    {
        cout << l*b << endl;
    }
};
int main()
{
    area a1;
    a1.calculatearea(2);
    a1.calculatearea(4, 5);
}