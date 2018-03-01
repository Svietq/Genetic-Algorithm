#ifndef HELPERS_H
#define HELPERS_H

namespace ga
{

namespace helpers
{

template <typename P, typename T>
void eval_func(P & pop, T func)
{
    for(auto & ind : pop)
    {
        func(ind);
    }
}


}

}

#endif // HELPERS_H
