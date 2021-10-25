#include <stdio.h>
#if defined(__linux__)
    void function(){
        printf("On linux\n");
        //getchar(); 
    }
#elif defined(_WIN32)
    void function(){
        printf("On windows\n");
        //getchar(); 
    }
#else
    void function(){
        printf("On somewhere else\n");
        //getchar(); 
    }

#endif

int main()
{
    function(); 
}