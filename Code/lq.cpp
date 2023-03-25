class test
{
private:
    char str[20] ;
public:
    test(char* str);
    ~test();
    void show();
};

test::test(char * str)
{
    
}

test::~test()
{

}


void fun(char * str){
    test obj(str);
    obj.show();
}