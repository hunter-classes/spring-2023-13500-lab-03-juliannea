#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
    //get east storage
    std::cout<<"East Storage test values"<<std::endl;

    std::cout<< get_east_storage("01/02/2018")<<std::endl;

    std::cout<< get_east_storage("09/29/2018")<<std::endl;

    std::cout<< get_east_storage("09/28/2018")<<std::endl;

    std::cout<<"\n";

    //get min and max of east
    std::cout<<"Get min and max of east"<<std::endl;

    std::cout << get_min_east() <<std::endl;

    std::cout << get_max_east() <<std::endl; 

    std::cout<<"\n";

    //compare basins
    std::cout<<"comparing basins"<<std::endl;

    std::cout<< compare_basins("01/01/2018")<<std::endl;

    std::cout<< compare_basins("02/04/2018")<<std::endl;

    std::cout<< compare_basins("09/13/2018")<<std::endl;

    std::cout<<"\n";

    //reverse order
    std::cout<<"Reverse order"<<std::endl;

    reverse_order("01/01/2018","01/05/2018");

    std::cout<<"\n";

    reverse_order("09/05/2018","09/11/2018");

    std::cout<<"\n"; 

    reverse_order("10/05/2018","10/11/2018");
}