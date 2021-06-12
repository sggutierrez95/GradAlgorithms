#include <iostream>
#include <random>
#include <string>


int runLIS(const int * seq, const int count)
{
    int * lis = new int[10];
    for (size_t i = 0; i < count; i++)
    {
        lis[i] = 1;
        int limit = i - 1;
        for (int j = 0; j <= limit; j++)
        {
            bool cond1 = seq[j] < seq[i];
            bool cond2 = lis[i] < 1 + lis[j];
            if(cond1 && cond2)
            {
                lis[i] = 1 + lis[j];
            }
        }
    }

    int max = 1;
    for (size_t i = 0; i < count; i++)
    {
        if(lis[i] > lis[max])
        {
            max = i;
        }
    }
    return lis[max];
}

///@brief Generates seq based on size
///@param [in] size size of seq desired
///@return seq of size inputed
int * generateSeq(size_t count)
{
    int * res = new int[10];
    for (size_t i = 0; i < count; i++)
    {
        res[i] = rand() % 100 +1;
    }
    
    return res;
}

///@brief Print out sequence
void printSeq(const int * seq, size_t count, std::string name)
{
    std::cout << "Seq(" << name << "):" << std::endl;
    for (size_t i = 0; i < count; i++)
    {
        std::cout << " " << seq[i];
    }
    std::cout << std::endl;
}

struct SeqData
{
    std::string name;
    int * seq;
    int lisRes;
};

int main(int argc, const char** argv) {
    const size_t count = 10;
    SeqData examples[count];

    for (size_t i = 0; i < count; i++)
    {
        SeqData * data = &examples[i];
        std::string name = "Seq" + std::to_string(i);
        data->name = name;
        data->seq = generateSeq(10);
        data->lisRes = runLIS(data->seq, 10);
    }

    for (size_t i = 0; i < count; i++)
    {
        SeqData * data = &examples[i];
        printSeq(data->seq, 10, data->name);
        std::cout << "LisCount: " << data->lisRes << std::endl;
    }

    return 0;
}