#include <iostream>

class Iterator
{
    friend class Multiple;
    private:
        int *element;
    public:
        Iterator()
        {
            element = 0;
        }
        Iterator(const Iterator &a)
        {
            element = a.element;
        }
        bool operator==(const Iterator &a)
        {
            return element==a.element;
        }
        bool operator!=(const Iterator &a)
        {
            return element!=a.element;
        }
        void operator++(int)
        {
            ++element;
        }
        int &operator*()
        {
            return *element;
        }
};

class Multiple
{
    protected:
        int size;
        int *data;
        Iterator start;
        Iterator end;
    public:
        Iterator first(){ return start; }
        Iterator last(){ return end; }
        Multiple(int, int);
        Multiple(const Multiple &);
        ~Multiple();
        Multiple &operator=(const Multiple &);
        Multiple &operator+(Multiple &);
        int operator[](int);
        int operator()();
        friend std::ostream &operator<<(std::ostream &out, const Multiple &);
        friend std::istream &operator>>(std::istream &in, Multiple &);
};