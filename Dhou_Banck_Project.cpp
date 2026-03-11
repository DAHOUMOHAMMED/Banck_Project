
#include <iostream>
#include "clsBanckClient.h"


int main()

{
    clsBanckClient Client1 = clsBanckClient::Find("A101");
    Client1.Print();

    system("pause>0");

    return 0;
}